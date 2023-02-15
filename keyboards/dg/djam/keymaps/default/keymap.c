#include QMK_KEYBOARD_H

#define L1_SPC LT(1, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   *     ┌───┬───┬───┐           ┌───┬───┬───┐
   * ┌───┤ S │ D │ F │           │ J │ K │ L ├───┐
   * │ A ├───┼───┼───┤   DJAM    ├───┼───┼───┤ ; │
   * └───┤ Z │ X │ C │           │ N │ M │ , ├───┘
   * ┌───┼───┼───┴─┬─┴─┬───────┬─┴─┬─┴───┼───┼───┐
   * │ ← │ → │     │LSh│ SPACE │RSh│     │ ↑ │ ↓ │
   * └───┴───┘     └───┴───────┴───┘     └───┴───┘
   */
  [0] = LAYOUT(
             KC_S,    KC_D,    KC_F,                               KC_J,    KC_K,    KC_L,
    KC_A,    KC_Z,    KC_X,    KC_C,                               KC_N,    KC_M,    KC_COMM, KC_SCLN,
    KC_LEFT, KC_RGHT,                   KC_LSFT, L1_SPC,  KC_RSFT,                   KC_UP,   KC_DOWN),

  [1] = LAYOUT(
             RGB_HUI, RGB_SAI, RGB_VAI,                            RGB_SPI, _______, RGB_RMOD,
    _______, RGB_HUD, RGB_SAD, RGB_VAD,                            RGB_SPD, _______, RGB_MOD, RGB_TOG,
    _______, _______,                   _______, _______, _______,                   _______, _______),

  [2] = LAYOUT(
             _______, _______, _______,                            _______, _______, _______,
    _______, _______, _______, _______,                            _______, _______, _______, _______,
    _______, _______,                   _______, _______, _______,                   _______, _______),

  [3] = LAYOUT(
             _______, _______, _______,                            _______, _______, _______,
    _______, _______, _______, _______,                            _______, _______, _______, _______,
    _______, _______,                   _______, _______, _______,                   _______, _______)

};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
      tap_code(KC_RGHT);
      tap_code(KC_MS_R);
    } else {
      tap_code(KC_LEFT);
      tap_code(KC_MS_L);
    }
  } else if (index == 1) {
    if (clockwise) {
      tap_code(KC_DOWN);
      tap_code(KC_MS_D);
    } else {
      tap_code(KC_UP);
      tap_code(KC_MS_U);
    }
  }
  return false;
}
#endif
