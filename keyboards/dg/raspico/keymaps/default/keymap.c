#include "print.h"
#include "i2c_master.h"
#include "spi_master.h"

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(KC_A,    KC_B,    KC_C,    KC_D),
  [1] = LAYOUT(KC_1,    KC_2,    KC_3,    KC_4),
  [2] = LAYOUT(KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),
  [3] = LAYOUT(KC_HOME, KC_END,  KC_PGUP, KC_PGDN),
  [4] = LAYOUT(KC_LCTL, KC_LGUI, KC_LALT, KC_ESC),
  [5] = LAYOUT(_______, RGB_TOG, RGB_MOD, RGB_RMOD)
};

uint16_t animation_timer;
spi_status_t spi_value;
// i2c_status_t i2c_value;
uint8_t i2c_data[16] = {0};

void keyboard_post_init_user(void) {
  debug_enable = true;
  debug_matrix = true;
  i2c_init();
  spi_init();
}

void matrix_scan_user(void) {
  if (timer_elapsed(animation_timer) > 25) {
    i2c_start(MY_I2C_ADDRESS);
    i2c_receive(MY_I2C_ADDRESS, (uint8_t*)i2c_data, 16, MY_I2C_TIMEOUT);
    i2c_stop();
    uprintf("I2C: ");
    for (int i = 0; i < 16; i++) {
      uprintf("%d ", i2c_data[i]);
    }
    uprintf("\n");

    spi_start(MY_SPI_SS_PIN, true, 0, 2);
    spi_value = spi_read();
    spi_stop();
    uprintf("SPI: %d\n", spi_value);

    animation_timer = timer_read();
  }
}
