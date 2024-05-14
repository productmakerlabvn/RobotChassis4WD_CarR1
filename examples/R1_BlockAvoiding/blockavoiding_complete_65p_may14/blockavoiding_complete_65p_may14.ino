#include "Servo.h"
#include "Makerlabvn_SimpleMotor.h"
#include "HCSR04.h"

#define servoPin 8
#define Angle_L 180
#define Angle_C 90
#define Angle_R 0

Servo servoMotor;
HCSR04 ultraSonic(9, 10);
Makerlabvn_SimpleMotor motorControl(4, 5, 6, 7);

int speed = 30;
int thresholdDistance = 35;
int distance;

long marktime=0;

void setup() {
servoMotor.attach(servoPin);
motorControl.car_stop();
servoMotor.write(Angle_C);
delay(1000);
}

void loop() {
if(servoMotor.read() == Angle_C){
  if(getDistance()>thresholdDistance){
    chaythang();
  } else {
    dung();
    servoMotor.write(Angle_L);
    delay(1000);
  }
} else if (servoMotor.read() == Angle_L){
    if(getDistance()>thresholdDistance){
    retrai();
    servoMotor.write(Angle_C);
  } else {
    dung();
    servoMotor.write(Angle_R);
    delay(1000);
  }
  } else if (servoMotor.read() == Angle_R){
    if(getDistance()>thresholdDistance){
    rephai();
    servoMotor.write(Angle_C);
  } else {
    dung();
    servoMotor.write(Angle_C);
    delay(1000);
    chaylui();
  }
}
}

void chaythang() {
  servoMotor.write(Angle_C);
  motorControl.car_fw(speed, speed);
}
void retrai() {
  servoMotor.write(Angle_C);
  motorControl.car_rotateL(speed);
  delay(625);
}
void rephai() {
  servoMotor.write(Angle_C);
  motorControl.car_rotateR(speed);
  delay(625);
}
void chaylui() {
  motorControl.car_bw(speed, speed);
  delay(300);
  motorControl.car_stop();
  delay(500);
  servoMotor.write(Angle_L);
}
int getDistance() {
  if(millis() - marktime >= 60){
    marktime=millis();
    distance = ultraSonic.dist();
  }
  return distance;
}
void dung(){
  motorControl.car_stop();
  delay(1000);
}