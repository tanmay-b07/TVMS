# TVMS Architecture

## Overview

TVMS (TrailBox Vehicle Monitoring System) is an IoT-based real-time monitoring platform designed to acquire sensor data using STM32, transmit it through ESP32 using MQTT, and visualize it on a live dashboard.

The platform supports environmental monitoring, device health monitoring and cloud-based data visualization.

---

## V2.0.0 Architecture

```text
LDR Sensor
      │
DHT11 Sensor
      │
      ▼
 STM32F407
      │ UART
      ▼
 ESP32 MQTT Gateway
      │ MQTT over TLS
      ▼
 HiveMQ Cloud
      │
      ▼
 TVMS Dashboard
```

---

## Component Responsibilities

### STM32F407

Responsibilities:

* LDR data acquisition using ADC
* DHT11 temperature monitoring
* DHT11 humidity monitoring
* Sensor data processing
* Hardware timer-based sampling
* UART communication with ESP32

Generated Data:

```text
LDR:3,TEMP:30.8,HUM:61
```

---

### ESP32 MQTT Gateway

Responsibilities:

* Receive sensor data through UART
* Parse sensor values
* Connect to WiFi
* Connect to HiveMQ Cloud
* Publish sensor values to MQTT topics
* Device heartbeat monitoring

Published Topics:

```text
talktrail/vehicle/ldr
talktrail/vehicle/temp
talktrail/vehicle/humidity
talktrail/vehicle/status
```

---

### HiveMQ Cloud

Responsibilities:

* MQTT message broker
* Secure device communication
* Real-time message delivery
* Dashboard integration

---

### TVMS Dashboard

Responsibilities:

* Subscribe to MQTT topics
* Display live sensor values
* Display device status
* Online/Offline monitoring
* Activity feed generation
* Real-time visualization

Dashboard Cards:

* LDR Monitoring
* Temperature Monitoring
* Humidity Monitoring
* Device Status
* MQTT Status

---

## Data Flow

1. STM32 reads LDR and DHT11 sensor data.
2. STM32 formats the sensor data string.
3. STM32 sends data to ESP32 through UART.
4. ESP32 parses the received data.
5. ESP32 publishes sensor values to MQTT topics.
6. HiveMQ Cloud distributes MQTT messages.
7. Dashboard receives updates and displays live values.

---

## MQTT Topics

```text
talktrail/vehicle/ldr
talktrail/vehicle/temp
talktrail/vehicle/humidity
talktrail/vehicle/status
```

---

## Current Version

TVMS V2.0.0

Implemented:

* LDR Monitoring
* Temperature Monitoring
* Humidity Monitoring
* UART Communication
* MQTT Integration
* Device Heartbeat Monitoring
* Online/Offline Detection
* Real-Time Dashboard
* Multi-Sensor Architecture

---

## Future Roadmap

### V3.0.0

* Historical Data Logging
* Database Integration
* Analytics Dashboard

### V4.0.0

* CAN Bus Integration
* Vehicle Telemetry
* Advanced Monitoring

### V5.0.0

* Multi-Vehicle Monitoring
* Fleet Dashboard
* Mobile Application Expansion

---

## Author

Tanmay Bhosle

TrailBox Vehicle Monitoring System (TVMS)

