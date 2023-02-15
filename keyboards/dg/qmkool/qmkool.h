#pragma once

#include "quantum.h"

#define LAYOUT( \
          K002,                     \
  K202,                 K000, K001, \
          K200, K201,   K100, K101  \
) { \
  { K000, K001, K002 }, \
  { K100, K101, KC_NO }, \
  { K200, K201, K202 }  \
}
