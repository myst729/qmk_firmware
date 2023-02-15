MCU = atmega32u4
BOOTLOADER = caterina
F_CPU = 8000000

DIP_SWITCH_ENABLE = yes
CUSTOM_MATRIX = lite

SRC += analog.c matrix.c
