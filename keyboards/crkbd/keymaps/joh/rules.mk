# Sparkfun Pro Micro RP2040 MCU settings
PLATFORM_KEY := chibios
MCU := RP2040
BOARD := QMK_PM2040
BOOTLOADER := rp2040

# These are defaults based on what has been implemented for RP2040 boards
SERIAL_DRIVER ?= vendor
WS2812_DRIVER ?= vendor
BACKLIGHT_DRIVER ?= software

MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
AUTO_SHIFT_ENABLE = yes # Auto Shift
CAPS_WORD_ENABLE = yes
RGB_MATRIX_ENABLE = yes
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes

# Enable trackpoint
TRACKPOINT_ENABLE = yes
ifeq ($(strip $(TRACKPOINT_ENABLE)), yes)
  PS2_ENABLE = yes
  PS2_MOUSE_ENABLE = yes
  PS2_DRIVER = vendor
endif

CONSOLE_ENABLE = yes

MH_AUTO_BUTTONS = yes

ifeq ($(strip $(MH_AUTO_BUTTONS)), yes)
  MOUSEKEY_ENABLE = yes
  OPT_DEFS += -DMH_AUTO_BUTTONS
endif
