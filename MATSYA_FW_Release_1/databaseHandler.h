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
// File Name: databaseHandler.h 
// File Description: Database related operations
// Author: Priyankar
// Date: June 05, 2021
//////////////////////////////////////////////////
#ifndef databaseHandler_h
#define databaseHandler_h

#ifdef __cplusplus
#include <stdint.h>
#include <SD.h>
#include <SPI.h>

#include "meteringd.h"

// To Do Use Singleton
class databaseHandler
{
private:
  uint8_t csPin;
public:
  databaseHandler(uint8_t);
  ~databaseHandler();
  bool updateSensorsData(meteringd::meteringData&, bool);
};

#endif
#endif
