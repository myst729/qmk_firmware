#pragma once

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7338
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         F401

/* Bootmagic & DFU */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* Matrix */
#define MATRIX_ROWS 3
#define MATRIX_COLS 10
#define MATRIX_ROW_PINS { A15, B3, B4 }
#define MATRIX_COL_PINS { B1, B0, A7, A6, A5, A4, A3, A2, A1, A0 }
#define UNUSED_PINS
// A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A15, B0, B1, B3, B4, B5, B6, B7, B8, B9, B10, B12, B13, B14, B15, C13
// Avoid A9, A10 if possible, see https://docs.qmk.fm/#/platformdev_blackpill_f411 for more information.
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL
#define DEBOUNCE 5
#define TAP_CODE_DELAY 10

/* LED Indicators */
#define LED_CAPS_LOCK_PIN C13
#define LED_PIN_ON_STATE 0

/* WS2812 RGB */
#ifdef RGBLIGHT_ENABLE
#define RGB_DI_PIN B12
#define RGBLED_NUM 8
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

/* VIA */
#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#endif
