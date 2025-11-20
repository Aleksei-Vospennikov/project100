#ifndef CONTINUOUS_SERVO_HPP
#define CONTINUOUS_SERVO_HPP

#include <Servo.h>

struct Continuous_servo {
    Servo cont_servo_;

    void ContinuousServoRotate(int speed) {
        int delay_time = 1000;

        contServo.write(speed);
    }
}

#endif // CONTINUOUS_SERVO_HPP
