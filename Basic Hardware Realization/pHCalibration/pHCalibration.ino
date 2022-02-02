//////////////////////////////////////////////////
//                                              //
// Copyright 2020-2021, 2021-2022               //
// Notice: Property of Innoweave Smart Solutions//
// Any part of this code cannot be copied or    //
// redistributed without written prior consent  //
// of Innoweave                                 //
//                                              //
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// File Name: pH_Calibration.ino 
// File Description: Calibration of pH Sensor
// Author: Priyankar
// Date: Jan 13, 2022
//////////////////////////////////////////////////

#include "Gravity_pH.h"             
Gravity_pH pH = Gravity_pH(A0);   

int user_bytes_received = -1;                
const uint8_t bufferlen = 32;                   
char user_data[bufferlen];                     

void parse_cmd(int incomingCalMessage) {                   
  Serial.print("Received String: ");
  Serial.println(incomingCalMessage);
//  strupr(string);
  Serial.print("Comparision: ");
  Serial.println(char(incomingCalMessage) == '1');
  
  if (char(incomingCalMessage) == '1') {            
    pH.cal_mid();                                
    Serial.println("MID CALIBRATED");
  }
  if (char(incomingCalMessage) == '2') {            
    pH.cal_low();                                
    Serial.println("LOW CALIBRATED");
  }
  if (char(incomingCalMessage) == '3') {            
    pH.cal_high();                               
    Serial.println("HIGH CALIBRATED");
  }
  if (char(incomingCalMessage) == '4') {            
    pH.cal_clear();                              
    Serial.println("CALIBRATION CLEARED");
  }
  else
    Serial.println("Invalid Command");
}

void setup() {
  Serial.begin(115200);                            
  delay(200);
  Serial.println(F("Use commands \"1: CAL,7\", \"2: CAL,4\", and \"3: CAL,10\" to calibrate the circuit to those respective values"));
  Serial.println(F("Use command \"4: CAL,CLEAR\" to clear the calibration"));
  if (pH.begin()) {                                     
    Serial.println("Loaded EEPROM");
  }
}

void loop() {
  if (Serial.available() > 0) {                                                      
    user_bytes_received = (int)Serial.read();   
  }

  if (user_bytes_received != -1) {                                                      
    parse_cmd(user_bytes_received);                                                          
    user_bytes_received = -1;                                                        
  }
  
  Serial.println(pH.read_ph()); 
  Serial.print("Low Calibration"); 
  Serial.println(pH.getLowCal()); 
  Serial.print("Mid Calibration"); 
  Serial.println(pH.getMidCal()); 
  Serial.print("High Calibration"); 
  Serial.println(pH.getHighCal()); 
                                                       
  delay(1000);
}
