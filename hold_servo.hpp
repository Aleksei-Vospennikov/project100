#ifndef HOLD_SERVO_HPP
#define HOLD_SERVO_HPP

#include <Servo.h>

struct AngleRange {
  int  left_bound;
  int right_bound;
  int angle_step;
};

struct Hold_servo {
    Servo hold_servo_;
    int hold_servo_pin_;

    Hold_servo(int hold_servo_pin) :
        hold_servo_pin_{hold_servo_pin} {
        hold_servo_.attach(hold_servo_pin);
    }

    void Rotate(int original_angle, AngleRange angles) {
        int delay_time = 10;

        hold_servo_.write(0); // ??? servo must begin with the original angle remained from the last usage

        for (int angle = original_angle; angle <= angles.right_bound; angle += angles.angle_step) {
            hold_servo_.write(angle);
            delay(delay_time);
        }

        for (int angle = angles.right_bound; angle >= angles.left_bound;  angle -= angles.angle_step) {
            hold_servo_.write(angle);
            delay(delay_time);
        }
    }
};

#endif // HOLD_SERVO_HPP
