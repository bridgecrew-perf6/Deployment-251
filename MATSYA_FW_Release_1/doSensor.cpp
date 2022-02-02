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
//File Name: doSensor.cpp 
//File Description: Interfacing DO Sensor
// Author: Priyankar
// Date: June 08, 2021
//////////////////////////////////////////////////

#include "doSensor.h"

// Constructor
doSensor::doSensor(analogMux::aChannel chpin, uint8_t EN, uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3, uint8_t SIG):
DoSensor(chpin, EN, S0, S1, S2, S3, SIG)
{
}

// Destructor
doSensor::~doSensor()
{
}

bool doSensor::begin(){
  return true;
}

uint16_t doSensor::readData()
{
  uint32_t sensorData = 0;
  for (int i = 0; i < avgFilterWindow; ++i) {
    sensorData += DoSensor.analogReadMUX();
  }
  sensorData /= avgFilterWindow;
  return(static_cast<uint16_t>(sensorData));;
}

float doSensor::dataTomV(uint16_t data) {
  return(static_cast<float>(data)*DEVICE_OPERATING_VOLTAGE_IN_MV/1024.0); 
}

float doSensor::rawtoPercentSat(uint16_t data) {
  return dataTomV(data) * 100.0 / doSatVolCal;
}

// TODO Calibration Code
/*float doSensor::cal() {
    this->Do.full_sat_voltage = read_voltage();
    EEPROM.put(this->EEPROM_offset,Do);
    #if defined(ESP8266) || defined(ESP32)
        EEPROM.commit(); 
    #endif
}

float doSensor::cal_clear() {
    this->Do.full_sat_voltage = DEFAULT_SAT_VOLTAGE;
    EEPROM.put(this->EEPROM_offset,Do);
    #if defined(ESP8266) || defined(ESP32)
        EEPROM.commit(); 
    #endif
}*/
