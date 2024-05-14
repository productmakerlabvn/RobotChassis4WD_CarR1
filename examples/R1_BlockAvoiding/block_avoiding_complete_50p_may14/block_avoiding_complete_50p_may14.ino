#include "Servo.h"
#include "Makerlabvn_SimpleMotor.h"
#include "HCSR04.h"

#define servoPin 8

#define Angle_L 180
#define Angle_C 90
#define Angle_R 0

#define DELAYROTATE 625

Servo servoMotor;
HCSR04 ultraSonic(9, 10);
Makerlabvn_SimpleMotor motorControl(4, 5, 6, 7);

int speed = 30;
int thresholdDistance = 35;
int distance;

int distance_mid = 0;
int distance_left = 0;
int distance_right = 0;

long marktime = 0;

void setup() {
  servoMotor.attach(servoPin);
  motorControl.car_stop();
  servoMotor.write(Angle_C);
  delay(1000);
}

void loop() {
  if (Distance_Scan() > thresholdDistance) {
    motorControl.car_fw(speed, speed);
  } else {
    motorControl.car_stop();
    Distance_Process();
    if (distance_mid > distance_left && distance_mid > distance_right) {
      servoMotor.write(Angle_C);
      motorControl.car_fw(speed, speed);
    } else if (distance_left > distance_mid && distance_left > distance_right) {
      servoMotor.write(Angle_C);
      motorControl.car_rotateL(speed);
      delay(DELAYROTATE);
    } else if (distance_right > distance_left && distance_right > distance_mid) {
      servoMotor.write(Angle_C);
      motorControl.car_rotateR(speed);
      delay(DELAYROTATE);
    } else {
      servoMotor.write(Angle_C);
      motorControl.car_bw(speed, speed);
      delay(DELAYROTATE);
    }
  }
}

int Distance_Scan() {
  distance = ultraSonic.dist();
  delay(60);
  return distance;
}

void Distance_Process() {
  servoMotor.write(Angle_C);
  delay(1000);
  distance_mid = Distance_Scan();
  delay(10);
  servoMotor.write(Angle_L);
  delay(1000);
  distance_left = Distance_Scan();
  delay(10);
  servoMotor.write(Angle_R);
  delay(1000);
  distance_right = Distance_Scan();
  delay(10);
  servoMotor.write(Angle_C);
  delay(100);
}