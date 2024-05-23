#include "magnet.h"

static const uint16_t magnet_threshold_options[] = {
  [0] = MAGNET_THRESHOLD_DEFAULT,
  [1] = MAGNET_THRESHOLD_LIGHT,
  [2] = MAGNET_THRESHOLD_HEAVY,
};

bool dip_switch_update_mask_kb(uint32_t state) {
  magnet_threshold = magnet_threshold_options[state];
  return true;
};
