#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_NO, JS_0, JS_1, JS_2, JS_3, JS_4, JS_5, JS_6, JS_7)
};

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(JOYSTICK_X_PIN, 0, 512, 1023),
    [1] = JOYSTICK_AXIS_IN(JOYSTICK_Y_PIN, 1023, 512, 0),
};
