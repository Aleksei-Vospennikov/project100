#include "motors.hpp"
#include "button.hpp"
#include "continuous_servo.hpp"
#include "hold_servo.hpp"

const int cont_servo_pin = 9;
const int hold_servo_pin = 10;

Continuous_servo contServo{cont_servo_pin};
Hold_servo holdServo{hold_servo_pin};

Button mode{26};
Button angle{28};

Motors motors{3, 4, 5, 6, 7, 8};

void setup() {

}

void loop() {
  int  original_angle = 60;
  AngleRange angles = {60, 120, 1};
  holdServo.Rotate(original_angle, angles);

  int cont_speed = 30;
  contServo.Rotate(cont_speed);

  int driving_speed = 255;
  motors.DrivingMotorsRotate(driving_speed);
}
