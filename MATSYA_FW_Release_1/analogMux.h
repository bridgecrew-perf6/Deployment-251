//////////////////////////////////////////////////
//                                              //
// Copyright 2020-2021                          //
// Notice: Property of Innoweave Smart Solutions//
// Any part of this code cannot be copied or    //
// redistributed without written prior consent  //
// of Innoweave                                 //
//                                              //
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// File Name: analogMux.h 
// File Description: Interface 16 Channel Analog  
//                   MUX
// Connection: Refer HW Design Documentation 
// Author: Priyankar
// Date: June 09, 2021
//////////////////////////////////////////////////


#ifndef analogMux_h
#define analogMux_h

#ifdef __cplusplus
#include <stdint.h>

#ifdef ARDUINO
#include <Arduino.h>       // for pinMode, analogRead, etc
#endif

class analogMux
{
public:
  enum aChannel
  {
    C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14, C15
  };
  
  analogMux(analogMux::aChannel, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
  ~analogMux();
  uint16_t analogReadMUX();
  
private:
  analogMux::aChannel chPin; // Channel Pin
  uint8_t en;    // EN Pin
  uint8_t s0;    // S0 Pin
  uint8_t s1;    // S1 Pin
  uint8_t s2;    // S2 Pin
  uint8_t s3;    // S3 Pin
  uint8_t sig;   // SIG Pin
  void en_pin_low();
  void en_pin_high();
};

#endif
#endif
