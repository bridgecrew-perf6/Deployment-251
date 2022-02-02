//////////////////////////////////////////////////
//                                              //
// Copyright 2020-2021                          //
// Notice: Property of Innoweave Smart Solutions//
// Any part of this code cannot be copied or    //
// redistributed without written prior consent  //
// of Innoweave                                 //
//                                              //
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// File Name: MATSYA_FW_Release_1.ino 
// File Description: Entry Point for MATSYA  
//                   Release 1 FW Code
// Connection: Refer HW Design Documentation 
// Author: Priyankar
// Date: June 01, 2021
//////////////////////////////////////////////////

// Include Header Files
#include <SimpleTimer.h>
#include "databaseHandler.h"
#include "meteringd.h"
#include "cloudCommunication.h"

// Device Settings
const char *FW_Version = "0.0.0.1";
#define TEMP
#define pH
#define DO

const long DO_FIFTEEN_MIN_INTERVAL_MS = 900000; // 15 min * 60 s * 1000 ms
const long DO_TWENTY_FOUR_HRS_INTERVAL_MS = 86400000; // 24 hr * 60 m * 60 s * 1000 ms
const long DO_SEVEN_DAYS_INTERVAL_MS = 604800000; // 7 d * 24 hr * 60 m * 60 s* 1000 ms

// Hardware Connection Details
// Chip Select pin for SD Card
#define SD_CARD_CS_PIN  D8

SimpleTimer doFifteenM;
SimpleTimer doTwentyFourH;
SimpleTimer doSevenD;
meteringd meterD;
cloudCommunication cCommunication;

void setup(void)
{
  doOnPowerOn();
}

void loop(void){ 
  doFifteenM.run();
  doTwentyFourH.run();
  doSevenD.run();
}

void doOnPowerOn()
{
  // Begin serial communication 
  Serial.begin(115200);
  Serial.print("Starting main program ... \n");
  cCommunication.begin();
  // Assumes the device is on for all the time (TODO: This Logic becomes independent of this Assumption
  doFifteenM.setInterval(DO_FIFTEEN_MIN_INTERVAL_MS, doFifteenMin);
  doTwentyFourH.setInterval(DO_TWENTY_FOUR_HRS_INTERVAL_MS, doTwentyFourHrs);
  doSevenD.setInterval(DO_SEVEN_DAYS_INTERVAL_MS, doSevenDays);
  Serial.print("Initialized Timers ...\n");
  delay(1000); // Wait for 1s to initialize Wifi connection
}
void doFifteenMin()
{
  Serial.print("Inside doFifteenMin ...\n");

  // Get Current Timestamp and Sensor Data
  uint32_t cTime = 0;
  cCommunication.getCurrentTime(cTime);
  meteringd::meteringData currentData;
  Serial.print("Reading SensorData ...\n");
  meterD.readCurrentData(cTime);
  meterD.getCurrentData(currentData);

  // Send Data to AWS if N/w is available
  // ToDo: Send all pending Data
  bool isDataSent = false;
  if(cCommunication.sendSensorsDatatoAWS(currentData) == true){
    isDataSent = true;
  }

  // Update dB with the data and isSent status
  Serial.print("Updating dB with Latest Value ... \n");
  updateSensorDataindB(currentData, isDataSent);
}

void doTwentyFourHrs()
{
  ;
}
void doSevenDays()
{
  ;
}

void updateSensorDataindB(meteringd::meteringData& currentData, bool isDataSent)
{
  databaseHandler dbHandler(SD_CARD_CS_PIN);
  bool updateStatus = 0;
  updateStatus = dbHandler.updateSensorsData(currentData, isDataSent);
  // Use try exception instead
  if (updateStatus)
  {
    Serial.println("sensorsData.txt was successfully updated");
  }
  else
  {
    Serial.println("Failed to open sensorsData.txt");
  }
}
