#pragma once

#include "quantum.h"

#ifdef BLUETOOTH_ENABLE
uint8_t battery_level(void);
#endif

#define LAYOUT( \
  K40, K04, K50, K05, K60, K06, K70, K07, K80, K08, K90, K09, \
  K41, K14, K51, K15, K61, K16, K71, K17, K81, K18, K91, K19, \
  K42, K24, K52, K25, K62, K26, K72, K27, K82, K28, K92, K29, \
  K43, K34, K53, K35,    K63,      K37,   K83, K38, K93, K39, K36, K73 \
) { \
  { KC_NO, KC_NO, KC_NO, KC_NO, K04,   K05,   K06,   K07,   K08,   K09 },   \
  { KC_NO, KC_NO, KC_NO, KC_NO, K14,   K15,   K16,   K17,   K18,   K19 },   \
  { KC_NO, KC_NO, KC_NO, KC_NO, K24,   K25,   K26,   K27,   K28,   K29 },   \
  { KC_NO, KC_NO, KC_NO, KC_NO, K34,   K35,   K36,   K37,   K38,   K39 },   \
  { K40,   K41,   K42,   K43,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { K50,   K51,   K52,   K53,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { K60,   K61,   K62,   K63,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { K70,   K71,   K72,   K73,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { K80,   K81,   K82,   K83,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { K90,   K91,   K92,   K93,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }  \
}
