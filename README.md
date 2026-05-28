# 🔍 Smart Inventory Monitoring System

An Arduino-based IoT project designed to monitor inventory levels intelligently using RFID authentication and load cell technology. The system provides real-time inventory monitoring, authorization verification, and alert indications through an LCD display and serial monitor.

# 📌 Project Description

The Smart Inventory Monitoring System is developed to automate inventory monitoring and refill authorization processes. The project uses a 5kg load cell sensor to continuously measure inventory weight and an RFID module to authenticate authorized users before allowing refill operations.

The measured data is displayed on a 16x2 LCD screen and monitored through the Arduino serial monitor. The system helps reduce manual monitoring and improves inventory management efficiency.

# 🚀 Key Features

✅ RFID-based authentication system
✅ Real-time inventory weight monitoring
✅ LCD display for live status updates
✅ Serial monitor output display
✅ Low inventory detection alert
✅ Smart refill authorization system
✅ IoT monitoring capability


# 🛠️ Hardware Components Used

| Component        | Description               |
| ---------------- | ------------------------- |
| Arduino UNO      | Main microcontroller      |
| HX711 Module     | Load cell amplifier       |
| 5kg Load Cell    | Weight measurement sensor |
| RFID RC522       | Authentication module     |
| 16x2 LCD Display | Output display            |
| ESP8266 Module   | IoT communication         |
| Jumper Wires     | Circuit connections       |



# ⚙️ Working Principle

### Step 1 — RFID Authentication

The user scans the RFID tag using the RC522 RFID reader.

### Step 2 — Authorization Verification

The system verifies whether the refill request is authorized.

### Step 3 — Weight Measurement

The load cell measures the current inventory weight through the HX711 amplifier module.

### Step 4 — Data Display

The measured inventory value and authorization status are displayed on the LCD screen and serial monitor.

### Step 5 — Alert Generation

If the inventory level falls below the threshold value, the system generates an alert indication.


# 📷 Project Output

## Hardware Setup

Project hardware setup includes Arduino UNO, RFID module, load cell, LCD display, and IoT module.

## Serial Monitor Output

The serial monitor displays:

* RFID authentication status
* Current inventory weight
* Refill authorization messages
* Low inventory alerts


# 🎯 Applications

* Smart warehouse systems
* Gas cylinder monitoring
* Industrial inventory management
* Automated stock monitoring
* Smart storage systems


# 🔮 Future Enhancements

* Mobile application integration
* Cloud database storage
* SMS & email notification system
* AI-based inventory prediction
* Web dashboard monitoring

# 👥 Project Team

This project was developed as a team project by:
SRI VIDHYA B
SRI AMIRTHA VARSHINI S V
SHRUTHI R
SHAHIN ASHIKA K
---
