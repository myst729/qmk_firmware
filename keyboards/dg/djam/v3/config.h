/* RP2040 */

/* Device */
#define DEVICE_VER 0x0003

/* Matrix */
#define MATRIX_ROW_PINS { GP0, GP1, GP2 }
#define MATRIX_COL_PINS { GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10 }
// { GP0, GP1, GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP11, GP12, GP13, GP14, GP15 }, { GP16, GP17, GP18, GP19, GP20, GP21, GP22, GP26, GP27, GP28 }

/* Backlight */
#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PIN GP11
#endif

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN GP12
#define NOP_FUDGE 0.4
#endif
