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
// File Name: databaseHandler.cpp 
// File Description: Database related operations
// Author: Priyankar
// Date: June 02, 2021
//////////////////////////////////////////////////

#include "databaseHandler.h"

databaseHandler::databaseHandler(uint8_t chipselectPin)
{
  csPin = chipselectPin;
  
  // Check the SD Card connection and Initialize it
  if (!SD.begin(chipselectPin)) {
    Serial.println("Initialization Failed. Check the Connection!");
    return;
  }
  
  Serial.println("SD Card Initialized");
}

databaseHandler::~databaseHandler()
{
}

bool databaseHandler::updateSensorsData(meteringd::meteringData& currentData, bool isDataSent)
{
  File sensorsData = SD.open("sensorsData.txt", FILE_WRITE);
  bool fStatus = 0;
  if (sensorsData) {
    fStatus = 1;
    // File Format Line By Line: Timestamp | Temp | ph | DO | isSent
    sensorsData.print(currentData.timeStamp);
    sensorsData.print(" | ");
    sensorsData.print(currentData.tempData);
    sensorsData.print(" | ");
    sensorsData.print(currentData.phData);
    sensorsData.print(" | ");
    sensorsData.print(currentData.doData);
    sensorsData.print(" | ");
    sensorsData.print(isDataSent);
    sensorsData.print("\n");

    sensorsData.close();
  }
  else {
    fStatus = 0;
  }
  return fStatus;
}
