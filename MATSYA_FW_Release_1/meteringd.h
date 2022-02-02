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
//File Name: meteringd.h 
//File Description: Metering class T, ph, DO
// Author: Priyankar
// Date: June 10, 2021
//////////////////////////////////////////////////
#ifndef meteringd_h
#define meteringd_h

#ifdef __cplusplus

#ifdef ARDUINO
#include <Arduino.h>       // for delayMicroseconds, digitalPinToBitMask, etc
#endif

#include "tempSensor.h"
#include "doSensor.h"
#include "phSensor.h"

// Data PIN of Tempertature Sensor 
#define ONE_WIRE_BUS D4

// Define Pins for 16 Channel Analog MUX 
#define EN D3
#define S0 D1
#define S1 D5
#define S2 D6
#define S3 D7
#define ASIG A0

class meteringd
{
    public:
        struct meteringData
        {
          uint32_t timeStamp;
          uint16_t tempData;
          uint16_t doData;
          uint16_t phData;
        };
        meteringd();
        virtual ~meteringd();
        void getCurrentData(meteringd::meteringData&);
        void readCurrentData(uint32_t);
    protected:
        static const analogMux::aChannel doPin = analogMux::aChannel::C0;
        static const analogMux::aChannel phPin = analogMux::aChannel::C1;
    private:
        meteringd::meteringData currentData;
};

#endif
#endif
