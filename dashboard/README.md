# TVMS Dashboard

This directory contains the web dashboard for the TVMS project.

The dashboard provides real-time monitoring of sensor data and device connectivity using MQTT communication.

## Features

* Real-time LDR Monitoring
* Real-time Temperature Monitoring
* Real-time Humidity Monitoring
* MQTT-based live updates
* Responsive user interface
* Device status visualization
* Device heartbeat monitoring
* Online/Offline device detection
* Live activity feed
* Automatic status updates

---

## MQTT Topics

### Sensor Data

```text
talktrail/vehicle/ldr
talktrail/vehicle/temp
talktrail/vehicle/humidity
```

Receives live sensor values from the ESP32 MQTT Gateway.

### Device Status

```text
talktrail/vehicle/status
```

Receives heartbeat messages used for device health monitoring.

Payload:

```text
online
```

---

## Dashboard Components

### Sensor Cards

* Current LDR Value
* Current Temperature
* Current Humidity
* Real-time updates

### Device Information

* Device identification
* MQTT connection status
* Device online/offline status
* Last update timestamp

### Activity Feed

Displays combined sensor updates in the format:

```text
LDR:2 | TEMP:30.8 | HUM:61
```

with timestamped entries.

---

## Online/Offline Detection

The dashboard monitors heartbeat messages published by the ESP32 MQTT Gateway.

Heartbeat Interval:

```text
5 Seconds
```

Offline Timeout:

```text
10 Seconds
```

Status Indicators:

```text
🟢 Online
🔴 Offline
```

When the device goes offline:

```text
LDR  -> --
TEMP -> --
HUM  -> --
```

---

## Technologies

* HTML5
* CSS3
* JavaScript
* MQTT.js

---

## Communication Flow

```text
STM32F407
   │
   ▼
ESP32 MQTT Gateway
   │
   ▼
HiveMQ Cloud
   │
   ▼
TVMS Dashboard
```

---

## Version

TVMS V2.0.0

## Status

Stable Release

## Author

Tanmay Bhosle

TrailBox Vehicle Monitoring System (TVMS)

