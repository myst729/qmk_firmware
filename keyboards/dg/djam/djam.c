#include "djam.h"

#ifdef DIP_SWITCH_ENABLE
static const uint16_t magnet_threshold_options[] = {
  [0] = MAGNET_THRESHOLD_DEFAULT,
  [1] = MAGNET_THRESHOLD_LIGHT,
  [2] = MAGNET_THRESHOLD_HEAVY,
};

bool dip_switch_update_mask_kb(uint32_t state) {
  magnet_threshold = magnet_threshold_options[state];
  return true;
};
#endif

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
  {
    /* Key Matrix to LED Index */
    { 17, 16, 15, NO_LED, NO_LED, 7, 6, 5 },
    { 21, 17, 16, 15, 7, 6, 5, 1 },
    { 19, 18, 13, 11, 9, 4, 3, NO_LED }
  },
  {
    /* LED Index to Physical Position */
    // Switch LEDs
    {224,14}, {224,24}, {224,33}, {212,57}, {192,57}, {192,38}, {172,38}, {152,38},
    {152,57}, {142,57}, {132,57}, {112,57}, {92,57},  {82,57},  {72,57},
    {72,38},  {52,38},  {32,38},  {32,57},  {12,57},  {0,33},   {0,24},   {0,14},
    // Underglow LEDs
    {0,0},    {87,0},   {137,0},  {224,0},  {222,64}, {168,64}, {56,64},  {2,64},
    // Underglow LEDs for MCU
    {88,49},  {104,49}, {120,49}, {136,49},
  },
  {
    /* LED Index to Flag */
    2, 4, 2, 4, 4, 4, 4, 4,
    2, 4, 2, 4, 2, 4, 2,
    4, 4, 4, 4, 4, 2, 4, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2
  }
};
#endif
