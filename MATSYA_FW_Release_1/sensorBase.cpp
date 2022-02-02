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
// File Name: sensorBase.cpp 
// File Description: Defines Base class for Sensor
// Author: Priyankar
// Date: October 19, 2020
//////////////////////////////////////////////////

#include "sensorBase.h"
 
sensorBase::sensorBase(/* args */)
{
}

sensorBase::~sensorBase()
{
}

void sensorBase::setHwType(bool hwType)
{
  isHwTypeOutput = hwType;
}

bool sensorBase::getHwType()
{
  return(isHwTypeOutput);
}

void sensorBase::setHwConnectedStatus(bool cStatus)
{
  isHwConnected = cStatus;
}

bool sensorBase::getHwConnectedStatus()
{
  return(isHwConnected);
}
