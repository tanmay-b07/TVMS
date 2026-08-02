# Hardware Connections

## Overview

This document describes the hardware connections used in the TrailBox Vehicle Monitoring System (TVMS).

The system consists of two STM32F407 Discovery boards communicating over a CAN bus using CJMCU-2551 CAN transceiver modules. The STM32 RX node forwards the received sensor data to the ESP32 gateway through UART.

---

# System Hardware

## STM32 TX Node

- STM32F407 Discovery
- CJMCU-2551 CAN Transceiver
- DHT22 Temperature & Humidity Sensor
- INA219 Current & Voltage Sensor
- HX710B Pressure Sensor
- LIS3DSH 3-Axis Accelerometer (On-board)

---

## STM32 RX Node

- STM32F407 Discovery
- CJMCU-2551 CAN Transceiver

---

## Gateway

- ESP32 DevKit (ESP-WROOM-32)

---

# System Architecture

```text
DHT22
INA219
HX710B
LIS3DSH
      │
      ▼
 STM32 TX
      │
Built-in CAN
      │
CJMCU-2551
══════════ CAN Bus ══════════
CJMCU-2551
      │
 STM32 RX
      │
 UART
      │
 ESP32
```

---

# Sensor Connections

## DHT22

| DHT22 | STM32 TX |
|--------|----------|
| VCC | 3.3V |
| GND | GND |
| DATA | PA1 |

---

## INA219

| INA219 | STM32 TX |
|---------|----------|
| VCC | 3.3V |
| GND | GND |
| SCL | PB6 |
| SDA | PB7 |

---

## HX710B

| HX710B | STM32 TX |
|---------|----------|
| VCC | 3.3V |
| GND | GND |
| DT | PD12 |
| SCK | PD13 |

---

## LIS3DSH (On-board)

| LIS3DSH | STM32 TX |
|----------|----------|
| SCK | PA5 |
| MISO | PA6 |
| MOSI | PA7 |
| CS | PE3 |

---

# CAN Connections

## STM32 TX ↔ CJMCU-2551

| STM32 TX | CJMCU-2551 |
|-----------|------------|
| PB9 (CAN_TX) | TXD |
| PB8 (CAN_RX) | RXD |
| 5V | VCC |
| GND | GND |

---

## STM32 RX ↔ CJMCU-2551

| STM32 RX | CJMCU-2551 |
|-----------|------------|
| PB9 (CAN_TX) | TXD |
| PB8 (CAN_RX) | RXD |
| 5V | VCC |
| GND | GND |

---

## CAN Bus

| Line | Connection |
|------|------------|
| CANH | CANH ↔ CANH |
| CANL | CANL ↔ CANL |
| GND | Common Ground |

---

# UART Connection

## STM32 RX ↔ ESP32

| STM32 RX | ESP32 |
|-----------|-------|
| PA2 (USART2_TX) | GPIO16 (RX2) |
| PA3 (USART2_RX) | GPIO17 (TX2) |
| GND | GND |

---

# Communication Summary

| Interface | Connected Device |
|------------|------------------|
| GPIO | DHT22 |
| GPIO | HX710B |
| I2C | INA219 |
| SPI | LIS3DSH |
| CAN | CJMCU-2551 |
| UART | ESP32 |

---

# Current Status

Current Release

**TVMS V3.3.0**

Implemented

- Multi-sensor hardware integration
- STM32 TX node
- STM32 RX node
- CAN communication
- UART forwarding

---

# Author

**Tanmay Bhosle**

TrailBox Vehicle Monitoring System (TVMS)

Built under the TrailBox ecosystem.
