// Pins mentioned here is for example and it should be given according to the connections in hardware (Arduino Nano)
// Motor Pins
const int ENA = 9;    // PWM pin for Left Motor Speed
const int IN1 = 8;    // Left Motor direction pin 1
const int IN2 = 7;    // Left Motor direction pin 2

const int ENB = 10;   // PWM pin for Right Motor Speed
const int IN3 = 6;    // Right Motor direction pin 1
const int IN4 = 5;    // Right Motor direction pin 2

// IR Sensor Pins
const int leftSensor = 2;
const int rightSensor = 3;

// Speed Control
int motorSpeed = 150; // Value between 0 - 255

void setup() {
  // Motor pins as OUTPUT
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // IR sensor pins as INPUT
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  // Start Serial Monitor
  Serial.begin(9600);
}

void loop() {
  int leftIR = digitalRead(leftSensor);
  int rightIR = digitalRead(rightSensor);

  // Debugging output
  Serial.print("Left: ");
  Serial.print(leftIR);
  Serial.print(" | Right: ");
  Serial.println(rightIR);

  // Decision logic
  if (leftIR == 0 && rightIR == 0) {
    // Both sensors on black line
    moveForward();
  }
  else if (leftIR == 0 && rightIR == 1) {
    // Left on line, right off line → turn left
    turnLeft();
  }
  else if (leftIR == 1 && rightIR == 0) {
    // Right on line, left off line → turn right
    turnRight();
  }
  else {
    // Both sensors off line → stop
    stopMotors();
  }

  delay(100);  // Small delay for stability
}

// Function Definitions

void moveForward() {
  analogWrite(ENA, motorSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, motorSpeed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  analogWrite(ENA, motorSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH); // Left motor backward

  analogWrite(ENB, motorSpeed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); // Right motor forward
}

void turnRight() {
  analogWrite(ENA, motorSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); // Left motor forward

  analogWrite(ENB, motorSpeed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); // Right motor backward
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
