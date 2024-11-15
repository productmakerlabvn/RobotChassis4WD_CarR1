# Arduino - 4WD Car R1 Robot Kit - Test Run
## Tóm tắt ý tưởng:
Phần này sẽ test chức năng cơ bản của mạch điều khiển động cơ L298 và các động cơ giúp robot thực hiện chạy tiến, lùi, trái, phải qua bộ thư viện Simple Motor.
## Mô tả tính năng:
Code mẫu sẽ chạy tuần tự mỗi hành động trong 2s: xoay tại chỗ trái, xoay tại chỗ phải, chạy tiến, chạy lùi, rẽ trái, rẽ phải.
## Kết nối phần cứng:
|  UNO  |  D4 |  D5 |  D6 |  D7 |  VIN | GND |
|:-----:|:---:|:---:|:---:|:---:|:----:|:---:|
|  L298 | IN1 | IN2 | IN3 | IN4 | +12V | GND |
| NGUỒN |     |     |     |     | VBAT | GND |

|   L298   | OUT1 | OUT2 | OUT3 | OUT4 |
|:--------:|:----:|:----:|:----:|:----:|
| ĐỘNG CƠ  |  DC1 |  DC1 |  DC2 |  DC2 |

## Cài đặt phần mềm:

## Code Arduino cho thiết bị:
```Cpp
/**
 * Tilte: Arduino - 4WD Car R1 Robot Kit - Test Run
 * Author: Mika
 * Date: 05/17/2024
 * Version: v1.0
 * Purpose: This code is for reference
*/

// INCLUDE LIBRARIES
#include "Makerlabvn_SimpleMotor.h"

// DEFINE
#define PIN_IN1 4
#define PIN_IN2 5
#define PIN_IN3 6
#define PIN_IN4 7
#define SPEED 100

// OBJECT INITIALIZATION
Makerlabvn_SimpleMotor demoMotor(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4);

void setup() {
  // put your setup code here, to run once:
  demoMotor.car_stop();    // Let the car stop
  Serial.begin(9600);    // Initialize Serial baudrate communication
}


void loop() {
  // put your main code here, to run repeatedly:
  demoMotor.car_rotateL(SPEED);  // Let the car rotate left
  delay(2000);
  demoMotor.car_rotateR(SPEED);  // Let the car rotate right
  delay(2000);
  demoMotor.car_fw(SPEED, SPEED);  // Let the car go foward
  delay(2000);
  demoMotor.car_bw(SPEED, SPEED);  // Let the car go backward
  delay(2000);
  int LSPEED = SPEED/3;
  demoMotor.car_fw(LSPEED, SPEED);  // Let the car turn left
  delay(2000);
  demoMotor.car_fw(SPEED, LSPEED);  // Let the car turn right
  delay(2000);
  demoMotor.car_stop();          // Let the car stop
  delay(10000);
}
``` 

