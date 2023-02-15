#include "raspico.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    {
        /* Key Matrix to LED Index */
        { 0, 1, 2 }, // { NO_LED, NO_LED, NO_LED },
    },
    {
        /* LED Index to Physical Position */
        // Switch LEDs
        // Underglow LEDs
        {2,2},    {46,2},   {90,2},   {134,2},  {178,2},  {222,2},
        {222,14}, {178,14}, {134,14}, {90,14},  {46,14},  {2,14},
        {2,26},   {46,26},  {90,26},  {134,26}, {178,26}, {222,26},
        {222,38}, {178,38}, {134,38}, {90,38},  {46,38},  {2,38},
        {2,50},   {46,50},  {90,50},  {134,50}, {178,50}, {222,50},
        {222,62}, {178,62}, {134,62}, {90,62},  {46,62},  {2,62},
    },
    {
        /* LED Index to Flag */
        4, 4, 4, 2, 2, 2,
        2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2,
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
