#include "charlieplex.h"

#ifdef LED_MATRIX_ENABLE

const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 * driver
 * |  LED address
 * |  | */
  {0, C2_5}, {0, C3_5}, {0, C4_5}, {0, C5_5},
  {0, C2_6}, {0, C3_6}, {0, C4_6}, {0, C5_6},
  {0, C2_7}, {0, C3_7}, {0, C4_7}, {0, C5_7},
};

led_config_t g_led_config = {
  {
    // Key Matrix to LED Index
    { NO_LED, 1, 2, 3 },
    { 0, NO_LED, 6, 7 },
    { 4, 5, NO_LED, 11 },
    { 8, 9, 10, NO_LED }
  },
  {
    // LED Index to Physical Position
    { 1,  1 }, { 75,  1 }, { 149,  1 }, { 223,  1 },
    { 1, 32 }, { 75, 32 }, { 149, 32 }, { 223, 32 },
    { 1, 63 }, { 75, 63 }, { 149, 63 }, { 223, 63 }
  },
  {
    // LED Index to Flag
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4
  }
};

#endif
