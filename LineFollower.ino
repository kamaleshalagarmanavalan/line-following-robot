// Pins mentioned here is for example and it should be given according to the connections in hardware (Arduino Nano)
// Define IR sensor pins
const int leftSensor = 2;
const int rightSensor = 3;

// Motor control pins
const int in1 = 4;
const int in2 = 5;
const int in3 = 6;
const int in4 = 7;

void setup() {
  // Set IR sensors as input
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  // Set motor pins as output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  int left = digitalRead(leftSensor);
  int right = digitalRead(rightSensor);

  // Case 1: Both sensors on track (black)
  if (left == LOW && right == LOW) {
    moveForward();
  }
  // Case 2: Left sensor off track (white), turn right
  else if (left == HIGH && right == LOW) {
    turnRight();
  }
  // Case 3: Right sensor off track, turn left
  else if (left == LOW && right == HIGH) {
    turnLeft();
  }
  // Case 4: Both off track - stop or turn
  else {
    stopMotors();
  }
}

// Movement functions
void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
