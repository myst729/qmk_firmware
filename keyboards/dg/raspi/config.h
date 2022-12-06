#pragma once

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7340
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         Raspi

/* Bootmagic & DFU */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* Matrix */
#define MATRIX_ROWS 3
#define MATRIX_COLS 10
#define MATRIX_ROW_PINS { GP0, GP1, GP2 }
#define MATRIX_COL_PINS { GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP11, GP12 }
// #define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL
#define DEBOUNCE 5
#define TAP_CODE_DELAY 10

/* LED Indicators */
#define LED_CAPS_LOCK_PIN GP17
#define LED_PIN_ON_STATE 0

/* WS2812 RGB */
#ifdef RGBLIGHT_ENABLE
#define RGB_DI_PIN GP18
#define RGBLED_NUM 8
// #define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

/* VIA */
#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#endif

// /* ChibiOS SPI definitions */
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN GP26
#define SPI_MOSI_PIN GP27
#define SPI_MISO_PIN GP28

/* Double tap the side button to enter bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP13
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
