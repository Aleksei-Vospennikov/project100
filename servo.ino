#include <Servo.h>

#include "my_servo.hpp"
#include "motors.hpp"

Servo contServo;
Servo holdServo;

void setup() {
  Button mode{26};
  Button angle{28};

  Motors{3, 4, 5, 6, 7, 8};

  holdServo.attach(hold_servo_pin);
  contServo.attach(cont_servo_pin);
}

void loop() {
  int  original_angle = 60;
  AngleRange_t angles = {60, 120, 1};
  HoldAngleServoRotate(original_angle, angles);

  int cont_speed = 30;
  ContinuousServoRotate(cont_speed);

  int driving_speed = 255;
  Motors.DrivingMotorsRotate(driving_speed);
}