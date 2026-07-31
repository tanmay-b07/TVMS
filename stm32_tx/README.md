# STM32 TX Node

The STM32 TX node is responsible for multi-sensor data acquisition and CAN message transmission in the TrailBox Vehicle Monitoring System (TVMS).

It acquires sensor data, processes the readings and transmits CAN frames to the STM32 RX node over the CAN bus.

---

## Version

Current Version: **V3.2.0**

Status: **Released**

---

## Overview

The STM32 TX firmware serves as the data acquisition unit of TVMS.

This release completes the STM32 TX node by integrating all supported sensors, implementing CAN frame generation and preparing the firmware for communication with the STM32 RX node.

---

## Hardware

- STM32F407 Discovery
- CJMCU-2551 CAN Transceiver Module
- DHT22 Temperature & Humidity Sensor
- INA219 Current & Voltage Sensor
- HX710B Pressure Sensor
- LIS3DSH 3-Axis Accelerometer (On-board)

---

## Communication Interfaces

| Interface | Device |
|-----------|--------|
| GPIO | DHT22 |
| GPIO | HX710B |
| I2C | INA219 |
| SPI | LIS3DSH |
| CAN | CJMCU-2551 |

---

## Project Structure

```text
stm32_tx/

├── Core/
├── Drivers/
├── Drivers_Custom/
│   ├── dht22/
│   ├── hx710b/
│   ├── ina219/
│   └── lis3dsh/
├── README.md
└── tx.ioc
```

---

## V3.2 Highlights

### Added

- Complete sensor integration
- DHT22 integration
- INA219 integration
- HX710B integration
- LIS3DSH integration
- Sensor initialization framework
- CAN frame generation
- CAN message transmission
- STM32 TX firmware completion

### Improved

- Driver integration
- Sensor scheduling
- Firmware architecture
- Code organization
- CAN transmission reliability

---

## Data Flow

```text
DHT22
INA219
HX710B
LIS3DSH
      │
      ▼
STM32F407
      │
Sensor Drivers
      │
Sensor Integration
      │
Data Processing
      │
CAN Frame Generation
      │
Built-in CAN Peripheral
      │
CJMCU-2551
      │
CAN Bus
      │
STM32 RX Node
```

---

## Current Status

✅ Sensor drivers completed

✅ Sensor integration completed

✅ CAN frame generation completed

✅ STM32 TX firmware completed

---

## Upcoming (V3.3)

- STM32 RX firmware
- CAN message reception
- CAN frame decoding
- UART communication to ESP32
- TX-RX communication testing

---

## Author

**Tanmay Bhosle**

TrailBox Vehicle Monitoring System (TVMS)

Built under the TrailBox ecosystem.
