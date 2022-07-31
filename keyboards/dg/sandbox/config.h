#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7335
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         SandBox

/* Bootmagic & DFU */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* Matrix */
#define MATRIX_ROWS 6
#define MATRIX_COLS 18
#define MATRIX_ROW_PINS { A15, A4, A3, A2, A1, A0 }
#define MATRIX_COL_PINS { B13, A10, B12, B14, B15, A8, A9, B11, A6, A7, B0, B1, B2, B10, C15, C14, C13, B8 }
#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE 5
#define TAP_CODE_DELAY 10

/* LED Indicators */
#define LED_CAPS_LOCK_PIN B9
// #define LED_PIN_ON_STATE 1

/* Backlight */
#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PIN B5
#define BACKLIGHT_LEVELS 10
// #define BACKLIGHT_BREATHING
// #define BREATHING_PERIOD 5
// #define BACKLIGHT_ON_STATE 1
#endif

/* VIA */
#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 2
#endif
