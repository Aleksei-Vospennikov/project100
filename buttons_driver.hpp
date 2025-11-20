#ifndef HANDLE_BUTTON_HPP
#define HANDLE_BUTTON_HPP

#include "button.hpp"

namespace project {

enum class Play_mode {
    common,
    low_random,
    high_random,
    number_modes,
};

enum class Turn_on_mode {
    off,
    on,
    number_modes,
};

Play_mode next_mode(Play_mode mode) {
    auto value = static_cast<int>(mode);
    value = (value + 1) % static_cast<int>(Play_mode::number_modes);
    return static_cast<Play_mode>(value);
}

Turn_on_mode next_turn_on_mode(Turn_on_mode mode) {
    auto value = static_cast<int>(mode);
    value = (value + 1) % static_cast<int>(Turn_on_mode::number_modes);
    return static_cast<Turn_on_mode>(value);
}

Play_mode get_play_mode(const Button &button_mode) {
    static Play_mode current_mode = Play_mode::common;
    static Play_mode buff_mode = Play_mode::common;

    if (button_mode.get_button_status() == LOW) {
        delay(200);
        if (current_mode == buff_mode)
            current_mode = next_mode(current_mode);
    } else {
        buff_mode = current_mode;
    }

    return current_mode;
}

Turn_on_mode get_turn_on_mode(const Button &button_turn_on) {
    static Turn_on_mode current_mode = Turn_on_mode::off;
    static Turn_on_mode buff_mode = Turn_on_mode::off;

    if (button_turn_on.get_button_status() == LOW) {
        delay(200);
        if (current_mode == buff_mode)
            current_mode = next_turn_on_mode(current_mode);
    } else {
        buff_mode = current_mode;
    }

    return current_mode;
}

bool handle_turn_on_button(const Button &button_turn_on,
                           Hold_servo &holdServo) {
    static Turn_on_mode buff_mode = Turn_on_mode::off;

    if (get_turn_on_mode(button_turn_on) == Turn_on_mode::off) {
        if (buff_mode == Turn_on_mode::on)
            holdServo.set_start_position();
        buff_mode = Turn_on_mode::off;
        return false;
    }

    return true; // mode "on"
}

} // namespace project

#endif // HANDLE_BUTTON_HPP
