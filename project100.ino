#include "motors.hpp"
#include "button.hpp"
#include "continuous_servo.hpp"
#include "hold_servo.hpp"
#include "buttons_driver.hpp"

#define WITHOUT_MODES

const int cont_servo_pin = 9;
const int hold_servo_pin = 10;
const int button_turn_on_pin = 26;
const int button_mode_pin = 28;

using namespace project;

Continuous_servo contServo{cont_servo_pin};
Hold_servo holdServo{hold_servo_pin};

Button button_turn_on{button_turn_on_pin};
Button button_mode{button_mode_pin};

Motors motors{3, 4, 5, 6, 7, 8};

void setup() {
  holdServo.begin();
  contServo.begin();
}

void loop() {
#ifdef WITHOUT_MODES
AngleRange angles = {30, 150, 5};
holdServo.update_sweep(angles, 25);
#else
    if (!handle_turn_on_button(button_turn_on, holdServo))
        return;

    auto play_mode = get_play_mode(button_mode);

    switch(play_mode) {
        case Play_mode::common: {
            holdServo.set_start_position();
            break;
        }
        case Play_mode::low_random: {
            AngleRange angles = {75, 105, 1};
            holdServo.update_sweep(angles, 30);
            break;
        }
        case Play_mode::high_random: {
            AngleRange angles = {60, 120, 1};
            holdServo.update_sweep(angles, 25);
            break;
        }
        default: {
            exit(0);
        }
    }
#endif

    int cont_speed = 30;
    contServo.Rotate(cont_speed);

    int driving_speed = 255;
    motors.Rotate(driving_speed);
}
