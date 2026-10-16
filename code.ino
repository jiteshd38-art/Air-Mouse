#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <BleMouse.h>

MPU6050 mpu;
BleMouse bleMouse("AirMouse", "ESP32", 100);

#define LEFT_BUTTON_PIN  4
#define RIGHT_BUTTON_PIN 5

int avgDx = 0;
int avgDy = 0;

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);
  mpu.initialize();

  if (mpu.testConnection()) {
    Serial.println("MPU6050 connected");
  } else {
    Serial.println("MPU6050 failed");
  }

  bleMouse.begin();

  pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
}

void loop() {

  if (bleMouse.isConnected()) {

    int16_t ax, ay, az;
    int16_t gx, gy, gz;

    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    int dx = gx / 900;
    int dy = -gy / 900;

    if (abs(dx) < 2) dx = 0;
    if (abs(dy) < 2) dy = 0;

    avgDx = (avgDx * 4 + dx) / 5;
    avgDy = (avgDy * 4 + dy) / 5;

    bleMouse.move(avgDx, avgDy);

    // Left click
    if (digitalRead(LEFT_BUTTON_PIN) == LOW) {
      bleMouse.press(MOUSE_LEFT);
    } else {
      bleMouse.release(MOUSE_LEFT);
    }

    // Right click
    if (digitalRead(RIGHT_BUTTON_PIN) == LOW) {
      bleMouse.press(MOUSE_RIGHT);
    } else {
      bleMouse.release(MOUSE_RIGHT);
    }
  }

  delay(10);
}
