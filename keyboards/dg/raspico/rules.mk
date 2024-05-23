MCU = RP2040
BOOTLOADER = rp2040

# ATM Unsupported by ChibiOS
PICO_INTRINSICS_ENABLED = no

# Build Options
BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = yes
COMMAND_ENABLE = no
NKRO_ENABLE = yes
BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
WS2812_DRIVER = vendor
AUDIO_ENABLE = no
OLED_DRIVER_ENABLE = no
VIA_ENABLE = yes
LTO_ENABLE = no

# Project specific files
QUANTUM_LIB_SRC += i2c_master.c spi_master.c
