#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R,
    KC_A, KC_S, KC_D, KC_F,
    KC_Z, KC_X, KC_C, MO(1)),

  [1] = LAYOUT(
    KC_T, KC_Y, KC_U, KC_I,
    KC_G, KC_H, KC_J, KC_K,
    KC_B, KC_N, KC_M, _______)

};
