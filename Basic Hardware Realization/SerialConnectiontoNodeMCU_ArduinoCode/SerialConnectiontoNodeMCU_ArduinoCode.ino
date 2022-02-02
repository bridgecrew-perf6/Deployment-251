//////////////////////////////////////////////////
//                                              //
// Copyright 2020-2021                          //
// Notise: Property of Innoweave Smart Solutions//
// Any part of this code cannot be copied or    //
// redistributed without written prior consent  //
// of Innoweave                                 //
//                                              //
//////////////////////////////////////////////////

///////////////////////////////////////////////////////////
// File Name: SerialConnectiontoNodeMCU_ArduinoCode.ino 
// File Description: Basic Interface of Nano with NodeMCU
// Author: Priyankar
// Date: March 05, 2021
///////////////////////////////////////////////////////////


//Arduino code
#include <SoftwareSerial.h>
SoftwareSerial s(9,10);
 
void setup() {
s.begin(9600);
}
 
void loop() {
int data=50;
if(s.available()>0)
{
 s.write(data);
}
}
