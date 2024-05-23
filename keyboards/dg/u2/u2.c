#include "u2.h"

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
  uint8_t layer = get_highest_layer(layer_state);
  if (clockwise) {
    tap_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 0, .col = 10 }));
  } else {
    tap_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 10, .col = 0 }));
  }
  return encoder_update_user(index, clockwise);
}
#endif

layer_state_t layer_state_set_kb(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case 1:
      writePin(LED_LAYER_STATE_1, true);
      writePin(LED_LAYER_STATE_2, false);
      break;
    case 2:
      writePin(LED_LAYER_STATE_1, false);
      writePin(LED_LAYER_STATE_2, true);
      break;
    default:
      writePin(LED_LAYER_STATE_1, false);
      writePin(LED_LAYER_STATE_2, false);
  }
  return layer_state_set_user(state);
}
