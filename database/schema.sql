DROP DATABASE IF EXISTS tvms;
CREATE DATABASE tvms;

USE tvms;

-- Temperature & Humidity

CREATE TABLE temperature_data (
    id INT AUTO_INCREMENT PRIMARY KEY,
    temperature FLOAT NOT NULL,
    humidity FLOAT NOT NULL,
    time TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Accelerometer

CREATE TABLE accelerometer_data (
    id INT AUTO_INCREMENT PRIMARY KEY,
    x INT NOT NULL,
    y INT NOT NULL,
    z INT NOT NULL,
    time TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Pressure

CREATE TABLE pressure_data (
    id INT AUTO_INCREMENT PRIMARY KEY,
    pressure INT NOT NULL,
    time TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Battery

CREATE TABLE battery_data (
    id INT AUTO_INCREMENT PRIMARY KEY,
    voltage FLOAT NOT NULL,
    current FLOAT NOT NULL,
    time TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
