#ifndef BUTTON_HPP
#define BUTTON_HPP

namespace project {

struct Button {
    int pin_;

    Button(int pin) : pin_{pin} { pinMode(pin_, INPUT_PULLUP); }

    int get_button_status() const {
        auto button_state = digitalRead(pin_);
        return button_state;
    }
};

} // namespace project

#endif // BUTTON_HPP
