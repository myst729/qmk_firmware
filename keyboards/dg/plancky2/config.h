#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7306
#define DEVICE_VER      0x0003
#define MANUFACTURER    Leo Deng
#define PRODUCT         Plancky2
#define DESCRIPTION     40% ortholinear layout keyboard

/* Matrix */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { F0, F5, D5, B5 }
#define MATRIX_COL_PINS { F1, F4, F7, C7, C6, F6, B7, D3, B4, D7, D6, D4 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

#define DEBOUNCE 5
#define TAP_CODE_DELAY 100
#define PREVENT_STUCK_MODIFIERS

/* Command */
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

/* DFU */
#define QMK_ESC_INPUT F0  // usually ROW
#define QMK_ESC_OUTPUT F1 // usually COL
#define QMK_LED B6

#endif