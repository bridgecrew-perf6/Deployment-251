//////////////////////////////////////////////////
//                                              //
// Copyright 2020-2021                          //
// Notice: Property of Innoweave Smart Solutions//
// Any part of this code cannot be copied or    //
// redistributed without prior consent of       //
// Innoweave                                    //
//                                              //
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//File Name: analogMux.cpp 
//File Description: Interface 16 Channel Analog  
//                  MUX
// Author: Priyankar
// Date: June 09, 2021
//////////////////////////////////////////////////

#include "analogMux.h"

//Constructor
analogMux::analogMux(analogMux::aChannel chpin, uint8_t EN, uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3, uint8_t SIG){
  chPin = chpin;
  en = EN;
  s0 = S0;
  s1 = S1;
  s2 = S2;
  s3 = S3;
  sig = SIG;
  pinMode(en, OUTPUT);                      /* Defire EN pin as Output */
  pinMode(s0,OUTPUT);                       /* Define digital signal pin as output to the Multiplexer pin SO */        
  pinMode(s1,OUTPUT);                       /* Define digital signal pin as output to the Multiplexer pin S1 */  
  pinMode(s2,OUTPUT);                       /* Define digital signal pin as output to the Multiplexer pin S2 */ 
  pinMode(s3,OUTPUT);                       /* Define digital signal pin as output to the Multiplexer pin S3 */  
  pinMode(sig, INPUT);                      /* Define analog signal pin as input or receiver from the Multiplexer pin SIG */  
  delay (100);

}

//Destructor
analogMux::~analogMux()
{
}

// Read Data from the DS18B20
// ToDO Add Multiple Sensor Capacity
uint16_t analogMux::analogReadMUX()
{
  uint16_t analogValue = 0;  
  switch (chPin)
  {
    case C0:
      // Channel 0
      en_pin_low();
      digitalWrite(s0,LOW); digitalWrite(s1,LOW); digitalWrite(s2,LOW); digitalWrite(s3,LOW);
      analogValue = analogRead(sig);
      en_pin_high();
      break;
    case C1:
      // Channel 1
      en_pin_low();
      digitalWrite(s0,HIGH); digitalWrite(s1,LOW); digitalWrite(s2,LOW); digitalWrite(s3,LOW);
      analogValue = analogRead(sig);
      en_pin_high();
      break;
  
    case C2:
      // Channel 2 
      en_pin_low();
      digitalWrite(s0,LOW); digitalWrite(s1,HIGH); digitalWrite(s2,LOW); digitalWrite(s3,LOW);
      analogValue = analogRead(sig);
      en_pin_high();
      break;

    case C3:
      // Channel 3 
      en_pin_low();
      digitalWrite(s0,HIGH); digitalWrite(s1,HIGH); digitalWrite(s2,LOW); digitalWrite(s3,LOW);
      analogValue = analogRead(sig);
      en_pin_high();
      break;

    case C4:
      // Channel 4 
      en_pin_low();
      digitalWrite(s0,LOW); digitalWrite(s1,LOW); digitalWrite(s2,HIGH); digitalWrite(s3,LOW);
      analogValue = analogRead(sig);
      en_pin_high();
      break;
    
    case C5:
      // Channel 5 (C5 pin - binary output 1,0,1,0)
      en_pin_low();
      digitalWrite(s0,HIGH); digitalWrite(s1,LOW); digitalWrite(s2,HIGH); digitalWrite(s3,LOW);
      analogValue = analogRead(sig);
      en_pin_high();
      break;
      
    case C6:
      // Channel 6 (C6 pin - binary output 0,1,1,0)
      en_pin_low();
      digitalWrite(s0,LOW); digitalWrite(s1,HIGH); digitalWrite(s2,HIGH); digitalWrite(s3,LOW);
      analogValue = analogRead(sig);
      en_pin_high();
      break;
      
    case C7:
      // Channel 7 (C7 pin - binary output 1,1,1,0)
      en_pin_low();
      digitalWrite(s0,HIGH); digitalWrite(s1,HIGH); digitalWrite(s2,HIGH); digitalWrite(s3,LOW);
      analogValue = analogRead(sig);
      en_pin_high();
      break;

    case C8:
      // Channel 8 (C8 pin - binary output 0,0,0,1)
      en_pin_low();
      digitalWrite(s0,LOW); digitalWrite(s1,LOW); digitalWrite(s2,LOW); digitalWrite(s3,HIGH);
      analogValue = analogRead(sig);
      en_pin_high();
      break;

    case C9:
      // Channel 9 (C9 pin - binary output 1,0,0,1)
      en_pin_low();
      digitalWrite(s0,HIGH); digitalWrite(s1,LOW); digitalWrite(s2,LOW); digitalWrite(s3,HIGH);
      analogValue = analogRead(sig);
      en_pin_high();
      break;

    case C10:
      // Channel 10 (C10 pin - binary output 0,1,0,1)
      en_pin_low();
      digitalWrite(s0,LOW); digitalWrite(s1,HIGH); digitalWrite(s2,LOW); digitalWrite(s3,HIGH);
      analogValue = analogRead(sig);
      en_pin_high();
      break;

    case C11:
      // Channel 11 (C11 pin - binary output 1,1,0,1)
      en_pin_low();
      digitalWrite(s0,HIGH); digitalWrite(s1,HIGH); digitalWrite(s2,LOW); digitalWrite(s3,HIGH);
      analogValue = analogRead(sig);
      en_pin_high();
      break;

    case C12:
      // Channel 12 (C12 pin - binary output 0,0,1,1)
      en_pin_low();
      digitalWrite(s0,LOW); digitalWrite(s1,LOW); digitalWrite(s2,HIGH); digitalWrite(s3,HIGH);
      analogValue = analogRead(sig);
      en_pin_high();
      break;

    case C13:
      // Channel 13 (C13 pin - binary output 1,0,1,1)
      en_pin_low();
      digitalWrite(s0,HIGH); digitalWrite(s1,LOW); digitalWrite(s2,HIGH); digitalWrite(s3,HIGH);
      analogValue = analogRead(sig);
      en_pin_high();
      break;

    case C14:
      // Channel 14 (C14 pin - binary output 0,1,1,1)
      en_pin_low();
      digitalWrite(s0,LOW); digitalWrite(s1,HIGH); digitalWrite(s2,HIGH); digitalWrite(s3,HIGH);
      analogValue = analogRead(sig);
      en_pin_high();
      break;

    case C15:
      // Channel 15 (C15 pin - binary output 1,1,1,1)
      en_pin_low();
      digitalWrite(s0,HIGH); digitalWrite(s1,HIGH); digitalWrite(s2,HIGH); digitalWrite(s3,HIGH);
      analogValue = analogRead(sig);
      en_pin_high();
      break;

    default:
      Serial.print("Invalid Analog Channel ... \n");   
  }
  return analogValue;  
}



void analogMux::en_pin_low(){
  digitalWrite(en, LOW);
  delay(10);
}

void analogMux::en_pin_high(){
  digitalWrite(en, HIGH);
  delay(10);
}
