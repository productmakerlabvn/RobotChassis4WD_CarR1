#include "Dabble.h" 
#include <SoftwareSerial.h>
#include <Arduino.h>
#include "Makerlabvn_SimpleMotor.h"
#include "SoftwareSerial.h"

#define PIN_IN1 4 
#define PIN_IN2 5 
#define PIN_IN3 6 
#define PIN_IN4 7 

#define PIN_TX_BLE 2 
#define PIN_RX_BLE 3 

Makerlabvn_SimpleMotor demoMotor(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4);
SoftwareSerial mySerial(PIN_TX_BLE, PIN_RX_BLE); 

void setup() {

  demoMotor.car_stop();

  mySerial.begin(115200);
  Serial.begin(115200);
  Dabble.begin(mySerial);
}

void loop() {

  Dabble.processInput();  //hàm nhận tín hiệu từ app Dabble trên điện thoại

  if (GamePad.isUpPressed()) {  //khi nhấn nút ˄
    demoMotor.motorA_fw(100);
    demoMotor.motorB_fw(100);
  } else {
    if (GamePad.isDownPressed()) {  //khi nhấn nút ˅
      demoMotor.motorA_bw(100);
      demoMotor.motorB_bw(100);
    } else {
      if (GamePad.isLeftPressed()) {  //khi nhấn nút ˂
        demoMotor.motorA_bw(100);
        demoMotor.motorB_fw(100);
      } else {
        if (GamePad.isRightPressed()) {  //khi nhấn nút ˃
          demoMotor.motorA_fw(100);
          demoMotor.motorB_bw(100);
        } else {  // khi không nhấn 1 trong 4 nút trên
          demoMotor.car_stop();
        }
      }
    }
  }
}