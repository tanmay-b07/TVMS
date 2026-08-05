# TVMS Dashboard

The TVMS Dashboard provides real-time visualization of sensor data received from the embedded system.

It communicates with the Flask backend using REST APIs and displays live sensor values, historical charts and device status.

---

# Version

Current Version: **V4.0.0**

Status: **In Development**

---

# Overview

The dashboard is the user interface of the TrailBox Vehicle Monitoring System (TVMS).

It periodically requests live sensor data from the Flask server and presents the information through interactive cards and charts.

---

# Features

- Real-Time Sensor Monitoring
- Device Online / Offline Status
- Temperature & Humidity Display
- Pressure Monitoring
- Battery Voltage & Current Monitoring
- 3-Axis Accelerometer Visualization
- Historical Data Charts
- Automatic Live Refresh
- Responsive User Interface

---

# Technology Stack

- HTML5
- CSS3
- JavaScript
- Bootstrap 5
- Chart.js
- Flask REST API

---

# Communication Flow

```text
STM32 TX
      │
CAN Bus
      │
STM32 RX
      │
UART
      │
ESP32 Gateway
      │
MQTT Broker
      │
Flask Backend
      │
REST APIs
      │
Dashboard
```

---

# REST API Endpoints

## Live Sensor Data

```text
GET /api/live
```

Returns

- Device Status
- Temperature
- Humidity
- Pressure
- Battery Voltage
- Battery Current
- Accelerometer Values

---

## Temperature History

```text
GET /api/temp
```

---

## Pressure History

```text
GET /api/pressure
```

---

## Battery History

```text
GET /api/battery
```

---

## Accelerometer History

```text
GET /api/accel
```

---

# Dashboard Components

## Navigation Bar

Displays

- TVMS Title
- System Clock
- Device Status

---

## Live Sensor Cards

- Temperature
- Humidity
- Pressure
- Battery Voltage
- Battery Current
- Accelerometer

---

## Charts

- Temperature History
- Pressure History
- Battery History
- Accelerometer History

---

# Auto Refresh

The dashboard periodically requests live sensor data from the Flask backend to provide near real-time updates.

---

# Project Structure

```text
dashboard/

├── index.html
├── static/
│   ├── css/
│   │   └── style.css
│   ├── js/
│   │   └── script.js
│   └── images/
└── README.md
```

---

# Screenshots

Dashboard screenshots are available in the project's `screenshots/` directory.

---

# Future Enhancements

- Dark Mode
- Multi-Device Dashboard
- Live CAN Traffic Monitor
- Historical Analytics
- User Authentication
- Alarm & Notification System
- Export Sensor Data
- Mobile Responsive Improvements

---

# Author

**Tanmay Bhosle**

Electronics & Telecommunication Engineer

TrailBox Vehicle Monitoring System (TVMS)

Built under the **TrailBox** ecosystem.
