#include <Servo.h>

// Khai báo các chân kết nối
const int trigPin = 9;
const int echoPin = 10;
const int motorPin1 = 5;
const int motorPin2 = 6;
const int servoPin = 11;

// Khai báo các cờ
bool isCarRunning = true;
bool isServoRunning = true;
bool isUltrasonicRunning = true;

Servo servoMotor; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  servoMotor.attach(servoPin);
}

void loop() {
  if (isUltrasonicRunning) {
    int distance = measureDistance();
    if (distance > 20 && isCarRunning) {
      moveForward();
    } else if (isServoRunning) {
      avoidObstacle();
    }
  }
}

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

void moveForward() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void avoidObstacle() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(1000);
  int leftDistance = scanDistance(180);
  int rightDistance = scanDistance(0);
  if (leftDistance > 20 && rightDistance > 20) {
    if (leftDistance > rightDistance) {
      turnLeft();
    } else {
      turnRight();
    }
    moveForward();
  } else {
    moveBackward();
    delay(1000);
    stopCar();
    delay(1000);
    isCarRunning = true;
    isServoRunning = true;
    isUltrasonicRunning = true;
  }
}

int scanDistance(int angle) {
  servoMotor.write(angle);
  delay(500);
  int distance = measureDistance();
  return distance;
}

void turnLeft() {
  servoMotor.write(180);
  delay(1000);
}

void turnRight() {
  servoMotor.write(0);
  delay(1000);
}

void moveBackward() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
}

void stopCar() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}
