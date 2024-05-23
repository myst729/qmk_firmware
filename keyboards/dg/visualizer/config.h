#pragma once

#include "config_common.h"

/* Matrix */
#define MATRIX_ROWS 1
#define MATRIX_COLS 3
#define DIRECT_PINS {{ B4, B5, B6 }}
#define DEBOUNCE 5

/* RGB Lighting */
#ifdef RGBLIGHT_ENABLE
#define RGB_DI_PIN B12
#define RGBLED_NUM 36
#define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 4, 5, 11, 10, 9, 8, 7, 6, 12, 13, 14, 15, 16, 17, 23, 22, 21, 20, 19, 18, 24, 25, 26, 27, 28, 29, 35, 34, 33, 32, 31, 30 }
#endif

/* OLED */
#ifdef OLED_ENABLE
#define OLED_DISPLAY_128X32
#define I2C1_SCL_PIN B8
#define I2C1_SDA_PIN B9
#define I2C_DRIVER I2CD1
#define OLED_BRIGHTNESS 128
#endif
