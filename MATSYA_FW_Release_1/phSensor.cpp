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
//File Name: doSensor.cpp 
//File Description: Interfacing pH Sensor
// Author: Priyankar
// Date: June 11, 2021
//////////////////////////////////////////////////

#include "phSensor.h"

// Constructor
phSensor::phSensor(analogMux::aChannel chpin, uint8_t EN, uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3, uint8_t SIG):
pHSensor(chpin, EN, S0, S1, S2, S3, SIG)
{
}

// Destructor
phSensor::~phSensor()
{
}

uint16_t phSensor::readData()
{
  uint32_t sensorData = 0;
  for (int i = 0; i < avgFilterWindow; ++i) {
    sensorData += pHSensor.analogReadMUX();
  }
  sensorData /= avgFilterWindow;
  return(static_cast<uint16_t>(sensorData));
}

float phSensor::rawtomV(uint16_t data) {
  return(static_cast<float>(data)*DEVICE_OPERATING_VOLTAGE_IN_MV/1024.0);   
}

float phSensor::rawtopH(uint16_t data) {
  float voltage_mV = rawtomV(data);
  if (voltage_mV > mid_cal) { //high voltage = low ph
    return 7.0 - 3.0 / (low_cal - mid_cal) * (voltage_mV - mid_cal);
  } else {
    return 7.0 - 3.0 / (mid_cal - high_cal) * (voltage_mV - mid_cal);
  }

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
