# STM32 RX Node

The STM32 RX node is responsible for receiving CAN messages from the STM32 TX node, decoding sensor data and forwarding the processed information to the ESP32 gateway through UART.

It acts as the communication bridge between the CAN network and the IoT gateway within the TrailBox Vehicle Monitoring System (TVMS).

---

## Version

Current Version: **V3.3.0**

Status: **Released**

---

## Overview

The STM32 RX firmware serves as the communication receiver of TVMS.

This release completes the STM32 RX node by implementing CAN message reception, frame decoding and UART forwarding, enabling reliable communication between the embedded CAN network and the ESP32 gateway.

---

## Hardware

- STM32F407 Discovery
- CJMCU-2551 CAN Transceiver Module
- ESP32 DevKit (UART Interface)

---

## Communication Interfaces

| Interface | Device |
|-----------|--------|
| CAN | CJMCU-2551 |
| UART | ESP32 Gateway |

---

## Project Structure

```text
stm32_rx/

├── Core/
├── Drivers/
├── README.md
└── rx.ioc
```

---

## V3.3 Highlights

### Added

- STM32 RX firmware
- CAN message reception
- CAN frame decoding
- UART forwarding
- ESP32 communication interface
- TX-RX communication support

### Improved

- CAN communication reliability
- UART communication
- Firmware architecture
- Code organization
- Embedded communication framework

---

## Data Flow

```text
CAN Bus
    │
    ▼
CJMCU-2551
    │
Built-in CAN Peripheral
    │
STM32F407
    │
CAN Frame Decoder
    │
UART Packet Generator
    │
UART
    │
ESP32 Gateway
```

---

## Current Status

✅ STM32 RX firmware completed

✅ CAN message reception completed

✅ CAN frame decoding completed

✅ UART forwarding completed

✅ STM32 TX ↔ STM32 RX communication completed

---

## Upcoming (V4.0)

- ESP32 MQTT gateway
- MQTT publishing
- Flask backend
- SQLite database
- Dashboard integration
- Android application

---

## Author

**Tanmay Bhosle**

TrailBox Vehicle Monitoring System (TVMS)

Built under the TrailBox ecosystem.
