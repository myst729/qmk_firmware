/* STM32F401 */

/* Matrix */
#define DIRECT_PINS {{ B4, B3, A15, NO_PIN, NO_PIN, B15, B14, B13 }, { B5, B9, B7, B6, A6, A5, A4, B10 }, { B8, A2, A8, A3, A7, B0, B1, NO_PIN }}

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#define WS2812_DI_PIN B12
#endif

/* Encoder */
// #ifdef ENCODER_ENABLE
// #define ENCODERS_PAD_A { A0, A13 }
// #define ENCODERS_PAD_B { A1, A14 }
// #define ENCODER_RESOLUTIONS { 10, 12 }
// #endif
