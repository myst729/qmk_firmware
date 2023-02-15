/* STM32F401 */

/* Matrix */
#define DIRECT_PINS {{ B4, A15, B3, NO_PIN, NO_PIN, A8, B15, B14 }, { B5, B6, B7, B8, B1, B10, B12, B13 }, { B9, A2, A3, A4, A5, A6, A7, NO_PIN }}

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#define WS2812_DI_PIN B0
#endif

/* Encoder */
#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { A13, A0 }
#define ENCODERS_PAD_B { A14, A1 }
#define ENCODER_RESOLUTIONS { 10, 12 }
#endif
