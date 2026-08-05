# TVMS Server

The TVMS Server is responsible for collecting sensor data from the MQTT broker, storing it in the database and providing REST APIs for the dashboard.

It acts as the backend layer of the TrailBox Vehicle Monitoring System (TVMS).

---

# Version

Current Version: **V4.0.0**

Status: **In Development**

---

# Responsibilities

- Subscribe to MQTT topics
- Receive real-time sensor data
- Store sensor data in MySQL
- Maintain latest live sensor values
- Track device Online / Offline status
- Provide REST APIs for the dashboard
- Serve historical sensor data

---

# Folder Structure

```text
server/

├── app.py
├── mqtt_client.py
├── database.py
├── requirements.txt
└── README.md
```

---

# Architecture

```text
ESP32 Gateway
        │
        ▼
 MQTT Broker
        │
        ▼
 mqtt_client.py
        │
        ├── Update Live Values
        ├── Store MySQL Data
        │
        ▼
     app.py
        │
 REST API Endpoints
        │
        ▼
 Dashboard
```

---

# Components

## app.py

Responsible for

- Flask Server
- Dashboard APIs
- Historical APIs
- Launching MQTT background thread

---

## mqtt_client.py

Responsible for

- MQTT Connection
- Topic Subscription
- JSON Parsing
- Online / Offline Detection
- Database Logging
- Latest Sensor Values

---

## database.py

Responsible for

- MySQL Connection
- Database Cursor
- Shared Database Access

---

# REST API Endpoints

## Live Data

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

# MQTT Topics

```text
talktrail/vehicle/temp
talktrail/vehicle/accel
talktrail/vehicle/pressure
talktrail/vehicle/battery
talktrail/vehicle/status
```

---

# Database

The server stores all received sensor data into MySQL.

Tables

- temperature_data
- accelerometer_data
- pressure_data
- battery_data

---

# Features

- Flask REST API
- MQTT Subscriber
- MySQL Logging
- Real-Time Data Updates
- Online / Offline Monitoring
- Historical Data Storage
- Multi-Sensor Support

---

# Development Environment

- Python 3
- Flask
- Paho MQTT
- MySQL Connector
- Mosquitto MQTT Broker
- MySQL Server

---

# Run

Install dependencies

```bash
pip install -r requirements.txt
```

Start the server

```bash
python app.py
```

The Flask server starts on

```text
http://localhost:5000
```

---

# Future Enhancements

- Authentication
- MQTT over TLS
- Cloud Database Support
- Docker Deployment
- REST API Authentication
- WebSocket Support

---

# Author

**Tanmay Bhosle**

TrailBox Vehicle Monitoring System (TVMS)

Built under the **TrailBox** ecosystem.
