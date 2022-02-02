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
//File Name: tempSensor.h 
//File Description: Interfacing class for DS18B20
// Author: Priyankar
// Date: June 01, 2021
//////////////////////////////////////////////////
#ifndef tempSensor_h
#define tempSensor_h
#include "sensorBase.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#ifdef __cplusplus

#ifdef ARDUINO
#include <Arduino.h>       // for delayMicroseconds, digitalPinToBitMask, etc
#endif

class tempSensor: public sensorBase
{
    public:
        tempSensor(uint8_t);
        float rawtoC(uint16_t);
        float rawtoF(uint16_t);
        virtual ~tempSensor();
        virtual uint16_t readData();
//        void medianFilter();
    private:
        OneWire oneWire;
        DallasTemperature sensors;
        uint8_t oneWirePin;
        uint16_t sensorData;
        DeviceAddress deviceAddress;
};

#endif
#endif
