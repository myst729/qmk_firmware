#include "analog.h"
#include "matrix.h"
#include "quantum.h"
#include "djam.h"

static const pin_t sig_pins[MATRIX_ROWS] = MUX_SIG_PINS;
static const pin_t channel_pins[MUX_CHANNELS] = MUX_CHANNEL_PINS;
static uint8_t sig_mux[MATRIX_ROWS];
static uint16_t mux_adc_raw_value[MATRIX_ROWS][MATRIX_COLS];

static void set_mux_channel(uint8_t col_index) {
  for (uint8_t i = 0; i < MUX_CHANNELS; i++) {
    setPinOutput(channel_pins[i]);
    writePin(channel_pins[i], (col_index >> i) & 1);
  }
  matrix_output_select_delay();
};

static void read_mux_adc_raw(void) {
  for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
    set_mux_channel(col_index);
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
      mux_adc_raw_value[row_index][col_index] = adc_read(sig_mux[row_index]);
    }
  }
};

static void update_temp_matrix(matrix_row_t custom_matrix[], matrix_row_t current_matrix[]) {
  read_mux_adc_raw();
  for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
    matrix_row_t current_row_value = 0;
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
      // Previous key state
      // bool prev_state = (current_matrix[row_index] >> col_index) & 1;
      uint16_t value = mux_adc_raw_value[row_index][col_index];
      if (value < magnet_threshold) {
        // Press
        current_row_value |= (1 << col_index);
      } else {
        // Release
        current_row_value &= ~(1 << col_index);
      }
    }

    // Update the matrix
    custom_matrix[row_index] = current_row_value;
  }
};

void matrix_init_custom(void) {
  for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
    // Uncomment this for ARM MCUs
    // palSetLineMode(sig_pins[i], PAL_MODE_INPUT_ANALOG);
    sig_mux[i] = pinToMux(sig_pins[i]);
  }

  for (uint8_t j = 0; j < MUX_CHANNELS; j++) {
    setPinInputHigh(channel_pins[j]);
  }
};

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
  static matrix_row_t temp_matrix[MATRIX_ROWS] = {0};
  update_temp_matrix(temp_matrix, current_matrix);

  bool changed = memcmp(current_matrix, temp_matrix, sizeof(temp_matrix)) != 0;
  if (changed) {
    memcpy(current_matrix, temp_matrix, sizeof(temp_matrix));
  }
  return changed;
};
