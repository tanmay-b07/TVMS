# TVMS Dashboard

This directory contains the web dashboard for the TVMS project.

The dashboard provides real-time monitoring of sensor data and device connectivity using MQTT communication.

## Features

* Real-time sensor monitoring
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
```

Receives live LDR sensor values from the ESP32 gateway.

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

### Main Display

* Current LDR value
* Real-time updates

### Device Information

* Device identification
* MQTT connection status
* Device online/offline status
* Last update timestamp

### Activity Feed

* Live MQTT message feed
* Recent sensor updates

---

## Online/Offline Detection

The dashboard monitors heartbeat messages published by the ESP32 gateway.

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

---

## Technologies

* HTML
* CSS
* JavaScript
* MQTT.js

---

## Version

TVMS V1.0.2

## Status

Stable Release

## Author

Tanmay Bhosle

TrailBox Vehicle Monitoring System (TVMS)

