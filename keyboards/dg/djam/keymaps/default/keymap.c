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
  const int ccwKeys[] = { KC_1, KC_3 };
  const int cwKeys[] = { KC_2, KC_4 };

  if (clockwise) {
    tap_code(KC_MS_R);
    tap_code(cwKeys[index]);
  } else {
    tap_code(KC_MS_L);
    tap_code(ccwKeys[index]);
  }

  return true;
}
#endif
