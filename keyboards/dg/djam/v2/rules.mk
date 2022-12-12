MCU = STM32F401
# MCU = STM32F103
# MCU = STM32F072

BOOTLOADER = stm32-dfu
# BOOTLOADER = stm32duino

# Enter lower-power sleep mode when on the ChibiOS idle thread
# OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# Wildcard to allow APM32 MCU
# DFU_SUFFIX_ARGS = -p FFFF -v FFFF
