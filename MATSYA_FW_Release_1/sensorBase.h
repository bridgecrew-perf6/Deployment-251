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
//File Name: sensorBase.h 
//File Description: Defines Base class for Sensor
// Author: Priyankar
// Date: October 15, 2020
//////////////////////////////////////////////////
#ifndef sensorBase_h
#define sensorBase_h

#ifdef __cplusplus

#include <stdint.h>

#ifdef ARDUINO
#include <Arduino.h>       // for delayMicroseconds, digitalPinToBitMask, etc
#endif

class sensorBase
{
private:
    bool isHwTypeOutput = false;
    bool isHwConnected = 0; //0: Inactive 1: Active
    //uint8_t config;
protected:
    static const int avgFilterWindow = 10;
public:
    sensorBase(/* args */);
    ~sensorBase();

    void setHwType(bool);
    bool getHwType();
    void setHwConnectedStatus(bool);
    bool getHwConnectedStatus();
    
    //Pure Virtual Functions
    virtual uint16_t readData() = 0;
    //void setData();
};

#endif
#endif
