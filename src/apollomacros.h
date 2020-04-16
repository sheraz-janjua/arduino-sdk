/**
 * @file apollomacros.h
 * @date 24.03.2020
 * @author Grandeur Technologies
 *
 * Copyright (c) 2019 Grandeur Technologies LLP. All rights reserved.
 * This file is part of the Hardware SDK for Grandeur Cloud.
 *
 */

// Connection macros
#define APOLLO_URL "api.grandeur.tech"
#define APOLLO_PORT 443
#define APOLLO_FINGERPRINT ""

// Strings sizes
#define SSID_SIZE 32
#define PASSPHRASE_SIZE 32
#define DEVICEID_SIZE 32
#define APIKEY_SIZE 32
#define TOKEN_SIZE 512
#define IP_SIZE 16
#define FINGERPRINT_SIZE 256
#define PACKET_SIZE 512
#define PING_PACKET_SIZE 64
#define TASK_SIZE 32

// Send Queue Size
#define SENDQUEUE_SIZE 16

// Ping interval in milliseconds
#define PING_INTERVAL 25000

// Defining macros for Apollo states
#define WIFI_NOT_CONNECTED 0
#define WIFI_CONNECTED 1
#define APOLLO_CONNECTED 2

// Indexes for handlers callbacks
#define ONCONNECTED 0
#define ONDISCONNECTED 1
#define ONMESSAGE 2

// Indexes for update handler callbacks in subscriptions array
#define NUMBER_OF_TOPICS 2
#define SUMMARYUPDATE 0
#define PARMSUPDATE 1