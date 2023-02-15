/* STM32F401 */

/* Matrix */
#define DIRECT_PINS {{ B6, B4, A15, B3, A8, B15, B14, B13, B7, B8, B9, B1, B10, B12, A1, A2, A3, A4, A5, A6, A7 }}

/* Backlight */
#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PIN A0
#endif

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN B0
#endif
