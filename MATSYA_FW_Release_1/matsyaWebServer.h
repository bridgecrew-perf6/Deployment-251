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
// File Name: matsyaWebServer.h 
// File Description:  Matsya Web Server class                    
// Author: Deepakkumar
// Date: February 19, 2022
//////////////////////////////////////////////////

#ifndef matsyaWebServer_h
#define matsyaWebServer_h
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <SPI.h>
#include <SD.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#define PORT_OUT Serial

#ifdef __cplusplus

#ifdef ARDUINO
#include <Arduino.h>       
#endif

class matsyaWebServer
{
    public:
	
	    matsyaWebServer();
		~matsyaWebServer();
        void returnOK();
        void returnFail(String msg);
        bool loadFromSdCard(String path);
        void handleFileUpload(); 	
        void deleteRecursive(String path);
        void handleDelete();
        void handleCreate();
        void printDirectory();	
        void handleNotFound();
        		
    private:
        const byte        dnsPort = 53;          
        IPAddress         apIP(192, 168, 1, 1);    
        static bool hasSD = false;
        File uploadFile;		
        DNSServer dnsServer;             
        ESP8266WebServer server(80);
};