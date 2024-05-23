#ifdef AUDIO_ENABLE
#include "audio.h"
#include "song_list.h"
#endif

#include QMK_KEYBOARD_H

enum custom_keycodes {
    SONG1 = SAFE_RANGE,
    SONG2,
    SONG3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        MO(1),   BL_TOGG, BL_BRTG,
        KC_CAPS, KC_NO,   RGB_MOD,
        SONG1,   SONG2,   SONG3),

    [1] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO)

    // [1] = LAYOUT(
    //     TO(0),   KC_NO,   KC_NO,
    //     JS_0,    JS_1,    JS_2,
    //     JS_3,    JS_4,    JS_5)
};

#ifdef JOYSTICK_ENABLE
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(JOYSTICK_X1_PIN, 0, 512, 1023),
    [1] = JOYSTICK_AXIS_IN(JOYSTICK_Y1_PIN, 0, 512, 1023),
    [2] = JOYSTICK_AXIS_IN(JOYSTICK_X2_PIN, 0, 512, 1023),
    [3] = JOYSTICK_AXIS_IN(JOYSTICK_Y2_PIN, 0, 512, 1023),
};
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
};
#endif

#ifdef AUDIO_ENABLE
float my_song_1[][2] = SONG(CAMPANELLA);
float my_song_2[][2] = SONG(FANTASIE_IMPROMPTU);
float my_song_3[][2] = SONG(NOCTURNE_OP_9_NO_1);

bool process_record_user (uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SONG1:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(my_song_1);
            }
            break;
        case SONG2:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(my_song_2);
            }
            break;
        case SONG3:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(my_song_3);
            }
            break;
    }
    return true;
}
#endif

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_user (uint8_t index, bool active) {
    switch (index) {
        case 0:
#ifdef AUDIO_ENABLE
            if (active) {
                audio_on();
            } else {
                audio_off();
            }
#endif
            break;
        case 1:
#ifdef OLED_ENABLE
            if (active) {
                oled_on();
            } else {
                oled_off();
            }
#endif
            break;
    }
    return true;
}
#endif

#ifdef OLED_ENABLE
bool oled_task_user (void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Layer 0\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Layer 1\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);

    return false;
}
#endif
