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
// File Name: DO_Calibration.ino 
// File Description: Calibration of DO Sensor
// Author: Priyankar
// Date: Jan 13, 2022
//////////////////////////////////////////////////

// Max Output Voltage = 40 mV
// Gain = 11
#define DEFAULT_SAT_VOLTAGE_CONST (40.0*11.0)

int user_bytes_received = -1;                
const uint8_t bufferlen = 32;
char user_data[bufferlen];
float full_sat_voltage = DEFAULT_SAT_VOLTAGE_CONST;
static const int volt_avg_len = 1000;

void parse_cmd(int incomingCalMessage) {                   
  if (char(incomingCalMessage) == '1') {            
    cal();
    Serial.println("DO CALIBRATED");
  }
  else if (char(incomingCalMessage) == '2') {            
    calClear();
    Serial.println("CALIBRATION CLEARED");
  }
  else {
    Serial.println("INVALID COMMAND");
  }
}
float readVoltage(){
  float voltage_mV = 0;
  for (int i = 0; i < volt_avg_len; ++i) {
    voltage_mV += analogRead(A0) / 1024.0 * 5000.0;
  }
  voltage_mV /= volt_avg_len;
  return voltage_mV;
}

void cal(){
  full_sat_voltage = readVoltage();
}

void calClear(){
  full_sat_voltage = DEFAULT_SAT_VOLTAGE_CONST;
}

float read_do_percentage() {
  return(readVoltage()* 100.0 / full_sat_voltage);
}

float getCalibrationValues(){
  return (full_sat_voltage);
}

void setup() {
  Serial.begin(115200);
}


void loop() {
  Serial.println(F("Use command \"1. CAL\" to calibrate the circuit to 100% saturation in air\n\"2. CAL_CLEAR\" clears the calibration"));
  if (Serial.available() > 0) {
    user_bytes_received = (int)Serial.read();   
  }

  if (user_bytes_received) {
    parse_cmd(user_bytes_received);
    user_bytes_received = -1;
  }
  
  Serial.println(read_do_percentage());
  Serial.println(getCalibrationValues());
  
  delay(1000);
}
