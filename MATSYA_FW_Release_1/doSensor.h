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
//File Name: doSensor.h 
//File Description: Interfacing class for DO 
//                  Sensor
// Author: Priyankar
// Date: June 08, 2021
//////////////////////////////////////////////////
#ifndef doSensor_h
#define doSensor_h
#include "sensorBase.h"
#include "analogMux.h"
#include "EEPROM.h"
#include "globalConst.h"

#ifdef __cplusplus

#ifdef ARDUINO
#include <Arduino.h>       // for delayMicroseconds, digitalPinToBitMask, etc
#endif

class doSensor: public sensorBase
{
    public:
        doSensor(analogMux::aChannel, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
        bool begin();
        float dataTomV(uint16_t);
        virtual ~doSensor();
        virtual uint16_t readData();                
        float rawtoPercentSat(uint16_t);
/*        
        float cal();
        float cal_clear();
*/

  private:
        float doSatVolCal = 1135.04;
        analogMux DoSensor;
};

#endif
#endif
