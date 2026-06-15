# ESP32 MQTT Gateway

This directory contains the ESP32 firmware used as the communication gateway in the TVMS project.

The ESP32 acts as a bridge between the STM32 microcontroller and HiveMQ Cloud, enabling real-time sensor data transmission and device status monitoring.

## Responsibilities

* Receive sensor data from STM32 through UART
* Connect to WiFi
* Connect to HiveMQ Cloud using MQTT over TLS
* Publish sensor data to MQTT topics
* Transmit periodic device heartbeat messages
* Support real-time dashboard monitoring

---

## MQTT Topics

### Sensor Data

```text
talktrail/vehicle/ldr
```

Publishes LDR sensor values received from STM32.

### Device Heartbeat

```text
talktrail/vehicle/status
```

Publishes device status messages used for online/offline monitoring.

Payload:

```text
online
```

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

---

## Communication Flow

```text
STM32
   │
   │ UART
   ▼
ESP32
   │
   ├── talktrail/vehicle/ldr
   │
   └── talktrail/vehicle/status
           │
           ▼
      HiveMQ Cloud
           │
           ▼
      TVMS Dashboard
```

---

## Version

TVMS V1.0.2

## Status

Stable Release

## Author

Tanmay Bhosle

TrailBox Vehicle Monitoring System (TVMS)

