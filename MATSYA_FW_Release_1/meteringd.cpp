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
//File Name: meteringd.cpp 
//File Description: Metering class T, ph, DO
// Author: Priyankar
// Date: June 10, 2021
//////////////////////////////////////////////////

#include "meteringd.h"

//Constructor
meteringd::meteringd()
{
  currentData.timeStamp = 0;
  currentData.tempData = 0;
  currentData.phData = 0;
  currentData.doData = 0;
}

//Destructor
meteringd::~meteringd()
{
}

void meteringd::getCurrentData(meteringd::meteringData& cData)
{
  cData.timeStamp = currentData.timeStamp;
  cData.tempData = currentData.tempData;
  cData.phData = currentData.phData;
  cData.doData = currentData.doData;  
}

void meteringd::readCurrentData(uint32_t cTime)
{
  tempSensor tSensor(ONE_WIRE_BUS);
  doSensor dOSensor(doPin, EN, S0, S1, S2, S3, ASIG);
  dOSensor.begin();
  phSensor pHSensor(phPin, EN, S0, S1, S2, S3, ASIG);

  currentData.timeStamp = cTime;
  currentData.tempData = tSensor.readData();
  currentData.doData = dOSensor.readData(); 
  currentData.phData = pHSensor.readData();

  Serial.print(" Raw Temperature: ");
  Serial.print(currentData.tempData);
  Serial.print(" Temperature in C: ");
  Serial.print(tSensor.rawtoC(currentData.tempData));
  Serial.print(" Temperature in F: ");
  Serial.print(tSensor.rawtoF(currentData.tempData));
  Serial.print("\n");
  Serial.print(" Raw DO: ");
  Serial.print(currentData.doData);
  Serial.print(" DO in % Sat: ");
  Serial.print(dOSensor.rawtoPercentSat(currentData.doData));
  Serial.print("\n");
  Serial.print(" Raw pH: ");
  Serial.print(currentData.phData );
  Serial.print(" pH: ");
  Serial.print(pHSensor.rawtopH(currentData.phData));
  Serial.print("\n");
}
