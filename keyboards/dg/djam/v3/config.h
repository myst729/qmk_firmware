/* STM32F401CCU6 top SMT */

/* Device */
#define DEVICE_VER 0x0003

/* Bootmagic & DFU */
#define BOOTMAGIC_LITE_ROW 1
#define BOOTMAGIC_LITE_COLUMN 0

/* Matrix */
#define MATRIX_ROWS 3
#define MATRIX_COLS 8
#define MATRIX_ROW_PINS { A6, A7, A1 }
#define MATRIX_COL_PINS { B3, B4, B5, A2, A5, A4, A3, B1 }
#define UNUSED_PINS { A8, A9, A10, A15 }, { B6, B7, B8, B9, B10, B12, B13, B14, B15 }, { C13 }
// { A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A15 }, { B0, B1, B3, B4, B5, B6, B7, B8, B9, B10, B12, B13, B14, B15 }, { C13 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

/* Backlight */
#define BACKLIGHT_PIN A0

/* RGB Matrix */
#define RGB_DI_PIN B0
