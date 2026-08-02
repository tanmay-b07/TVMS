# CAN Communication Protocol

## Overview

The TVMS CAN protocol defines the communication between the STM32 TX node and STM32 RX node over the CAN bus.

The STM32 TX node acquires sensor data, packs the information into CAN frames and transmits it using the built-in CAN peripheral and CJMCU-2551 CAN transceiver.

The STM32 RX node receives the CAN frames, decodes the payload and forwards the processed data to the ESP32 gateway through UART.

---

# Network Architecture

```text
Sensors
    │
    ▼
STM32 TX
    │
Built-in CAN Peripheral
    │
CJMCU-2551
══════════ CAN Bus ══════════
CJMCU-2551
    │
STM32 RX
    │
UART
    ▼
ESP32 Gateway
```

---

# CAN Configuration

| Parameter | Value |
|-----------|-------|
| Protocol | CAN 2.0A |
| Identifier | Standard (11-bit) |
| Frame Type | Data Frame |
| DLC | Variable (3–6 Bytes) |

---

# CAN Message IDs

| CAN ID | Message | DLC |
|---------|---------|-----|
| 0xA9 | Temperature & Humidity | 4 |
| 0xAA | Pressure | 3 |
| 0xAB | Accelerometer (X,Y,Z) | 6 |
| 0xAC | Battery (Voltage & Current) | 4 |

---

# Payload Format

## Temperature & Humidity (0xA9)

| Byte | Description |
|------|-------------|
| 0 | Humidity Integer |
| 1 | Humidity Decimal |
| 2 | Temperature Integer |
| 3 | Temperature Decimal |

---

## Pressure (0xAA)

| Byte | Description |
|------|-------------|
| 0 | Pressure MSB |
| 1 | Pressure Mid |
| 2 | Pressure LSB |

---

## Accelerometer (0xAB)

| Byte | Description |
|------|-------------|
| 0 | X Low |
| 1 | X High |
| 2 | Y Low |
| 3 | Y High |
| 4 | Z Low |
| 5 | Z High |

---

## Battery (0xAC)

| Byte | Description |
|------|-------------|
| 0 | Voltage High |
| 1 | Voltage Low |
| 2 | Current High |
| 3 | Current Low |

---

# Communication Flow

```text
Sensor
    │
    ▼
Sensor Driver
    │
STM32 TX
    │
CAN Frame Generation
    │
CAN Bus
    │
STM32 RX
    │
Frame Decoding
    │
UART Packet
    │
ESP32 Gateway
```

---

# Error Handling

The STM32 CAN peripheral provides:

- CRC validation
- Bit error detection
- Acknowledgement checking
- Frame integrity verification

Application-level validation is performed by the STM32 RX node before forwarding data to the ESP32 gateway.

---

# Current Status

Current Release

**TVMS V3.3.0**

Implemented

- CAN initialization
- CAN transmission
- CAN reception
- Sensor frame encoding
- Sensor frame decoding
- UART forwarding

---

# Future Enhancements

## V4.0

- CAN filtering
- Error logging
- Diagnostic messages
- Vehicle telemetry support
- Extended monitoring

---

# Author

**Tanmay Bhosle**

TrailBox Vehicle Monitoring System (TVMS)

Built under the TrailBox ecosystem.
