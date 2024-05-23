#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif

enum dg_custom_keycodes {
  DG_BATT = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SLSH, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, MO(1),      KC_SPC,           KC_SPC,        MO(2),   KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_PGUP),

  [1] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_CAPS, KC_INS,  KC_HOME, KC_PGUP, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______,
    _______, KC_DEL,  KC_END,  KC_PGDN, _______, _______, KC_SCLN, KC_QUOT, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______,          _______,       _______, _______, _______, _______, KC_VOLD, KC_VOLU),

  [2] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, _______, _______, DG_BATT,
    _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______,
    _______, _______, _______, _______,    RESET,            _______,       _______, _______, _______, _______, KC_BRID, KC_BRIU),

  [3] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______,          _______,       _______, _______, _______, _______, _______, _______)

};

#ifdef BLUETOOTH_ENABLE
void tap_battery_level(void) {
  int digits[10] = { KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9 };
  uint8_t percentage = battery_level();

  if (percentage <= 0) {
    tap_code(KC_0);
  } else if (percentage >= 100) {
    tap_code(KC_O);
    tap_code(KC_K);
  } else {
    if (percentage >= 10) {
      int index10 = (percentage / 10) % 10;
      int digit10 = digits[index10];
      tap_code(digit10);
    }
    int index1 = percentage % 10;
    int digit1 = digits[index1];
    tap_code(digit1);
  }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DG_BATT:
      if (record->event.pressed) {
#ifdef BLUETOOTH_ENABLE
        tap_battery_level();
#endif
      }
      break;
  }
  return true;
}

/* Audio */
#ifdef AUDIO_ENABLE
float tone_caps_on[][2] = SONG(Q__NOTE(_C4), Q__NOTE(_G4));
float tone_caps_off[][2] = SONG(Q__NOTE(_G4), Q__NOTE(_C4));

bool led_update_user(led_t led_state) {
  static uint8_t caps_state = 0;
  if (caps_state != led_state.caps_lock) {
    if (led_state.caps_lock) {
      PLAY_SONG(tone_caps_on);
    } else {
      PLAY_SONG(tone_caps_off);
    }
    caps_state = led_state.caps_lock;
  }
  return true;
};
#endif

/* Encoders */
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  uint8_t layer = biton32(layer_state);
  if (layer == 0) {
    tap_code(clockwise ? KC_VOLU : KC_VOLD);
  } else {
    tap_code(clockwise ? KC_BRIU : KC_BRID);
  }
  // if (clockwise) {
  //   tap_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 3, .col = 6 }));
  // } else {
  //   tap_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 3, .col = 4 }));
  // }
  return true;
}
#endif

/* DIP Switch */
#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
#ifdef AUDIO_ENABLE
      if(active) {
          audio_off();
      } else { 
          audio_on();
      }
#endif
      break;
  }
  return true;
}
#endif

/* RGB Lighting */
#ifdef RGBLIGHT_ENABLE
// RGB indicator LEDs
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 1, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {2, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_blink_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 3, HSV_CYAN}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_capslock_layer,
  my_layer1_layer,
  my_layer2_layer,
  my_blink_layer
);

void keyboard_post_init_user(void) {
  rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(0, led_state.caps_lock);
  return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, 0));
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(1, layer_state_cmp(state, 1));
  rgblight_set_layer_state(2, layer_state_cmp(state, 2));
  return state;
}
#endif
