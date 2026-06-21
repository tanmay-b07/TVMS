# STM32 Firmware

This directory contains the STM32F407 firmware source code used in the TVMS project.

## Contents

* Core source files
* STM32 HAL drivers
* CubeMX project configuration (.ioc)

## Function

The STM32F407 is responsible for:

* Reading LDR sensor values using ADC
* Reading DHT11 temperature and humidity data
* Processing sensor data
* Generating periodic sensor updates using hardware timers
* Transmitting formatted sensor data to ESP32 through UART

## Sensor Data Format

The STM32 sends sensor data in the following format:

```text
LDR:<value>,TEMP:<value>,HUM:<value>
```

Example:

```text
LDR:3,TEMP:30.8,HUM:61
```

## Features

* Non-blocking ADC acquisition using Timer Trigger
* DHT11 Temperature Monitoring
* DHT11 Humidity Monitoring
* UART Communication with ESP32
* Hardware Timer Based Sampling
* Real-Time Sensor Data Processing

## Development Environment

* STM32CubeIDE
* STM32CubeMX
* STM32 HAL Library
* STM32F407 Discovery Board

## Hardware Used

* STM32F407 Discovery
* LDR Sensor Module
* DHT11 Temperature & Humidity Sensor
* ESP32 Dev Board

## System Architecture

STM32F407 → UART → ESP32 → MQTT → Dashboard

## Version

TVMS V2.0.0

