/* STM32F401 */

/* Matrix */
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL
#define MATRIX_ROW_PINS { B3, B4, B5 }
#define MATRIX_COL_PINS { B1, B0, A7, A6, A5, A4, A3, A2 }

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN A0
#endif
