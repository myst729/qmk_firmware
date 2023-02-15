#pragma once

/* Device */
// #define VENDOR_ID       0xDE29
// #define PRODUCT_ID      0x7340
// #define DEVICE_VER      0x0001
// #define MANUFACTURER    Leo Deng
// #define PRODUCT         Raspico

/* Bootmagic & DFU */
// #define BOOTMAGIC_LITE_ROW 0
// #define BOOTMAGIC_LITE_COLUMN 0

/* Matrix */
#define MATRIX_ROWS 1
#define MATRIX_COLS 4
#define DIRECT_PINS {{ GP6, GP7, GP8, GP9 }}
#define DEBOUNCE 5
#define HOLD_ON_OTHER_KEY_PRESS

/* LED Indicators */
#define LED_CAPS_LOCK_PIN GP10
#define LED_PIN_ON_STATE 0

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#define WS2812_DI_PIN GP11
// #define NOP_FUDGE 0.4
// #define WS2812_PIO_USE_PIO1
#define RGB_MATRIX_LED_COUNT 36
#define RGB_MATRIX_KEYPRESSES
// #define RGB_MATRIX_KEYRELEASES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
#define RGB_MATRIX_TIMEOUT 0
#define RGB_DISABLE_WHEN_USB_SUSPENDED false
#define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5
#define RGB_MATRIX_LED_FLUSH_LIMIT 16
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_ALL
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 255
#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_DEFAULT_SPD 127
// Enable Effects
// == Regular Effects ==
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
// == Framebuffer Effects ==
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// == Reactive Effects ==
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

/* VIA */
#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#endif

/* SPI definitions */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP16
#define MY_SPI_SS_PIN GP17

/* I2C definitions */
#define I2C_DRIVER I2CD0
#define I2C1_SCL_PIN GP5
#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PIN GP4
#define I2C1_SDA_PAL_MODE 4
#define MY_I2C_ADDRESS (0x36 << 1)
#define MY_I2C_TIMEOUT 100

/* Double tap the side button to enter bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500
