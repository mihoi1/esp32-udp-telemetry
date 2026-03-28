# ESP32 Real-Time UDP Telemetry System

A wireless telemetry system built on ESP32 using PlatformIO, transmitting 
real-time sensor data over UDP to a Python server at ~15 packets/sec.

## How It Works

The ESP32 reads two physical sensors and transmits the data wirelessly:
- **Potentiometer** (pin 36) — mapped to throttle percentage via 12-bit ADC (0–100%)
- **Ultrasonic sensor HC-SR04** (pins 5/18) — distance measurement via GPIO
- Data is packed in the format `ACCEL:XX%,DIST:XXcm` and sent over UDP
- Python server listens on port 4210 and displays data live in the terminal

## Packet Format
```
ACCEL:75%,DIST:30cm
```

## Hardware

| Component | Pin |
|-----------|-----|
| Potentiometer | GPIO 36 (ADC) |
| HC-SR04 Trig | GPIO 5 |
| HC-SR04 Echo | GPIO 18 |

## Build & Run

**Firmware (ESP32):** open in PlatformIO, configure WiFi credentials, upload.

**Python server:**
```bash
python telemetrie.py
```
