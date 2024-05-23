#include "analog.h"
#include "matrix.h"
#include "quantum.h"
#include "magnet.h"

static const pin_t channel_pins[MUX_CHANNELS] = MUX_CHANNEL_PINS;
static const pin_t sig_pins[MATRIX_COLS] = MUX_SIG_PINS;
static int16_t matrix_raw_value[MATRIX_ROWS][MATRIX_COLS];
#ifdef HAL_USE_ADC // ARM MCUs
static adc_mux sig_mux[MATRIX_COLS];
#else
static uint8_t sig_mux[MATRIX_COLS];
#endif

static void custom_select_row(uint8_t row_index) {
  // Select mux channel
  for (uint8_t channel_index = 0; channel_index < MUX_CHANNELS; channel_index++) {
    setPinOutput(channel_pins[channel_index]);
    writePin(channel_pins[channel_index], (row_index >> channel_index) & 1);
  }
  matrix_output_select_delay();
};

static void custom_read_matrix_raw(void) {
  for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
    custom_select_row(row_index);
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
      matrix_raw_value[row_index][col_index] = adc_read(sig_mux[col_index]); // analogReadPin
    }
  }
};

static void custom_update_matrix(matrix_row_t custom_matrix[], matrix_row_t current_matrix[]) {
  custom_read_matrix_raw();
  for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
    matrix_row_t current_row_value = 0;
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
      // Previous key state
      // bool prev_state = (current_matrix[row_index] >> col_index) & 1;
      uint16_t value = matrix_raw_value[row_index][col_index];
      if (value < magnet_threshold) {
        // Pressed
        current_row_value |= (1 << col_index);
      } else {
        // Released
        current_row_value &= ~(1 << col_index);
      }
    }
    custom_matrix[row_index] = current_row_value;
  }
};

void matrix_init_custom(void) {
  for (uint8_t channel_index = 0; channel_index < MUX_CHANNELS; channel_index++) {
    setPinInputHigh(channel_pins[channel_index]);
  }

  for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
#ifdef HAL_USE_ADC // ARM MCUs
    palSetLineMode(sig_pins[col_index], PAL_MODE_INPUT_ANALOG);
#endif
    sig_mux[col_index] = pinToMux(sig_pins[col_index]);
  }
};

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
  static matrix_row_t temp_matrix[MATRIX_ROWS] = {0};
  custom_update_matrix(temp_matrix, current_matrix);

  bool changed = memcmp(current_matrix, temp_matrix, sizeof(temp_matrix)) != 0;
  if (changed) {
    memcpy(current_matrix, temp_matrix, sizeof(temp_matrix));
  }
  return changed;
};
