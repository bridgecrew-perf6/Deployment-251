//////////////////////////////////////////////////
//                                              //
// Copyright 2020-2021                          //
// Notise: Property of Innoweave Smart Solutions//
// Any part of this code cannot be copied or    //
// redistributed without prior consent of       //
// Innoweave                                    //
//                                              //
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// File Name: cloudCommunication.h 
// File Description: communication related 
//                   operations
// Author: Priyankar
// Date: July 01, 2021
//////////////////////////////////////////////////

#include "cloudCommunication.h"

cloudCommunication::cloudCommunication():
  timeClient(ntpUDP, ntpServer, gmtOffsetSec, updateIntervalmSec),
  client(AWS_endpoint, mqttPortNo, espClient) 
{ 
  WiFi.begin(ssid, password); 
  timeClient.begin();
}

cloudCommunication::~cloudCommunication()
{
}

bool cloudCommunication::getWifiStatus()
{
  return(WiFi.status() == WL_CONNECTED);
}

void cloudCommunication::begin()
{
  espClient.setBufferSizes(512, 512);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  

  // Blocking Call to Update timeclient
  // TODO: HIGH PRIORITY Make it non blocking Call
  while(!timeClient.update()){
    timeClient.forceUpdate();
  }
  espClient.setX509Time(timeClient.getEpochTime());
  isCertLoaded = loadCerts();
  macID = WiFi.macAddress();
}
bool cloudCommunication::getAWSConnectStatus()
{
  if(client.connected()){
    return true;
  }
  Serial.print("Attempt connection to AWS...");
  if (client.connect(AWS_THINGNAME)) 
  {
    Serial.println("Connection to AWS established ... ");
    client.publish(AWS_IOT_PUBLISH_TOPIC, "hello world");
    client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
    return true;
  }
  return false;
}

bool cloudCommunication::sendSensorsDatatoAWS(meteringd::meteringData& cData)
{
  isCertLoaded = loadCerts();
  isWifiConnected = getWifiStatus();
  isAWSConnected = getAWSConnectStatus();
  
  // Check if Certificates are Loaded, Wifi and AWS Connected
  if(isCertLoaded && isWifiConnected && isAWSConnected) 
  {
    StaticJsonDocument<256> meteringMsg;
    meteringMsg["ts"] = cData.timeStamp;
    meteringMsg["macID"] = macID;
    meteringMsg["uID"] = uID;
    meteringMsg["mType"] = static_cast<uint8_t>(cloudCommunication::messageType::METERING_DATA);
    meteringMsg["T"] = cData.tempData;
    meteringMsg["pH"] = cData.phData;
    meteringMsg["dO"] = cData.doData;

    char mMsgBuffer[512];
    serializeJson(meteringMsg, mMsgBuffer); // print to client
    Serial.print("Publish message: ");
    Serial.println(mMsgBuffer);
    client.publish(AWS_IOT_PUBLISH_TOPIC, mMsgBuffer);
    Serial.print("Heap: "); Serial.println(ESP.getFreeHeap()); //Low heap can cause problems
    return true;
  }
  else
  {
    Serial.print("isCertLoaded: ");
    Serial.print(isCertLoaded);
    Serial.print(" isWifiConnected: ");
    Serial.print(isWifiConnected);
    Serial.print(" isAWSConnected: ");
    Serial.print(isAWSConnected);
    return false;
  }
}

// Updates cTime with Current Time
// Returns True if time is Good else returns false
bool cloudCommunication::getCurrentTime(uint32_t& cTime)
{
  isTimeGood = timeClient.update();
  cTime = timeClient.getEpochTime();
  return isTimeGood;
}

bool cloudCommunication::loadCerts()
{
  if(isCertLoaded == true){
    return true;
  }
  
  if (!SPIFFS.begin()) {
    Serial.println("Failed to mount file system");
    return false;
  }
  
  File cert = SPIFFS.open("/cert.der", "r"); 
  if (!cert) {
    return false;
  }
  if (!espClient.loadCertificate(cert)){
    return false;
  }

  // Load private key file
  File private_key = SPIFFS.open("/private.der", "r");
  if (!private_key) {
    return false;
  }    
  if (!espClient.loadPrivateKey(private_key)){
    return false;
  }
  
  // Load CA file
  File ca = SPIFFS.open("/ca.der", "r"); //replace ca eith your uploaded file name
  if (!ca) {
    return false;
  }  
  if(!espClient.loadCACert(ca)){
    return false;
  }
  return true;
}
