#pragma once

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7331
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         U2

/* Bootmagic & DFU */
#define BOOTMAGIC_LITE_ROW 4
#define BOOTMAGIC_LITE_COLUMN 0

/* Matrix */
#define MATRIX_ROWS 11
#define MATRIX_COLS 11
#define MATRIX_ROW_PINS { /* ROWS */ C7, C5, D4, D6, /* COLS */ C4, D3, D0, C2, D1, D2, /* ENCODER */ B7 }
#define MATRIX_COL_PINS { /* ROWS */ C7, C5, D4, D6, /* COLS */ C4, D3, D0, C2, D1, D2, /* ENCODER */ B7 }
#define LOGICAL_ROW_COUNT 4
#define DEBOUNCE 5
#define TAP_CODE_DELAY 10

/* LED Indicators */
#define LED_CAPS_LOCK_PIN B1
#define LED_LAYER_STATE_1 B2
#define LED_LAYER_STATE_2 B3

/* Backlight */
#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PIN C6
#define BACKLIGHT_LEVELS 6
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 6
#endif

/* WS2812 RGB */
#ifdef RGBLIGHT_ENABLE
#define RGB_DI_PIN B0
#define RGBLED_NUM 8
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#endif

/* Encoder */
#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B5 }
#define ENCODERS_PAD_B { B4 }
#endif

/* VIA */
#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 3
#endif
