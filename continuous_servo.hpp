#ifndef CONTINUOUS_SERVO_HPP
#define CONTINUOUS_SERVO_HPP

#include <Servo.h>

namespace project {

struct Continuous_servo {
    Servo cont_servo_;
    int cont_servo_pin_;

    Continuous_servo(int cont_servo_pin) : cont_servo_pin_{cont_servo_pin} {}

    void begin() { cont_servo_.attach(cont_servo_pin_); }

    void Rotate(int speed) { cont_servo_.write(speed); }
};

} // namespace project

#endif // CONTINUOUS_SERVO_HPP
