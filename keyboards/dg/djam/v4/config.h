/* RP2040 */

/* Matrix */
#define DIRECT_PINS {{ GP1, GP2, GP3, NO_PIN, NO_PIN, GP6, GP7, GP8 }, { GP9, GP10, GP11, GP12, GP13, GP14, GP15, GP16 }, { GP17, GP18, GP19, GP20, GP21, GP22, GP23, NO_PIN }}

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#define WS2812_DI_PIN GP0
// #define NOP_FUDGE 0.4
// #define WS2812_PIO_USE_PIO1
#endif

/* Encoder */
#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { GP26, GP27 }
#define ENCODERS_PAD_B { GP28, GP29 }
#endif
