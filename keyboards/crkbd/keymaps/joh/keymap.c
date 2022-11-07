/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>

#ifdef PS2_MOUSE_ENABLE
#include "ps2_mouse.h"
#include "ps2.h"
#endif

#define U_RDO KC_AGIN
#define U_PST KC_PSTE
#define U_CPY KC_COPY
#define U_CUT KC_CUT
#define U_UND KC_UNDO

#define XXX KC_NO
#define ___ KC_TRANSPARENT

#define LAYER_NAMES BASE, BUTTON, NAV, MOUSE, MEDIA, NUM, SYM, FUN, COMPOSE
enum layers { LAYER_NAMES };
const char* const layer_strings[] = {
    "Base", "Button", "Nav", "Mouse", "Media", "Num", "Sym", "Fun", "Compose"
};

enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
    COMPOSE_AE,
    COMPOSE_OSLASH,
    COMPOSE_ARING,
    CUSTOM_LAST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
        KC_EQL,   KC_Q,               KC_W,          KC_E,          KC_R,          KC_T,  /***/  KC_Y,  KC_U,          KC_I,          KC_O,            KC_P,                 KC_BSLS,
        KC_UNDS,  LALT_T(KC_A),       LGUI_T(KC_S),  LCTL_T(KC_D),  LSFT_T(KC_F),  KC_G,  /***/  KC_H,  RSFT_T(KC_J),  LCTL_T(KC_K),  LGUI_T(KC_L),    LALT_T(KC_SCLN),      KC_QUOT,
        KC_HASH,  LT(COMPOSE, KC_Z),  ALGR_T(KC_X),  KC_C,          KC_V,          KC_B,  /***/  KC_N,  KC_M,          KC_COMM,       ALGR_T(KC_DOT),  LT(BUTTON, KC_SLSH),  KC_MINS,
                                LT(MEDIA, KC_ESC),  LT(NAV, KC_SPC),  LT(MOUSE, KC_TAB),  /***/  LT(SYM, KC_ENT),  LT(NUM, KC_BSPC),  LT(FUN, KC_DEL)
  ),

  [NAV] = LAYOUT_split_3x6_3(
        XXX,  QK_BOOT,  XXX,      XXX,      XXX,      XXX,  /***/  U_RDO,    U_PST,    U_CPY,    U_CUT,    U_UND,    XXX,
        XXX,  KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,  XXX,  /***/  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_CAPS,  ALT_TAB,
        XXX,  XXX,      KC_ALGR,  XXX,      XXX,      XXX,  /***/  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_INS,   XXX,
                                  XXX,      XXX,      XXX,  /***/  KC_ENT,   KC_BSPC,  KC_DEL
  ),

  [MOUSE] = LAYOUT_split_3x6_3(
        XXX,  QK_BOOT,  XXX,      XXX,      XXX,      XXX,  /***/  U_RDO,    U_PST,    U_CPY,    U_CUT,    U_UND,  XXX,
        XXX,  KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,  XXX,  /***/  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  XXX,    XXX,
        XXX,  XXX,      KC_ALGR,  XXX,      XXX,      XXX,  /***/  KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  XXX,    XXX,
                                          XXX,  XXX,  XXX,  /***/  KC_BTN1,  KC_BTN3,  KC_BTN2
  ),

  [MEDIA] = LAYOUT_split_3x6_3(
        XXX,  QK_BOOT,  XXX,      XXX,      XXX,      XXX,  /***/  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,   XXX,
        XXX,  KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,  XXX,  /***/  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  OUT_AUTO,  XXX,
        XXX,  XXX,      KC_ALGR,  XXX,      XXX,      XXX,  /***/  XXX,      XXX,      XXX,      XXX,      XXX,       XXX,
                                  XXX,      XXX,      XXX,  /***/  KC_MSTP,  KC_MPLY,  KC_MUTE
  ),

  [NUM] = LAYOUT_split_3x6_3(
        XXX,  KC_LBRC,  KC_7,  KC_8,    KC_9,  KC_RBRC,  /***/  XXX,  XXX,      XXX,      XXX,      QK_BOOT,  XXX,
        XXX,  KC_SCLN,  KC_4,  KC_5,    KC_6,  KC_EQL,   /***/  XXX,  KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  XXX,
        XXX,  KC_GRV,   KC_1,  KC_2,    KC_3,  KC_BSLS,  /***/  XXX,  XXX,      XXX,      KC_ALGR,  XXX,      XXX,
                               KC_DOT,  KC_0,  KC_MINS,  /***/  XXX,  XXX,      XXX
  ),

  [SYM] = LAYOUT_split_3x6_3(
        XXX,  KC_LCBR,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RCBR,  /***/  XXX,  XXX,      XXX,      XXX,      QK_BOOT,  XXX,
        XXX,  KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_PLUS,  /***/  XXX,  KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  XXX,
        XXX,  KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_PIPE,  /***/  XXX,  XXX,      XXX,      KC_ALGR,  XXX,      XXX,
                                  KC_LPRN,  KC_RPRN,  KC_UNDS,  /***/  XXX,  XXX,      XXX
  ),

  [FUN] = LAYOUT_split_3x6_3(
        XXX,  KC_F12,  KC_F7,  KC_F8,   KC_F9,   KC_PSCR,  /***/  XXX,  XXX,      XXX,      XXX,      QK_BOOT,  XXX,
        XXX,  KC_F11,  KC_F4,  KC_F5,   KC_F6,   KC_SCRL,  /***/  XXX,  KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  XXX,
        XXX,  KC_F10,  KC_F1,  KC_F2,   KC_F3,   KC_PAUS,  /***/  XXX,  XXX,      XXX,      KC_ALGR,  XXX,      XXX,
                               KC_APP,  KC_SPC,  KC_TAB,   /***/  XXX,  XXX,      XXX
  ),

  [BUTTON] = LAYOUT_split_3x6_3(
        XXX,  U_UND,    U_CUT,    U_CPY,    U_PST,    /***/  U_RDO,    U_RDO,    U_PST,    U_CPY,    U_CUT,    U_UND,    XXX,
        XXX,  KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,  /***/  KC_NO,    KC_NO,    KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  XXX,
        XXX,  U_UND,    U_CUT,    U_CPY,    U_PST,    /***/  U_RDO,    U_RDO,    U_PST,    U_CPY,    U_CUT,    U_UND,    XXX,
                        KC_BTN2,  KC_BTN3,  KC_BTN1,  /***/  KC_BTN1,  KC_BTN3,  KC_BTN2
  ),

  [COMPOSE] = LAYOUT_split_3x6_3(
        XXX,  QK_BOOT,  XXX,      XXX,      XXX,      XXX,  /***/  XXX,     XXX,      XXX,    XXX,  XXX,             COMPOSE_ARING,
        XXX,  KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,  XXX,  /***/  XXX,     XXX,      XXX,    XXX,  COMPOSE_OSLASH,  COMPOSE_AE,
        XXX,  XXX,      KC_ALGR,  XXX,      XXX,      XXX,  /***/  XXX,     XXX,      XXX,    XXX,  XXX,             XXX,
                                  XXX,      XXX,      XXX,  /***/  KC_ENT,  KC_BSPC,  KC_DEL
  )
};

#ifdef OLED_ENABLE
// clang-format off
// QK_BASIC - QK_BASIC_MAX (0x0000 - 0x00FF)
static const char PROGMEM code_to_name[256] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  17,  26,  22, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 127,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,  // 3x
    0xDB,0xDC,0xDD,0xDE,0XDF,0xFB,'P', 'S',  19, 'I',  17,  30,  16,  16,  31,  26,  // 4x
     27,  25,  24, 'N', '/', '*', '-', '+',  23, '1', '2', '3', '4', '5', '6', '7',  // 5x
    '8', '9', '0', '.','\\', 'A',   0, '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ',   0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ',  18, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  24,  25,  27,  // Cx
     26, 'L', 'R', 'M', ' ', ' ', ' ', ' ', ' ',  30,  31,  17,  16, ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  24,  26,  24,  // Ex
     25,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,  24,  25,  27,  26, ' ', ' ', ' '   // Fx
};

// S(QK_BASIC) - S(QK_BASIC_MAX) (0x0200 - 0x02FF)
static const char PROGMEM code_to_name_shift[256] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    ' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',  // 0x
    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '!', '@',  // 1x
    '#', '$', '%', '^', '&', '*', '(', ')',  20,  19,  27,  26,  22, '_', '+', '{',  // 2x
    '}', '|', '#', ':', '"', '~', '<', '>', '?', 127,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,  // 3x
    0xDB,0xDC,0xDD,0xDE,0XDF,0xFB,'P', 'S',  19, 'I',  17,  30,  16,  16,  31,  26,  // 4x
     27,  25,  24, 'N', '/', '*', '-', '+',  23, '1', '2', '3', '4', '5', '6', '7',  // 5x
    '8', '9', '0', '.','\\', 'A',   0, '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ',   0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ',  18, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  24,  25,  27,  // Cx
     26, 'L', 'R', 'M', ' ', ' ', ' ', ' ', ' ',  30,  31,  17,  16, ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  24,  26,  24,  // Ex
     25,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,0x9D,  24,  25,  27,  26, ' ', ' ', ' '   // Fx
};

// clang-format on
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return OLED_ROTATION_270;
}

#define IS_TAP_HOLD(keycode) ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || \
                              (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX))

const char keycode_to_char(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {

        keycode &= 0xFF;
    }

    if (keycode >= QK_MODS && keycode <= QK_MODS_MAX) {
        keycode &= 0xFF;
        return pgm_read_byte(&code_to_name_shift[keycode]);
    }
    //    (keycode >= ALT_TAB && keycode < CUSTOM_LAST)) {

    if (keycode < ARRAY_SIZE(code_to_name)) {
        return pgm_read_byte(&code_to_name[keycode]);
    }

    return 0x04;
}

void oled_render_layer_state(void) {
    static unsigned int prev_layer = -1;

    unsigned int layer = get_highest_layer(layer_state);
    if (layer == prev_layer)
        return;
    prev_layer = layer;
    print("Layer: ");
    print_dec(layer);
    print("\n");
    /*
    char buf[10];
    sprintf(buf, "%d", layer);
    oled_write_ln(buf, false);
    */
    oled_write_ln(layer_strings[layer], false);
    oled_advance_page(true);

    if (is_keyboard_left()) {
        for (int row = 0; row <= 3; row++) {
            for (int col = 0; col < MATRIX_COLS; col++) {
                uint16_t keycode = keymaps[layer][row][col];
                bool invert = IS_TAP_HOLD(keycode);
                oled_write_char(keycode_to_char(keycode), invert);
            }
            //oled_advance_page(true);
        }

    } else {
        for (int row = 4; row < MATRIX_ROWS; row++) {
            for (int col = MATRIX_COLS-1; col >= 0; col--) {
                uint16_t keycode = keymaps[layer][row][col];
                //bool invert = IS_TAP_HOLD(keycode);
                bool invert = false;
                oled_write_char(keycode_to_char(keycode), invert);
            }
            //oled_advance_page(true);
        }

#if 0
        for (int row = 4; row < MATRIX_ROWS-1; row++) {
            for (int col = MATRIX_COLS-1; col >= 1; col--) {
                uint16_t keycode = keymaps[layer][row][col];
                oled_write_char(keycode_to_char(keycode), false);
            }
            //oled_advance_page(true);
        }

        oled_advance_page(true);

        for (int row = 4; row < MATRIX_ROWS-1; row++) {
            oled_write("    ", false);
            for (int col = 0; col >= 0; col--) {
                uint16_t keycode = keymaps[layer][row][col];
                oled_write_char(keycode_to_char(keycode), false);
            }
            //oled_advance_page(true);
        }

        //oled_advance_page(true);
        for (int row = MATRIX_ROWS-1; row < MATRIX_ROWS; row++) {
            for (int col = MATRIX_COLS-1; col >= 1; col--) {
                uint16_t keycode = keymaps[layer][row][col];
                oled_write_char(keycode_to_char(keycode), false);
            }
            //oled_advance_page(true);
        }
#endif
    }

}

/*
 * 1183
 * 1197
 * 1199
 * 1211
 * 1226
 */

void oled_test(void) {
    // Display: 21x5
    //oled_write("abcdefghijklmnopqrstuvwxyz", false);
    oled_write(" !\"#$%&'()*+,-./", false);
    oled_write("0123456789", false);
    //oled_write(":;<=>?@", false);
    oled_write("ABCDEFGHIJKLMNOPQRSTUVWXYZ", false);
    //oled_write("[\\]^_`", false);
    oled_write("abcdefghijklmnopqrstuvwxyz", false);
    //oled_write("{|}~", false);
    //oled_scroll_left();  // Turns on scrolling
}


char keylog_str[24] = {};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        //oled_render_keylog();
        //oled_test();
    } else {
        oled_render_logo();
    }
    return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
    switch (keycode) {
        case ALT_TAB:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_TAB) SS_UP(X_LALT));
            break;
        case COMPOSE_AE:
            SEND_STRING(SS_RALT("ae"));
            break;
        case COMPOSE_OSLASH:
            SEND_STRING(SS_RALT("/o"));
            break;
        case COMPOSE_ARING:
            SEND_STRING(SS_RALT("aa"));
            break;
    }
  }
  return true;
}
#endif // OLED_ENABLE

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
    debug_mouse=true;
}

#ifdef PS2_MOUSE_ENABLE
void ps2_mouse_init_user() {
    // set TrackPoint sensitivity
    PS2_MOUSE_SEND(0xE2, "tpsens: 0xE2");
    PS2_MOUSE_SEND(0x81, "tpsens: 0x81");
    PS2_MOUSE_SEND(0x4A, "tpsens: 0x4A");
    PS2_MOUSE_SEND(0xA0, "tpsens: 0x59");

    // force calibration
    PS2_MOUSE_SEND(0xE2, "tpcali: 0xE2");
    PS2_MOUSE_SEND(0x51, "tpcali: 0x51");
}
#endif

#if defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE

static uint16_t mh_auto_buttons_timer;
extern int tp_buttons; // mousekey button state set in action.c and used in ps2_mouse.c

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
  if (mh_auto_buttons_timer) {
    mh_auto_buttons_timer = timer_read();
  } else {
    if (!tp_buttons) {
      layer_on(MH_AUTO_BUTTONS_LAYER);
      mh_auto_buttons_timer = timer_read();
  #if defined CONSOLE_ENABLE
      print("mh_auto_buttons: on\n");
  #endif
    }
  }
}

void matrix_scan_user(void) {
  if (mh_auto_buttons_timer && (timer_elapsed(mh_auto_buttons_timer) > MH_AUTO_BUTTONS_TIMEOUT)) {
    if (!tp_buttons) {
      layer_off(MH_AUTO_BUTTONS_LAYER);
      mh_auto_buttons_timer = 0;
  #if defined CONSOLE_ENABLE
      print("mh_auto_buttons: off\n");
  #endif
    }
  }
}

#endif // defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && #defined MOUSEKEY_ENABLE
