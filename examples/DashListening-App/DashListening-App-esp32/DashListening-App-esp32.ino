/**
 * @file DashListening-App-esp32.ino
 * @date 24.03.2020
 * @author Grandeur Technologies
 *
 * Copyright (c) 2019 Grandeur Technologies LLP. All rights reserved.
 * This file is part of the Arduino SDK for Grandeur.
 *
 * Grandeur.h is used for device's communication to Grandeur.
 * WiFi.h is used for handling device's WiFi.
 * 
 * Dash listening is for one-way listening.
 * This example illustrates the use case of an app listening for updates from the device.
 * It would be useful in building a DEVICE MONITOR which would show how your devices are
 * behaving in terms of their energy units consumed for example.
*/

#include <Grandeur.h>
#include <WiFi.h>

// Device's connection configurations
String apiKey = "YOUR-PROJECT-APIKEY";
String deviceID = "YOUR-DEVICE-ID";
String token = "YOUR-ACCESS-TOKEN";
const char* ssid = "YOUR-WIFI-SSID";
const char* passphrase = "YOUR-WIFI-PASSWORD";

// Declaring and initializing other variables
unsigned long current = millis();
Project myProject;
Device myDevice;
int statePin = 4;
int voltagePin = 2;

// Function prototypes
void WiFiEventCallback(WiFiEvent_t event);
void setupWiFi(void);
void connectionCallback(bool state);
void initializeState(Var getResult);
void summarySetCallback(Var setResult);
void parmsSetCallback(Var setResult);

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  // This initializes the SDK's configurations and returns a new object of Project class.
  myProject = grandeur.init(apiKey, token);
  // Getting object of Device class.
  myDevice = myProject.device(deviceID);
  // This schedules the connectionCallback() function to be called when connection with the cloud
  // is made/broken.
  myProject.onConnection(connectionCallback);
}

void loop() {
  // In this loop() function, after every five seconds, we send the updated values of our
  // device's voltage and state to Grandeur.
  if(myProject.isConnected()) {
    if(millis() - current >= 5000) {
      // This if-condition makes sure that the code inside this block runs only after
      // every five seconds.

      Serial.println("Setting Summary");
      Var summary;
      summary["voltage"] = analogRead(voltagePin);
      // This updates the summary of our device on Grandeur and schedules summarySetCallback()
      // function to be called when Grandeur responds with the SUMMARY UPDATED message.
      myDevice.setSummary(summary, summarySetCallback);

      Serial.println("Setting Parms");
      Var parms;
      parms["state"] = digitalRead(statePin);
      // This updates the parms of our device on Grandeur and schedules parmsSetCallback()
      // function to be called when Grandeur responds with the PARMS UPDATED message.
      myDevice.setParms(parms, parmsSetCallback);

      // This updates the millis counter for
      // the five seconds scheduler.
      current = millis();
    }
  }

  // This runs the SDK only when the WiFi is connected.
  myProject.loop(WiFi.status() == WL_CONNECTED);
}

void WiFiEventCallback(WiFiEvent_t event) {
  switch(event) {
    case SYSTEM_EVENT_STA_GOT_IP:
      // This runs when the device connects with WiFi.
      Serial.printf("\nDevice has successfully connected to WiFi. Its IP Address is: %s\n",
        WiFi.localIP().toString().c_str());
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      // This runs when the device disconnects with WiFi.
      Serial.println("Device is disconnected from WiFi.");
      break;
    default: break;
  }
}

void setupWiFi(void) {
  // Disconnecting WiFi if it"s already connected
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers
  WiFi.mode(WIFI_STA);
  // Setting WiFi event handler
  WiFi.onEvent(WiFiEventCallback);
  // Begin connecting to WiFi
  WiFi.begin(ssid, passphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid, passphrase);
}

void connectionCallback(bool state) {
  switch(state) {
    case CONNECTED:
      // On successful connection with the cloud, we initialize the device's *state*.
      // To do that, we get device parms from the cloud and set the *state pin* to the value of *state* in those parms.
      Serial.println("Device is connected to the cloud.");
      myDevice.getParms(initializeState);

      // Initializing the millis counter for the five
      // seconds timer.
      current = millis();
      break;
    case DISCONNECTED:
      Serial.println("Device is disconnected from the cloud.");
      break;
  }
}

void initializeState(Var getResult) {
  // This function sets the *state pin* to the *state value* that we received in parms
  // from the cloud.
  if(getResult["code"] == "DEVICE-PARMS-FETCHED") {
    int state = getResult["deviceParms"]["state"];
    digitalWrite(statePin, state);
    return;
  }
  // If the parms could not be fetched.
  Serial.println("Failed to Fetch Parms");
  return;
}

void summarySetCallback(Var setResult) {
  if(setResult["code"] == "DEVICE-SUMMARY-UPDATED") {
    Serial.printf("Voltage is updated to: %d\n", (int) setResult["update"]["voltage"]);
    
    /* You can set some pins or trigger events here which depend on successful
    ** device summary update.
    */
    return;
  }
  // If the summary could not be updated.
  Serial.println("Failed to Update Summary");
  return;
}

void parmsSetCallback(Var setResult) {
  if(setResult["code"] == "DEVICE-PARMS-UPDATED") {
    Serial.printf("State is updated to: %d\n", (bool) setResult["update"]["state"]);

    /* You can set some pins or trigger events here which depend on successful
    ** device parms update.
    */
    return;
  }
  // If the parms could not be updated.
  Serial.println("Failed to Update Parms");
  return;
}
