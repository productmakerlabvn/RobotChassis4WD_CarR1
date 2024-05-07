# [MakerEdu Creator] Xe dò line
## Tóm tắt ý tưởng:
Xe dò line DIY.
## Mô tả tính năng:
Xe dò line bằng cảm biến dò line.
## Chuẩn bị phần cứng và kết nối:
### Chuẩn bị:

<table class="tg">
<thead>
  <tr>
    <th class="tg-baqh">STT</th>
    <th class="tg-baqh">Tên thiết bị </th>
    <th class="tg-baqh">SL</th>
    <th class="tg-baqh">Link</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-baqh">1</td>
    <td class="tg-73oq">Mạch Uno SMD CH340 (Arduino Uno Compatible).</td>
    <td class="tg-baqh">1 cái</td>
    <td class="tg-baqh"><a href="https://hshop.vn/products/arduino-uno-r3-smd-chip-don">Link</a></td>
  </tr>
  <tr>
    <td class="tg-baqh">2</td>
    <td class="tg-0lax">Khung Xe Robot Chasiss 4WD Car R1.</td>
    <td class="tg-baqh">1 cái</td>
    <td class="tg-baqh"><a href="https://hshop.vn/products/khung-xe-robot-chasiss-4wd-car-r1">Link</a></td>
  </tr>
  <tr>
    <td class="tg-baqh">3</td>
    <td class="tg-0lax">Động Cơ DC Giảm Tốc V1 Dual Shaft Plastic Geared TT Motor + Bánh Xe.</td>
    <td class="tg-baqh">4 cái</td>
    <td class="tg-baqh"><a href="https://hshop.vn/products/dong-co-dc-giamtoc-v1-1-48">Link</a></td>
  </tr>
  <tr>
    <td class="tg-baqh">4</td>
    <td class="tg-0lax">Hộp Pin 2 X 18650 Battery Holder Có Công Tắc.</td>
    <td class="tg-baqh">1 cái</td>
    <td class="tg-baqh"><a href="https://hshop.vn/products/hop-pin-2-co-18650-co-cong-tac">Link</a></td>
  </tr>
  <tr>
    <td class="tg-baqh">5</td>
    <td class="tg-0lax">Breadboard Mini 170 Lỗ 45x34x9mm.</td>
    <td class="tg-baqh">1 cái</td>
    <td class="tg-baqh"><a href="https://hshop.vn/products/test-board-cammini-35-x-47mm">Link</a></td>
  </tr>
  <tr>
    <td class="tg-baqh">6</td>
    <td class="tg-0lax">Cảm Biến Dò Line Đơn TCRT5000 Line Follower Sensor</td>
    <td class="tg-baqh">3 cái</td>
    <td class="tg-baqh"><a href="https://hshop.vn/products/cam-bien-do-line-don">Link</a></td>
  </tr>
  <tr>
    <td class="tg-baqh">7</td>
    <td class="tg-0lax">Mạch Điều Khiển Động Cơ L298 DC Motor Driver.</td>
    <td class="tg-baqh">1 cái</td>
    <td class="tg-baqh"><a href="https://hshop.vn/products/mach-dieu-khien-dong-co-dc-l298">Link</a></td>
  </tr>
  <tr>
    <td class="tg-baqh">8</td>
    <td class="tg-0lax">Đầu Chuyển Domino Sang Giắc DC Đực 2.1mm.</td>
    <td class="tg-baqh">1 cái</td>
    <td class="tg-baqh"><a href="https://hshop.vn/products/dau-chuyen-domino-sang-giac-dc-duc-2-1mm">Link</a></td>
  </tr>
  <tr>
    <td class="tg-baqh">9</td>
    <td class="tg-0lax">Dây Điện Đỏ Đen.</td>
    <td class="tg-baqh">1 m </td>
    <td class="tg-baqh"><a href="https://hshop.vn/products/day-dien-do-den">Link</a></td>
  </tr>
  <tr>
    <td class="tg-baqh">10</td>
    <td class="tg-0lax">Dây bus đực - cái.</td>
    <td class="tg-baqh">1 tép</td>
    <td class="tg-baqh"><a href="https://hshop.vn/products/day-camtest-board-duc-coi20cm40soi">Link</a></td>
  </tr>
  <tr>
    <td class="tg-0lax">11</td>
    <td class="tg-0lax">Dây bus đực - đực.</td>
    <td class="tg-0lax">1 tép</td>
    <td class="tg-0lax"><a href="https://hshop.vn/products/day-camtest-board-duc-duc-20cm40soi">Link</a></td>
  </tr>
</tbody>
</table>

### Kết nối:

| UNO              | A1  | A2  | A3  | 5V | GND |
|:----------------:|-----|-----|-----|----|-----|
| TCRT 5000 (Trái) |     |     | DO | 5V | GND |
| TCRT 5000 (Giữa) |     | DO |     | 5V | GND |
| TCRT 5000 (Phải) | DO |     |     | 5V | GND |

|  UNO  |  D4 |  D5 |  D6 |  D7 |  DC+ | DC- |
|:-----:|:---:|:---:|:---:|:---:|:----:|:---:|
|  L298 | IN1 | IN2 | IN3 | IN4 |  VCC | GND |
| NGUỒN |     |     |     |     |   +  |  -  |

|   L298   | OUT1 | OUT2 | OUT3 | OUT4 |
|:--------:|:----:|:----:|:----:|:----:|
| ĐỘNG CƠ  |  DC1 |  DC1 |  DC2 |  DC2 |

<img src="image/R1_LineTracking.png">

## Chuẩn bị kiến thức:
- Nếu là lần đầu tiên sử dụng phần mềm Arduino, các bạn cần thực hiện đầy đủ các bước trong hướng dẫn <a href="https://wiki.makerlab.vn/index.php/H%C6%B0%E1%BB%9Bng_d%E1%BA%ABn_s%E1%BB%AD_d%E1%BB%A5ng_ph%E1%BA%A7n_m%E1%BB%81m_Arduino_v%E1%BB%9Bi_c%C3%A1c_m%E1%BA%A1ch_Vietduino_%2B_MakerEdu_Shield_for_Vietduino">tại đây</a>.
- Nếu các phần cứng trong bài là hoàn toàn mới với các bạn, để có thể nắm được cách hệ thống vận hành, các bạn cần đọc và tìm hiểu về cách sử dụng của từng phần cứng tại trang Wiki của <a href="https://wiki.makerlab.vn/index.php/Main_Page">Makerlab</a>.
 
## Code Arduino cho thiết bị:
```Cpp
#include <Arduino.h>
#include "Makerlabvn_SimpleMotor.h"

#define PIN_OUT1 A1  //! A1
#define PIN_OUT2 A2  //! A2
#define PIN_OUT3 A3  //! A3

#define PIN_IN1 4  //! D4
#define PIN_IN2 5  //! D5 (~)
#define PIN_IN3 6  //! D6 (~)
#define PIN_IN4 7  //! D7

/* VARIABLE */
Makerlabvn_SimpleMotor demoMotor(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4);

float eye_Left_Value;
float eye_Right_Value;
float eye_Mid_Value;
float threshold_left;
float last_lost_dir;
float left_dir;
float speedForward;
float threshold_right;
float right_dir;
float threshold_mid;
float speedForwardlow;
float stopspeed;

/* RUN ONCE TIME WHEN START */

  void setup() {
    threshold_left = 0.5;
    threshold_right = 0.5;
    threshold_mid = 0.5;
    left_dir = 0;
    right_dir = 1;
    speedForward = 35;
    speedForwardlow = 10;
    stopspeed = 0;
  }
  /* RUN LOOP AFTER SETUP RUN */
  void loop() {

    eye_Left_Value = digitalRead(A3);
    eye_Right_Value = digitalRead(A1);
    eye_Mid_Value = digitalRead(A2);

    if ((eye_Mid_Value > threshold_mid)) {

      demoMotor.car_fw(speedForward, speedForward);

      
    } else {
      if ((eye_Left_Value > threshold_left) && (eye_Right_Value < threshold_right) && (eye_Mid_Value > threshold_mid)) {

        demoMotor.car_fw(speedForwardlow, speedForward);
       
      } else {
        if ((eye_Left_Value < threshold_left) && (eye_Right_Value > threshold_right) && (eye_Mid_Value > threshold_mid)) {

          demoMotor.car_fw(speedForward, speedForwardlow);
          
        } else {
          if ((eye_Left_Value > threshold_left) && (eye_Right_Value < threshold_right) && (eye_Mid_Value < threshold_mid)) {
            last_lost_dir = left_dir;

            demoMotor.car_fw(stopspeed, speedForward);
          } else {
            if ((eye_Left_Value < threshold_left) && (eye_Right_Value > threshold_right) && (eye_Mid_Value < threshold_mid)) {
              last_lost_dir = right_dir;

              demoMotor.car_fw(speedForward, stopspeed);

            } else {
              if (last_lost_dir == left_dir) {

                demoMotor.car_rotateL(speedForward);

              } else {

                demoMotor.car_rotateR(speedForward);
              }
            }
          }
        }
      }
    }
  }
```