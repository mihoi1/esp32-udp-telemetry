# ESP32 Real-Time UDP Telemetry System

A wireless telemetry system built on ESP32 using PlatformIO, transmitting 
real-time sensor data over UDP to a Python server at ~15 packets/sec.

## How It Works

The ESP32 reads two physical sensors and transmits the data wirelessly:
- **Potentiometer** (pin 36) - mapped to throttle percentage via 12-bit ADC (0–100%)
- **Ultrasonic sensor HC-SR04** (pins 5/18) - distance measurement via GPIO
- Data is packed in the format `ACCEL:XX%,DIST:XXcm` and sent over UDP
- Python server listens on port 4210 and displays data live in the terminal

## Hardware Setup

- **MCU:** ESP32
- **Inputs:** 
  - 1x Potentiometer (GPIO 36 - ADC input, throttle simulation)
  - 1x HC-SR04 Ultrasonic Sensor (Trig: GPIO 5, Echo: GPIO 18 - distance measurement)
- **Outputs:** Serial monitor (UART, 115200 baud) + UDP packets to host PC
  
## Configuration

Before uploading to your ESP32, open `main.cpp` and update these lines:
```cpp
const char* ssid = "your_wifi_ssid";       
const char* password = "your_wifi_password";       
const char* udpAddress = "your_pc_ip";
```

To find your PC's IP on Linux:
```bash
ip addr show
# or
hostname -I
```

## Build & Run

**Firmware (ESP32):** open in PlatformIO, configure credentials above, upload.

**Python server:**
```bash
python telemetrie.py
```

Make sure ESP32 and PC are on the same WiFi network.

## Packet Format
```
ACCEL:75%,DIST:30cm
```
