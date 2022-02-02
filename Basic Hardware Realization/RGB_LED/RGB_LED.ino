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
// File Name: RGB_LED.ino 
// File Description: Basic Interface of RGB LED
// Author: Priyankar
// Date: March 05, 2021
//////////////////////////////////////////////////

const int redPin = 3;
const int greenPin = 4;
const int bluePin = 5;

void setup() 
{
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop()
{
  delay(1000);
  primaryColors(1,0,0); // Red
  delay(2000);
  primaryColors(0,1,0); // Green
  delay(2000);
  primaryColors(0,0,1); // Blue
  delay(2000);
  primaryColors(1,1,0); // Yellow
  delay(2000);
  primaryColors(1,0,1); // Magenta
  delay(2000);
  primaryColors(0,1,1); // Cyan
  delay(2000);
  primaryColors(1,1,1); // White
  delay(2000);
  
}
void primaryColors(int redValue, int greenValue, int blueValue)
{
  digitalWrite(redPin, !redValue);
  digitalWrite(greenPin, !greenValue);
  digitalWrite(bluePin, !blueValue);
}
