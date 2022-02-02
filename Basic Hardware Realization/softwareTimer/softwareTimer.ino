//////////////////////////////////////////////////
//                                              //
// Copyright 2020-2021                          //
// Notice: Property of Innoweave Smart Solutions//
// Any part of this code cannot be copied or    //
// redistributed without written prior consent  //
// of Innoweave                                 //
//                                              //
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// File Name: softwareTimer.ino 
// File Description: softwareTimer Demo   
// Author: Priyankar
// Date: June 11, 2021
//////////////////////////////////////////////////

#include <SimpleTimer.h>

// the timer object
SimpleTimer doOneS;
SimpleTimer doFiveS;

// A One Sec Function
void doOneSec() {
    Serial.print("Inside doOneSec \n");
}

// A Five Sec Function
void doFiveSec() {
    Serial.print("Inside doFiveSec \n");
}
void setup() {
    Serial.begin(115200);
    doOneS.setInterval(1000, doOneSec);
    doFiveS.setInterval(5000, doFiveSec);
}

void loop() {
    doOneS.run();
    doFiveS.run();
}
