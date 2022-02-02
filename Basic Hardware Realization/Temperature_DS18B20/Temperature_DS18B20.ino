//////////////////////////////////////////////////
//                                              //
// Copyright 2020-2021                          //
// Notise: Property of Innoweave Smart Solutions//
// Any part of this code cannot be copied or    //
// redistributed without written prior consent  //
// of Innoweave                                 //
//                                              //
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// File Name: Temperature_DS18b20.ino 
// File Description: Basic Interface Testing of
//                   DS18B20 with Arduino Nano
// Author: Priyankar
// Date: March 05, 2021
//////////////////////////////////////////////////

#include <OneWire.h>
#include <DallasTemperature.h>

// DQ is connected to the Arduino D4
#define ONE_WIRE_BUS D4
DeviceAddress deviceAddress;
// Setup Onewire Temperature Sensor instance
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // Begin serial communication 
  Serial.begin(115200);
  // Begin Onewire Sensor 
  sensors.begin();
}

void loop(void){ 
  Serial.print(sensors.getAddress(deviceAddress, 0));
  Serial.print(sensors.getTemp(deviceAddress));
  sensors.requestTemperatures();
  Serial.print("Temperature C: ");
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.print(" Temperature F: ");
  Serial.println(sensors.getTempFByIndex(0));
  delay(1000);
}
