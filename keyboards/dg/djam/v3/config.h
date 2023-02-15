/* STM32F401 */

/* Matrix */
#define DIRECT_PINS {{ B4, A15, B3, C6, C7, A8, B15, B14 }, { B6, B7, B8, B9, B1, B10, B12, B13 }, { A1, A2, A3, A4, A5, A6, A7, C8 }}

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN B0
#endif

/* Encoder */
#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { A13, A0 }
#define ENCODERS_PAD_B { A14, B5 }
#endif
