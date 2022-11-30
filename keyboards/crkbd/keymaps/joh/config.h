/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
#define MASTER_RIGHT
#define EE_HANDS

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 175

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#endif

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

//#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
//#define OLED_FONT_H "dpla_11834776007007.c"
//#define OLED_FONT_H "dpla_11974770607007.c"
//#define OLED_FONT_H "dpla_11974770607007.c"
//#define OLED_FONT_H "oled_font.c"
//#define OLED_FONT_WIDTH 5
#define OLED_FONT_H "keyboards/crkbd/keymaps/joh/glcdfont.c"

#define OLED_DISPLAY_CUSTOM
#define OLED_DISPLAY_WIDTH 64
#define OLED_DISPLAY_HEIGHT 128
#define OLED_COM_PIN_OFFSET 32
#define OLED_MATRIX_SIZE (OLED_DISPLAY_HEIGHT / 8 * OLED_DISPLAY_WIDTH)
#define OLED_BLOCK_TYPE uint16_t
#define OLED_SOURCE_MAP { 0, 8, 16, 24, 32, 40, 48, 56 }
#define OLED_TARGET_MAP { 56, 48, 40, 32, 24, 16, 8, 0 }
#define OLED_BLOCK_COUNT (sizeof(OLED_BLOCK_TYPE) * 8)
#define OLED_BLOCK_SIZE (OLED_MATRIX_SIZE / OLED_BLOCK_COUNT)
#define OLED_COM_PINS COM_PINS_ALT
#define OLED_IC OLED_IC_SH1107

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT

#define PS2_CLOCK_PIN B5
#define PS2_DATA_PIN  B4
#define PS2_PIO_USE_PIO1
#define PS2_MOUSE_ROTATE 90
#define PS2_MOUSE_SCROLL_BTN_MASK 0

//#define TAP_CODE_DELAY 100

/*
#include <quantum/util.h>
#pragma message ("TAP_CODE_DELAY=" STR(TAP_CODE_DELAY))
#pragma message ("PS2_MOUSE_ROTATE=" STR(PS2_MOUSE_ROTATE))
*/

#define PS2_MOUSE_DEBUG_RAW
//#define PS2_MOUSE_DEBUG_HID

#if defined MH_AUTO_BUTTONS
  #define MH_AUTO_BUTTONS_LAYER MOUSE
  #define MH_AUTO_BUTTONS_TIMEOUT 750
#endif
