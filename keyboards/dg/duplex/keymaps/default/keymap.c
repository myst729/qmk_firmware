#include QMK_KEYBOARD_H

#define CTL_Z       CTL_T(KC_Z)
#define ALT_X       ALT_T(KC_X)
#define GUI_C       GUI_T(KC_C)
#define L1_SPC      LT(1, KC_SPC)
#define L2_BSPC     LT(2, KC_BSPC)
#define L3_V        LT(3, KC_V)
#define ALT_B       RALT_T(KC_B)
#define GUI_N       RGUI_T(KC_N)
#define CTL_M       RCTL_T(KC_M)
#define SFT_ENT     RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ESC,
    CTL_Z,   ALT_X,   GUI_C,   L3_V,    L2_BSPC, L1_SPC,  ALT_B,   GUI_N,   CTL_M,   SFT_ENT),

  [1] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_COMM, KC_DOT,  KC_SLSH, KC_SCLN, KC_QUOT,
    KC_TAB,  KC_GRV,  KC_CAPS, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),

  [2] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_PSCR, KC_SLCK, KC_PAUS,
    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BRID, KC_BRIU, KC_INS,  KC_HOME, KC_PGUP,
    KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_DEL,  KC_END,  KC_PGDN),

  [3] = LAYOUT(
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

  [4] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

  [5] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)

};
