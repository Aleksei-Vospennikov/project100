#ifndef HANDLE_BUTTON_HPP
#define HANDLE_BUTTON_HPP

#include "button.hpp"

namespace project {

bool handle_turn_on_button(const Button &button_turn_on) {
    static int current_mode = turn_on_mode::off;
    static int buff_mode = turn_on_mode::off;

    if (button_turn_on.get_button_status() == LOW) {
        delay(200);
        if (current_mode == buff_mode)
            current_mode = (current_mode + 1) % turn_on_mode::count_modes;
    } else {
        buff_mode = current_mode;
    }

    return current_mode;
}

} // namespace project

#endif // HANDLE_BUTTON_HPP
