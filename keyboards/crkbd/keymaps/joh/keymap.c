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
//#define U_PST KC_PSTE
#define U_CPY KC_COPY
#define U_CUT KC_CUT
#define U_UND KC_UNDO

#define XXX KC_NO
#define ___ KC_TRANSPARENT

#define LAYER_NAMES BASE, BUTTON, NAV, MOUSE, MEDIA, NUM, SYM, FUN, COMPOSE
enum layers { LAYER_NAMES };
const char* const layer_strings[] = {
    "Base", "Button", "Nav", "Mouse", "Media", "Num", "Sym", "Fun", "Comp"
};

enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
    U_PST,
    COMM_SPC,
    TP_SENSI,
    TP_SENSD,
    //TP_REGDUMP,
    TP_RESET,
    COMPOSE_AE,
    COMPOSE_OSLASH,
    COMPOSE_ARING,
    CUSTOM_LAST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
        KC_EQL,   KC_Q,               KC_W,          KC_E,          KC_R,          KC_T,  /***/  KC_Y,  KC_U,          KC_I,          KC_O,            KC_P,                 KC_BSLS,
        KC_HASH,  LALT_T(KC_A),       LGUI_T(KC_S),  LCTL_T(KC_D),  LSFT_T(KC_F),  KC_G,  /***/  KC_H,  RSFT_T(KC_J),  LCTL_T(KC_K),  LGUI_T(KC_L),    LALT_T(KC_SCLN),      KC_QUOT,
        KC_UNDS,  LT(COMPOSE, KC_Z),  ALGR_T(KC_X),  KC_C,          KC_V,          KC_B,  /***/  KC_N,  KC_M,          KC_COMM,       ALGR_T(KC_DOT),  LT(BUTTON, KC_SLSH),  KC_MINS,
        //KC_UNDS,  KC_A,       KC_S,  KC_D,  KC_F,  KC_G,  /***/  KC_H,  KC_J,  KC_K,  KC_L,    KC_SCLN,      KC_QUOT,
        //KC_HASH,  KC_Z,  KC_X,  KC_C,          KC_V,          KC_B,  /***/  KC_N,  KC_M,          KC_COMM,       KC_DOT,  KC_SLSH,  KC_MINS,
                                LT(MEDIA, KC_ESC),  LT(NAV, KC_SPC),  LT(MOUSE, KC_TAB),  /***/  LT(SYM, KC_ENT),  LT(NUM, KC_BSPC),  LT(FUN, KC_DEL)
  ),

  [NAV] = LAYOUT_split_3x6_3(
        XXX,     QK_BOOT,  XXX,      XXX,      XXX,      XXX,  /***/  U_RDO,    U_PST,    U_CPY,    U_CUT,    U_UND,    XXX,
        XXX,     KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,  XXX,  /***/  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  CW_TOGG,  ALT_TAB,
        XXX,     XXX,      KC_ALGR,  XXX,      XXX,      XXX,  /***/  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_INS,   XXX,
                                     XXX,      XXX,      XXX,  /***/  KC_ENT,   KC_BSPC,  KC_DEL
  ),

  [MOUSE] = LAYOUT_split_3x6_3(
        ___,  ___,  ___,  ___,  ___,  ___,  /***/  ___,      ___,      ___,     ___,  ___,  ___,
        ___,  ___,  ___,  ___,  ___,  ___,  /***/  ___,      ___,      ___,     ___,  ___,  ___,
        ___,  ___,  ___,  ___,  ___,  ___,  /***/  ___,      ___,      ___,     ___,  ___,  ___,
                          ___,  ___,  ___,  /***/  KC_BTN1,  KC_BTN3,  KC_BTN2
  ),

  [MEDIA] = LAYOUT_split_3x6_3(
        XXX,     QK_BOOT,  XXX,      XXX,      XXX,      XXX,  /***/  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXX,
        XXX,     KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,  XXX,  /***/  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  OU_AUTO,  XXX,
        XXX,     XXX,      KC_ALGR,  XXX,      XXX,      XXX,  /***/  XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
                                     XXX,      XXX,      XXX,  /***/  KC_MSTP,  KC_MPLY,  KC_MUTE
  ),

  [NUM] = LAYOUT_split_3x6_3(
        ___,  KC_LBRC,  KC_7,  KC_8,    KC_9,  KC_RBRC,  /***/  XXX,  XXX,      XXX,      XXX,      QK_BOOT,  XXX,
        ___,  KC_MINS,  KC_4,  KC_5,    KC_6,  KC_PLUS,  /***/  XXX,  KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  XXX,
        ___,  KC_GRV,   KC_1,  KC_2,    KC_3,  KC_ASTR,  /***/  XXX,  XXX,      XXX,      KC_ALGR,  KC_SLSH,  XXX,
                               KC_DOT,  KC_0,  COMM_SPC, /***/  XXX,  XXX,      XXX
  ),

  [SYM] = LAYOUT_split_3x6_3(
        ___,  KC_LCBR,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RCBR,  /***/  XXX,  XXX,      XXX,      XXX,      QK_BOOT,  XXX,
        ___,  KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_PLUS,  /***/  XXX,  KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  XXX,
        ___,  KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_PIPE,  /***/  XXX,  XXX,      XXX,      KC_ALGR,  XXX,      XXX,
                                  KC_LPRN,  KC_RPRN,  KC_UNDS,  /***/  XXX,  XXX,      XXX
  ),

  [FUN] = LAYOUT_split_3x6_3(
        XXX,  KC_F12,  KC_F7,  KC_F8,   KC_F9,   KC_PSCR,  /***/  XXX,  XXX,      XXX,      XXX,      QK_BOOT,  XXX,
        XXX,  KC_F11,  KC_F4,  KC_F5,   KC_F6,   KC_SCRL,  /***/  XXX,  KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  XXX,
        XXX,  KC_F10,  KC_F1,  KC_F2,   KC_F3,   KC_PAUS,  /***/  XXX,  XXX,      XXX,      KC_ALGR,  XXX,      XXX,
                               KC_APP,  KC_SPC,  KC_TAB,   /***/  XXX,  XXX,      XXX
  ),

  [BUTTON] = LAYOUT_split_3x6_3(
        XXX,  TP_RESET,  XXX,  XXX,      XXX,      XXX,      /***/  XXX,  XXX,      XXX,      XXX,      QK_BOOT,  XXX,
        XXX,  TP_SENSI,  XXX,  DM_REC1,  DM_REC2,  XXX,      /***/  XXX,  KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  XXX,
        XXX,  TP_SENSD,  XXX,  XXX,      XXX,      XXX,      /***/  XXX,  XXX,      XXX,      KC_ALGR,  XXX,      XXX,
                               XXX,      DM_PLY1,  DM_PLY2,  /***/  XXX,  XXX,      XXX
  ),

  [COMPOSE] = LAYOUT_split_3x6_3(
        XXX,  QK_BOOT,  XXX,      XXX,      XXX,      XXX,  /***/  XXX,     XXX,      XXX,    XXX,  XXX,             COMPOSE_ARING,
        XXX,  KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,  XXX,  /***/  XXX,     XXX,      XXX,    XXX,  COMPOSE_OSLASH,  COMPOSE_AE,
        XXX,  XXX,      KC_ALGR,  XXX,      XXX,      XXX,  /***/  XXX,     XXX,      XXX,    XXX,  XXX,             XXX,
                                  XXX,      XXX,      XXX,  /***/  KC_ENT,  KC_BSPC,  KC_DEL
  )
};

// Trackpoint sensitivity
static uint8_t trackpoint_sensitivity = 90;

// Dynamic macro recording state
static uint8_t dynamic_rec = 0;

#ifdef DYNAMIC_MACRO_ENABLE
#define DYNAMIC_MACRO_CURRENT_SLOT() (direction > 0 ? 1 : 2)
void dynamic_macro_record_start_user(int8_t direction) {
    dynamic_rec = DYNAMIC_MACRO_CURRENT_SLOT();
}

void dynamic_macro_record_end_user(int8_t direction) {
    dynamic_rec = 0;
}
#endif

#ifdef OLED_ENABLE
const char keycode_to_char(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {

        keycode &= 0xFF;
    }

    switch (keycode) {
        // Basic:
        case KC_NO: return ' ';
        case KC_TRANSPARENT: return ' ';
        case KC_A: return 'A';
        case KC_B: return 'B';
        case KC_C: return 'C';
        case KC_D: return 'D';
        case KC_E: return 'E';
        case KC_F: return 'F';
        case KC_G: return 'G';
        case KC_H: return 'H';
        case KC_I: return 'I';
        case KC_J: return 'J';
        case KC_K: return 'K';
        case KC_L: return 'L';
        case KC_M: return 'M';
        case KC_N: return 'N';
        case KC_O: return 'O';
        case KC_P: return 'P';
        case KC_Q: return 'Q';
        case KC_R: return 'R';
        case KC_S: return 'S';
        case KC_T: return 'T';
        case KC_U: return 'U';
        case KC_V: return 'V';
        case KC_W: return 'W';
        case KC_X: return 'X';
        case KC_Y: return 'Y';
        case KC_Z: return 'Z';
        case KC_1: return '1';
        case KC_2: return '2';
        case KC_3: return '3';
        case KC_4: return '4';
        case KC_5: return '5';
        case KC_6: return '6';
        case KC_7: return '7';
        case KC_8: return '8';
        case KC_9: return '9';
        case KC_0: return '0';
        case KC_ENTER: return 20;
        case KC_ESCAPE: return 19;
        case KC_BACKSPACE: return 17;
        case KC_TAB: return 26;
        case KC_SPACE: return 22;
        case KC_MINUS: return '-';
        case KC_EQUAL: return '=';
        case KC_LEFT_BRACKET: return '[';
        case KC_RIGHT_BRACKET: return ']';
        case KC_BACKSLASH: return '\\';
        case KC_NONUS_HASH: return '#';
        case KC_SEMICOLON: return ';';
        case KC_QUOTE: return '\'';
        case KC_GRAVE: return '`';
        case KC_COMMA: return ',';
        case KC_DOT: return '.';
        case KC_SLASH: return '/';
        case KC_CAPS_LOCK: return 145;
        case KC_F1: return '1';
        case KC_F2: return '2';
        case KC_F3: return '3';
        case KC_F4: return '4';
        case KC_F5: return '5';
        case KC_F6: return '6';
        case KC_F7: return '7';
        case KC_F8: return '8';
        case KC_F9: return '9';
        case KC_F10: return '0';
        case KC_F11: return '1';
        case KC_F12: return '2';
        case KC_PRINT_SCREEN: return 171;
        case KC_SCROLL_LOCK: return 168;
        case KC_PAUSE: return 169;
        case KC_INSERT: return 167;
        case KC_HOME: return 28;
        case KC_PAGE_UP: return 30;
        case KC_DELETE: return 16;
        case KC_END: return 29;
        case KC_PAGE_DOWN: return 31;
        case KC_RIGHT: return 26;
        case KC_LEFT: return 27;
        case KC_DOWN: return 25;
        case KC_UP: return 24;
        case KC_NUM_LOCK: return 'N';
        case KC_KP_SLASH: return '/';
        case KC_KP_ASTERISK: return '*';
        case KC_KP_MINUS: return '-';
        case KC_KP_PLUS: return '+';
        case KC_KP_ENTER: return 20;
        case KC_KP_1: return '1';
        case KC_KP_2: return '2';
        case KC_KP_3: return '3';
        case KC_KP_4: return '4';
        case KC_KP_5: return '5';
        case KC_KP_6: return '6';
        case KC_KP_7: return '7';
        case KC_KP_8: return '8';
        case KC_KP_9: return '9';
        case KC_KP_0: return '0';
        case KC_KP_DOT: return '.';
        case KC_NONUS_BACKSLASH: return '\\';
        case KC_APPLICATION: return 163;
        case KC_KB_POWER: return 'P';
        case KC_KP_EQUAL: return '=';
        case KC_EXECUTE: return 'E';
        case KC_HELP: return 'H';
        case KC_MENU: return 'M';
        case KC_SELECT: return 'S';
        case KC_STOP: return 'S';
        case KC_AGAIN: return 174;
        case KC_UNDO: return 175;
        case KC_CUT: return 173;
        case KC_COPY: return 165;
        case KC_PASTE: return 172;
        case KC_FIND: return 'F';
        case KC_KB_MUTE: return 1;
        case KC_KB_VOLUME_UP: return 2;
        case KC_KB_VOLUME_DOWN: return 3;
        case KC_LOCKING_CAPS_LOCK: return 'L';
        case KC_LOCKING_NUM_LOCK: return 'N';
        case KC_LOCKING_SCROLL_LOCK: return 'S';
        case KC_KP_COMMA: return ',';
        case KC_RETURN: return 20;
        case KC_AUDIO_MUTE: return 1;
        case KC_AUDIO_VOL_UP: return 2;
        case KC_AUDIO_VOL_DOWN: return 3;
        case KC_MEDIA_NEXT_TRACK: return 4;
        case KC_MEDIA_PREV_TRACK: return 5;
        case KC_MEDIA_STOP: return 6;
        case KC_MEDIA_PLAY_PAUSE: return 7;
        case KC_MS_UP: return 24;
        case KC_MS_DOWN: return 25;
        case KC_MS_LEFT: return 27;
        case KC_MS_RIGHT: return 26;
        case KC_MS_BTN1: return 131;
        case KC_MS_BTN2: return 132;
        case KC_MS_BTN3: return 133;
        case KC_MS_BTN4: return 134;
        case KC_MS_BTN5: return 135;
        case KC_MS_BTN6: return 136;
        case KC_MS_BTN7: return 137;
        case KC_MS_BTN8: return 138;
        case KC_MS_WH_UP: return 30;
        case KC_MS_WH_DOWN: return 31;
        case KC_MS_WH_LEFT: return 17;
        case KC_MS_WH_RIGHT: return 16;
        case KC_LEFT_CTRL: return 165;
        case KC_LEFT_SHIFT: return 171;
        case KC_LEFT_ALT: return 163;
        case KC_LEFT_GUI: return 166;
        case KC_RIGHT_CTRL: return 165;
        case KC_RIGHT_SHIFT: return 171;
        case KC_RIGHT_ALT: return 176;
        case KC_RIGHT_GUI: return 166;

        // US shifted keycodes
        case KC_TILD: return '~';
        case KC_EXLM: return '!';
        case KC_AT: return '@';
        case KC_HASH: return '#';
        case KC_DLR: return '$';
        case KC_PERC: return '%';
        case KC_CIRC: return '^';
        case KC_AMPR: return '&';
        case KC_ASTR: return '*';
        case KC_LPRN: return '(';
        case KC_RPRN: return ')';
        case KC_UNDS: return '_';
        case KC_PLUS: return '+';
        case KC_LCBR: return '{';
        case KC_RCBR: return '}';
        case KC_PIPE: return '|';
        case KC_COLN: return ':';
        case KC_DQUO: return '"';
        case KC_LABK: return '<';
        case KC_RABK: return '>';
        case KC_QUES: return '?';

        // Lighting
        case RGB_TOG: return 9;
        case RGB_MODE_FORWARD: return 14;
        case RGB_MODE_REVERSE: return 14;
        case RGB_HUI: return 12;
        case RGB_HUD: return 12;
        case RGB_SAI: return 11;
        case RGB_SAD: return 11;
        case RGB_VAI: return 15;
        case RGB_VAD: return 15;
        case RGB_SPI: return 30;
        case RGB_SPD: return 31;

        // Quantum keycodes
        case QK_BOOT: return 164;
        case QK_RBT: return 170;
        case CW_TOGG: return 168;

        // Dynamic macros
        case DM_REC1: return 141;
        case DM_REC2: return 142;
        case DM_PLY1: return 143;
        case DM_PLY2: return 144;

        // Custom keycodes
        case ALT_TAB:
            return 0x12;
        case U_PST:
            return 172;
        case COMM_SPC:
            return ',';
        case TP_SENSI:
            return '+';
        case TP_SENSD:
            return '-';
        case COMPOSE_AE:
            return 0x80;
        case COMPOSE_OSLASH:
            return 0x81;
        case COMPOSE_ARING:
            return 0x82;
        default:
            break;
    }

    return 8;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    /*
       if (!is_keyboard_master()) {
       return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
       }
       */
    //return OLED_ROTATION_270;
    return OLED_ROTATION_0;
}

#define IS_TAP_HOLD(keycode) ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || \
                              (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX))

void oled_render_layer_state(void) {
    unsigned int layer = get_highest_layer(layer_state);
    bool caps_word = is_caps_word_on();

    oled_write_ln(layer_strings[layer], false);
    oled_advance_page(true);

    if (is_keyboard_left()) {
        for (int row = 0; row <= 3; row++) {
            for (int col = 0; col < MATRIX_COLS; col++) {
                keypos_t pos = {col, row};
                uint8_t key_layer = layer_switch_get_layer(pos);
                uint16_t keycode = keymaps[key_layer][row][col];
                oled_write_char(keycode_to_char(keycode), false);
            }
            oled_advance_page(true);
        }

    } else {
        for (int row = 4; row < MATRIX_ROWS; row++) {
            for (int col = MATRIX_COLS-1; col >= 0; col--) {
                keypos_t pos = {col, row};
                uint8_t key_layer = layer_switch_get_layer(pos);
                uint16_t keycode = keymaps[key_layer][row][col];
                oled_write_char(keycode_to_char(keycode), false);
            }
            oled_advance_page(true);
        }
    }

    oled_advance_page(true);

    if (layer == BUTTON || layer == MOUSE) {
        char buf[32];
        snprintf(buf, sizeof(buf), "TP: %d", trackpoint_sensitivity);
        oled_write_ln(buf, false);
    } else {
        oled_advance_page(true);
    }

    if (caps_word) {
        oled_write_char(keycode_to_char(CW_TOGG), false);
    } else {
        oled_write_char(' ', false);
    }

    switch (dynamic_rec) {
        case 1:
            oled_write_char(keycode_to_char(DM_REC1), false);
            break;
        case 2:
            oled_write_char(keycode_to_char(DM_REC2), false);
            break;
        default:
            oled_write_char(' ', false);
            break;
    }
}

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

bool oled_task_user(void) {
    oled_render_layer_state();
    return false;
}
#endif // OLED_ENABLE

#ifdef PS2_MOUSE_ENABLE
void trackpoint_set_sensitivity(uint8_t sensitivity) {
    PS2_MOUSE_SEND(0xE2, "trackpoint_set_sensitivity: 0xE2");
    PS2_MOUSE_SEND(0x81, "trackpoint_set_sensitivity: 0x81");
    PS2_MOUSE_SEND(0x4A, "trackpoint_set_sensitivity: 0x4A");
    PS2_MOUSE_SEND(sensitivity, "trackpoint_set_sensitivity: xxx");
}

void trackpoint_reset(void) {
    PS2_MOUSE_SEND(0xE2, "trackpoint_reset: 0xE2");
    PS2_MOUSE_SEND(0x51, "trackpoint_reset: 0x51");
}

void ps2_mouse_init_user() {
    // set TrackPoint sensitivity
    trackpoint_set_sensitivity(trackpoint_sensitivity);
}

void ps2_regdump(void) {
    println("Register dump:");
    print("     ");
    for (uint8_t addr = 0; addr <= 0xF; addr++) {
        print_hex8(addr);
        print(" ");
    }
    println("");
    for (uint16_t addr = 0; addr <= 0xFF; addr++) {
        uint8_t data;
        if ((addr & 0xf) == 0) {
            print_hex8(addr);
            print(" | ");
        }

        ps2_host_send(0xE2);
        ps2_host_send(0x80);
        data = ps2_host_send((uint8_t)addr);
        if (data == 0xFA) {
            data = ps2_host_recv_response();
            print_hex8(data);
            print(" ");
        } else {
            print("xx ");
        }
        if ((addr & 0xf) == 0xf) {
            println("");
        }
    }
    println("");
}
#endif // PS2_MOUSE_ENABLE

#if defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE

static uint16_t mh_auto_buttons_timer;
extern int tp_buttons; // mousekey button state set in action.c and used in ps2_mouse.c

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
    if (abs(mouse_report->x) <= 1 && abs(mouse_report->y) <= 1) {
        // Ignore tiny mouse events
        return;
    }
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



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed)
        return true;

    switch (keycode) {
        case ALT_TAB:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_TAB) SS_UP(X_LALT));
            break;
        case U_PST:
            SEND_STRING(SS_LSFT(SS_TAP(X_INS)));
            break;
        case COMM_SPC:
            SEND_STRING(", ");
            break;
#ifdef PS2_MOUSE_ENABLE
        case TP_SENSI:
            if ((int)trackpoint_sensitivity + 5 > 0xff)
                trackpoint_sensitivity = 0xff;
            else
                trackpoint_sensitivity += 5;
            trackpoint_set_sensitivity(trackpoint_sensitivity);
            break;
        case TP_SENSD:
            if ((int)trackpoint_sensitivity - 5 < 0)
                trackpoint_sensitivity = 0;
            else
                trackpoint_sensitivity -= 5;
            trackpoint_set_sensitivity(trackpoint_sensitivity);
            break;
        case TP_RESET:
            trackpoint_reset();
            break;
#endif
        case COMPOSE_AE:
            SEND_STRING(SS_RALT("ae"));
            break;
        case COMPOSE_OSLASH:
            SEND_STRING(SS_RALT("/o"));
            break;
        case COMPOSE_ARING:
            SEND_STRING(SS_RALT("aa"));
            break;
        default:
            break;
    }

    return true;
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
    debug_mouse=true;
}
