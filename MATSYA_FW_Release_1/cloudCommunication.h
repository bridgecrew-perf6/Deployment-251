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
// Date: Juky 01, 2021
//////////////////////////////////////////////////
#ifndef cloudCommunication_h
#define cloudCommunication_h

#ifdef __cplusplus
#include <stdint.h>

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <PubSubClient.h> //https://www.arduinolibraries.info/libraries/pub-sub-client
#include <ArduinoJson.h>

#include "meteringd.h"

class cloudCommunication
{
private:
  WiFiUDP ntpUDP;
  NTPClient timeClient;
  WiFiClientSecure espClient;
  PubSubClient client;
  bool isTimeGood = false;
  bool isWifiConnected = false;
  bool isAWSConnected = false;
  bool isCertLoaded = false;
  bool loadCerts();
  String macID;

protected:
  static constexpr char *ssid     = "pks";
  static constexpr char *password = "priyankar";
  static constexpr char *ntpServer = "pool.ntp.org";
  static const uint32_t gmtOffsetSec = 19800; // UTC + 5:30 = 5.5 x 60 x 60
  static const uint32_t updateIntervalmSec = 3600000; // 1 hr = 1 x 60 x 60 x 1000 
  static constexpr char *AWS_endpoint = "a34q0juk8ecoeu-ats.iot.ap-south-1.amazonaws.com"; //MQTT broker ip
  static const uint16_t mqttPortNo = 8883; //set MQTT port number to 8883 as per standard
  static constexpr char *deviceType = "MATSYA_RELEASE_1";
  static constexpr char *uID = "MAT_TEST_DEV_000001";
  static const uint16_t BUFFER_LEN = 256;
  static constexpr char *AWS_THINGNAME = "ESPthing";
  static constexpr char *AWS_IOT_PUBLISH_TOPIC = "outTopic";
  static constexpr char *AWS_IOT_SUBSCRIBE_TOPIC = "inTopic";

public:
  cloudCommunication();
  ~cloudCommunication();
  bool sendSensorsDatatoAWS(meteringd::meteringData&);
  bool getWifiStatus();
  bool getAWSConnectStatus();
  bool getCurrentTime(uint32_t&);
  void begin();
  enum class messageType : uint8_t
  {
    ACK = 0x00,
    NAK = 0x01,
    REG_REQ = 0x02,
    METERING_DATA = 0x03,
    DEBUG_LOGS = 0x04,
    DEBUG_LOGS_RESPONSE = 0x05,
    ACTION_REQ = 0x06
  };

};

#endif
#endif
