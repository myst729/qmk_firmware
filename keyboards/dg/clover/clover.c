#include "clover.h"
#ifdef BLUETOOTH_ENABLE
#include "bluefruit_le.h"
#endif

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
  {
    /* Key Matrix to LED Index */
    { NO_LED, NO_LED, NO_LED, NO_LED, 1,      3,      5,      7,      9,      11 },
    { NO_LED, NO_LED, NO_LED, NO_LED, 13,     15,     17,     19,     21,     23 },
    { NO_LED, NO_LED, NO_LED, NO_LED, 25,     27,     29,     31,     33,     35 },
    { NO_LED, NO_LED, NO_LED, NO_LED, 37,     39,     NO_LED, 41,     43,     45 },
    { 0,      12,     24,     36,     NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { 2,      14,     26,     38,     NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { 4,      16,     28,     40,     NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { 6,      18,     30,     NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { 8,      20,     32,     42,     NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { 10,     22,     34,     44,     NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
  }, {
    /* LED Index to Physical Position */
    // Switch LEDs
    {2,2},    {22,2},   {42,2},   {62,2},   {82,2},   {102,2},  {122,2},  {142,2},  {162,2},  {182,2},  {202,2},  {222,2},
    {2,22},   {22,22},  {42,22},  {62,22},  {82,22},  {102,22}, {122,22}, {142,22}, {162,22}, {182,22}, {202,22}, {222,22},
    {2,42},   {22,42},  {42,42},  {62,42},  {82,42},  {102,42}, {122,42}, {142,42}, {162,42}, {182,42}, {202,42}, {222,42},
    {2,62},   {22,62},  {42,62},  {62,62},       {92,62},            {132,62},      {162,62}, {182,62}, {202,62}, {222,62},
    // Underglow LEDs
    {10,10},  {78,10},  {146,10}, {214,10},
    {10,53},  {78,53},  {146,53}, {214,53},
  }, {
    /* LED Index to Flag */
    // Switch LEDs
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4,   4,   4,   4, 4, 4, 4,
    // Underglow LEDs
    2, 2, 2, 2,
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

#ifdef BLUETOOTH_ENABLE
uint8_t battery_level(void) {
  float min_voltage = 3.2;
  float max_voltage = 4.2;
  float voltage = bluefruit_le_read_battery_voltage() * 2 * 3.3 / 1024;
  if (voltage < min_voltage) return 0;
  if (voltage > max_voltage) return 100;
  return (voltage - min_voltage) / (max_voltage - min_voltage) * 100;
}
#endif

void matrix_scan_kb(void) {
  static uint16_t counter = BATTERY_POLL;
  counter++;

  if (counter > BATTERY_POLL) {
    counter = 0;
#ifdef BLUETOOTH_ENABLE
    if (battery_level() < 20) {
      // TODO: blink RGB indicator
    }
#endif
  }

  matrix_scan_user();
}
