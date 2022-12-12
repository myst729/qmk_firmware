/* STM32F */

/* Device */
#define DEVICE_VER 0x0002

/* Matrix */
#define MATRIX_ROW_PINS { B3, B4, B5 }
#define MATRIX_COL_PINS { B1, B0, A7, A6, A5, A4, A3, A2 }
// { A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A15 }, { B0, B1, B3, B4, B5, B6, B7, B8, B9, B10, B12, B13, B14, B15 }, { C13 }

/* Backlight */
#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PIN B6
#endif

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN A0
#endif
