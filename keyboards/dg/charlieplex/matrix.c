#include <stdint.h>
#include <stdbool.h>
#include "matrix.h"
#include "quantum.h"

#define ROW_SHIFTER ((uint16_t)1)

static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

static bool custom_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
  // Store last value of row prior to reading
  matrix_row_t last_row_value = current_matrix[current_row];

  // Clear data in matrix row
  current_matrix[current_row] = 0;

  // Select row and wait for row selecton to stabilize
  setPinOutput(row_pins[current_row]);
  writePinLow(row_pins[current_row]);
  matrix_io_delay();

  // For each col...
  for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {

    // skip reading when index equals (= pin itself)
    if (col_index != current_row) {
      // Check col pin pin_state
      if (readPin(col_pins[col_index]) == 0) {
        // Pin LO, set col bit
        current_matrix[current_row] |= (ROW_SHIFTER << col_index);
      } else {
        // Pin HI, clear col bit
        current_matrix[current_row] &= ~(ROW_SHIFTER << col_index);
      }
    }
  }

  // Unselect row
  setPinInputHigh(row_pins[current_row]);

  return (last_row_value != current_matrix[current_row]);
}

void matrix_init_custom(void) {
  for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
    setPinInputHigh(row_pins[r]);
  }

  for (uint8_t c = 0; c < MATRIX_COLS; c++) {
    setPinInputHigh(col_pins[c]);
  }

  matrix_init_quantum();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
  bool changed = false;

  // Set row, read cols
  for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
    changed |= custom_read_cols_on_row(current_matrix, current_row);
  }

  matrix_scan_quantum();
  return changed;
}
