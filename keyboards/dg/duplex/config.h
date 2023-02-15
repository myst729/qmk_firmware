#pragma once

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7329
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         Duplex

/* Bootmagic & DFU */
#define BOOTMAGIC_LITE_ROW 3
#define BOOTMAGIC_LITE_COLUMN 0

/* Matrix */
#define MATRIX_ROWS 8
#define MATRIX_COLS 8
#define MATRIX_ROW_PINS { /* ROWS */ F0, F1, F4, /* COLS */ F5, F6, F7, B7, D2 }
#define MATRIX_COL_PINS { /* ROWS */ F0, F1, F4, /* COLS */ F5, F6, F7, B7, D2 }
#define LOGICAL_ROW_COUNT 3
#define DEBOUNCE 5
#define TAP_CODE_DELAY 10

/* Bluetooth */
#ifdef BLUETOOTH_ENABLE
#define ADAFRUIT_BLE_RST_PIN D4
#define ADAFRUIT_BLE_CS_PIN B4
#define ADAFRUIT_BLE_IRQ_PIN E6
#define BATTERY_LEVEL_PIN B5
#endif

/* VIA */
#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#endif
