# TVMS Architecture

## Overview

TVMS (TrailBox Vehicle Monitoring System) is an IoT-based monitoring platform designed to collect sensor data, transmit it through a cloud communication layer and visualize it on a real-time dashboard.

---

## V1 Architecture

```text
Sensor
  │
  ▼
STM32F407
  │ UART
  ▼
ESP32
  │ MQTT
  ▼
HiveMQ Cloud
  │
  ▼
Web Dashboard
```

---

## Component Responsibilities

### STM32F407

Responsibilities:

* Sensor interfacing
* ADC data acquisition
* Data processing
* UART transmission

---

### ESP32

Responsibilities:

* Receive data from STM32
* Connect to WiFi
* Publish data to MQTT broker

---

### HiveMQ Cloud

Responsibilities:

* MQTT message broker
* Real-time message delivery
* Device communication layer

---

### Web Dashboard

Responsibilities:

* Subscribe to MQTT topics
* Display live sensor values
* Provide monitoring interface

---

## Data Flow

1. Sensor value is read by STM32.
2. STM32 sends the value to ESP32 using UART.
3. ESP32 publishes the value to HiveMQ Cloud.
4. Dashboard subscribes to the MQTT topic.
5. Live value is displayed to the user.

---

## Current Version

TVMS V1.0

Implemented:

* STM32 UART communication
* ESP32 MQTT publishing
* HiveMQ Cloud integration
* Real-time dashboard

---

## Future Architecture

### V2

* Multiple sensors
* Improved security
* Multiple devices

### V3

* Database integration
* Historical analytics

### V4

* CAN communication
* Multiple STM32 nodes

### V5

* Production-ready vehicle monitoring platform

