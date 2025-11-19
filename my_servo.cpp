#include <Servo.h>

#include "my_servo.hpp"

void ContinuousServoTest() {
  int delay_time = 1000;

  contServo.write(90);

  for (int speed = 90; speed >= 0; speed-=2) {
    contServo.write(speed);
    delay(delay_time);
  }
}

void HoldAngleServoTest() {
  int delay_time = 100;

  holdServo.write(0);

  for (int angle = 0; angle <= 180; angle+=3) {
    holdServo.write(angle);
    delay(delay_time);
  }
}

void HoldAngleServoRotate(int original_angle, AngleRange_t angles) {
  int delay_time = 10;
  
  holdServo.write(0);               // ??? servo must begin with the original angle remained from the last usage

  for (int angle = original_angle; angle <= angles.right_bound; angle += angles.angle_step) {
    holdServo.write(angle);
    delay(delay_time);
  }

  for (int angle = angles.right_bound; angle >= angles.left_bound;  angle -= angles.angle_step) {
    holdServo.write(angle);
    delay(delay_time);
  }
}

void ContinuousServoRotate(int speed) {
  int delay_time = 1000;
  
  contServo.write(speed);
}
