#ifndef MY_SERVO_HPP
#define MY_SERVO_HPP

#include <Servo.h>

const int cont_servo_pin = 9;
const int hold_servo_pin = 10;

struct AngleRange {
  int  left_bound_;
  int right_bound_;
  int angle_step_;
};

void ContinuousServoTest();
void ContinuousServoRotate();

void HoldAngleServoTest(int speed);
void HoldAngleServoRotate(int original_angle, AngleRange angles);

#endif // MY_SERVO_HPP
