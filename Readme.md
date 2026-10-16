# ESP32 Air Mouse Using MPU6050 and BLE

## Description

A wireless Air Mouse built using the ESP32 microcontroller, MPU6050 motion sensor, and Bluetooth Low Energy (BLE). This project allows users to control a computer mouse cursor through hand movements without using a physical mouse.

The MPU6050 gyroscope detects hand motion, while the ESP32 processes sensor data and transmits mouse movement commands wirelessly through Bluetooth. Two push buttons provide left-click and right-click functionality.

## Features

- Wireless mouse control using Bluetooth Low Energy (BLE).
- Motion-based cursor movement using the MPU6050 gyroscope.
- Left-click and right-click functionality using push buttons.
- Smooth cursor movement using a weighted moving average.
- Dead-zone filtering to reduce unwanted movements.
- Adjustable cursor sensitivity.
- Compact and low-cost hardware design.

## Components Required

- ESP32 Development Board
- MPU6050 Accelerometer and Gyroscope Sensor
- Two Push Buttons
- Jumper Wires
- Breadboard
- USB Cable or suitable power supply

## Libraries Used

- Wire.h
- I2Cdev.h
- MPU6050.h
- BleMouse.h

## How It Works

1. The MPU6050 detects hand movements using its gyroscope.
2. The ESP32 reads the gyroscope values through I2C communication.
3. The sensor readings are converted into horizontal and vertical cursor movements.
4. Dead-zone filtering and smoothing improve cursor stability.
5. Bluetooth Low Energy transmits the mouse commands to the connected device.
6. Two push buttons perform left-click and right-click operations.

## Applications

- Wireless computer navigation
- Human-computer interaction projects
- Gesture-based control systems
- Educational IoT and embedded systems projects
- Experimental input devices

## Future Improvements

- Scroll wheel functionality
- Motion calibration
- Adjustable sensitivity settings
- Battery monitoring
- Improved gesture recognition

## Conclusion

The ESP32 Air Mouse demonstrates how motion sensing and Bluetooth communication can be combined to create an alternative computer input device. It is a practical project for learning embedded systems, sensor interfacing, and wireless human-computer interaction.
