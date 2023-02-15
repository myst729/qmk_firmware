#pragma once

#include "quantum.h"

/*
FULL 10x10 CHARLIEPLEX MATRIX for Reference
  { KC_NO, K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09 },  \
  { K10,   KC_NO, K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19 },  \
  { K20,   K21,   KC_NO, K23,   K24,   K25,   K26,   K27,   K28,   K29 },  \
  { K30,   K31,   K32,   KC_NO, K34,   K35,   K36,   K37,   K38,   K39 },  \
  { K40,   K41,   K42,   K43,   KC_NO, K45,   K46,   K47,   K48,   K49 },  \
  { K50,   K51,   K52,   K53,   K54,   KC_NO, K56,   K57,   K58,   K59 },  \
  { K60,   K61,   K62,   K63,   K64,   K65,   KC_NO, K67,   K68,   K69 },  \
  { K70,   K71,   K72,   K73,   K74,   K75,   K76,   KC_NO, K78,   K79 },  \
  { K80,   K81,   K82,   K83,   K84,   K85,   K86,   K87,   KC_NO, K89 },  \
  { K90,   K91,   K92,   K93,   K94,   K95,   K96,   K97,   K98,   KC_NO } \
*/

#define LAYOUT( \
  K30, K03, K40, K04, K50, K05, K60, K06, K70, K07, \
  K31, K13, K41, K14, K51, K15, K61, K16, K71, K17, \
  K32, K23, K42, K24, K52, K25, K62, K26, K72, K27  \
) { \
  { KC_NO, KC_NO, KC_NO, K03,   K04,   K05,   K06,   K07 },   \
  { KC_NO, KC_NO, KC_NO, K13,   K14,   K15,   K16,   K17 },   \
  { KC_NO, KC_NO, KC_NO, K23,   K24,   K25,   K26,   K27 },   \
  { K30,   K31,   K32,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { K40,   K41,   K42,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { K50,   K51,   K52,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { K60,   K61,   K62,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { K70,   K71,   K72,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }  \
}
