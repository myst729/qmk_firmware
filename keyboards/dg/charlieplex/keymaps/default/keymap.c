#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,
    KC_A,    KC_S,    KC_D,    KC_F,
    KC_Z,    KC_X,    KC_C,    MO(1)),

  [1] = LAYOUT(
    RESET,   BL_INC,  KC_VOLU, KC_BRIU,
    BL_ON,   BL_DEC,  KC_VOLD, KC_BRID,
    BL_OFF,  BL_STEP, KC_MUTE, _______),

  [2] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO),

  [3] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO),

  [4] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO),

  [5] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO),

  [6] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO),

  [7] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO),

};
