#pragma once

/* Matrix */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { D2, D3, F1, B7 }
#define MATRIX_COL_PINS { F0, D5, F4, F5, F6, F7, C7, C6, B6, B5, B4, D4 }
// 25 pins: { B0, B1, B2, B3, B4, B5, B6, B7 }, { C6, C7 }, { D0, D1, D2, D3, D4, D5, D6, D7 }, { E6 }, { F0, F1, F4, F5, F6, F7 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL
#define DEBOUNCE 5
#define TAP_CODE_DELAY 10

/* LED Indicators */
#define LED_CAPS_LOCK_PIN D1
#define LED_PIN_ON_STATE 0

/* Encoder */
#define ENCODERS_PAD_A { D7 }
#define ENCODERS_PAD_B { D6 }
