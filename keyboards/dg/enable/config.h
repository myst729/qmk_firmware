#pragma once

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7312
#define DEVICE_VER      0x0003
#define MANUFACTURER    Leo Deng
#define PRODUCT         enaBLE

/* Bootmagic & DFU */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* Matrix */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { D0, D1, D2, D3 }
#define MATRIX_COL_PINS { F0, F1, F4, F5, F6, F7, C7, C6, B6, D7, D6, D5 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL
#define UNUSED_PINS
#define DEBOUNCE 5
#define TAP_CODE_DELAY 10

/* LED Indicators */
#define LED_CAPS_LOCK_PIN B0
#define LED_PIN_ON_STATE 0

/* Bluetooth */
#ifdef BLUETOOTH_ENABLE
#define BLUEFRUIT_LE_RST_PIN D4
#define BLUEFRUIT_LE_CS_PIN B4
#define BLUEFRUIT_LE_IRQ_PIN E6
#define BATTERY_LEVEL_PIN B5
#define BATTERY_LEVEL_POLL 5000
#define LED_LOW_BATTERY_PIN B7
#endif

/* VIA */
#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#endif
