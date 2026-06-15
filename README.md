# TVMS - TrailBox Vehicle Monitoring System

TVMS (TrailBox Vehicle Monitoring System) is a real-time IoT monitoring platform built using STM32F407, ESP32, MQTT and a web dashboard.

The project demonstrates end-to-end sensor data acquisition, cloud communication and real-time visualization. This release serves as the foundation for future CAN-based vehicle telemetry and monitoring systems.

---

## Version

Current Release: **V1.0.1**

Status: **Released**

---

## Features

* STM32F407 sensor data acquisition
* UART communication between STM32 and ESP32
* ESP32 MQTT publishing
* HiveMQ Cloud integration
* Real-time dashboard
* Live sensor monitoring
* Android companion application
* Mobile dashboard access
* End-to-end IoT data flow

---

## System Architecture

```text
STM32F407
     │
     │ UART
     ▼
ESP32
     │
     │ MQTT
     ▼
HiveMQ Cloud
     │
     ▼
Web Dashboard
     │
     ▼
Android App
```

---

## Technology Stack

### Hardware

* STM32F407
* ESP32
* LDR Sensor

### Software

* STM32CubeIDE
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
* Mobile access to TVMS dashboard
* Improved monitoring accessibility

---

## Release History

### V1.0.1 - Android App Support

Added:

* Android companion application
* Mobile dashboard access

No changes:

* STM32 firmware
* ESP32 firmware
* MQTT architecture
* Dashboard functionality

### V1.0.0 - Initial IoT Monitoring Platform

* STM32 ADC acquisition
* UART communication
* ESP32 MQTT gateway
* HiveMQ Cloud integration
* Real-time dashboard
* GitHub documentation

---

## Roadmap

### V2.0

* Multiple sensor support
* Temperature monitoring
* Humidity monitoring
* Voltage monitoring
* Current monitoring
* Improved dashboard UI
* Secure credential handling
* Multi-device ready architecture

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

https://v1dashboard.trailbox.in/

---

## Author

Tanmay Bhosle

Built under the TrailBox ecosystem.
