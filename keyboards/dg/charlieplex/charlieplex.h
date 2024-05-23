#pragma once

#include "quantum.h"

#define LAYOUT( \
  K10, K01, K02, K03, \
  K20, K21, K12, K13, \
  K30, K31, K32, K23  \
) { \
  { KC_NO, K01,   K02,   K03 },  \
  { K10,   KC_NO, K12,   K13 },  \
  { K20,   K21,   KC_NO, K23 },  \
  { K30,   K31,   K32,   KC_NO } \
}
