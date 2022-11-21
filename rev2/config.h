#pragma once

#include "config_common.h"

/* USB Device descriptor parameters */
#define VENDOR_ID       0x4B50  // "KP"
#define PRODUCT_ID      0x3430  // "40"
#define DEVICE_VER      0x0002
#define MANUFACTURER    KPRepublic
#define PRODUCT         BM40

/* Force enable N-key rollover (NKRO) */
#define FORCE_NKRO
#define QMK_KEYS_PER_SCAN 6

/* USB polling rate */
#define USB_POLLING_INTERNAL_MS 1  // 1000 Hz

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { D7, F7, F6, F5 }
#define MATRIX_COL_PINS { B2, B3, D5, D3, D2, B7, F0, B4, B5, B6, C6, C7 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN B0
#define RGBLED_NUM 6
#ifdef RGB_DI_PIN
#    define RGB_MATRIX_KEYPRESSES  // reacts to keypresses
#    define RGBLIGHT_LIMIT_VAL 180  // Limit to vendor-recommended value
// Default RGB light settings
#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#    define RGBLIGHT_DEFAULT_HUE 71
#    define RGBLIGHT_DEFAULT_SAT 211
#    define RGBLIGHT_DEFAULT_VAL 130
//#    define RGBLIGHT_DEFAULT_HUE 176
//#    define RGBLIGHT_DEFAULT_SAT 120
//#    define RGBLIGHT_DEFAULT_VAL 72

#    define RGBLIGHT_DEFAULT_SPD 0
#endif
#ifdef RGB_MATRIX_ENABLE
// IS31FL3733 configuration
#    define DRIVER_COUNT 1
#    define DRIVER_ADDR_1 0b1010000
#    define DRIVER_1_LED_TOTAL 47
#    define ISSI_LED_TOTAL DRIVER_1_LED_TOTAL
// Underglow LEDs are WS2812, but someone might want to use RGBLIGHT for them;
// don't use those LEDs in RGB Matrix in that case.
#    ifdef RGBLIGHT_ENABLE
#        define WS2812_LED_TOTAL 0
#    else
#        define WS2812_LED_TOTAL 6
#    endif
#    define DRIVER_LED_TOTAL (ISSI_LED_TOTAL + WS2812_LED_TOTAL)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS RGBLIGHT_LIMIT_VAL // Limit to vendor-recommended value
// Default RGB light settings
#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define RGB_MATRIX_STARTUP_HUE RGBLIGHT_DEFAULT_HUE
#    define RGB_MATRIX_STARTUP_SAT RGBLIGHT_DEFAULT_SAT
#    define RGB_MATRIX_STARTUP_VAL RGBLIGHT_DEFAULT_VAL
#    define RGB_MATRIX_STARTUP_SPD RGBLIGHT_DEFAULT_SPD
// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
/*
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
*/
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
/*
#    define ENABLE_RGB_MATRIX_BAND_SAT
#    define ENABLE_RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
*/
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
#    define ENABLE_RGB_MATRIX_HUE_WAVE
/*
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
*/
#    define ENABLE_RGB_MATRIX_PIXEL_FLOW
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_MULTISPLASH
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#define RGBLIGHT_SLEEP
#define RGB_DISABLE_WHEN_USB_SUSPENDED

/* Via properties */
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

/* Vial properties */
#define VIAL_KEYBOARD_UID {0x42, 0x99, 0x2C, 0x9A, 0x03, 0x6D, 0xF1, 0x61}
#define VIAL_UNLOCK_COMBO_ROWS { 1, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 11 }

#define CAPS_WORD_IDLE_TIMEOUT 0  // Never time out waiting for CAPS_WORD
