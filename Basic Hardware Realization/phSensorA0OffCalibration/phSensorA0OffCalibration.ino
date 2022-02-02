//////////////////////////////////////////////////
//                                              //
// Copyright 2020-2021                          //
// Notise: Property of Innoweave Smart Solutions//
// Any part of this code cannot be copied or    //
// redistributed without written prior consent  //
// of Innoweave                                 //
//                                              //
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// File Name: phSensorA0OffCalibration.ino 
// File Description: Basic Interface Testing of
//                   ph Sensor with NodeMCU
// Author: Priyankar
// Date: March 05, 2021
//////////////////////////////////////////////////

void setup() {

  Serial.begin(9600);

}

void loop() {

  int sensorValue = analogRead(A0);

  float voltage = sensorValue * (3.3 / 1023.0);

  Serial.println(voltage);

}
