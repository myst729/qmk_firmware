#pragma once

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7308
#define DEVICE_VER      0x0002
#define MANUFACTURER    Leo Deng
#define PRODUCT         Enjoy

/* Matrix */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS { D1, C6, B4, B3, B1, E6, D4, D0 }
#define MATRIX_COL_PINS { D2, D3, D7, B5, F6, F7 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL
#define DEBOUNCE 5
#define TAP_CODE_DELAY 10

/* LED Indicators */
#define LED_CAPS_LOCK_PIN B2
#define LED_PIN_ON_STATE 0

/* Backlight */
#define BACKLIGHT_PIN B6
#define BACKLIGHT_LEVELS 5
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 5
#define BACKLIGHT_ON_STATE 0

/* Joystick */
#define JOYSTICK_BUTTON_COUNT 8
#define JOYSTICK_AXES_COUNT 2

/* Pointing Device */
#define ANALOG_JOYSTICK_X_AXIS_PIN F4
#define ANALOG_JOYSTICK_Y_AXIS_PIN F5
