MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
AUTO_SHIFT_ENABLE = yes # Auto Shift
CAPS_WORD_ENABLE = yes
RGBLIGHT_ENABLE = yes    # Enable WS2812 RGB underlight.
OLED_ENABLE     = no
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes
BOOTLOADER = atmel-dfu

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

PS2_ENABLE = yes
PS2_MOUSE_ENABLE = yes
PS2_DRIVER = vendor
#PS2_USE_INT = yes
#
CONSOLE_ENABLE = yes

MH_AUTO_BUTTONS=yes

ifeq ($(strip $(MH_AUTO_BUTTONS)), yes)
  MOUSEKEY_ENABLE = yes
  OPT_DEFS += -DMH_AUTO_BUTTONS
endif
