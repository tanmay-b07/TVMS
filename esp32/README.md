# ESP32 MQTT Gateway

This directory contains the ESP32 firmware used as the communication gateway in the TVMS project.

The ESP32 acts as a bridge between the STM32 microcontroller and HiveMQ Cloud, enabling real-time sensor data transmission, environmental monitoring and device status tracking.

## Responsibilities

* Receive sensor data from STM32 through UART
* Parse LDR, Temperature and Humidity values
* Connect to WiFi
* Connect to HiveMQ Cloud using MQTT over TLS
* Publish sensor data to dedicated MQTT topics
* Transmit periodic device heartbeat messages
* Support real-time dashboard monitoring

---

## MQTT Topics

### Sensor Data

```text
talktrail/vehicle/ldr
talktrail/vehicle/temp
talktrail/vehicle/humidity
```

Published Values:

```text
LDR Value
Temperature Value
Humidity Value
```

### Device Heartbeat

```text
talktrail/vehicle/status
```

Payload:

```text
online
```

---

## UART Data Format

Received from STM32:

```text
LDR:3,TEMP:30.8,HUM:61
```

Parsed by ESP32 and published to individual MQTT topics.

---

## Heartbeat Monitoring

The ESP32 sends a heartbeat message every 5 seconds to indicate that the device is operational and connected to the MQTT broker.

Heartbeat Interval:

```text
5 Seconds
```

Purpose:

* Device health monitoring
* Online/Offline detection
* Dashboard status updates
* Future multi-device support

---

## Development Environment

* Arduino IDE
* ESP32 Board Package
* PubSubClient Library
* WiFi Library
* WiFiClientSecure

---

## Communication Flow

```text
STM32F407
   │
   │ UART
   ▼
ESP32 MQTT Gateway
   │
   ├── talktrail/vehicle/ldr
   ├── talktrail/vehicle/temp
   ├── talktrail/vehicle/humidity
   └── talktrail/vehicle/status
           │
           ▼
      HiveMQ Cloud
           │
           ▼
      TVMS Dashboard
```

---

## Features

* Multi-Sensor MQTT Publishing
* UART Data Parsing
* Secure MQTT Communication (TLS)
* Device Heartbeat Monitoring
* Real-Time Data Streaming
* Online/Offline Device Detection

---

## Version

TVMS V2.0.0

## Status

Stable Release

## Author

Tanmay Bhosle

TrailBox Vehicle Monitoring System (TVMS)

