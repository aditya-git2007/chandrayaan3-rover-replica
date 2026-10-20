# Chandrayaan-3 Replica — Wiring & Pin-Multiplexing Specifications

## ⚡ Power & Subsystem Architecture
* **Core Processing:** AI-Thinker ESP32-CAM mounted on the rover deck, handling both wireless FPV video streaming and rover telemetry/locomotion.
* **Drivetrain Power:** Dual power rail setup—Battery pack supplies power through the L298N H-Bridge for the 6WD motor banks, while regulated 5V/3.3V supplies logic power to the ESP32-CAM and sensors.
* **Harvesting:** 6V active solar panel array connected via a TP4056 module for autonomous battery replenishment.

---

## 📌 Complete GPIO Pin-Multiplexing Table (`ESP32-CAM`)
Because the OV2640 camera module utilizes a significant portion of the ESP32-CAM pins, the microSD slot is left unused to free up the following headers for sensors and motors:

| Subsystem / Sensor | Component Pin | ESP32-CAM Pin | Engineering Function |
| :--- | :--- | :--- | :--- |
| **6WD Left Motor Bank (3x)** | `L298N IN1 / IN2` | `GPIO 12` / `GPIO 13` | Left Rocker-Bogie Skid-Steer Drive |
| **6WD Right Motor Bank (3x)**| `L298N IN3 / IN4` | `GPIO 14` / `GPIO 15` | Right Rocker-Bogie Skid-Steer Drive |
| **BMP280 Pressure Sensor** | `SDA` / `SCL` | `GPIO 2` / `GPIO 4` | Software I2C Barometric & Altitude Bus |
| **HC-SR04 Ultrasonic Sensor**| `TRIG` / `ECHO` | `GPIO 16` / `GPIO 3 (RX)` | Front Obstacle Ranging |
| **SG90 Radar Pan Servo** | `PWM Signal` | `GPIO 0` (Post-Boot) | 180° Sensor Mast Scanning |
| **DHT11 Thermal Sensor** | `DATA` | `GPIO 1 (TX)` | Surface Ambient Temperature Telemetry |
| **Solar Panel Array (6V)** | `Positive (+)` | `TP4056 Charging Rail` | Autonomous Solar Battery Replenishment |
