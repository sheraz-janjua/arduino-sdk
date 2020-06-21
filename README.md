# Grandeur Cloud [![Version](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://cloud.grandeur.tech)

Building a smart (IoT) product is an art because it is about unifying the physical world with the digital one. When you put a piece of hardware on the web, magic happens. But one device on the web is one thing. Think about tens of them, interconnected, forging an automated ecosystem of pure reverie. Now imagine tens of thousands of these ecosystems spread throughout the globe. Seems profound, no? But developing an IoT product and then managing it is just as profoundly difficult. It involves development across a huge technology stack (your IoT hardware itself, your apps to monitor/control your hardware and a server backend to manage them both) to make such products work in production. And then in production comes the hardest challenge; you are going to have to scale it up as your user base grows.

We understand this because we have been there.

Introducing Grandeur Cloud: A backend as a service (Baas) platform for IoT. We have designed this platform so you do not have to worry about the backend of your next big thing, and can focus on what matters the most: your hardware and your apps. It is designed specifically to accelerate your IoT product development and push your products to market in weeks rather than in months or years. So you can then actually build *grandeur* ecosystems like the one above.

## Why Grandeur Cloud

Grandeur Cloud is designed keeping in mind all the challenges a hardware engineer can face in developing and commercializing a smart (IoT) product. And we made available out-of-the-box APIs to help you integrate your devices and apps.

For example, you can use the **Auth API** to create *register* and *login* flows and make sure each user has access to its own data and no one other than the device admin itself should be able to interact with its device. You can store a humongous amount of data in cloud database to analyze and extract intelligent information from it and display useful graphs. Use our **datastore API** for that. You can host your product's website and your web app on Grandeur Cloud as well. It's **as simple as running literally a single command**. Also, your hardware device can listen for events and updates from your app, your app can listen for events and updates from your hardware device, and they can communicate with each other in realtime (with a latency of ~200ms). **Devices API** and **Device SDK** come into play here. But in no way would you have to waste your time in mixing and matching the APIs, checking which one works for your use case, and go through a huge learning curve -- like you would do while working with AWS or Google Cloud Platform. All the Grandeur APIs are completely integrated and speed and security is built in. The SDKs are designed around the whole ideology of **seamless integration.** 

Grandeur Cloud is not a regular IoT cloud. It's a complete IoT product development and management platform, designed for production environments. Here's how:

* Grandeur Cloud is product-centered. It is much more than just a medium of communication between your app and your hardware device. Focusing on expediting IoT product development, it offers an ecosystem of the most necessary tools integrated to make the most head-cracking development problems seamless. What problems you may ask?
  * Huge development stack (Your IoT product which is generally hardware, your web app, your server API, and the communication between all of these).
  * Your database design and management.
  * Setting up and maintaining your servers handling your compute, storage, and networking.
  * Web development (backend of your server, frontend of your web apps).
  * Your IoT product development itself.
  * Scaling your system up to hundreds of thousands of devices as your business grows.

* No need to mix and match various services to come up with your own solution. Grandeur Cloud is a single spot solution for all of your needs, from **built-in authentication** of your users and devices to **an integrated database** to an **out-of-the-box file storage system** and a registry of data for all of your devices. And You can manage absolutely everything from a single dashboard.

* Simple pricing. Unlike Google and AWS, we do not have to deal with a different pricing model for each service and aggregate them together to compute the monthly bill making it almost impossible for the user to understand why he has to pay this much! Packaging all our services into one platform has let us develop a very simple and transparent pricing model. You can [start free][Grandeur Cloud Sign Up] for a certain quota and then pay as you go based on your resources consumption. Checkout [pricing][Grandeur Cloud Pricing] for more details.

* We have a growing [community on Hackster][Grandeur Cloud Hackster] which is equivalent to growing number of developers which are using Grandeur Cloud and improving the opensource SDKs resulting in increasing Grandeur Cloud support.

* It is terrifically simple to [get started][Get Started with Grandeur Cloud] with your IoT product development. Just create a project from the [cloud dashboard][Grandeur Cloud Dashboard], plug your project's API key into our SDKs and start developing.

Follow [our Hackster Hub][Grandeur Cloud Hackster] for quick starts and advanced development projects.

[Here][Get Started With Grandeur Cloud] is how you can create a new project on Grandeur Cloud and start using the Javascript SDK to build your IoT apps.

From here onwards, we'll look at how you can use the Arduino SDK for all arduino-compatible modules to put your devices live and connected on Grandeur Cloud. Let's dive in!

# Arduino SDK

**Arduino SDK** is the official SDK for arduino-compatible hardware modules and it utilizes the *Apollo* API to connect your device to **[Grandeur Cloud][Grandeur Cloud]**.

Follow the [get started][Get Started with Arduino SDK] guidelines to quickly get into the context of integrating your devices to Grandeur Cloud or jump straight to an [Arduino example][Example] to make your hands dirty.

For a developer reference for the Arduino SDK, you can have a look at the [documentation][Documentation].

To get a deeper understanding of the core concepts Grandeur Cloud is built upon, dive into the [Grandeur Ecosystem][Ecosystem] section.

* [Get Started](#get-started)
  * [Installation](#installation)
  * [Inclusion](#inclusion)
  * [Initialization](#initialization)
  * [Handling the WiFi](#handling-the-wifi)
  * [Setting Up the Valve](#setting-up-the-valve)
  * [Events Listening](#events-listening)
  * [Fetching Device Variables and Updating Them](#fetching-device-variables-and-updating-them)
  * [Handling Updates From the Cloud](#handling-updates-from-the-cloud)
* [Example](#example)
* [The Dexterity of Arduino SDK](#the-dexterity-of-arduino-sdk)
* [Grandeur Ecosystem](#grandeur-ecosystem)
  * [A Brief Case Study](#a-brief-case-study)
  * [Concepts](#concepts)
    * [Project](#project)
    * [SDK](#SDK)
    * [User and Administrator](#user-and-administrator)
    * [Device](#device)
    * [Device Registry](#device-registry)
    * [Models](#models)
    * [Authentication and Access](#authentication-and-access)
    * [Networking](#networking)
    * [Allowed Origins](#allowed-origins)
* [Documentation](#documentation)
    * [init](#apollo-init)
  * [Project](#project)
    * [isConnected](#isconnected)
    * [onConnection](#onconnection)
    * [loop](#loop)
    * [device](#device)
    * [datastore](#datastore)
  * [Device](#device)
    * [getSummary](#getsummary)
    * [getParms](#getparms)
    * [setSummary](#setsummary)
    * [setParms](#setparms)
    * [onSummaryUpdated](#onsummaryupdated)
    * [onParmsUpdated](#oparmsupdated)
  * [Datastore](#datastore)
    * [insert](#insert)
* [Enhancements Under Consideration](#enhancements-under-consideration)

## Get Started

### Installation

1. You can search for **Grandeur Cloud** in Arduino's library manager. In Arduino IDE, open `Sketch > Include Library > Manage Libraries` and install Grandeur Cloud from there.

2. You can also clone **Arduino SDK** from [here][Arduino SDK] and [install it in your Arduino IDE][Installing an Arduino Library].

### Inclusion

When you include `<Apollo.h>` in your sketch, a global object `apollo` is defined right away which you can use to initialize the SDK's configurations.

```cpp
#include <Apollo.h>

// **RESULT**
// Includes the SDK in your sketch and defines the global object apollo.
```

### Initialization

Initialization is as simple as calling `apollo.init()` with your credentials (Device ID, Project's API Key and Device's Access Token). The SDK uses your API key to select your project, and device ID and access token to limit its scope to only your device's data. It then returns a `Project` object which exposes other subclasses like `Device` and `Datastore`, and you can go programming your device from there.

```cpp
#include <Apollo.h>

Project myProject;

void setup() {
  // You can initialize device configurations like this.
  myProject = apollo.init(YourApiKey, YourDeviceID, YourDeviceToken);
}

void loop() {}

// **RESULT**
// Initializes the SDK's configurations and returns Project reference.
```

As soon as you call `apollo.init()`, the SDK uses the configurations to start trying to connect with the your project on the Cloud. But it cannot reach Grandeur Cloud if the device is not already connected to a WiFi.

### Handling the WiFi

You can use a WiFi library corresponding to your microcontroller to handle your device's WiFi. Here are some popular ones:

* **ESP8266**: https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi
* **ESP32**:  https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi
* **Arduino WiFi Shield**: https://www.arduino.cc/en/Reference/WiFi

Here we illustrate how to handle your ESP8266's WiFi.

```cpp
#include <Apollo.h>
#include <ESP8266WiFi.h>

Project myProject;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  // You can initialize device configurations like this.
  myProject = apollo.init(YourDeviceID, YourApiKey, YourDeviceToken);
}

void loop() {
  // This runs the SDK when the device WiFi is connected.
  myProject.loop(WiFi.status() == WL_CONNECTED);
}

```

### Setting Up the Valve

You can see this line in the previous subsection: `myProject.loop(WiFi.status() == WL_CONNECTED)`, but what does that mean?

`loop` function is what runs the SDK: it connects with the cloud; when disconnected, it automatically reconnects; pulls new messages from the cloud; pushes messages to the cloud; and so on. But doing any sort of communication on the internet is useless until the WiFi isn't connected. That's exactly what the statement does: it acts like a **valve** for the SDK. The conditional expression passed to the `loop` function decides when the SDK would run and when it would not. In this case, it would only run when the WiFi is connected, causing `WiFi.status() == WL_CONNECTED` expression to evaluate to `true`. If while running, the WiFi gets disconnected, `WiFi.status() == WL_CONNECTED` would evaluate to `false` and the SDK would stop running.

### Events Listening

You can also listen on SDK's connection-related events. For example, to run some code when the device makes a successful connection to the cloud or when the device's connection to the cloud breaks, you can wrap that code in a `Callback` function and pass it to `onConnection()` function. The `Callback` function is a special type of function that accepts a `JSONObject` as a parameter and returns `void`. Read more about `Callback` and `JSONObject` [here][jsonobject].

Here's how you can handle the connection event:

```cpp
#include <Apollo.h>
#include <ESP8266WiFi.h>

ApolloDevice apolloDevice;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected.
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers.
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi.
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void connectionCallback(JSONObject result) {
  // This method handles the events related to device's connection with the Cloud.
  switch((int) updateObject["event"]) {
    case CONNECTED:
      // If the connection event occurred.
      Serial.println("Device Connected to the Cloud!\n");
      break;
    case DISCONNECTED:
      // If the disconnection event occurred.
      Serial.println("Device Disconnected from the Cloud!\n");
      break;
  }
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  // You can initialize device configurations like this.
  apolloDevice = apollo.init(YourDeviceID, YourApiKey, YourDeviceToken);
  // Setting up listener for device's connection event
  apolloDevice.onConnection(connectionCallback);
}

void loop() {
  // This runs the SDK when the device WiFi is connected.
  apolloDevice.loop(WiFi.status() == WL_CONNECTED);
}

// **RESULT**
// Prints "Device Connected to the Cloud!\n" when device gets connected to the cloud.
// And prints "Device Disconnected from the Cloud!\n" when device's connection from
// the cloud breaks.
```

### Fetching Device Variables and Updating Them

On Gradeur Cloud, we generally store the device data in two containers: **summary** to contain uncontrollable device variables and **parms** to contain controllable device variables. You can get and set both types using the following functions:

* `apolloDevice.getSummary()`
* `apolloDevice.getParms()`
* `apolloDevice.setSummary()`
* `apolloDevice.setParms()`

They are all Async functions because they communicate with the Cloud through internet. Communication through internet takes some time and we cannot wait, for example, for device's summary variables to arrive from the Cloud -- meanwhile blocking the rest of the device program. So, what we do is, we schedule a function to be called when the summary variables and resume with rest of the device program, forgetting that we ever called `getSummary()`. When the summary variables arrive, the SDK calls our scheduled function, giving us access to those variables inside that function.

For now, there's only one type of function that the SDK's Async methods accept: `Callback` which accepts a `JSONObject` as argument and returns nothing aka. `void`.

Read more about **Async functions**, `Callback`, and `JSONObject` [here][the dexterity of arduino sdk].

Here's how we would get and set device's summary and parms:

```cpp
#include <Apollo.h>
#include <ESP8266WiFi.h>

ApolloDevice apolloDevice;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected.
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers.
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi.
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void getSummaryCallback(JSONObject result) {
  // This function prints the variables stored in summary and sets the device pins.
  Serial.printf("Voltage: %s\n", (int) result["deviceSummary"]["voltage"]);
  Serial.printf("Current: %s\n", (int) result["deviceSummary"]["current"]);
  analogWrite(A0, (int) result["deviceSummary"]["voltage"]);
  analogWrite(A1, (int) result["deviceSummary"]["current"]);
}

void getParmsCallback(JSONObject result) {
  // This function prints the variables stored in parms and sets device pins.
  Serial.printf("State: %s\n", (bool) result["deviceParms"]["state"]);
  digitalWrite(D0, (bool) result["deviceParms"]["state"]);
}

void setSummaryCallback(JSONObject result) {
  // This function prints the updated values of the variables stored in summary.
  Serial.printf("Updated Voltage: %s\n", (int) result["update"]["voltage"]);
  Serial.printf("Updated Current: %s\n", (int) result["update"]["current"]);
}

void setParmsCallback(JSONObject result) {
  // This function prints the updated values of the variables stored in parms.
  Serial.printf("Updated State: %s\n", (bool) result["update"]["state"]);
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  // You can initialize device configurations like this.
  apolloDevice = apollo.init(YourDeviceID, YourApiKey, YourDeviceToken);
}

void loop() {
  int state = apolloDevice.getState();

  if(state == CONNECTED) {
    // Getting device's summary
    apolloDevice.getSummary(getSummaryCallback);
    // Getting device's parms
    apolloDevice.getParms(getParmsCallback);
    // Updating device's summary
    JSONObject summary;
    summary["voltage"] = 3.3;
    summary["current"] = 2.1;
    apolloDevice.setSummary(summary, setSummaryCallback);
    // Updating device's parms
    JSONObject parms;
    parms["state"] = true;
    apolloDevice.setParms(parms, setParmsCallback);
  }

  // This runs the SDK when the device WiFi is connected.
  apolloDevice.loop(WiFi.status() == WL_CONNECTED);
}

// **RESULT**
// When the loop() starts, summary and parms are fetched. When they arrive from the cloud, their
// corresponding callbacks are called which print the variables stored in summary and parms objects
// and set the corresponding pins.
// Then the summary and parms are updated with the new values. When their updates complete, their
// callbacks are called with the updated values of their variables and these updated values are
// printed on the screen.
```

### Handling Updates From the Cloud

Device variables are distributed on the cloud in form of **summary** and **parms**. Passing a `Callback` to `onSummaryUpdated()` and `onParmsUpdated()` you can set **update handlers** for updates to those variables. Let's do that now:

```cpp
#include <Apollo.h>
#include <ESP8266WiFi.h>

ApolloDevice apolloDevice;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected.
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers.
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi.
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void summaryUpdatedCallback(JSONObject result) {
  // This function prints the updated values of the variables stored in summary.
    Serial.printf("Updated Voltage: %s\n", (int) updatedSummary["voltage"]);
    Serial.printf("Updated Current: %s\n", (int) updatedSummary["current"]);
}

void parmsUpdatedCallback(JSONObject result) {
  // This function prints the updated values of the variables stored in parms.
  Serial.printf("Updated State: %s\n", (int) updatedParms["state"]);
}

void setup() {
  Serial.begin(9600);
  setupWiFi();
  apolloDevice = apollo.init(YourDeviceID, YourApiKey, YourDeviceToken);

  apolloDevice.onSummaryUpdated(summaryUpdatedCallback);
  apolloDevice.onParmsUpdated(parmsUpdatedCallback);
}

void loop() {
  // This runs the SDK when the device WiFi is connected.
  apolloDevice.loop(WiFi.status() == WL_CONNECTED);
}

// **RESULT**
// Whenever an update in the device's summary or parms occur, the updated values of the
// variables are printed.
```

## Example

Here we go through a general example to explain the **Arduino SDK** in action. For a little more broken-down approach, do have a look at [these examples][Examples] as well.

To begin working with the **Arduino SDK**, the very first step is to [create a new project][Grandeur Cloud Dashboard] and [register a new device][Grandeur Cloud Devices] through the [Cloud Dashboard][Grandeur Cloud Dashboard]. Then create a new Arduino sketch in your workspace folder.

### Create a New Sketch

Create a new folder for your `arduino workspace`, create a `.ino` file in it, and open it with [Arduino IDE][Arduino IDE]. This is the sketch file where you'll write your device's program.

### Include Apollo.h into Your Sketch

After [cloning the Arduino SDK][installation] and [installing it][Installing an Arduino Library], you can import it into your sketch like this:

```cpp
#include <Apollo.h>
```

### Initialize the SDK's Configurations

**Arduino SDK** takes care of your device's connection with Grandeur Cloud. To use it into your sketch, you need to initialize its configurations first. You can do that using the global object `apollo`. Initializing the SDK returns an object of `ApolloDevice` class which exposes all the SDK's functions.

```cpp
#include <Apollo.h>

ApolloDevice apolloDevice;

void setup() {
  apolloDevice = apollo.init(YourDeviceID, YourAPIKey, YourToken);
}
```

You can find the API Key on the [settings page][Grandeur Cloud Settings] of your project's dashboard. For the Access Token, you need to pair your device with a user account in your project first. A device can only connect to Grandeur Cloud if it's paired with a user. And only the paired user can access the device's data through its web app. For convenient testing, we have made device pairing function available on the [devices page][Grandeur Cloud Devices] too. You can find your device's ID and pair your device with a user account. If your project has no registered user yet, you can add one easily from the [accounts page][Grandeur Cloud Accounts].

### Handle the device's WiFi

Here we illustrate this with the example of an ESP8266.

```cpp
#include <Apollo.h>
#include <ESP8266WiFi.h>

ApolloDevice apolloDevice;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  // You can initialize device configurations like this.
  apolloDevice = apollo.init(YourDeviceID, YourApiKey, YourDeviceToken);
}

void loop() {
  // This runs the SDK when the device WiFi is connected.
  apolloDevice.loop(WiFi.status() == WL_CONNECTED);
}
```

### Initialize Your Device

Before doing anything, you need to initialize your device with data from the cloud to keep them both in sync. You can get all the device variables by using `getSummary()` and `getParms()` functions. Here's how you can get the device **state** from the cloud.

```cpp
#include <Apollo.h>
#include <ESP8266WiFi.h>

ApolloDevice apolloDevice;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void getParmsCallback(JSONObject parms) {
  if(payload["code"] == "DEVICE-PARMS-FETCHED") {
    bool state = (bool) payload["deviceParms"]["state"];
    // You can set a digital pin here with the state value
    // to switch the hardware connected to it ON/OFF.
    digitalWrite(D0, state);
  }
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  apolloDevice = apollo.init(YourDeviceID, YourApiKey, YourDeviceToken);
  // This gets the device's parms variables from the Cloud and passes them to
  // getParmsCallback() function.
  apolloDevice.getParms(getParmsCallback);
}

void loop() {
  // This runs the SDK when the device WiFi is connected.
  apolloDevice.loop(WiFi.status() == WL_CONNECTED);
}
```

### Set Update Handlers

Update handlers are the functions which are called when a device variable is updated on the cloud. The update could be from a user or the device itself. Without the handlers, your device would not be notified when a user turns it off from the webapp.
Here's how you can set update handlers in your sketch for the device's state stored in parms.

```cpp
#include <Apollo.h>
#include <ESP8266WiFi.h>

ApolloDevice apolloDevice;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void getParmsCallback(JSONObject parms) {
  if(payload["code"] == "DEVICE-PARMS-FETCHED") {
    bool state = (bool) payload["deviceParms"]["state"];
    // You can set a digital pin here with the state value
    // to switch the hardware connected to it ON/OFF.
    digitalWrite(D0, state);
  }
}

void parmsUpdatedCallback(JSONObject parms) {
  bool newState = (bool) updatedParms["state"];
  // You can set a digital pin here with the newState value
  // to switch the hardware connected to it ON/OFF.
  digitalWrite(D0, newState);
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  apolloDevice = apollo.init(YourDeviceID, YourApiKey, YourDeviceToken);
  // This gets the device's parms variables from the Cloud and passes them to
  // getParmsCallback() function.
  apolloDevice.getParms(getParmsCallback);
  // This sets up the update handler for parms. When an update to parms occur on the Cloud,
  // parmsUpdatedCallback() function is called.
  apolloDevice.onParmsUpdated(parmsUpdatedCallback);
}

void loop() {
  // This runs the SDK when the device WiFi is connected.
  apolloDevice.loop(WiFi.status() == WL_CONNECTED);
}
```

### Update Device Variables

To see the live state of the device on the web app, you need to keep sending the updated state after every few seconds. Since we've stored the device's state in **Parms**, we'll use the `setParms()` function to update the state value.

```cpp
#include <Apollo.h>
#include <ESP8266WiFi.h>

ApolloDevice apolloDevice;

void setupWiFi(void) {
  Serial.begin(9600);
  // Disconnecting WiFi if it"s already connected
  WiFi.disconnect();
  // Setting it to Station mode which basically scans for nearby WiFi routers
  WiFi.mode(WIFI_STA);
  // Begin connecting to WiFi
  WiFi.begin(YourWiFiSSID, YourWiFiPassphrase);
  Serial.printf("\nDevice is connecting to WiFi using SSID %s and Passphrase %s.\n", ssid.c_str(), passphrase.c_str());
}

void getParmsCallback(JSONObject parms) {
  if(payload["code"] == "DEVICE-PARMS-FETCHED") {
    bool state = (bool) payload["deviceParms"]["state"];
    // You can set a digital pin here with the state value
    // to switch the hardware connected to it ON/OFF.
    digitalWrite(D0, state);
  }
}

void parmsUpdatedCallback(JSONObject parms) {
  bool newState = (bool) updatedParms["state"];
  // You can set a digital pin here with the newState value
  // to switch the hardware connected to it ON/OFF.
  digitalWrite(D0, newState);
}

void setParmsCallback(JSONObject parms) {
  if(result["code"] == "DEVICE-PARMS-UPDATED") {
    Serial.printf("State is updated to: %d\n", (bool) payload["update"]["state"]);
  }
}

void setup() {
  Serial.begin(9600);
  // This sets up the device WiFi.
  setupWiFi();
  apolloDevice = apollo.init(YourDeviceID, YourApiKey, YourDeviceToken);
  // This gets the device's parms variables from the Cloud and passes them to
  // getParmsCallback() function.
  apolloDevice.getParms(getParmsCallback);
  // This sets up the update handler for parms. When an update to parms occur on the Cloud,
  // parmsUpdatedCallback() function is called.
  apolloDevice.onParmsUpdated(parmsUpdatedCallback);
}

void loop() {
  // Parms container to store device's state.
  JSONObject parms;
  parms["state"] = digitalRead(D0);
  // This sends the updated parms to the Cloud and calls setParmsCallback() when
  // the response from the cloud arrives.
  apolloDevice.setParms(parms, setParmsCallback);

  // This runs the SDK when the device WiFi is connected.
  apolloDevice.loop(WiFi.status() == WL_CONNECTED);
}
```

### Test it With Your Web app

You can build a web app for your product to control your hardware device over the cloud. [Here's a simple example for that][An Example Webapp].

## The Dexterity of Arduino SDK

The Arduino SDK is aimed at providing extremely to-the-point functions, being almost invisible in your device program to make the integration of Grandeur Cloud in your product seamless. Here is what it does under the hood without you paying attention to the most painful things:

* **Arduino SDK** takes care of your device's connection to [Grandeur Cloud][Grandeur Cloud]. **It can start trying to connect with the Cloud as soon as the device boots or you can manually tell the SDK when to begin.** There's a [`loop()`][loop] function that you place in the Arduino's `loop` whose sole function is to run the SDK. It accepts a **boolean expression as argument** and the SDK runs when the boolean expression evaluates to `true`. So, let's say if you pass the expression `WiFiState == CONNECTED` to it, the SDK would only run when the device's WiFi is connected.

* As soon as the WiFi gets connected, **Arduino SDK** begins trying to connect to *[Grandeur Cloud][Grandeur Cloud]* using the **connection credentials** you provide during `apollo.init()`. When it connects, only then does the communication with Grandeur Cloud happen. And if somehow the connection breaks, SDK handles the reconnection and everything resumes right from where it left.

*  **Arduino SDK** exposes the state of your device (`CONNECTED` or `DISCONNECTED`) through [`getState()`][getState] function to let you make your decisions based on that.

* **Arduino SDK** is event-driven. You can set **event handler** for device's connection or disconnection with Grandeur Cloud by using [`onConnection()`][onConnection]. So, when the device connects or disconnects from the cloud, the function passed to `onConnection()` is called.

* You can also set **update handlers** for device's summary and parms using [`onSummaryUpdated()`][onSummaryUpdated] and [`onParmsUpdated()`][onParmsUpdated]. So, when the any of the device variables stored in summary or parms is updated, the function passed to `onSummaryUpdated()` or `onParmsUpdated()` is called.

* **Async functions** are what make the event-drive of the SDK possible. They do all the same things as regular functions plus one extra. They receive a function parameter which they schedule for later. For example, in the `ApolloDevice` class, all of the following are Async functions:
  
  * `onConnection(Callback callback)`
  * `onSummaryUpdated(Callback callback)`
  * `onParmsUpdated(Callback callback)`
  * `getSummary(Callback callback)`
  * `getParms(Callback callback)`
  * `setSummary(JSONObject summary, Callback callback)`
  * `setParms(JSONObject parms, Callback callback)`

  `getParms()` for example, requests the cloud for the device's parms and schedules the `callback` function for when the parms arrive, because obviously, they don't arrive instantaneously; there is always some latency involved in web communications.

* There is a special type of function defined in **Arduino SDK** as [`Callback`][callback]. It's nothing but a regular function of the form:
  ```cpp
  void callback(JSONObject result) {}
  ```
  For now, it is the only function type that the Async functions of SDK accept as argument.

* [`JSONObject`][jsonobject] is a special variable type which acts like a container for other variables, just like a javascript object or a C++ map. You can store variables in it as key-value pairs. This what summary and parms are -- container for other variables aka. `JSONObject`s.

```cpp
JSONObject summary;
summary["foo"] = "This is foo";
summary["bar"] = true;
summary["foobar"]["foo"] = "This is foo inside foobar";

// In JSON, summary would look like:
//  {
//    "foo": "This is foo",
//    "bar": true,
//    "foobar": {
//      "foo": "This is foo inside foobar"
//    }
//  }
```

To see the **Arduino SDK** in action, jump to [Example][Example].

# Grandeur Ecosystem

The purpose of writing this is to give you a glimpse into the thought process and psychologies behind designing the Grandeur Cloud Platform the way it feels now. We believe that the first very important step towards choosing a platform for your product and company is to understand the design language of developers of the platform. So we thought of writing about it in detail. We wanted to document how you can use this platform effectively to make your life as a developer or founder a bit simpler.

Here we present a case study to help you understand exactly where, how and what Grandeur Cloud can help you with. Then we explain some of the terms and keywords we use to identify and classify things that make abstraction seamless. So here we go.

## A Brief Case Study

Suppose you are a cleantech startup and want to radicalize the home appliances market to make the appliances more eco and user friendly. You analyzed the market, did user interviews and realized that there is a really big problem in the air conditioner market. Even though millions of new air conditioners are produced every year but there are so many old and inefficient ACs already in the market installed in people's homes and offices. These old air conditioners consume a huge chunk of power and are a major cause of CFCs emissions. Something has to be done because these devices are impacting both the users and the environment. Upgrading each single one of them is just not feasible at all economically.

To resolve the energy efficiency issue of these old ACs, you decided to build an electronic solution that could be used as an extension with these old ACs. So people could control their power consumption without actually upgrading their devices. And you thought of providing your users with an interface to interact with their appliances. You wanted your users to see how much has this new extension been saving them in expenses by cutting down the power consumption. You also wanted to give your users control over how much they wanted to save through this app. In short, you decided to make your product smart (on IoT). And you decided to build a companion app for your device.

That's where the problem arose. You are a hardware startup, after all, that builds amazing electronics technology. But here you got to deal with a few more things as well. You have to build your app and figure out how to establish its communication with your hardware. You may decide to hire more engineers. But do you know how much of them will you have to hire? To give you a perspective, you generally need 8+ engineers just to do the server-end, like one to figure out your networking, one to design and manage your database, one to develop your API (the interface layer between your users and devices), about four for building your SDKs (one for each platform android, ios, web, and hardware) and then when you start scaling up a bit, one DevOps engineer. This makes it a package of $8000+ just to figure out the backend of your system and you haven't even validated your product yet. This turns out exhausting for your business. You have hit a concrete wall with no idea what to do about it.

Then one day the sun of fate shown. You came across a platform that goes by the name of Grandeur Cloud. You went through its [website][Grandeur Technologies] and discovered a perfectly fitting solution for all your headaches. You wanted a solution for authentication of your users, it has the Auth feature in it. You needed online file storage to store maybe the profile pictures of your users and other stuff, it comes with a storage builtin. You were in dire need of a scalable out-of-the-box database to store power consumption logs of your device to show your users graphs on their monthly/yearly savings, it provides a cloud datastore service. And the most important of these all, you needed a realtime communication bridge between your hardware and your apps, THANK GOD, its SDKs are available for all the stacks including Arduino, web, and mobile (both android and ios).

So here you are giving it a shot. You simply [registered for the platform][Grandeur Cloud], created your first project, downloaded their SDKs and started connecting your devices and apps through Grandeur Cloud. You didn't even have to worry about the security of your users and devices, because the data on Grandeur Cloud is protected under standard security protocols. Each user and device in a project is limited in its scope. All you had to worry about was designing your product core and develop your business logic. And in a matter of weeks, your product was out in people's hands, your apps live on app stores. People loved what you built and you were getting live feedback on it. You could see how many people have paired with your devices. You made an early entry into the market and now adding a dent to the universe.

By the way, that is the story of team SolDrive. Check out their [website][SolDrive] right now and explore how they are transforming the world with Grandeur Cloud.

## Concepts

In this subsection, we will explore the Grandeur Cloud platform in detail and see how it pulls it all off. So let's get started.

### Project

A project is the first thing you need to create to start working with Grandeur Cloud. A project is like a namespace, a completely isolated network of users and devices, along with separate file storage and a separate datastore. While you can create an unlimited number of projects, but no two projects can interact or share anything with one other.

Each project is identified by a digital signature that we call the API key, just as your identification card or social security number identifies you as a citizen. To connect your apps or hardware to your project's network, this is what you need to provide to the SDKs. The API key is sent with every request to Grandeur Cloud and this is what defines the project of the request. Check out the [SDK][SDK] section to read more about it.

> ***NOTE***: Our pricing applies separately to each project. So you get a free tier on every project and pay for each separately for what you consume when you cross your resources limit.

### SDK

Apollo is the API that exposes Grandeur Cloud to the outside world. Our SDKs utilize this API and map each functionality to a function. We have tried our best to make the integration of our SDKs into your codebase simple. For example, while developing your web app, you simply need to drop in the link of JS SDK CDN in your codebase and you are done. We have developed our SDKs for each platform in coherence with each other so you could work and collaborate everywhere seamlessly.

This is how they work: In every SDK, there is a global object aka. `apollo`. You can initialize your configurations (API Key and a couple of more stuff in case of hardware SDK) by calling `apollo.init()`. This returns you a reference to your whole project (in case of your app) or just to your device (in case of hardware because hardware scope is limited to the device itself). In **JS SDK**, you can interact with the authentication API, the device API, the file storage and the datastore API. In the case of **Arduino SDK** your scope is limited to just the device's namespace. Check out the [Authentication and Access][Authentication and Access] section to get more insight into how scope varies across the different platforms (app and hardware).

### User and Administrator

This topic is about the relationship between you as an administrator and your users and the access scope of both.

You aka. **the administrator** is an entity that creates, develops and maintains one or more [projects][Project] on Grandeur Cloud. The administrator has full authority over a project's resources (users, devices, files, and data) and can monitor and control all its projects from the [dashboard][Grandeur Cloud Dashboard].

A **user** is an entity that uses your product. While you have full control over your project, a user of your product has access to his profile and delegated access limited to its device scope only.

In the real world, you would not want to add a new user or pair a device with that user manually every time someone buys your product. Therefore you delegate a part of your project authorities to the SDK when you plug your project's API Key in. And so a new user gets to sign up, pair, monitor and control your device through your product's companion app.

Using just your project's API Key for full delegation is like putting all of your eggs in one basket. A stolen API Key can give the hacker, at the minimum, user-level access to your project. He can register any number of bogus users and do whatnot. Hence the concept of CORS comes to play. Read more on CORS in [Allowed Origins][Allowed Origins] section.

### Device

Devices are the *things* in **Internet of Things** (IoT) around which the IoT product development revolves. Like a user, a device entity has a limited scope of access. But unlike users, you can register new devices only from the dashboard. Read the [Device Registry][Device Registry] section for more on what happens when you register a new device to your project.

On Grandeur Cloud, a device falls under the ownership of the project's administrator. The project's API Key delegates the device pairing authority to the SDK which the user uses to pair with the device. Pairing a device makes it live on Grandeur Cloud and the user gets delegated access to the device's data. But a user cannot delete or modify a device's inherent data because it's not within its scope.

A user can pair with any number of devices but a device can be paired with at the most one user.

The device entity, in the end, defines two things:

* What kind of data a hardware device can access in your namespace and
* Which hardware devices a user can control.

This matters a lot because you would never want your neighbor to control your air conditioner (that would be a horrible situation). That's what this entity has been designed for. A user can only interact with devices that are paired with it.

When you pair a device with a user account, an access token is generated for the device. This token is what the device uses to connect to Grandeur Cloud. This token also delegates access of the device namespace to the Arduino SDK. The Arduino SDK takes this access token along with the project's API Key while doing `apollo.init()`. To read about the device's namespace and how the device's data is stored on Grandeur Cloud, have a look at the [Device Registry][Device Registry] section.

> ***NOTE***: A user cannot pair with a device that is already paired.

### Device Registry

The device registry constitutes one of the key elements of Grandeur Cloud. There are two types of approaches you see out there:

* Those which deal with user's authentication only e.g. firebase and
* Those which employ a device's registry e.g. Google IoT Core, to make sure no unauthorized devices get into your network.

We wanted to combine the best of both worlds. This is why at Grandeur Cloud, not do we just authenticate a device on connection, we also maintain a device's registry for you. See [Authentication and Access][Authentication and Access] section for detail on how a device is authenticated on Grandeur Cloud.

When you register a device, you make it available in your project's network. Not just that, a new namespace is created for your device in the device registry. When your device comes online, this is where all of its data is stored, in the form of i) Summary and ii) Parms.

Now let's define what you can store in **Parms** and **Summary**. To be honest, there is no hard and fast rule about it. We just created two objects instead of a single one to help you develop understanding. However, we generally take the *parms as the directly controllable device variables* and the *summary as those device variables which are not directly controllable* or are just needed to be logged or displayed to apps. In another way, the parms sometimes refer to the inputs from the user and the summary refers to the outputs of the device resulting from the inputs. Consider an example where you have a smart light bulb. The parms can store the bulb ON/OFF state which the user can control, while in summary, you can log the voltage consumption of the bulb.

We defined these two objects just to give you a basic framework to work on and build your logic fast. But we are very flexible in what and how you store data in the device registry. You can define an initial schema of these objects using [models][models] and go on from there.

### Models

### Authentication and Access

Previously, we have discussed in depth which entity (administrator, user, device) can access what. This section revisits the topic and gives you a broader picture of authentication and access scopes. Let's start by outlining the relationships. There are three major scopes:

* The global scope or project's scope
* User scope
* Device scope

You (as an administrator) create a project and therefore have global access to everything. You can access and manage your projects and their resources using the dashboard application. You want your users and devices to have limited access to your project's resources based on their scopes which you achieve by using our SDKs in your apps and hardware. Your project's API Key delegates your project's access to the SDKs and access tokens allow and limit, at the same time, this access to user and device scopes.

The user scope is wider than the device scope. A user can access its profile, the registry of the devices it's paired to, the files in the project's storage and the data in the project's datastore. When a user logs in, an Auth token is returned. This token along with the API Key, being sent with every request, is what validates the authority of the request.

The device scope is limited to the device's namespace in the device registry. When a user pairs with a device, an access token is returned for the device. This access token along with the API Key is what authenticates the device's connection to Grandeur Cloud.

This is how the global project scope is distributed among the smaller entities and we make sure that everyone gets what they are allowed to access.

### Networking

Here we write about how the networking works on Grandeur Cloud.

We work with two communication channels in **Web SDK** i) HTTP based REST API channel and ii) Duplex based realtime API channel. We use the first to do some basic things like authentication or handle big requests like file uploading, while the latter, as its name suggests, for realtime communication like fetching or updating the device's data. The realtime channel is as fast as 200ms RTT. It is based on our custom protocol aka. Duplex. We do not allow any unauthenticated communication over this channel and therefore authenticate a connection over the REST channel first.

In the **Arduino SDK**, we only use the realtime channel. A device cannot establish a connection over this channel unless and until its access token is validated. A device access token is provided while initializing the apollo configurations through `apollo.init()`.

### Allowed Origins

This is another amazing topic and somehow related to access delegation in the end. As mentioned in the sections above that you can interact with your project's namespace through the JS SDK by initializing apollo with your API key. This returns an object referring to your project which can be used to interact with its resources including its devices, datastore, and files storage. Putting this much responsibility on just the API key poses a security threat particularly in case of web apps as API Key can easily be stolen. Even though a user needs to log in first before making any request to the cloud, a hacker with having your API key can still cause some serious damage. For example, Registering bogus users to your project or creating a copycat site on your name for phishing to name a few. That's where cross-origin request sharing (CORS) policies come to play.

So to allow a web app to interact with your project using the Web SDK, you first need to whitelist the domain name your web app uses via the settings page in the dashboard. You cannot even send a request from your localhost without first whitelisting it.

> ***NOTE***: Keeping localhost whitelisted in a production application is a very serious vulnerability that can make you pay as you go (pun intended).

# Documentation

`Project` is the main class and all functionalities originate from it. You get the object of this class when you initialize SDK's configurations using `apollo.init()`. `apollo` is the global object that gets available right away when you include `<Apollo.h>` in your sketch. It has only one purpose and therefore gives you only one function: `apollo.init()`.

> ***Note 2***: You cannot connect with Grandeur Cloud or even with internet without first connecting with the WiFi. Therefore, the examples below are just for reference and you are required to handle your device's WiFi in order for them to work. You can see [these ESP8266 examples][Examples] to get a deeper understanding. Plus they handle WiFi too. 😉

### init

> apollo.init (deviceID: _String_, apiKey: _String_, token: _String_) : returns _Project_

This method initializes SDK's connection configurations: `deviceID`, `apiKey` and `authToken`, and returns an object of the `Project` class. `Project` class is the main class that exposes all other functions of the SDK.

#### Parameters

| Name        | Type     | Description                                                     |
|-------------|----------|-----------------------------------------------------------------|
| deviceID    | _String_ | ID of your device                                               |
| apiKey      | _String_ | API key of your project that your device belongs to             |
| token       | _String_ | Access token generated when the device is paired with the user  |

#### Example

```cpp
// Container for the object of ApolloDevice class.
Project myProject;
void setup() {
  myProject = apollo.init(YourDeviceID, YourApiKey, YourToken);
}

// **RESULT**
// SDK configurations are initialized.

```

## Project

Project is the main class of the SDK. When our SDK connects with the Cloud, this class represents our cloud project but at device scope. This means that device has access to its own data only. It cannot access all the project's data with any bounds.

This class exposes the methods:

### isConnected

> isConnected(void): returns _bool_

This method returns true if the SDK is connected with Grandeur Cloud.

#### Example

```cpp
Project myProject;
void setup() {
  myProject = apollo.init(YourDeviceID, YourApiKey, YourToken);
}

void loop() {
  if(!myProject.isConnected()) {
    Serial.println("Device is not connected with the Cloud!\n");
  }
  else {
    Serial.println("Yay! Device has made a successful connection with Grandeur Cloud!\n");
  }

  myProject.loop(true);
}

// **RESULT**
// In the beginning, isConnected() returns false and the first *if-block* runs.
// When the SDK is connected with the Cloud, isConnected() returns true running the second
// *if-block*.
```

### onConnection

> onConnection (callback : _Callback_) : returns _void_

This method schedules a function to be called when the SDK's connection with Grandeur Cloud is made or broken. The function passed to it as argument is called an **event handler** for it handles events like connection / disconnection with the cloud. Example below illustrates how you can handle these events.

#### Parameters

| Name        | Type             | Description                                                      |
|-------------|------------------|------------------------------------------------------------------|
| callback    | _void (*)(bool)_ | An event handler function for device's connection with the Cloud |


#### Example

```cpp
Project myProject;

void connectionCallback(bool status) {
  // This method handles the events related to device's connection with the Cloud.
  switch(status) {
    case CONNECTED:
      // If the connection event occurred.
      Serial.println("Device Connected to the Cloud!\n");
      break;
    case DISCONNECTED:
      // If the disconnection event occurred.
      Serial.println("Device Disconnected from the Cloud!\n");
      break;
  }
}

void setup() {
  myProject = apollo.init(YourDeviceID, YourApiKey, YourToken);

  myProject.onConnection(connectionCallback);
}

void loop() {
  myProject.loop(true);
}

// **RESULT**
// Prints "Device Connected to the Cloud!" when device makes a successful connection with Grandeur Cloud
// and "Device Disconnected from the Cloud!" when device breaks connection from Grandeur Cloud.
```

### loop

> loop (valve: _bool_) : returns _void_

This method forms the legs of the SDK. Without it, the SDK can't run. Therefore, it must be called in Arduino's `loop()` and without being suspected to any kind of *delay*. **This method is what runs the underlying event loop and makes all the *Async* functions possible.**
This method accepts an argument which we call **valve**. A **valve** is a boolean expression whose value decides if the SDK would run for this `loop` or not. For example, we can use it to dictate to the SDK to run only when the device WiFi is connected.

> **A Tidbit:** [Here][Using Millis Instead of Delay] is how you can use `millis()` instead of `delay()` if you want a function to run every few moments.

#### Example

```cpp
Project myProject;
void setup() {
  myProject = apollo.init(YourDeviceID, YourApiKey, YourToken);
}

void loop() {
  myProject.loop(WiFiState == CONNECTED);  
}
// **RESULT**
// Runs the SDK only when the WiFi is connected.
```

### device

> device (void) : returns _Device_

This method returns an object of the **Device** class. Read about it [here][Device Class].

#### Example

```cpp
Project myProject;
Device myDevice;
void setup() {
  myProject = apollo.init(YourDeviceID, YourApiKey, YourToken);
  myDevice = myProject.device();
}

// **RESULT**
// Gets the object of Device class.
```

### datastore

> datastore (void) : returns _Datastore_

This method returns an object of the **Datastore** class. Datastore class exposes the functions of the datastore API which handles your queries to your project's datastore like: logging device variables to the cloud datastore, fetching those logs etc.

#### Example

```cpp
Project myProject;
Datastore myDatastore;
void setup() {
  myProject = apollo.init(YourDeviceID, YourApiKey, YourToken);
  myDatastore = myProject.datastore();
}

// **RESULT**
// Gets the object of Datastore class.
```

## Device

Device class exposes the functions of the device API. It generally handles your device's data on Grandeur Cloud like: updating device variables on the Cloud, pulling variables from the Cloud, listening for cloud updates in your device variables, and so on.

It exposes the following functions:

### getSummary

> getSummary (callback: _Callback_) : returns _void_

This method gets device's [summary][summary] from the Cloud.

#### Parameters

| Name        | Type       | Description                                                  |
|-------------|------------|--------------------------------------------------------------|
| callback    | _Callback_ | A function to be called when getSummary response is received |

#### Example

```cpp
Project myProject;
Device myDevice;

void getSummaryCallback(JSONObject result) {
  // This method just prints *voltage* variable from the device's summary.
  Serial.println(result["summary"]["voltage"]<<"\n");
}

void setup() {
  myProject = apollo.init(YourDeviceID, YourApiKey, YourToken);
  myDevice = myProject.device();
}

void loop() {
  // This gets the summary on every loop and calls getSummaryCallback() function when its
  // response from the cloud is received.
  myDevice.getSummary(getSummaryCallback);

  myProject.loop(true);
}

// **RESULT**
// Prints the value of the voltage variable stored in the device's summary on every loop.
```

### getParms

> getParms (callback: _Callback_) : returns _void_

This method gets device's [parms][parms] from the Cloud.

#### Parameters

| Name        | Type       | Description                                                |
|-------------|------------|------------------------------------------------------------|
| callback    | _Callback_ | A function to be called when getParms response is received |

#### Example

```cpp
Project myProject;
Device myDevice;

void getParmsCallback(JSONObject result) {
  // This method just prints *state* variable from the device's parms.
  Serial.println(result["parms"]["state"]<<"\n");
}

void setup() {
  myProject = apollo.init(YourDeviceID, YourApiKey, YourToken);
  myDevice = myProject.device();
}

void loop() {
  // This gets the parms on every loop and calls getParmsCallback() function when its
  // response from the cloud is received.
  myDevice.getParms(getParmsCallback);

  myProject.loop(true);
}

// **RESULT**
// Prints the value of the state variable stored in the device's parms on every loop.
```

### setSummary

> setSummary (summary : _JSONObject_, callback: _Callback_) : returns _void_

This method updates the device's [summary][summary] on the Cloud with new values.

#### Parameters

| Name        | Type          | Description                                                  |
|-------------|---------------|--------------------------------------------------------------|
| summary     | _JSONObject_  | A JSONObject containing the summary variables                |
| callback    | _Callback_    | A function to be called when setSummary response is received |

#### Example

```cpp
Project myProject;
Device myDevice;

void setSummaryCallback(JSONObject result) {
  // This method prints *voltage* and *current* variables from device's updated summary.
  Serial.println(result["update"]["voltage"]<<"\n");
  Serial.println(result["update"]["current"]<<"\n");
}

void setup() {
  myProject = apollo.init(YourDeviceID, YourApiKey, YourToken);
  myDevice = myProject.device();
}

void loop() {
  // A JSONObject container to store summary variables.
  JSONObject summary;
  summary["voltage"] = analogRead(A0);
  summary["current"] = analogRead(A1);
  // This sets the summary on every loop and calls setSummaryCallback() function when its
  // response from the cloud is received.
  myDevice.setSummary(summary, setSummaryCallback);

  myProject.loop(true);
}

// **RESULT**
// Setting the summary and prints the updated values of the summary
// variables (voltage and current in our case) on every loop.
```

### setParms

> setParms (parms : _JSONObject_, callback: _Callback_) : returns _void_  

Setter method for device's [parms][parms].

#### Parameters

| Name        | Type         | Description                                                     |
|-------------|--------------|-----------------------------------------------------------------|
| parms       | _JSONObject_ | A JSONObject containing the summary variables                   |
| callback    | _Callback_   | A function to be called when setParms response is received      |

#### Example

```cpp
Project myProject;
Device myDevice;

void setParmsCallback(JSONObject result) {
  // This method prints *state* variable from device's updated parms.
  Serial.println(result["parms"]["state"]<<"\n");
}

void setup() {
  myProject = apollo.init(YourDeviceID, YourApiKey, YourToken);
  myDevice = myProject.device();
}

void loop() {
  // A JSONObject container to store parms variables.
  JSONObject parms;
  parms["state"] = digitalRead(D0);
  // This sets the parms on every loop and calls setParmsCallback() function when its
  // response from the cloud is received.
  myDevice.setParms(parms, setParmsCallback);

  myProject.loop(true);
}

// **RESULT**
// Setts the parms and prints the updated values of the parms
// variables (just state in our case) on every loop
```

### onSummaryUpdated

> onSummaryUpdated (callback : _Callback_) : returns _void_

This method schedules a function to be called when the summary of the device is updated on Grandeur Cloud.

> ***A Tidbit***: *Update is a special type of event* and the function that handles it is called an **update handler**.

#### Parameters

| Name        | Type       | Description                            |
|-------------|------------|----------------------------------------|
| callback    | _Callback_ | An update handler for device's summary |

More on Callback [here][callback].

#### Example

```cpp
Project myProject;
Device myDevice;

void summaryUpdatedCallback(JSONObject result) {
  // When summary update occurs on the Cloud, this function extracts the updated values of
  // voltage and current, and sets the corresponding pins.
  Serial.println("Summary update occurred!\n");
  int voltage = updatedSummary["voltage"];
  int current = updatedSummary["current"];
  digitalWrite(voltage, A0);
  digitalWrite(current, A1);
}

void setup() {
  myProject = apollo.init(YourDeviceID, YourApiKey, YourToken);
  myDevice = myProject.device();

  myDevice.onSummaryUpdated(summaryUpdatedCallback);
}

void loop() {
  myProject.loop(true);
}
```

### onParmsUpdated

> onParmsUpdated (callback : _Callback_) : returns _void_

This method schedules a function to be called when the parms of the device are updated on Grandeur Cloud.

#### Parameters

| Name        | Type       | Description                          |
|-------------|------------|--------------------------------------|
| callback    | _Callback_ | An update handler for device's parms |

More on Callback [here][callback].

#### Example

```cpp
Project myProject;
Device myDevice;

void parmsUpdatedCallback(JSONObject updatedParms) {
  // When parms update occurs on the Cloud, this function extracts the updated value of
  // state, and sets the corresponding pin.
  Serial.println("Parms update occurred!\n");
  int state = updatedParms["state"];
  digitalWrite(D0, state);
}

void setup() {
  myProject = apollo.init(YourDeviceID, YourApiKey, YourToken);
  myDevice = myProject.device();
  myDevice.onParmsUpdated(parmsUpdatedCallback);
}

void loop() {
  myProject.loop(true);
}
```

## Datastore

Device class exposes the functions of the device API. It generally handles your device's data on Grandeur Cloud like: updating device variables on the Cloud, pulling variables from the Cloud, listening for cloud updates in your device variables, and so on.

It exposes the following functions:

### insert

> insert (documents: _JSONObject_, callback: _Callback_) : returns _void_

This method inserts documents into the Cloud datastore.

#### Parameters

| Name        | Type         | Description                                                              |
|-------------|--------------|--------------------------------------------------------------------------|
| documents   | _JSONObject_ | An array of documents (_JSONObject_ s) to be inserted into the datastore |
| callback    | _Callback_   | A function to be called when insertion of documents is completed         |

#### Example

```cpp
Project myProject;
Datastore myDatastore;

void insertCallback(JSONObject insertionResult) {
  // This method just prints if the insertion is successful or not.
  if(insertionResult["code"] == "DATASTORE-DOCUMENTS-INSERTED") {
    Serial.prinln("Insertion successful.");
  }
  Serial.println("Insertion Failed.");
}

void setup() {
  myProject = apollo.init(YourDeviceID, YourApiKey, YourToken);
  myDatastore = myProject.datastore();
}

void loop() {
  // This inserts a document containing voltage and current readings in datastore on every loop.
  JSONObject docs;
  // Adding voltage and current readings to the first document of docs array.
  // In JSON, the docs array looks like this:
  // [{"voltage": analogRead(A0), "current": analogRead(A1)}]
  docs[0]["voltage"] = analogRead(A0);
  docs[0]["current"] = analogRead(A1);
  // Inserting the docs in datastore. insertCallback() will be called when insertion process
  // completes.
  myDatastore.insert(docs, insertCallback);

  myProject.loop(true);
}

// **RESULT**
// Prints "Insertion successful." if documents are inserted. If an error occurred, it prints
// "Insertion Failed."
```

## Enhancements Under Consideration:

Here are some enhancements that we are considering to implement in the SDK. They have their corresponding issues as well. If you can relate to any one of these and would like to fast forward its implementation, just comment +1 on its issue. This would be a feedback for us to set priorities in a user-centered way. Thank you 👇

[#4][i4] — Move the error handling inside the SDK. The developer would not have to check the response code to see if the request executed successfully or not. We would do that the native C-way instead: by returning 0 for success and 1, 2, 3 for other error codes. Or we can create some macros like SUCCESS, ERROR etc.

[Grandeur Technologies]: https://grandeur.tech "Grandeur Technologies"
[Grandeur Cloud]: https://cloud.grandeur.tech "Grandeur Cloud"
[Grandeur Cloud Sign Up]: https://cloud.grandeur.tech/register "Sign up on Grandeur Cloud"
[Grandeur Cloud Dashboard]: https://cloud.grandeur.tech/dashboard "Grandeur Cloud Dashboard"
[Grandeur Cloud Accounts]: https://cloud.grandeur.tech/accounts "Grandeur Cloud Accounts"
[Grandeur Cloud Devices]: https://cloud.grandeur.tech/devices "Grandeur Cloud Devices"
[Grandeur Cloud Settings]: https://cloud.grandeur.tech/settings "Grandeur Cloud Settings"
[Grandeur Cloud Pricing]: https://grandeur.tech/pricing "Pricing"
[Get Started With Grandeur Cloud]: https://github.com/grandeurtech/grandeurcloud-js-sdk#get-started "Get Started With Grandeur Cloud"
[An Example Webapp]: https://github.com/grandeurtech/grandeurcloud-js-sdk#example "An Example Webapp"
[Examples]:  https://github.com/grandeurtech/grandeurcloud-arduino-sdk/tree/master/examples/
[Arduino IDE]: https://www.arduino.cc/en/main/software "Arduino IDE"
[Installing an Arduino Library]: https://www.arduino.cc/en/guide/libraries "Installing an Arduino Library"

[Grandeur Cloud Hackster]: https://www.hackster.io/grandeurcloud "Hackster Community"

[Installation]: #installation "Installation"
[Example]: #example "Arduino SDK Example"
[Documentation]: #documentation "Documentation"
[Ecosystem]: #grandeur-ecosystem "Grandeur Ecosystem"

[SolDrive]: https://sol-drive.com/ "SolDrive"

[Project]: #project "Project"
[SDK]: #sdk "SDK"
[Authentication and Access]: #authentication-and-access "Authentication and Access"
[Allowed Origins]: #allowed-origins "Allowed Origins"
[Device Registry]: #device-registry "Device Registry"

[Get Started with Arduino SDK]: #get-started "Get Started with Arduino SDK"
[Arduino SDK]: https://github.com/grandeurtech/grandeurcloud-arduino-sdk "Arduino SDK"
[project]: #project "Project"
[summary]: #device-registry "Summary"
[parms]: #device-registry "Parms"
[callback]: #the-dexterity-of-arduino-sdk "The Dexterity of Arduino SDK"
[jsonobject]: #the-dexterity-of-arduino-sdk "The Dexterity of Arduino SDK"
[the dexterity of arduino sdk]: #the-dexterity-of-arduino-sdk "The Dexterity of Arduino SDK"
[models]: #models "Models"
[apikey]: #project "Project"
[access token]: #authentication-and-access "Authentication and Access"

[getState]: #get-state
[onConnection]: #apollo-connection-event-listener
[onSummaryUpdated]: #summary-update-handler
[onParmsUpdated]: #parms-update-handler
[loop]: #loop

[Using Millis Instead of Delay]: https://www.norwegiancreations.com/2017/09/arduino-tutorial-using-millis-instead-of-delay/ "Using millis() instead of delay()"

[i4]: https://github.com/grandeurtech/grandeurcloud-arduino-sdk/issues/4
