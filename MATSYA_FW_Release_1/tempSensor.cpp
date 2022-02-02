//////////////////////////////////////////////////
//                                              //
// Copyright 2020-2021                          //
// Notice: Property of Innoweave Smart Solutions//
// Any part of this code cannot be copied or    //
// redistributed without prior consent of       //
// Innoweave                                    //
//                                              //
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//File Name: tempSensor.cpp 
//File Description: Interfacing DS18B20
// Author: Priyankar
// Date: June 01, 2021
//////////////////////////////////////////////////

#include "tempSensor.h"

//Constructor
tempSensor::tempSensor(uint8_t oneWireBus):
  oneWire(oneWireBus),  
  sensors(&oneWire)
{
  oneWirePin = oneWireBus;
  // Begin Onewire Sensor 
  sensors.begin();
}

//Destructor
tempSensor::~tempSensor()
{
}

// Read Data from the DS18B20
// ToDO Add Multiple Sensor Capacity
uint16_t tempSensor::readData()
{
  sensors.requestTemperatures();
  if(sensors.getAddress(deviceAddress, 0))
  { 
    uint32_t tempSensor = 0;
    for (int i = 0; i < avgFilterWindow; ++i) {
      tempSensor += sensors.getTemp(deviceAddress); 
    }
    tempSensor /= avgFilterWindow;
    sensorData = static_cast<uint16_t>(tempSensor);
  }
/*  else
  {
    return (static_cast<uint16_t>(0));
  }*/
  return sensorData;  
}

// rawtoC converts the raw value to Celsius
float tempSensor::rawtoC(uint16_t raw)
{
  return sensors.rawToCelsius(raw);
}

// rawtoF converts the raw value to Fahrenheit
float tempSensor::rawtoF(uint16_t raw)
{
  return sensors.rawToFahrenheit(raw);
}
