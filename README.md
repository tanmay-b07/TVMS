# TVMS - TrailBox Vehicle Monitoring System

TVMS (TrailBox Vehicle Monitoring System) is a modular real-time vehicle
monitoring platform built using STM32F407, CAN Bus, ESP32, MQTT and
Flask.

The project demonstrates end-to-end embedded communication, multi-sensor
data acquisition, CAN-based networking and provides a scalable
foundation for future MQTT, Flask and dashboard integration.

------------------------------------------------------------------------

# Version

**Current Release:** V3.3.0

**Status:** Released

------------------------------------------------------------------------

# Features

-   Complete STM32 TX firmware
-   Complete STM32 RX firmware
-   Multi-sensor data acquisition
-   DHT22 integration
-   INA219 integration
-   HX710B integration
-   LIS3DSH integration
-   CAN frame generation
-   CAN message transmission
-   CAN message reception
-   CAN frame decoding
-   UART forwarding to ESP32
-   Modular sensor driver architecture
-   Custom reusable driver libraries
-   Non-blocking firmware design
-   Timer-based processing
-   End-to-end embedded communication framework

------------------------------------------------------------------------

# System Architecture

``` text
                 Sensors
(DHT22, INA219, HX710B, LIS3DSH)
                    │
                    ▼
          STM32F407 (TX Node)
                    │
         Built-in CAN Peripheral
                    │
       CJMCU-2551 CAN Transceiver
════════════════ CAN Bus ════════════════
       CJMCU-2551 CAN Transceiver
                    │
          STM32F407 (RX Node)
                    │
                 UART (USART2)
                    │
              ESP32 Gateway
                    │
          (MQTT / Flask - V4.0)
```

------------------------------------------------------------------------

# Technology Stack

## Hardware

-   STM32F407 Discovery
-   ESP32 DevKit
-   CJMCU-2551 CAN Transceiver
-   DHT22
-   INA219
-   HX710B
-   LIS3DSH

## Software (Current)

-   STM32CubeIDE
-   STM32CubeMX
-   Arduino IDE
-   Embedded C (STM32 HAL)

## Planned (V4.0)

-   MQTT
-   HiveMQ / Mosquitto
-   Flask
-   SQLite
-   HTML
-   CSS
-   JavaScript
-   MIT App Inventor

------------------------------------------------------------------------

# Project Structure

``` text
TVMS/
├── app/
├── dashboard/
├── docs/
│   ├── architecture.md
│   ├── can_protocol.md
│   ├── hardware_connections.md
│   └── pin_configuration.md
├── esp32/
├── stm32_tx/
├── stm32_rx/
├── screenshots/
└── README.md
```

------------------------------------------------------------------------

# Implemented Features

## V3.3.0

### Added

-   Complete STM32 RX firmware
-   CAN message reception
-   CAN frame decoding
-   UART forwarding to ESP32
-   End-to-end STM32 TX ↔ STM32 RX communication
-   Technical documentation
-   Hardware documentation
-   CAN protocol documentation
-   Pin configuration documentation

### Improved

-   Embedded communication framework
-   Firmware organization
-   Repository documentation
-   CAN communication reliability

------------------------------------------------------------------------

## V3.2.0

-   Complete STM32 TX firmware
-   Multi-sensor integration
-   CAN frame generation
-   CAN transmission

## V3.1.0

-   Modular sensor driver architecture
-   Custom driver library

## V2.0.0

-   Multi-sensor monitoring
-   ESP32 MQTT gateway
-   Dashboard improvements

## V1.x

-   UART communication
-   HiveMQ integration
-   Android companion app
-   Non-blocking firmware
-   Device heartbeat monitoring

------------------------------------------------------------------------

# Documentation

Available in `docs/`

-   System Architecture
-   CAN Communication Protocol
-   Hardware Connections
-   Pin Configuration

------------------------------------------------------------------------

# Roadmap

## V4.0

-   ESP32 Gateway
-   MQTT Communication
-   Flask Backend
-   SQLite Database
-   Live Dashboard
-   Android Application

## V5.0

-   Vehicle Telemetry
-   Fleet Monitoring
-   Alerts & Notifications
-   Advanced Analytics
-   OTA Firmware Updates

------------------------------------------------------------------------

# Repository Modules

## STM32 TX

-   Sensor acquisition
-   CAN frame generation
-   CAN transmission

## STM32 RX

-   CAN reception
-   CAN decoding
-   UART forwarding

## ESP32

-   UART reception
-   MQTT publishing (V4.0)

## Dashboard

-   Live monitoring (V4.0)

------------------------------------------------------------------------

# Live Dashboard

https://v1dashboard.trailbox.in/release2.html

------------------------------------------------------------------------

# Project Status

**Current Stage:** Embedded Communication Layer Completed

**Next Milestone:** V4.0 - ESP32 + MQTT + Flask + Dashboard

------------------------------------------------------------------------

# Author

**Tanmay Bhosle**

Electronics & Telecommunication Engineer

Embedded Systems \| STM32 \| CAN Bus \| ESP32 \| IoT

Built under the **TrailBox** ecosystem.
