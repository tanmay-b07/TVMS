# ESP32 MQTT Gateway

The ESP32 acts as the IoT communication gateway in the TrailBox Vehicle Monitoring System (TVMS).

It receives JSON sensor packets from the STM32 RX node through UART, parses the data and publishes it to dedicated MQTT topics. The gateway also manages device heartbeat monitoring and MQTT Last Will for online/offline status detection.

---

# Version

Current Version: **V4.0.0**

Status: **In Development**

---

# Overview

The ESP32 bridges the embedded CAN network and the IoT platform.

It receives decoded sensor data from the STM32 RX node, publishes it to the MQTT broker and enables real-time monitoring through the TVMS dashboard.

---

# Responsibilities

- Receive JSON packets from STM32 RX over UART
- Parse sensor data
- Connect to Wi-Fi
- Connect to MQTT Broker
- Publish sensor values to dedicated MQTT topics
- Publish device heartbeat
- Support MQTT Last Will (Online / Offline detection)
- Automatic Wi-Fi reconnection
- Automatic MQTT reconnection

---

# Communication Flow

```text
STM32 TX
     │
     ▼
CAN Bus
     │
     ▼
STM32 RX
     │
 UART (USART2)
     │
     ▼
ESP32 MQTT Gateway
     │
     ▼
 MQTT Broker
     │
     ▼
 Flask Backend
     │
     ▼
 TVMS Dashboard
```

---

# Supported Sensor Packets

## Temperature & Humidity

```json
{
  "type":"temp",
  "temperature":30.5,
  "humidity":65
}
```

Published Topic

```text
talktrail/vehicle/temp
```

---

## Accelerometer

```json
{
  "type":"accel",
  "x":120,
  "y":-35,
  "z":980
}
```

Published Topic

```text
talktrail/vehicle/accel
```

---

## Pressure

```json
{
  "type":"pressure",
  "value":1024
}
```

Published Topic

```text
talktrail/vehicle/pressure
```

---

## Battery

```json
{
  "type":"battery",
  "voltage":12.45,
  "current":1.28
}
```

Published Topic

```text
talktrail/vehicle/battery
```

---

# MQTT Topics

```text
talktrail/vehicle/temp
talktrail/vehicle/accel
talktrail/vehicle/pressure
talktrail/vehicle/battery
talktrail/vehicle/status
```

---

# Device Status Monitoring

The gateway periodically publishes its status to MQTT.

Online

```text
online
```

Offline

```text
offline
```

Features

- MQTT Last Will & Testament (LWT)
- Retained Status Messages
- Heartbeat Monitoring
- Online / Offline Detection

---

# Heartbeat

Heartbeat Interval

```text
5 Seconds
```

Purpose

- Device health monitoring
- Connection verification
- Dashboard status updates

---

# Development Environment

- Arduino IDE
- ESP32 Arduino Core
- PubSubClient
- ArduinoJson
- WiFi Library

---

# Features

- UART JSON Parsing
- Multi-Sensor MQTT Publishing
- Automatic Wi-Fi Reconnection
- Automatic MQTT Reconnection
- Device Heartbeat
- MQTT Last Will Support
- Retained Device Status
- Modular Topic-Based Architecture

---

# Upcoming

- MQTT over TLS
- HiveMQ Cloud Integration
- Configuration File Support
- OTA Firmware Updates

---

# Author

**Tanmay Bhosle**

TrailBox Vehicle Monitoring System (TVMS)

Built under the **TrailBox** ecosystem.
