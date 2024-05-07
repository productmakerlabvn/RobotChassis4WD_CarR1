#include <Arduino.h>
#include "Makerlabvn_SimpleMotor.h"

#define PIN_OUT1 A1 //! A1
#define PIN_OUT2 A2 //! A2
#define PIN_OUT3 A3 //! A3
#define PIN_IN1 4 //! D4
#define PIN_IN2 5 //! D5 (~)
#define PIN_IN3 6 //! D6 (~)
#define PIN_IN4 7 //! D7

Makerlabvn_SimpleMotor demoMotor(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4);

float eye_Left_Value;
float eye_Right_Value;
float threshold_left;
float last_lost_dir;
float left_dir;
float speedForward;
float threshold_right;
float right_dir;

void setup(){
    threshold_left =  0.5;
    threshold_right = 0.5;
    left_dir = 0;
    right_dir = 1;
    last_lost_dir = left_dir;
    speedForward = 50;
    while(1) {
        eye_Left_Value = digitalRead(A3);
        eye_Right_Value = digitalRead(A2);
        if((eye_Left_Value > threshold_left)  &&  (eye_Right_Value > threshold_right)){
          demoMotor.car_fw(speedForward,speedForward);
        }else{
          if((eye_Left_Value > threshold_left)  &&  (eye_Right_Value < threshold_right)){
            last_lost_dir = left_dir;
            demoMotor.car_fw(speedForward,0);
          }else{
            if((eye_Left_Value < threshold_left)  &&  (eye_Right_Value > threshold_right)){
              last_lost_dir = right_dir;
              demoMotor.car_fw(0,speedForward);  

            }else{
              if(last_lost_dir == left_dir){
                demoMotor.car_rotateL(speedForward);

              }else{
                demoMotor.car_rotateR(speedForward);
              }

            }

          }

        }


    }

}

void loop(){
}
