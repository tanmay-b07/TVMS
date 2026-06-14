# TVMS - TrailBox Vehicle Monitoring System

TVMS (TrailBox Vehicle Monitoring System) is a real-time IoT monitoring platform built using STM32F407, ESP32, MQTT and a web dashboard.

The project demonstrates end-to-end sensor data acquisition, cloud communication and real-time visualization. This release serves as the foundation for future CAN-based vehicle telemetry and monitoring systems.

---

## Version

Current Release: **V1.0.0**

Status: **Released**

---

## Features

* STM32F407 sensor data acquisition
* UART communication between STM32 and ESP32
* ESP32 MQTT publishing
* HiveMQ Cloud integration
* Real-time dashboard
* Live sensor monitoring
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

---

## Project Structure

```text
TVMS/

├── stm32/
├── esp32/
├── dashboard/
├── screenshots/
├── docs/
└── README.md
```

---

## Implemented in V1.0

* Sensor value acquisition using STM32 ADC
* UART communication
* ESP32 MQTT gateway
* Cloud connectivity through HiveMQ
* Real-time dashboard updates

---

## Roadmap

### V2.0

* Multiple sensor support
* Improved dashboard UI
* Secure credential handling
* Non-blocking architecture

### V3.0

* Database integration
* Historical data storage
* Charts and analytics

### V4.0

* CAN bus communication
* Multiple STM32 nodes
* Vehicle telemetry network

### V5.0

* Production-ready TVMS platform
* Advanced analytics
* Alerts and notifications
* Complete vehicle monitoring ecosystem

---

## Author

Tanmay Bhosle

Built under the TalkTrail / TrailBox ecosystem.
