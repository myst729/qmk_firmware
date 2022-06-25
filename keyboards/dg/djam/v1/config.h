/* ATMEGA32U4 */

/* Device */
#define DEVICE_VER 0x0001

/* Bootmagic & DFU */
#define BOOTMAGIC_LITE_ROW 1
#define BOOTMAGIC_LITE_COLUMN 0

/* Matrix */
#define MATRIX_ROWS 3
#define MATRIX_COLS 8
#define MATRIX_ROW_PINS { F0, F1, F4 }
#define MATRIX_COL_PINS { C7, C6, B6, B5, B4, D7, D6, D4 }
#define UNUSED_PINS { B0, D0, D1, D2, D3, E6, F5, F6, F7 }
// { B0, B1, B2, B3, B6, B5, B4, B7 }, { C6, C7 }, { D0, D1, D2, D3, D4, D5, D6, D7 }, { E6 }, { F0, F1, F4, F5, F6, F7 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

/* Backlight */
#define BACKLIGHT_PIN B7

/* RGB Matrix */
#define RGB_DI_PIN D5
