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
//File Name: phSensor.h 
//File Description: Interfacing class for pH 
//                  Sensor
// Author: Priyankar
// Date: June 11, 2021
//////////////////////////////////////////////////
#ifndef phSensor_h
#define phSensor_h
#include "sensorBase.h"
#include "analogMux.h"
#include "globalConst.h"

#ifdef __cplusplus

#ifdef ARDUINO
#include <Arduino.h>       // for delayMicroseconds, digitalPinToBitMask, etc
#endif


class phSensor: public sensorBase
{
    public:
        phSensor(analogMux::aChannel, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
        virtual ~phSensor();
        virtual uint16_t readData();
        float rawtomV(uint16_t data); 
        float rawtopH(uint16_t);
/*        
        float cal();
        float cal_clear();
*/
    private:
        analogMux pHSensor;
        float mid_cal = 2336.54;
        float high_cal = 539.76;
        float low_cal = 3114.02;
};

#endif
#endif
