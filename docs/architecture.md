# TVMS Architecture

## Overview

TVMS (TrailBox Vehicle Monitoring System) is a modular real-time vehicle monitoring platform designed around a distributed embedded architecture.

The system acquires sensor data using the STM32 TX node, transmits it over the CAN bus, receives and decodes the messages using the STM32 RX node, forwards the data to the ESP32 gateway through UART, publishes it via MQTT and visualizes the information using a Flask-based web dashboard and Android application.

---

## System Architecture

```text
                Sensors
 (DHT22, INA219, HX710B, LIS3DSH)
                     │
                     ▼
          ┌───────────────────┐
          │   STM32 TX Node   │
          │ Sensor Processing │
          │ CAN Frame Creator │
          └───────────────────┘
                     │
             Built-in CAN
                     │
           CJMCU-2551 Transceiver
                     │
════════════════ CAN Bus ════════════════
                     │
           CJMCU-2551 Transceiver
                     │
          ┌───────────────────┐
          │   STM32 RX Node   │
          │ CAN Frame Decode  │
          │ UART Forwarding   │
          └───────────────────┘
                     │
                    UART
                     │
                     ▼
          ┌───────────────────┐
          │   ESP32 Gateway   │
          │ MQTT Publisher    │
          └───────────────────┘
                     │
                 MQTT Broker
          (HiveMQ / Mosquitto)
                     │
                     ▼
          ┌───────────────────┐
          │   Flask Backend   │
          │ SQLite Database   │
          └───────────────────┘
                     │
          ┌──────────┴──────────┐
          ▼                     ▼
   Web Dashboard         Android Application
```

---

# Component Responsibilities

## STM32 TX Node

Responsibilities

- Initialize all sensors
- Read sensor values
- Process sensor data
- Generate CAN frames
- Transmit CAN messages

Connected Sensors

- DHT22
- INA219
- HX710B
- LIS3DSH

---

## STM32 RX Node

Responsibilities

- Receive CAN messages
- Decode CAN frames
- Process received data
- Generate UART packets
- Forward data to ESP32

---

## ESP32 Gateway

Responsibilities

- Receive UART data
- Connect to Wi-Fi
- Connect to MQTT broker
- Publish sensor values
- Device heartbeat monitoring

---

## MQTT Broker

Responsibilities

- Route MQTT messages
- Secure communication
- Real-time message delivery

Supported Brokers

- HiveMQ Cloud
- Eclipse Mosquitto

---

## Flask Backend

Responsibilities

- Subscribe to MQTT topics
- Process incoming sensor data
- Store data in SQLite
- Provide dashboard APIs

---

## Dashboard

Responsibilities

- Live sensor monitoring
- Device status monitoring
- Activity feed
- Historical charts
- Fleet monitoring (Future)

---

## Android Application

Responsibilities

- Mobile monitoring
- Device status
- Live sensor values
- Remote accessibility

---

# End-to-End Data Flow

1. Sensors acquire physical measurements.
2. STM32 TX reads and processes sensor data.
3. CAN frames are generated.
4. CAN frames are transmitted over the CAN bus.
5. STM32 RX receives and decodes CAN frames.
6. UART forwards decoded data to ESP32.
7. ESP32 publishes sensor data using MQTT.
8. MQTT broker distributes messages.
9. Flask backend processes incoming data.
10. Dashboard and Android application display live sensor values.

---

# Current Architecture

Current Release

**TVMS V3.3.0**

Implemented

- STM32 TX firmware
- STM32 RX firmware
- Multi-sensor acquisition
- CAN communication
- UART forwarding
- ESP32 gateway
- MQTT-ready architecture

---

# Future Enhancements

## V4.0

- Flask backend
- SQLite database
- Historical data logging
- Dashboard analytics
- Android integration

## V5.0

- Production-ready TVMS platform
- Multi-node CAN network
- Vehicle telemetry
- Fleet monitoring
- Alerts & Notifications

---

# Author

**Tanmay Bhosle**

TrailBox Vehicle Monitoring System (TVMS)

Built under the TrailBox ecosystem.
