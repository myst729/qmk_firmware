#pragma once

#include "quantum.h"

#define LAYOUT( \
  K00,      K02, K03, K04, K05, K06, K07,      K08, K09, K0A, K0B, K0C, K0D,                K0E, K0F, K0G, \
  K10, K11, K12, K13, K14, K15, K16, K17,      K18, K19, K1A, K1B, K1C, K1D, K5E, K1E,      K1F, K1G, K0H, \
  K20, K22, K23, K24, K25, K26, K27,           K28, K29, K2A, K2B, K2C, K2D, K2E, K2F,      K2G, K2H, K1H, \
       K32, K33, K34, K35, K36, K37,           K38, K39, K3A, K3B, K3C, K3D, K3E,                          \
       K42, K41, K43, K44, K45, K46, K47,      K48, K49, K4A, K4B, K4C, K4D, K4E, K4F,      K3G,           \
       K21,           K30,      K31, K01,      K58, K59,      K5B,           K5D,      K5F, K5G, K5H       \
) { \
  { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E,   K0F,   K0G,   K0H },   \
  { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   K1F,   K1G,   K1H },   \
  { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,   K2D,   K2E,   K2F,   K2G,   K2H },   \
  { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E,   KC_NO, K3G,   KC_NO }, \
  { KC_NO, K41,   K42,   K43,   K44,   K45,   K46,   K47,   K48,   K49,   K4A,   K4B,   K3D,   K4D,   K4E,   K4F,   KC_NO, KC_NO }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K58,   K59,   KC_NO, K5B,   KC_NO, K5D,   K5E,   K5F,   K5G,   K5H }    \
}
