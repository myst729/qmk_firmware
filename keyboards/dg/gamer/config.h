#pragma once

#include "config_common.h"

/* Device */
// #define PRODUCT         Gamer
// #define MANUFACTURER    Leo Deng
// #define VENDOR_ID       0xDE29
// #define PRODUCT_ID      0x7344
// #define DEVICE_VER      0x0001

/* Matrix */
#define MATRIX_ROWS 1
#define MATRIX_COLS 9
#define DIRECT_PINS {{ A7, A15, B3, B4, B7, B6, B5, B9, B8 }}
#define DEBOUNCE 5

/* Joystick */
#define JOYSTICK_BUTTON_COUNT 8
#define JOYSTICK_AXIS_COUNT 2
#define JOYSTICK_AXES_COUNT 2
#define JOYSTICK_AXIS_RESOLUTION 10
#define JOYSTICK_X_PIN A2
#define JOYSTICK_Y_PIN A3

/* EEPRom */
#define FEE_MCU_FLASH_SIZE 32
#define FEE_PAGE_COUNT 2
#define FEE_PAGE_SIZE 1024
