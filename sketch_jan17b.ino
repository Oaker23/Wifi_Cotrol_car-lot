/*Nodemcu ESP8266 WIFI control car.
 * This code created by sritu hobby team.
 * https://srituhobby.com
 */
 
#define BLYNK_TEMPLATE_ID "TMPL6rhL262ii"
#define BLYNK_TEMPLATE_NAME "connect blynk"
#define BLYNK_AUTH_TOKEN "NzspX2CtuTLZ7PkJjiVsFJm-ddgEVsOk"

// Include necessary libraries
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "esp32-hal-ledc.h"

// Pin Definitions (Based on your setup)
#define ENA 13  // Motor A Speed Control
#define IN1 12  // Motor A Direction
#define IN2 14  // Motor A Direction
#define IN3 27  // Motor B Direction
#define IN4 26  // Motor B Direction
#define ENB 25  // Motor B Speed Control

char ssid[] = "Veevi_2G";       // WiFi SSID
char pass[] = "0860304069";     // WiFi Password


bool forward = 0;
bool backward = 0;
bool left = 0;
bool right = 0;
int Speed;
 
 
void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
 
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}
 
BLYNK_WRITE(V0) {
  forward = param.asInt();
}
 
BLYNK_WRITE(V1) {
  backward = param.asInt();
}
 
BLYNK_WRITE(V2) {
  left = param.asInt();
}
 
BLYNK_WRITE(V3) {
  right = param.asInt();
}
 
BLYNK_WRITE(V4) {
  Speed = param.asInt();
}
 
void smartcar() {
  if (forward && !backward && !left && !right) {
    carForward();
    Serial.println("carForward");
  } else if (backward && !forward && !left && !right) {
    carBackward();
    Serial.println("carBackward");
  } else if (left && !forward && !backward && !right) {
    carTurnLeft();
    Serial.println("carTurnLeft");
  } else if (right && !forward && !backward && !left) {
    carTurnRight();
    Serial.println("carTurnRight");
  } else {
    carStop();
    Serial.println("carStop");
  }
}

void loop() {
  Blynk.run();
  smartcar();
}
// ฟังก์ชันสำหรับขับรถไปข้างหน้า
void carForward() {
  ledcWrite(0, Speed);
  ledcWrite(1, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// ฟังก์ชันสำหรับถอยหลัง
void carBackward() {
  ledcWrite(0, Speed);
  ledcWrite(1, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// ฟังก์ชันสำหรับเลี้ยวซ้าย
void carTurnLeft() {
  ledcWrite(0, Speed);
  ledcWrite(1, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// ฟังก์ชันสำหรับเลี้ยวขวา
void carTurnRight() {
  ledcWrite(0, Speed);
  ledcWrite(1, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// ฟังก์ชันสำหรับหยุดรถ
void carStop() {
  ledcWrite(0, 0);
  ledcWrite(1, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
