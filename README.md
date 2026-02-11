# 🌍 Smart Environmental Monitoring System using ESP32 & Blynk IoT

An IoT-based Environmental Monitoring System built using **ESP32**, **DHT11**, and **MQ-2 Gas Sensor**.  
This project monitors Temperature, Humidity, and Gas levels in real-time and displays the data on the **Blynk IoT Mobile App** using cloud connectivity.

---

## 🚀 Project Overview

This system collects environmental data and sends it to the Blynk IoT Cloud using WiFi.  
Users can monitor live readings from anywhere using the Blynk mobile application.

---

## 📌 Features

- 🌡 Real-time Temperature Monitoring (°C)
- 💧 Real-time Humidity Monitoring (%)
- 🔥 Gas Detection (LPG, Methane, Smoke, Hydrogen)
- 📲 Mobile App Monitoring (Blynk IoT)
- ☁️ Cloud-Based Data Transmission
- 📊 Live Gauge and Value Display
- ⚡ Low Power IoT Solution

---

## 🛠 Hardware Components

- ESP32 Development Board
- DHT11 Temperature & Humidity Sensor
- MQ-2 Gas Sensor
- Breadboard
- Jumper Wires
- USB Cable / 5V Power Supply

---

## 🔌 Pin Connections

### DHT11 Sensor
| DHT11 Pin | ESP32 Pin |
|-----------|-----------|
| VCC       | 3.3V      |
| GND       | GND       |
| DATA      | GPIO 4    |

### MQ-2 Gas Sensor
| MQ-2 Pin | ESP32 Pin |
|----------|-----------|
| VCC      | 5V        |
| GND      | GND       |
| A0       | GPIO 34   |

---

## 📱 Blynk IoT Configuration

Create a Template in **Blynk IoT Cloud** and add the following Datastreams:

| Parameter     | Virtual Pin | Unit |
|--------------|------------|------|
| Temperature  | V0         | °C   |
| Humidity     | V1         | %    |
| Gas Value    | V2         | Raw Value (0–4095) |

Add Gauge widgets in the Blynk mobile app and link them to respective Virtual Pins.

Replace the following in code:
- `BLYNK_TEMPLATE_ID`
- `BLYNK_TEMPLATE_NAME`
- `BLYNK_AUTH_TOKEN`
- WiFi SSID & Password

---

## 📊 Gas Types Detected (MQ-2)

The MQ-2 sensor can detect:

- LPG
- Methane (CH₄)
- Hydrogen (H₂)
- Smoke
- Propane

⚠️ Note: The MQ-2 provides analog values (0–4095). For accurate PPM measurement, proper calibration is required.

---

## 🧠 Working Principle

1. ESP32 reads temperature and humidity from DHT11.
2. ESP32 reads gas concentration (analog value) from MQ-2.
3. Data is sent to Blynk Cloud via WiFi.
4. Blynk App displays live values using gauges.

---

## 💻 Software Requirements

- Arduino IDE
- ESP32 Board Package
- Required Libraries:
  - WiFi.h
  - BlynkSimpleEsp32.h
  - DHT.h

---

## 🔮 Future Enhancements

- Add BMP280 (Pressure Sensor)
- Add MQ-135 (Air Quality Index)
- Add Data Logging (ThingSpeak)
- Add SMS/Email Alert System
- Add Battery Backup System

---

## 📷 Project Applications

- Smart Agriculture
- Industrial Safety Monitoring
- Home Gas Leakage Detection
- Smart City Environmental Monitoring

---

## 👨‍💻 Developed By

**Shivshankar Kumar**  
B.Tech – Electronics & Communication Engineering  
IoT & Embedded Systems Enthusiast  

---

## ⭐ If you like this project

Give it a ⭐ on GitHub and share your feedback!
