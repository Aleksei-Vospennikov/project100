#include "motors.hpp"
#include "button.hpp"
#include "continuous_servo.hpp"
#include "hold_servo.hpp"
#include "handle_button.hpp"

const int cont_servo_pin = 9;
const int hold_servo_pin = 10;

using namespace project;

Continuous_servo contServo{cont_servo_pin};
Hold_servo holdServo{hold_servo_pin};

Button button_turn_on{26};
Button button_angle{28};

Motors motors{3, 4, 5, 6, 7, 8};

void setup() {}

void loop() {
    static int mode = 0;
    static int buff_mode = 0;

    if (get_turn_on_mode(button_turn_on) == turn_on_mode::off) {

    }

    auto mode_state = button_angle.get_button_status();

    int  original_angle = 60;
    AngleRange angles = {60, 120, 1};
    holdServo.Rotate(original_angle, angles);

    int cont_speed = 30;
    contServo.Rotate(cont_speed);

    int driving_speed = 255;
    motors.Rotate(driving_speed);
}
