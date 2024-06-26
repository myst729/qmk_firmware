MCU = atmega32u4
F_CPU = 16000000
F_USB = $(F_CPU)
ARCH = AVR8
BOOTLOADER = caterina
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT
OPT_DEFS += -DBOOTLOADER_SIZE=4096

# Build Options
BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
NKRO_ENABLE = yes
BACKLIGHT_ENABLE = yes
BACKLIGHT_DRIVER = pwm
RGBLIGHT_ENABLE = no
AUDIO_ENABLE = no
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = analog_joystick
JOYSTICK_ENABLE = yes
JOYSTICK_DRIVER = analog
VIA_ENABLE = yes
