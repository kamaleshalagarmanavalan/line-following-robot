# Robot Description
This line-following robot is designed using an Arduino Nano mounted on a custom-designed PCB that integrates both motor driver circuitry and sensor interfaces. 
The PCB houses the L298N motor driver IC, which controls two DC motors responsible for the robot’s left and right wheel movements.
Essential power regulation components such as resistors, capacitors, and LEDs are included for circuit stability and status indication. 
Screw terminals make motor and sensor connections neat and secure. The robot employs two blue-light infrared (IR) sensors developed by Sparrow Innovation, Tamil Nadu. 
These sensors detect the black line on the ground and provide digital feedback to the microcontroller, allowing the robot to follow the path intelligently by adjusting motor speed and direction.
The entire setup is mounted on a red acrylic chassis, which serves as a sturdy base frame for holding the electronics, motors, and wheels.
The chassis supports two main wheels for motion and a front caster wheel to maintain balance during turns.
The robot is currently powered via USB connection for programming and testing, but it is designed to work with a battery pack for untethered operation in real-world applications.

# Arduino Code Explanation
## Pin Definitions
1. ENA/ENB → PWM pins to control motor speed.
2. IN1–IN4 → Direction control for left and right motors.
3. leftSensor, rightSensor → IR sensors connected to digital pins.

## In setup()
1. Set all motor and sensor pins as input/output.
2. Start the serial monitor for debugging sensor values.

## Movement Logic in loop()
Read IR sensors:
| IR Sensor Output | Surface Detected |
| ---------------- | ---------------- |
| 0                | Black Line       |
| 1                | White Surface    |

Based on sensor values:
| Left IR | Right IR | Binary Input | Robot Action   |
| ------- | -------- | ------------ | -------------- |
| 0       | 0        | 00           | Move Forward   |
| 0       | 1        | 01           | Turn Left      |
| 1       | 0        | 10           | Turn Right     |
| 1       | 1        | 11           | Stop (No Line) |

## Movement Functions
Each function controls motor direction and speed using digitalWrite() and analogWrite().

## Serial Monitor Output
Shows real-time sensor status like:

Left: 0 | Right: 1

Helpful for debugging and calibration.
