#include <HCSR04.h>
#include <Makerlabvn_SimpleMotor.h>
#include <Servo.h>

#define ANGLE_L 180
#define ANGLE_C 90
#define ANGLE_R 0

#define DELAYSERVO 500
#define MOTORSPEED 30
#define DELAYROTATE 500
#define DELAYBW 400

Makerlabvn_SimpleMotor Driver(4, 5, 6, 7);
HCSR04 Scaner(9, 10);
Servo Rotater;

long marktime = 0;
int Ultrasonic_interval;
int distance;
const int threshold_distance = 30;

enum {
  RB_FF,
  RB_BB,
  RB_RL,
  RB_RR,
};
int RB_state = RB_FF;

void setup() {
  Serial.begin(9600);
  Rotater.attach(8);
  Rotater.write(ANGLE_C);
  delay(DELAYSERVO);
}

void loop() {
  switch (RB_state) {
    case RB_FF:
      chaytoi();
      break;
    case RB_RL:
      xoaytrai();
      break;
    case RB_RR:
      xoayphai();
      break;
  }
}


bool chaytoi() {
  if(Rotater.read()!=ANGLE_C){
  Rotater.write(ANGLE_C);
  delay(DELAYSERVO);
  }
  if (Ultradistance_Scan() < threshold_distance) {
    Driver.car_stop();
    RB_state = RB_RL;
  } else {
    Driver.car_fw(MOTORSPEED, MOTORSPEED);
  }
}

bool xoaytrai() {
  Rotater.write(ANGLE_L);
  delay(DELAYSERVO);
  if (Ultradistance_Scan() < threshold_distance) {
    Driver.car_stop();
    RB_state = RB_RR;
  } else {
    Rotater.write(ANGLE_C);
    delay(DELAYSERVO);
    Driver.car_rotateL(MOTORSPEED);
    delay(DELAYROTATE);
    Driver.car_stop();
    RB_state = RB_FF;
  }
}

bool xoayphai() {
  Rotater.write(ANGLE_R);
  delay(DELAYSERVO);
  if (Ultradistance_Scan() < threshold_distance) {
    Rotater.write(ANGLE_C);
    delay(DELAYSERVO);
    Driver.car_bw(MOTORSPEED, MOTORSPEED);
    delay(DELAYBW);
    Driver.car_stop();
    RB_state = RB_RL;
  } else {
    Rotater.write(ANGLE_C);
    delay(DELAYSERVO);
    Driver.car_rotateR(MOTORSPEED);
    delay(DELAYROTATE);
    RB_state = RB_FF;
  }
}

int Ultradistance_Scan() {
  distance = Scaner.dist();
  delay(60);
  return distance;
}
