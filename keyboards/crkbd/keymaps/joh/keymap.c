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
    COMPOSE_ARING
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
        KC_EQL,   KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 KC_BSLS,
        KC_UNDS,  LALT_T(KC_A),      LGUI_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              RSFT_T(KC_J),      LCTL_T(KC_K),      LGUI_T(KC_L),      LALT_T(KC_SCLN),      KC_QUOT,
        KC_HASH,  LT(COMPOSE, KC_Z), ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(BUTTON, KC_SLSH),  KC_MINS,
                                                        LT(MEDIA, KC_ESC), LT(NAV, KC_SPC),   LT(MOUSE, KC_TAB), LT(SYM, KC_ENT),   LT(NUM, KC_BSPC),  LT(FUN, KC_DEL)
  ),

  [NAV] = LAYOUT_split_3x6_3(
        XXX,  RESET,             XXX,               XXX,               XXX,               XXX,               U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,               XXX,
        XXX,  KC_LALT,           KC_LGUI,           KC_LCTL,           KC_LSFT,           XXX,               KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           KC_CAPS,             ALT_TAB,
        XXX,  XXX,               KC_ALGR,           XXX,               XXX,               XXX,               KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            KC_INS,              XXX,
                                                    XXX,               XXX,               XXX,               KC_ENT,            KC_BSPC,           KC_DEL
  ),

  [MOUSE] = LAYOUT_split_3x6_3(
        XXX,  RESET,             XXX,               XXX,              XXX,              XXX,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,            XXX,
        XXX,  KC_LALT,           KC_LGUI,           KC_LCTL,          KC_LSFT,          XXX,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           XXX,              XXX,
        XXX,  XXX,               KC_ALGR,           XXX,              XXX,              XXX,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           XXX,              XXX,
                                                    XXX,              XXX,              XXX,              KC_BTN1,           KC_BTN3,           KC_BTN2
  ),

  [MEDIA] = LAYOUT_split_3x6_3(
        XXX,  RESET,             XXX,               XXX,              XXX,              XXX,              RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,          XXX,
        XXX,  KC_LALT,           KC_LGUI,           KC_LCTL,          KC_LSFT,          XXX,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           OUT_AUTO,         XXX,
        XXX,  XXX,               KC_ALGR,           XXX,              XXX,              XXX,              XXX,               XXX,               XXX,               XXX,               XXX,              XXX,
                                                    XXX,              XXX,              XXX,              KC_MSTP,           KC_MPLY,           KC_MUTE
  ),

  [NUM] = LAYOUT_split_3x6_3(
        XXX,  KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           XXX,              XXX,              XXX,              XXX,               RESET,           XXX,
        XXX,  KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            XXX,              KC_LSFT,          KC_LCTL,          KC_LGUI,           KC_LALT,         XXX,
        XXX,  KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           XXX,              XXX,              XXX,              KC_ALGR,           XXX,             XXX,
                                                    KC_DOT,            KC_0,              KC_MINS,           XXX,              XXX,              XXX
  ),

  [SYM] = LAYOUT_split_3x6_3(
        XXX,  KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           XXX,              XXX,              XXX,              XXX,               RESET,           XXX,
        XXX,  KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,           XXX,              KC_LSFT,          KC_LCTL,          KC_LGUI,           KC_LALT,         XXX,
        XXX,  KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,           XXX,              XXX,              XXX,              KC_ALGR,           XXX,             XXX,
                                                    KC_LPRN,           KC_RPRN,           KC_UNDS,           XXX,              XXX,              XXX
  ),

  [FUN] = LAYOUT_split_3x6_3(
        XXX,  KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           XXX,              XXX,              XXX,              XXX,               RESET,           XXX,
        XXX,  KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SLCK,           XXX,              KC_LSFT,          KC_LCTL,          KC_LGUI,           KC_LALT,         XXX,
        XXX,  KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           XXX,              XXX,              XXX,              KC_ALGR,           XXX,             XXX,
                                                    KC_APP,            KC_SPC,            KC_TAB,            XXX,              XXX,              XXX
  ),

  [BUTTON] = LAYOUT_split_3x6_3(
        XXX,  U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,        XXX,
        XXX,  KC_LALT,           KC_LGUI,           KC_LCTL,           KC_LSFT,           KC_NO,             KC_NO,             KC_LSFT,           KC_LCTL,           KC_LGUI,           KC_LALT,      XXX,
        XXX,  U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,        XXX,
                                                    KC_BTN2,           KC_BTN3,           KC_BTN1,           KC_BTN1,           KC_BTN3,           KC_BTN2
  ),

  [COMPOSE] = LAYOUT_split_3x6_3(
        XXX,  RESET,             XXX,               XXX,               XXX,               XXX,               XXX,             XXX,             XXX,             XXX,             XXX,               COMPOSE_ARING,
        XXX,  KC_LALT,           KC_LGUI,           KC_LCTL,           KC_LSFT,           XXX,               XXX,           XXX,           XXX,             XXX,           COMPOSE_OSLASH,             COMPOSE_AE,
        XXX,  XXX,               KC_ALGR,           XXX,               XXX,               XXX,               XXX,           XXX,           XXX,           XXX,            XXX,              XXX,
                                                    XXX,               XXX,               XXX,               KC_ENT,            KC_BSPC,           KC_DEL
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    unsigned int layer = get_highest_layer(layer_state);
    /*
    char buf[10];
    sprintf(buf, "%d", layer);
    oled_write_ln(buf, false);
    */
    oled_write_ln(layer_strings[layer], false);
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

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
