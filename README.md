# chandrayaan3-rover-replica
Live working replica of Chandrayaan-3 Vikram Lander &amp; 6WD Pragyan Rover powered by ESP32-CAM.
# 🚀 Chandrayaan-3 Working Replica (Vikram Lander & 6WD Pragyan Rover)

> An advanced, solar-powered miniature robotic rover and lander system featuring live ESP32-CAM video streaming, differential 6-wheel-drive (6WD) mobility, and multi-sensor environmental telemetry.

[![Status](https://img.shields.io/badge/Status-Completed-emerald?style=for-the-badge)]()
[![MCU](https://img.shields.io/badge/Controller-ESP32--CAM-blue?style=for-the-badge)]()

---

## 📋 Overview & Engineering Objectives
This project replicates ISRO's historic Chandrayaan-3 mission architecture. The rover is built around an **AI-Thinker ESP32-CAM**, which simultaneously streams real-time optical video feeds over Wi-Fi while processing local telemetry, managing solar power charging, and executing autonomous obstacle avoidance maneuvers.

---

## 🛠️ Bill of Materials (BOM)
| Component | Specification / Role |
| :--- | :--- |
| **AI-Thinker ESP32-CAM** | Dual-core Tensilica MCU + OV2640 Camera Module (Vision & Control Core) |
| **6x BO Gear Motors** | Arranged in 2 parallel groups (3 left, 3 right) for 6WD skid-steer mobility |
| **L298N Dual H-Bridge Driver** | High-current motor driver for differential drive control |
| **BMP280 Sensor** | I2C Barometric Pressure & Altitude Telemetry |
| **DHT11 Sensor** | Surface Ambient Temperature & Humidity Tracking |
| **HC-SR04 + SG90 Servo** | Ultrasonic distance sensor mounted on a 180° pan servo for obstacle radar |
| **6V Solar Panel Bus** | Active solar energy harvesting and battery replenishment |
| **Power System** | 3.7V Li-Ion battery pack + TP4056 charging module |

---

## 📌 GPIO Pinout & Pin-Multiplexing Architecture
Because the OV2640 camera utilizes most of the ESP32-CAM's pins, the microSD card slot was disabled to free up critical pins for motor control and sensor integration:

| Subsystem / Sensor | Component Pin | ESP32-CAM Pin | Engineering Function |
| :--- | :--- | :--- | :--- |
| **6WD Left Motor Bank (3x)** | `L298N IN1 / IN2` | `GPIO 12` / `GPIO 13` | Left Rocker-Bogie Skid-Steer Drive |
| **6WD Right Motor Bank (3x)**| `L298N IN3 / IN4` | `GPIO 14` / `GPIO 15` | Right Rocker-Bogie Skid-Steer Drive |
| **BMP280 Pressure Sensor** | `SDA` / `SCL` | `GPIO 2` / `GPIO 4` | Software I2C Barometric & Altitude Bus |
| **HC-SR04 Ultrasonic Sensor**| `TRIG` / `ECHO` | `GPIO 16` / `GPIO 3 (RX)` | Front Obstacle Ranging |
| **SG90 Radar Pan Servo** | `PWM Signal` | `GPIO 0` (Post-Boot) | 180° Sensor Mast Scanning |
| **DHT11 Thermal Sensor** | `DATA` | `GPIO 1 (TX)` | Surface Ambient Temperature Telemetry |
| **Solar Panel Array (6V)** | `Positive (+)` | `TP4056 Charging Rail` | Autonomous Solar Battery Replenishment |

---

## 📂 Repository Structure
```text
📂 chandrayaan3-rover-replica
├── 📂 firmware             <-- ESP32-CAM C++ source code (chandrayaan3_esp32cam.ino)
├── 📂 schematics           <-- Pinout mapping & wiring architecture
└── 📄 README.md            <-- Project documentation
