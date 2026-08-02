# Pin Configuration

## STM32 TX Node

### DHT22

| Signal | STM32 Pin |
|---------|-----------|
| DATA | PA1 |

---

### INA219 (I2C1)

| Signal | STM32 Pin |
|---------|-----------|
| SCL | PB6 |
| SDA | PB7 |

---

### HX710B

| Signal | STM32 Pin |
|---------|-----------|
| DT | PD12 |
| SCK | PD13 |

---

### LIS3DSH (SPI1)

| Signal | STM32 Pin |
|---------|-----------|
| SCK | PA5 |
| MISO | PA6 |
| MOSI | PA7 |
| CS | PE3 |

---

### CAN1

| Signal | STM32 Pin |
|---------|-----------|
| CAN_RX | PB8 |
| CAN_TX | PB9 |

---

## STM32 RX Node

### CAN1

| Signal | STM32 Pin |
|---------|-----------|
| CAN_RX | PB8 |
| CAN_TX | PB9 |

---

### UART (USART2)

| Signal | STM32 Pin |
|---------|-----------|
| TX | PA2 |
| RX | PA3 |

---

## ESP32 Gateway

| STM32 RX | ESP32 |
|-----------|--------|
| PA2 (USART2_TX) | GPIO16 (RX2) |
| PA3 (USART2_RX) | GPIO17 (TX2) |
| GND | GND |
