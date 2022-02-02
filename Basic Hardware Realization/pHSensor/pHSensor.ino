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
// File Name: phSensor.ino 
// File Description: Basic Interface Testing of
//                   ph Sensor with Arduino Nano
// Author: Priyankar
// Date: March 05, 2021
//////////////////////////////////////////////////

// We can also use this program for Analog Reading Offset pot
// For that just short the pins and adjust pot till ph becomes 7
float calibration = 21.34-0.06; //change this value to calibrate

const int analogInPin = A0;

int sensorValue = 0;

unsigned long int avgValue;

float b;

int buf[10],temp;

void setup() {

  Serial.begin(9600);

}

void loop() {

for(int i=0;i<10;i++)

{

  buf[i]=analogRead(analogInPin);

  delay(30);

  }

  for(int i=0;i<9;i++)

  {

  for(int j=i+1;j<10;j++)

  {

  if(buf[i]>buf[j])

  {

  temp=buf[i];

  buf[i]=buf[j];

  buf[j]=temp;

  }

  }

  }

  avgValue=0;

  for(int i=2;i<8;i++)

  avgValue+=buf[i];

  float pHVol=(float)avgValue*5.0/1024/6;

  float phValue = -5.70 * pHVol + calibration;

  Serial.print("sensor = ");

  Serial.println(phValue);

  delay(500);

}
