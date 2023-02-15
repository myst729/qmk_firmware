#include "qmkool.h"

void keyboard_pre_init_kb(void) {
  UHWCON &= ~(1 << UVREGE);
  keyboard_pre_init_user();
};

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
  {
    /* Key Matrix to LED Index */
    { NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED }
  }, {
    /* LED Index to Physical Position */
    {0,0}, {224,0},  {224,64}, {0,64}
  }, {
    /* LED Index to Flag */
    2, 2, 2, 2
  }
};

void suspend_power_down_kb(void) {
  rgb_matrix_set_suspend_state(true);
  suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
  rgb_matrix_set_suspend_state(false);
  suspend_wakeup_init_user();
}

#endif
