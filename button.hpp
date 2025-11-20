#ifndef BUTTON_HPP
#define BUTTON_HPP

struct Button {
    int pin_;
    bool status_{false};

    Button(int pin) : pin_{pin} {}
    bool get_button_status() const { return status_; }

    void update_button_status() { status_ = digitalRead(pin_); }
};

#endif // BUTTON_HPP