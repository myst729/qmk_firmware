#include "enable.h"

#ifdef BLUETOOTH_ENABLE
#include <stdio.h>
#include "bluefruit_le.h"

uint8_t bluefruit_le_read_battery_level(void) {
  float min_voltage = 3.2;
  float max_voltage = 4.2;
  float voltage     = bluefruit_le_read_battery_voltage() * 2 * 3.3 / 1024;
  if (voltage <= min_voltage) {
    return 0;
  };
  if (voltage >= max_voltage) {
    return 100;
  }
  return (voltage - min_voltage) / (max_voltage - min_voltage) * 100;
}

void tap_battery_level(void) {
  char result[4];
  snprintf(result, sizeof(result), "%d", bluefruit_le_read_battery_level());
  send_string(result);
}

void set_low_battery_led(void) {
  bool low_battery = bluefruit_le_read_battery_level() < 25;
  writePin(LED_LOW_BATTERY_PIN, low_battery);
}
#endif

void matrix_scan_kb(void) {
#ifdef BLUETOOTH_ENABLE
  static uint16_t counter = BATTERY_LEVEL_POLL;
  counter++;
  if (counter > BATTERY_LEVEL_POLL) {
    counter = 0;
    set_low_battery_led();
  }
#endif
  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DG_BATT:
      if (record->event.pressed) {
#ifdef BLUETOOTH_ENABLE
        tap_battery_level();
#endif
      }
      break;
  }
  return process_record_user(keycode, record);
}
