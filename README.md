# TVMS - TrailBox Vehicle Monitoring System

TVMS (TrailBox Vehicle Monitoring System) is a real-time IoT monitoring platform built using STM32F407, ESP32, MQTT and a web dashboard.

The project demonstrates end-to-end sensor data acquisition, cloud communication and real-time visualization. This release serves as the foundation for future CAN-based vehicle telemetry and monitoring systems.

---

## Version

Current Release: **V2.0.0**

Status: **Released**

---

## Features
* Multi-sensor monitoring
* DHT11 temperature monitoring
* DHT11 humidity monitoring
* Dedicated MQTT topics
* Enhanced dashboard UI
* Activity feed logging
* STM32F407 sensor data acquisition
* Non-blocking firmware architecture
* Timer-based sensor processing
* UART communication between STM32 and ESP32
* ESP32 MQTT publishing
* HiveMQ Cloud integration
* Real-time dashboard
* Live sensor monitoring
* Android companion application
* Mobile dashboard access
* Device heartbeat monitoring
* Online/Offline device detection
* Device status dashboard card
* End-to-end IoT data flow

---

## System Architecture

```text
LDR Sensor
DHT11 Sensor
      │
      ▼
 STM32F407
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
      │
      ▼
 Android App
```

---

## Technology Stack

### Hardware

* STM32F407 Discovery
* ESP32 DevKit
* LDR Sensor
* DHT11 Sensor
### Software

* STM32CubeIDE
* STM32CubeMX
* Arduino IDE
* HiveMQ Cloud
* HTML
* CSS
* JavaScript
* MQTT.js
* MIT App Inventor

---

## Project Structure

```text
TVMS/

├── app/
│   ├── TVMS.apk
│   ├── screenshots/
│   └── README.md
│
├── stm32/
├── esp32/
├── dashboard/
├── screenshots/
├── docs/
└── README.md
```

---

## Implemented Features

### V1.0.0

* Sensor value acquisition using STM32 ADC
* UART communication
* ESP32 MQTT gateway
* Cloud connectivity through HiveMQ
* Real-time dashboard updates

### V1.0.1

* Android companion application
* Mobile dashboard access
* Improved monitoring accessibility

### V1.0.2

* Device heartbeat monitoring
* Online/Offline device status detection
* Automatic heartbeat publishing
* Device status dashboard card
* MQTT status topic support

### V1.0.3

* Non-blocking STM32 firmware architecture
* Timer-based task scheduling
* Improved sensor acquisition responsiveness
* Improved UART communication handling
* Reduced firmware latency
* Enhanced firmware stability

### V2.0.0

* Multi-sensor monitoring
* Temperature monitoring
* Humidity monitoring
* Dedicated MQTT topics
* Enhanced dashboard UI
* Live activity feed
* Improved STM32 firmware
* Improved ESP32 gateway
* Real-time environmental monitoring

---

## Release History

### V2.0.0 - Multi Sensor Monitoring Platform

Added:

* DHT11 integration
* Temperature monitoring
* Humidity monitoring
* Dedicated MQTT topics
* Dashboard redesign
* Multi-sensor activity feed

Improved:

* STM32 firmware
* ESP32 MQTT gateway
* Dashboard visualization

MQTT Topics:

* talktrail/vehicle/ldr
* talktrail/vehicle/temp
* talktrail/vehicle/humidity
* talktrail/vehicle/status
---
### V1.0.3 - Non-Blocking Firmware Upgrade

Added:

* Timer-based non-blocking processing
* Improved firmware responsiveness
* Better task scheduling architecture

Improved:

* Sensor acquisition performance
* UART communication reliability
* Overall firmware stability

No changes:

* Dashboard architecture
* Android application
* MQTT topics
* HiveMQ Cloud integration

MQTT Topics:

* talktrail/vehicle/ldr
* talktrail/vehicle/status

---

### V1.0.2 - Device Heartbeat Monitoring

Added:

* Device heartbeat monitoring
* Online/Offline device detection
* Device status dashboard card
* Heartbeat MQTT topic
* Automatic offline timeout detection

MQTT Topics:

* talktrail/vehicle/ldr
* talktrail/vehicle/status

---

### V1.0.1 - Android App Support

Added:

* Android companion application
* Mobile dashboard access

No changes:

* STM32 firmware
* ESP32 firmware
* MQTT architecture
* Dashboard functionality

---

### V1.0.0 - Initial IoT Monitoring Platform

* STM32 ADC acquisition
* UART communication
* ESP32 MQTT gateway
* HiveMQ Cloud integration
* Real-time dashboard
* GitHub documentation

---

## Roadmap


### V3.0

* Database integration
* Historical data storage
* Charts and analytics
* Sensor history

### V4.0

* CAN bus communication
* Multiple STM32 nodes
* Vehicle telemetry network

### V5.0

* Production-ready TVMS platform
* Advanced analytics
* Alerts and notifications
* Fleet monitoring
* Complete vehicle monitoring ecosystem

---

## Live Dashboard

https://v1dashboard.trailbox.in/release2.html

---

## Author

Tanmay Bhosle

Built under the TrailBox ecosystem.

