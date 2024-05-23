#pragma once

/* MUX: RS2252XS16, 2v8 */
#define MUX_CHANNELS 2
#define MUX_CHANNEL_PINS { B3, B4 }
#define MUX_SIG_PINS { A0, A1, A2, A3 }

/* MUX: 74HC4051D, 1v8 */
// #define MUX_CHANNELS 3
// #define MUX_CHANNEL_PINS { B3, B4, B5 }
// #define MUX_SIG_PINS { A0, A1, A2, A3 }

/* MUX: CD74HC4067M, 1v16 */
// #define MUX_CHANNELS 4
// #define MUX_CHANNEL_PINS { B3, B4, B5, B6 }
// #define MUX_SIG_PINS { A0, A1, A2, A3 }

/* Matrix */
#define MATRIX_ROWS 3 // Used mux channels, max = 2 ^ MUX_CHANNELS
#define MATRIX_COLS 4 // Total mux sig pins, MUX_COUNT * MUX_OUTPUT
#define MATRIX_ROW_PINS { NO_PIN, NO_PIN, NO_PIN }
#define MATRIX_COL_PINS { NO_PIN, NO_PIN, NO_PIN, NO_PIN }

/* Magnet Switch Trigger */
#define DIP_SWITCH_PINS { B12, B13 }
#define MAGNET_THRESHOLD_TOP 486 // stay still
#define MAGNET_THRESHOLD_LIGHT 430
#define MAGNET_THRESHOLD_DEFAULT 380
#define MAGNET_THRESHOLD_HEAVY 330
#define MAGNET_THRESHOLD_BOTTOM 270 // fully push down
