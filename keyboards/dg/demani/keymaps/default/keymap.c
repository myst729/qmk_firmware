#include QMK_KEYBOARD_H

#define L1_SPC LT(1, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * ┌───┬───┬───┬───┐
   * │ Q │ W │ E │ R │
   * └───┴───┴───┴───┘
   *                      ┌───┐
   *   ┌───┬───┬───┐      │ ● │
   *   │ A │ S │ D │      └───┘
   * ┌─┴─┬─┴─┬─┴─┬─┴─┐
   * │ Z │ X │ C │ V │
   * └───┴───┴───┴───┘
   */
  [0] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,
    KC_A,    KC_S,    KC_D,
    KC_Z,    KC_X,    KC_C,    KC_V),

  [1] = LAYOUT(
    RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
    RGB_MOD, RGB_TOG, RGB_RMOD,
    RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD),

  [2] = LAYOUT(
    _______, _______, _______, _______,
    _______, _______, _______,
    _______, _______, _______, _______),

  [3] = LAYOUT(
    _______, _______, _______, _______,
    _______, _______, _______,
    _______, _______, _______, _______)
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
  [2] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
  [3] = { ENCODER_CCW_CW(KC_MS_L, KC_MS_R) },
};
