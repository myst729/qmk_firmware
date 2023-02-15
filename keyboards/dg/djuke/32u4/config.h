/* ATMEGA32U4 */

/* Matrix */
#define DIRECT_PINS {{ B0, B1, B2, B3, B4, B5, B6, D0, D1, D2, D3, D4, D6, D7, E6, F0, F1, F4, F5, F6, F7 }}

/* Backlight */
#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PIN B7
#endif

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN D5
#endif
