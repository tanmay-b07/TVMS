# TVMS - TrailBox Vehicle Monitoring System

TVMS (TrailBox Vehicle Monitoring System) is a modular real-time vehicle monitoring platform built using STM32F407, CAN Bus, ESP32, MQTT and Flask.

The project demonstrates end-to-end embedded communication, sensor data acquisition, CAN-based networking, wireless MQTT communication and real-time dashboard visualization. TVMS is designed as a scalable platform for future vehicle telemetry and fleet monitoring applications.

---

# Version

Current Release: **V3.1.0**

Status: **Released**

---

# Features

- Modular sensor driver architecture
- DHT22 driver
- INA219 driver
- HX710B driver
- LIS3DSH driver
- STM32 TX project architecture
- Custom reusable driver library
- Multi-sensor platform foundation
- CAN-ready firmware architecture
- Non-blocking firmware design
- Timer-based processing
- MQTT-ready architecture
- Real-time IoT platform

---

# System Architecture

```text
Sensors (SPI / I2C / Digital)
        │
        ▼
 STM32F407 (TX Node)
        │
 Built-in CAN Peripheral
        │
 CJMCU-2551 CAN Transceiver
        │
============= CAN Bus =============
        │
 CJMCU-2551 CAN Transceiver
        │
 STM32F407 (RX Node)
        │
 UART
        │
 ESP32 Gateway
        │
 MQTT Broker
        │
 Flask Dashboard
        │
 Android Application
```

---

# Technology Stack

## Hardware

- STM32F407 Discovery
- ESP32 DevKit
- CJMCU-2551 CAN Transceiver
- DHT22 Sensor
- INA219 Current & Voltage Monitor
- HX710B Pressure Sensor
- LIS3DSH Accelerometer

## Software

- STM32CubeIDE
- STM32CubeMX
- Arduino IDE
- Embedded C (STM32 HAL)
- MQTT
- HiveMQ / Mosquitto
- HTML
- CSS
- JavaScript
- Flask
- SQLite
- MIT App Inventor

---

# Project Structure

```text
TVMS/

├── app/
│   ├── TVMS.apk
│   ├── screenshots/
│   └── README.md
│
├── stm32_tx/
│   ├── Core/
│   ├── Drivers/
│   ├── Drivers_Custom/
│   │   ├── dht22/
│   │   ├── hx710b/
│   │   ├── ina219/
│   │   └── lis3dsh/
│   └── README.md
│
├── esp32/
│
├── dashboard/
│
├── docs/
│
├── screenshots/
│
└── README.md
```

---

# Implemented Features

## V3.1.0

### Added

- Modular sensor driver architecture
- DHT22 driver
- INA219 driver
- HX710B driver
- LIS3DSH driver
- STM32 TX project structure
- Custom driver library
- Reusable firmware architecture

### Improved

- Code organization
- Driver modularity
- Firmware scalability
- Project maintainability

---

## V2.0.0

- Multi-sensor monitoring
- Temperature monitoring
- Humidity monitoring
- Dedicated MQTT topics
- Enhanced dashboard
- Activity feed
- Improved firmware
- ESP32 MQTT gateway

---

## V1.0.3

- Non-blocking firmware
- Timer scheduling
- Firmware optimization

---

## V1.0.2

- Device heartbeat monitoring
- Online / Offline detection

---

## V1.0.1

- Android companion application

---

## V1.0.0

- STM32 ADC acquisition
- UART communication
- ESP32 MQTT gateway
- HiveMQ integration
- Live dashboard

---

# Release History

## V3.1.0 — Modular Sensor Driver Library

### Added

- DHT22 driver
- INA219 driver
- HX710B driver
- LIS3DSH driver
- STM32 TX firmware architecture
- Custom driver library
- Project restructuring

### Improved

- Driver modularity
- Firmware organization
- Reusable embedded architecture

### No Changes

- ESP32 firmware
- MQTT communication
- Dashboard
- Android application

---

# Roadmap

## V3.2

- Sensor integration
- STM32 TX firmware
- CAN message generation

## V3.3

- STM32 RX firmware
- CAN communication
- TX-RX integration

## V4.0

- ESP32 gateway
- MQTT communication
- Flask backend
- SQLite database
- Dashboard
- Android application

## V5.0

- Production-ready TVMS platform
- Vehicle telemetry
- Fleet monitoring
- Alerts & notifications
- Advanced analytics

---

# Live Dashboard

https://v1dashboard.trailbox.in/release2.html

---

# Author

**Tanmay Bhosle**

Built under the **TrailBox** ecosystem.
