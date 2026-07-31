# STM32 TX Node

The STM32 TX node is responsible for sensor data acquisition and CAN message transmission in the TrailBox Vehicle Monitoring System (TVMS).

This module acquires data from multiple sensors, processes the readings and prepares CAN frames for transmission over the CAN bus.

---

## Version

Current Version: **V3.1.0**

Status: **Development**

---

## Overview

The STM32 TX firmware serves as the data acquisition unit of TVMS. It interfaces with multiple sensors, collects real-time measurements and prepares them for transmission to the STM32 RX node.

This release introduces a modular driver architecture, making future sensor integration simpler, reusable and easier to maintain.

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

## V3.1 Highlights

### Added

- Modular sensor driver architecture
- DHT22 driver
- INA219 driver
- HX710B driver
- LIS3DSH driver
- Custom driver directory
- Independent reusable sensor libraries

### Improved

- Firmware modularity
- Code organization
- Driver reusability
- Project maintainability

---

## Data Flow

```text
Sensors
    │
    ▼
STM32F407
    │
Sensor Drivers
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

## Upcoming (V3.2)

- Sensor integration
- Multi-sensor data acquisition
- CAN frame generation
- STM32 TX firmware completion

---

## Author

**Tanmay Bhosle**

TrailBox Vehicle Monitoring System (TVMS)

Built under the TrailBox ecosystem.
