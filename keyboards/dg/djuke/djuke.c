#include "djuke.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
  {
    /* Key Matrix to LED Index */
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
  },
  {
    /* LED Index to Physical Position */
    {221,5},  {221,46},
    {204,60}, {193,60}, {185,60}, {174,60}, {156,60}, {126,60},
    {195,43}, {183,43}, {176,43}, {164,43}, {156,43}, {144,43},
    {136,52}, {128,52}, {120,52},
    {118,60}, {106,60},
    {112,52}, {104,52}, {96,52},  {88,52},
    {80,43},  {68,43},  {60,43},  {48,43},  {41,43},  {29,43},
    {98,60},  {68,60},  {50,60},  {39,60},  {31,60},  {20,60},
    {3,46},   {3,5}
  },
  {
    /* LED Index to Flag */
    2, 2,
    2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2,
    2, 2, 2,
    2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2,
    2, 2
  }
};
#endif
