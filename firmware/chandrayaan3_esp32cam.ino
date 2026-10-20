```cpp
// ==========================================
// CHANDRAYAAN-3 6WD ROVER & LANDER REPLICA
// ESP32-CAM Vision, Telemetry & Motor Control
// Developer: Aditya Kumar Gupta (aditya.geninfo.in)
// ==========================================

#include "esp_camera.h"
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>

// Motor Pins (6WD Skid Steer via L298N in 2 Parallel Banks)
#define IN1 12
#define IN2 13
#define IN3 14
#define IN4 15

// Software I2C Pins on ESP32-CAM free pins
#define I2C_SDA 2
#define I2C_SCL 4

// Ultrasonic & DHT11 Pins
#define TRIG_PIN 16
#define ECHO_PIN 3
#define DHT_PIN  1
#define DHTTYPE  DHT11

Adafruit_BMP280 bmp;
DHT dht(DHT_PIN, DHTTYPE);

long readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 25000);
  return duration == 0 ? 999 : duration * 0.034 / 2;
}

void driveRover(int l1, int l2, int r1, int r2) {
  digitalWrite(IN1, l1); digitalWrite(IN2, l2);
  digitalWrite(IN3, r1); digitalWrite(IN4, r2);
}

void setup() {
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT); pinMode(ECHO_PIN, INPUT);

  Wire.begin(I2C_SDA, I2C_SCL);
  bmp.begin(0x76);
  dht.begin();
}

void loop() {
  long dist = readDistanceCM();
  float pressure_hPa = bmp.readPressure() / 100.0F;
  float temp_C = dht.readTemperature();

  // Autonomous Crater/Obstacle Avoidance Routine
  if (dist < 20) {
    driveRover(LOW, HIGH, LOW, HIGH); // Reverse
    delay(400);
    driveRover(HIGH, LOW, LOW, HIGH); // Pivot Turn
    delay(350);
  } else {
    driveRover(HIGH, LOW, HIGH, LOW); // Forward 6WD Crawl
  }
  delay(100);
}
