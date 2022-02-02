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
// File Name: SerialConnectiontoArduino_NodeMCUCode.ino 
// File Description: Basic Interface of Nano with NodeMCU
// Author: Priyankar
// Date: March 05, 2021
///////////////////////////////////////////////////////////

#include <SoftwareSerial.h>
SoftwareSerial s(D6,D5);
int data;
void setup() {
s.begin(9600);
Serial.begin(9600);
}
 
void loop() {
  s.write("s");
  if (s.available()>0)
  {
    data=s.read();
    Serial.println(data);
  }
 
 
}
