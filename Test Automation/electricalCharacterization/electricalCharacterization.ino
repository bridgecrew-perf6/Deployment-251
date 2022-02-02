//////////////////////////////////////////////////
//                                              //
// Copyright 2021-2022                          //
// Notice: Property of Innoweave Smart Solutions//
// Any part of this code cannot be copied or    //
// redistributed without prior consent of       //
// Innoweave                                    //
//                                              //
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// File Name: electricalCharacterization.ion
// File Description: Perform Electric
// Characterization on any circuit
// Author: Deepakkumar
// Date: January 18, 2022
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// Hardware Setup:                              //
// Connect DAC to Input of DUT and A1           //
// Connect A2 to output of DUT                  //
//////////////////////////////////////////////////

#define PIN_DAC A0
#define VIN_1 A1
#define VOUT A2
#define OPERATING_VOLTAGE 3300
#define MAX_COUNTER_VALUE 60  //For DO set MAX_COUNTER_VALUE 40
#define COUNT 10 // For printing value no. of time 
float mvOut = 0.0;
float mvIp = 0.0;
float ipToCircuit = 0.0;
float opFromCircuit = 0.0;

void setup() {
  pinMode(PIN_DAC, OUTPUT);
  pinMode(VIN_1, INPUT);
  pinMode(VOUT, INPUT);
  Serial.begin(115200);
  for(int i = 0; i <= MAX_COUNTER_VALUE; i++){
    for(int j = 0; j < COUNT; j++){
      analogWrite(A0, i);
      delay(1000);
      ipToCircuit = analogRead(A1);
      opFromCircuit = analogRead(A2);
      mvIp = (ipToCircuit * (OPERATING_VOLTAGE/1023.0));
      mvOut = (opFromCircuit * (OPERATING_VOLTAGE/1023.0));
      Serial.print("counter : ");
      Serial.print(i);
      Serial.print("; ip : ");
      Serial.print(mvIp);
      Serial.print("; out : ");
      Serial.println(mvOut);
    }
  }
}
void loop() { 
}
