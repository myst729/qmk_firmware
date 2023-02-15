#pragma once

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7326
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         QMKool

/* Matrix */
#define MATRIX_ROWS 3
#define MATRIX_COLS 3
#define MATRIX_ROW_PINS { C3, C4, C5 }
#define MATRIX_COL_PINS { C0, C1, C2 }
#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL
#define DEBOUNCE 5
#define TAP_CODE_DELAY 10

/* LED Indicators */
#define LED_CAPS_LOCK_PIN A3
#define LED_PIN_ON_STATE 0

/* OLED SSD1306 */
#ifdef OLED_ENABLE
#define OLED_BRIGHTNESS 5
#define OLED_TIMEOUT 3000
#endif

/* Backlight */
#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PIN B6
#define BACKLIGHT_LEVELS 5
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 5
#define BACKLIGHT_ON_STATE 1
#endif

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN D7
#define RGBLED_NUM 4
#define DRIVER_LED_TOTAL (RGBLED_NUM)
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGB_MATRIX_KEYPRESSES
#define RGB_DISABLE_TIMEOUT 0
#define RGB_DISABLE_AFTER_TIMEOUT 0
#define RGB_DISABLE_WHEN_USB_SUSPENDED false
#define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5
#define RGB_MATRIX_LED_FLUSH_LIMIT 16
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
#define RGB_MATRIX_STARTUP_HUE 0
#define RGB_MATRIX_STARTUP_SAT 255
#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_STARTUP_SPD 127

// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
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
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
// #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
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

/* Audio */
#ifdef AUDIO_ENABLE
#define AUDIO_PIN C6
// #define AUDIO_PIN_ALT B6
// #define AUDIO_ENABLE_TONE_MULTIPLEXING
// #define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
// #define AUDIO_CLICKY
// #define AUDIO_VOICES
// #define AUDIO_VOICE_DEFAULT something // vibrating | something | drums | butts_fader | octave_crunch | duty_osc | duty_octave_down | delayed_vibrato
// #define THINK_STARTUP Q__NOTE(_C4), Q__NOTE(_E4), Q__NOTE(_D4), Q__NOTE(_G4),
// #define THINK_GOODBYE Q__NOTE(_C5), Q__NOTE(_G4), Q__NOTE(_E4), Q__NOTE(_C4),
// #define STARTUP_SONG SONG(THINK_STARTUP)
// #define GOODBYE_SONG SONG(THINK_GOODBYE)
#define NO_MUSIC_MODE
#endif

/* Bluetooth */
#ifdef BLUETOOTH
// #define AdafruitBleResetPin D4
// #define AdafruitBleCSPin B4
// #define AdafruitBleIRQPin E6
// #define BATTERY_LEVEL_PIN B5
#endif

/* DIP Switches */
#ifdef DIP_SWITCH_ENABLE
// #define DIP_SWITCH_PINS { B0 }
#define DIP_SWITCH_MATRIX_GRID { {1,2} } // List of row and col pairs
#endif

/* Encoders */
#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { F0 }
#define ENCODERS_PAD_B { F1 }
#endif

/* Joystick */
#ifdef JOYSTICK_ENABLE
#define JOYSTICK_AXES_COUNT 2
#define JOYSTICK_BUTTON_COUNT 6
#endif

/* PS/2 Mouse */
#ifdef PS2_USE_USART
#define PS2_CLOCK_PORT PORTD
#define PS2_CLOCK_PIN  PIND
#define PS2_CLOCK_DDR  DDRD
#define PS2_CLOCK_BIT  5
#define PS2_DATA_PORT  PORTD
#define PS2_DATA_PIN   PIND
#define PS2_DATA_DDR   DDRD
#define PS2_DATA_BIT   2

/* synchronous, odd parity, 1-bit stop, 8-bit data, sample at falling edge */
/* set DDR of CLOCK as input to be slave */
#define PS2_USART_INIT() do {           \
PS2_CLOCK_DDR &= ~(1<<PS2_CLOCK_BIT); \
PS2_DATA_DDR &= ~(1<<PS2_DATA_BIT);   \
UCSR1C = ((1 << UMSEL10) |            \
            (3 << UPM10)   |            \
            (0 << USBS1)   |            \
            (3 << UCSZ10)  |            \
            (0 << UCPOL1));             \
UCSR1A = 0;                           \
UBRR1H = 0;                           \
UBRR1L = 0;                           \
} while (0)

#define PS2_USART_RX_INT_ON() do {      \
UCSR1B = ((1 << RXCIE1) |             \
            (1 << RXEN1));              \
} while (0)

#define PS2_USART_RX_POLL_ON() do {     \
UCSR1B = (1 << RXEN1);                \
} while (0)

#define PS2_USART_OFF() do {            \
UCSR1C = 0;                           \
UCSR1B &= ~((1 << RXEN1) |            \
            (1 << TXEN1));            \
} while (0)

#define PS2_USART_RX_READY        (UCSR1A & (1<<RXC1))
#define PS2_USART_RX_DATA         UDR1
#define PS2_USART_ERROR           (UCSR1A & ((1<<FE1) | (1<<DOR1) | (1<<UPE1)))
#define PS2_USART_RX_VECT         USART1_RX_vect
#define PS2_MOUSE_SCROLL_BTN_MASK (1<<PS2_MOUSE_BTN_MIDDLE)
#define PS2_MOUSE_SCROLL_BTN_SEND 300
// #define PS2_MOUSE_ROTATE          180
// #define PS2_MOUSE_USE_REMOTE_MODE
// #define PS2_MOUSE_ENABLE_SCROLLING
// #define PS2_MOUSE_INIT_DELAY      1000
// #define PS2_MOUSE_X_MULTIPLIER    1
// #define PS2_MOUSE_Y_MULTIPLIER    1
// #define PS2_MOUSE_V_MULTIPLIER    1
#endif

/* VIA */
// #ifdef VIA_ENABLE
// #define DYNAMIC_KEYMAP_LAYER_COUNT 3
// #endif

/* Pointing Device */
#define ANALOG_JOYSTICK_X_AXIS_PIN F4
#define ANALOG_JOYSTICK_Y_AXIS_PIN F5
