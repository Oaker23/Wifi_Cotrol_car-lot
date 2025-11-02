# Wifi_Cotrol_car-lot
# WiFi Controlled Car with Blynk and ESP8266

---

## 🎬 Project Demo  

<details>
  <summary>คลิกเพื่อดูวิดีโอสาธิตบน YouTube</summary>

  [![WiFi Car Demo – YouTube](https://img.youtube.com/vi/dN35aqvpnqM/hqdefault.jpg)](https://www.youtube.com/watch?v=dN35aqvpnqM)
</details>
---

This project is a WiFi-controlled car using a NodeMCU ESP8266 and the Blynk app. The car can be controlled remotely via the Blynk app to move forward, backward, turn left, turn right, and stop. You can also adjust the speed of the car via the app.

## Overview

This code was created by the **Sritu Hobby Team** as part of a simple DIY project to control a car via WiFi using Blynk. The car's movement is controlled through an ESP32 board (although the code is written for ESP8266, it's easily adaptable). This project is suitable for beginners looking to integrate WiFi control with hardware components such as motors and sensors.

## Features

- **Remote control via Blynk app**: Control the car's direction (forward, backward, left, right) and speed.
- **Speed adjustment**: Adjust the motor speed for smooth movement.
- **Easy setup**: Set up the WiFi credentials and Blynk authentication token to get started.

## Components

- NodeMCU ESP8266 or ESP32
- DC Motors (x2)
- Motor Driver Module (L298N or similar)
- 4WD chassis or any car platform
- Blynk app (available on Android/iOS)

## Circuit Diagram

Ensure the following connections between the ESP32 and motor driver:

- **ENA** (PWM pin) -> Motor A Speed
- **IN1** -> Motor A Direction
- **IN2** -> Motor A Direction
- **IN3** -> Motor B Direction
- **IN4** -> Motor B Direction
- **ENB** (PWM pin) -> Motor B Speed

## Setup

1. **Install Blynk**: Download the Blynk app from the [App Store](https://apps.apple.com/us/app/blynk/id818211288) (iOS) or [Google Play](https://play.google.com/store/apps/details?id=cc.blynk) (Android).
   
2. **Create a New Project in Blynk**:
    - Open the Blynk app.
    - Create a new project and select ESP32 or ESP8266 as the device.
    - Copy the **Auth Token** provided by the app. You'll need this to authenticate the connection.

3. **Connect the Hardware**: 
    - Connect the ESP32 to your motor driver as shown in the circuit diagram.
    - Connect the motor driver to the motors and power supply.
  
4. **Edit the Code**:
    - Replace the following in the code:
        - `ssid[]` with your Wi-Fi SSID.
        - `pass[]` with your Wi-Fi password.
        - `BLYNK_AUTH_TOKEN` with your Blynk Auth Token.
        
5. **Upload the Code**: 
    - Open the Arduino IDE.
    - Select the correct board and port for your ESP32/ESP8266.
    - Upload the code to the ESP32/ESP8266.

6. **Run the Project**:
    - Open the Blynk app and connect to your ESP32/ESP8266.
    - Control the car's movement using the app's controls.

## Code Explanation

- **Blynk Communication**: The Blynk library is used to communicate with the Blynk app. The car's movement is controlled by receiving signals from the app's virtual pins (V0 to V4).
  
- **Car Movement**: 
    - The car can move forward, backward, turn left, or turn right.
    - Speed can be adjusted by modifying the PWM values sent to the motor driver.

- **Functions**:
    - `carforward()`: Moves the car forward by controlling the motor's direction.
    - `carbackward()`: Moves the car backward.
    - `carturnleft()`: Turns the car left.
    - `carturnright()`: Turns the car right.
    - `carStop()`: Stops the car.

## License

This project is open-source and available for personal use. Feel free to modify it for your own projects.

---

**Created by XTEN Team** 
