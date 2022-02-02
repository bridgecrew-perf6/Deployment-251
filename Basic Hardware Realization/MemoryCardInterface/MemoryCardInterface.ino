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
// File Name: MemoryCardInterface.ino 
// File Description: Interface Memory Card using 
//                   SPI with NodeMCU
// Connection: CS - D8 and MOSI, MISO, SCK to 
//             respective pins
// Author: Priyankar
// Date: May 29, 2021
//////////////////////////////////////////////////

#include <OneWire.h>
#include <DallasTemperature.h>
#include <SD.h>
#include <SPI.h>


// Chip Select pin for SPI
#define CS_PIN  D8

// DQ is connected to the Arduino D4
#define ONE_WIRE_BUS D4

// Setup Onewire Temperature Sensor instance
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // Begin serial communication 
  Serial.begin(115200);
  // Begin Onewire Sensor 
  sensors.begin();
  
  Serial.print("Initializing SD Card...");   
  // Check the SD Card connection and Initialize it
  if (!SD.begin(CS_PIN)) {
    Serial.println("Initialization Failed. Check the Connection!");
    return;
  }
  
  Serial.println("SD Card Initialized");
}

void loop(void){ 
  sensors.requestTemperatures();
  Serial.print("Temperature C: ");
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.print(" Temperature F: ");
  Serial.println(sensors.getTempFByIndex(0));
  
  File sensorsData = SD.open("sensorsData.txt", FILE_WRITE);
  if (sensorsData) {
    // File Format Line By Line: Temp in C | Temp in F
    sensorsData.print(sensors.getTempCByIndex(0));
    sensorsData.print(" | ");
    sensorsData.println(sensors.getTempFByIndex(0));
    sensorsData.close();
    Serial.println("sensorsData.txt was successfully updated");
  }
  else {
    Serial.println("Failed to open sensorsData.txt");
  }

  delay(2000);
}
