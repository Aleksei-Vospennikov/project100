#ifndef HOLD_SERVO_HPP
#define HOLD_SERVO_HPP

#include <Servo.h>

namespace project {

struct AngleRange {
    int left_bound;
    int right_bound;
    int angle_step;
};

struct Hold_servo {
  private:
    Servo hold_servo_;
    int hold_servo_pin_;
    int current_angle_ = 90;
    bool direction_up_ = true; // true - up, false - down
    unsigned long last_update_ = 0;

  public:
    Hold_servo(int hold_servo_pin) : hold_servo_pin_{hold_servo_pin} {}

    void begin() { hold_servo_.attach(hold_servo_pin_); }

    void set_start_position() {}

    void update_sweep(AngleRange range, unsigned long interval_ms = 30) {
        unsigned long now = millis();
        if (now - last_update_ < interval_ms)
            return;

        if (direction_up_) {
            current_angle_ += range.angle_step;
            if (current_angle_ >= range.right_bound) {
                current_angle_ = range.right_bound;
                direction_up_ = false;
            }
        } else {
            current_angle_ -= range.angle_step;
            if (current_angle_ <= range.left_bound) {
                current_angle_ = range.left_bound;
                direction_up_ = true;
            }
        }

        hold_servo_.write(current_angle_);
        last_update_ = now;
    }
};

} // namespace project

#endif // HOLD_SERVO_HPP
