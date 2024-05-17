# [MakerEdu Creator] Xe tránh vật cản
## Tóm tắt ý tưởng:
Xe tránh vật cản DIY.
## Mô tả tính năng:
Xe tránh vật cản nhờ vào cảm biến siêu âm.
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
    <td class="tg-0lax">Cảm Biến Siêu Âm Ultrasonic HC-SR04</td>
    <td class="tg-baqh">1 cái</td>
    <td class="tg-baqh"><a href="https://hshop.vn/products/cam-bien-sieu-am-srf04">Link</a></td>
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
    <tr>
    <td class="tg-0lax">12</td>
    <td class="tg-0lax">Động Cơ RC Servo 9G.</td>
    <td class="tg-0lax">1 cái</td>
    <td class="tg-0lax"><a href="https://hshop.vn/products/dong-co-rc-servo-9g">Link</a></td>
  </tr>
</tbody>
</table>

### Kết nối:

|   UNO  |  5V | GND |  D8  |  D9  | D10  |
|:------:|:---:|:---:|:----:|:----:|------|
| HCSR04 | VCC | GND |      | TRIG | ECHO |
| SERVO  | ĐỎ  | NÂU | VÀNG |      |      |

|  UNO  |  D4 |  D5 |  D6 |  D7 |  VIN | GND |
|:-----:|:---:|:---:|:---:|:---:|:----:|:---:|
|  L298 | IN1 | IN2 | IN3 | IN4 | +12V | GND |
| NGUỒN |     |     |     |     | VBAT | GND |

|   L298   | OUT1 | OUT2 | OUT3 | OUT4 |
|:--------:|:----:|:----:|:----:|:----:|
| ĐỘNG CƠ  |  DC1 |  DC1 |  DC2 |  DC2 |

<img src="../../image/R1_BlockAvoiding.png">

## Chuẩn bị kiến thức:
- Nếu là lần đầu tiên sử dụng phần mềm Arduino, các bạn cần thực hiện đầy đủ các bước trong hướng dẫn <a href="https://wiki.makerlab.vn/index.php/H%C6%B0%E1%BB%9Bng_d%E1%BA%ABn_s%E1%BB%AD_d%E1%BB%A5ng_ph%E1%BA%A7n_m%E1%BB%81m_Arduino_v%E1%BB%9Bi_c%C3%A1c_m%E1%BA%A1ch_Vietduino_%2B_MakerEdu_Shield_for_Vietduino">tại đây</a>.
- Nếu các phần cứng trong bài là hoàn toàn mới với các bạn, để có thể nắm được cách hệ thống vận hành, các bạn cần đọc và tìm hiểu về cách sử dụng của từng phần cứng tại trang Wiki của <a href="https://wiki.makerlab.vn/index.php/Main_Page">Makerlab</a>.
 
## Code Arduino cho thiết bị:
```Cpp
/**
 * Tilte: Block Avoiding Car R1
 * Author: Mika
 * Date: 05/16/2024
 * Version: v1.0
 * Purpose: This code is for reference
*/

// Include libraries
#include <HCSR04.h>
#include <Makerlabvn_SimpleMotor.h>
#include <Servo.h>

// Define
#define ANGLE_L 180 // The left side of the car for rc servo motor rotate
#define ANGLE_C 90  // The middle side of the car for rc servo motor rotate
#define ANGLE_R 0   // The right side of the car for rc servo motor rotate

#define DELAYSERVO 500  // Define the servo's delay time
#define MOTORSPEED 30   // Define the car's speed
#define DELAYROTATE 500 // Define the delaytime for the car rotates
#define DELAYBW 400     // Define the delaytime for the car goes back

// Object initialization
Makerlabvn_SimpleMotor Driver(4, 5, 6, 7);
HCSR04 Scaner(9, 10);
Servo Rotater;

// Variable
int distance; // The variable stores the distance value
const int threshold_distance = 30; // Variable that specifies the distance threshold to the obstacle
enum { // Specifies 4 car's states
  RB_FF,
  RB_BB,
  RB_RL,
  RB_RR,
};
int RB_state = RB_FF; // Specifies the fist car's state is going forward

void setup() {
    // put your setup code here, to run once: 
  Rotater.attach(8); // Initialize the control pin of rc servo
  Rotater.write(ANGLE_C); // For the ultrasonic sensor to look forward
  delay(DELAYSERVO); // Wait for the motor to rotate for about DELAYSERVO
}

void loop() {
   // put your main code here, to run repeatedly:
  switch (RB_state) { 
    /**
     * Consider variable RB_state:
     * - RB_FF: go foward
     * - RB_RL: turn left
     * - RB_RR: turn right
     */
    case RB_FF:
      go_F();
      break;
    case RB_RL:
      rotate_L();
      break;
    case RB_RR:
      rotate_R();
      break;
  }
}

// Function 
void go_F() {
  // In case the ultrasonic sensor is at an angle that does not look straight ahead of the car
  if(Rotater.read()!=ANGLE_C){
  // Return the ultrasonic sensor to the middle 
  Rotater.write(ANGLE_C); 
    // Wait for the rc servo to rotate
  delay(DELAYSERVO);
  }
  // In case of encountering obstacles
  if (Ultradistance_Scan() < threshold_distance) {
    Driver.car_stop(); // Let the car stop
    RB_state = RB_RL; // Change the vehicle's status to turn left
  // And if there are no obstacles
  } else {
    Driver.car_fw(MOTORSPEED, MOTORSPEED); // Let the car run straight
  }
}

void rotate_L() {
  // Turn the rc servo to the left side of the car
  Rotater.write(ANGLE_L);
  // Wait for the rc servo to rotate
  delay(DELAYSERVO);
  // In case of encountering obstacles
  if (Ultradistance_Scan() < threshold_distance) { 
    Driver.car_stop(); // Let the car stop
    RB_state = RB_RR; // Change the vehicle's status to turn left
  // And if there are no obstacles
  } else {
    Rotater.write(ANGLE_C); // Turn the rc servo to the middle side of the car
    delay(DELAYSERVO);   // Wait for the rc servo to rotate
    Driver.car_rotateL(MOTORSPEED); // Let the car turn left
    delay(DELAYROTATE);   // Wait for the car to rotate
    Driver.car_stop(); // Let the car stop
    RB_state = RB_FF; // Change the vehicle's status to go forward
  }
}

void rotate_R() {
    // Turn the rc servo to the left side of the car
  Rotater.write(ANGLE_R);
    // Wait for the rc servo to rotate
  delay(DELAYSERVO);

    // In case of encountering obstacles
  if (Ultradistance_Scan() < threshold_distance) {
    Rotater.write(ANGLE_C); // Turn the rc servo to the middle side of the car
    delay(DELAYSERVO);  // Wait for the rc servo to rotate
    Driver.car_bw(MOTORSPEED, MOTORSPEED);  // Let the car go backward
    delay(DELAYBW); // Wait for the car to go backward
    Driver.car_stop(); // Let the car stop
    RB_state = RB_RL; // Change the vehicle's status to turn left

    // And if there are no obstacles
  } else {
    Rotater.write(ANGLE_C); // Turn the rc servo to the middle side of the car
    delay(DELAYSERVO); // Wait for the rc servo to rotate
    Driver.car_rotateR(MOTORSPEED); // Let the car turn right
    delay(DELAYROTATE); // Wait for the car to rotate
    RB_state = RB_FF; // Change the vehicle's status to go foward
  }
}

int Ultradistance_Scan() {
  distance = Scaner.dist(); // Store the measured value in the distance variable
  delay(60); // Scanning interval
  return distance; // Returns the value of the distance variable
}

```