#pragma once

#include_next "mcuconf.h"

#undef STM32_ADC_USE_ADC0
#define STM32_ADC_USE_ADC0 TRUE
#undef STM32_ADC_USE_ADC1
#define STM32_ADC_USE_ADC1 TRUE
