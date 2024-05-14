#include <HCSR04.h>
#include <Makerlabvn_SimpleMotor.h>
#include <Servo.h>

#define ANGLE_L 180
#define ANGLE_C 90
#define ANGLE_R 0


Makerlabvn_SimpleMotor Driver(4, 5, 6, 7);
HCSR04 Scaner(9, 10);
Servo Rotater;



long marktime = 0;
int distance;
int threshold_distance = 30;
int speed = 30;

enum {
  car_left,
  car_right,
  car_stop,
  servo_left,
  servo_right,
  servo_straight,
  car_back,
};
int car_state = servo_straight;


void setup() {
  Rotater.attach(8);
  Rotater.write(ANGLE_C);
  delay(1000);
}

void loop() {
  Car_state();
}

void Car_state() {
  switch (car_state) {

    case servo_straight:
      Driver.car_stop();
      delay(100);
      Rotater.write(ANGLE_C);
      delay(1);
      if (Ultradistance_Scan() > threshold_distance) {
        Driver.car_fw(speed, speed);
        delay(300);
        Driver.car_stop();
        delay(10);
        car_state = servo_straight;
      } else {
        Driver.car_stop();
        delay(10);
        car_state = servo_left;
      }
      break;

    case servo_left:
      Driver.car_stop();
      delay(100);
      Rotater.write(ANGLE_L);
      delay(1000);
      if (Ultradistance_Scan() > threshold_distance) {
        Driver.car_rotateL(speed);
        delay(300);
        Driver.car_stop();
        delay(10);
        car_state = servo_straight;
      } else {
        Driver.car_stop();
        delay(10);
        car_state = servo_right;
      }
      break;

    case servo_right:
      Driver.car_stop();
      delay(100);
      Rotater.write(ANGLE_R);
      delay(1000);
      if (Ultradistance_Scan() > threshold_distance) {
        Driver.car_rotateR(speed);
        delay(300);
        Driver.car_stop();
        delay(10);
        car_state = servo_straight;
      } else {
        Driver.car_stop();
        delay(10);
        car_state = car_left;
      }
      break;

    case car_left:
      Driver.car_stop();
      delay(10);
      Rotater.write(ANGLE_C);
      delay(100);
      Driver.car_rotateL(speed);
      delay(300);
      if (Ultradistance_Scan() > threshold_distance) {
        Driver.car_stop();
        delay(10);
        car_state = servo_straight;
      } else {
        Driver.car_stop();
        delay(10);
        car_state = car_right;
      }
      break;

    case car_right:
      Driver.car_stop();
      delay(100);
      Rotater.write(ANGLE_C);
      delay(1000);
      Driver.car_rotateR(speed);
      delay(3000);
      if (Ultradistance_Scan() > threshold_distance) {
        Driver.car_stop();
        delay(1);
        car_state = servo_straight;
      } else {
        Driver.car_stop();
        delay(10);
        car_state = car_back;
      }
      break;

    case car_back:
      Driver.car_stop();
      delay(100);
      Rotater.write(ANGLE_C);
      delay(1000);
      Driver.car_bw(speed, speed);
      delay(600);
      car_state = servo_straight;
      break;
  }
}


int Ultradistance_Scan() {
  if (millis() - marktime >= 60) {
    marktime = millis();
    distance = Scaner.dist();
  }
  return distance;
}
