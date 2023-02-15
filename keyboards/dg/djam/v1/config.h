/* ATMEGA32U4 */

/* Matrix */
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL
#define MATRIX_ROW_PINS { F0, F1, F4 }
#define MATRIX_COL_PINS { C7, C6, B6, B5, B4, D7, D6, D4 }

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN D5
#endif
