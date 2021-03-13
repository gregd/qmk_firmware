#include QMK_KEYBOARD_H

#include <print.h>
#include "tbk3.h"

// #define SSFT ACTION_MODS_ONESHOT(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_split_4x6_3( \
        KC_GRV, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, /**/ KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_UNDERSCORE, KC_MINS, KC_PLUS, \
        OSM(MOD_LALT), KC_Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL, \
        OSM(MOD_LSFT), KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        KC_LEAD, KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_LCTL), \
        LT(_IDE_ACTIONS,KC_LGUI), LT(_NAV,KC_BSPC), LT(_SYMBOLS,KC_ESC), /**/ LT(_SYMBOLS,KC_ENT), LT(_NAV,KC_SPC), LT(_IDE_ACTIONS,KC_TAB)),

	[_POLISH] = LAYOUT_split_4x6_3( \
        RALT(KC_X), RALT(KC_A), RALT(KC_S), RALT(KC_E), RALT(KC_Z), RALT(KC_C), /**/ GD_PL_DZ, RALT(KC_N), RALT(KC_L), RALT(KC_O), GD_PL_CZ, GD_PL_RZ, \
        _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, GD_PL_SZ, \
        _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, /**/ _______, _______, _______),

	[_NAV] = LAYOUT_split_4x6_3( \
        BABL_BROWSER_RELOAD, BABL_CLOSE_APP, BABL_BROWSER_ZOOM_OUT, BABL_BROWSER_ZOOM_IN, BABL_WINDOW_NEXT, BABL_REDO, /**/ BABL_DEL_TO_LINE_START, BABL_DEL_LEFT_WORD, BABL_DEL_RIGHT_WORD, BABL_DEL_TO_LINE_END, BABL_DEL_LINE, _______, \
        BABL_BROWSER_REOPEN_LAST_TAB, BABL_BROWSER_CLOSE_TAB, BABL_BROWSER_NEW_TAB, BABL_SWITCH_APP_NEXT, GD_ALT_TAB, BABL_UNDO, /**/ BABL_GO_START_LINE, BABL_GO_LEFT_WORD, BABL_GO_RIGHT_WORD, BABL_GO_END_LINE, BABL_PASTE, BABL_SELECT_ALL, \
        BABL_BROWSER_URL_BAR, BABL_BROWSER_PREV_TAB, BABL_BROWSER_NEXT_TAB, BABL_FIND_NEXT, BABL_FIND, BABL_FIND_PREV, /**/ KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, BABL_COPY, BABL_IDE_EX_SEL, \
        GD_QWERTY, _______, _______, _______, _______, _______, /**/ BABL_GO_START_DOC, BABL_PGDN,  BABL_PGUP, BABL_GO_END_DOC, BABL_CUT, _______, \
        KC_APP, KC_DEL, _______, /**/ _______, _______, _______),

	[_SYMBOLS] = LAYOUT_split_4x6_3( \
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /**/ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, \
        _______, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR, /**/ KC_PIPE, KC_7, KC_8, KC_9, KC_PPLS, KC_PCMM, \
        _______, KC_NO, KC_NO, KC_NO, KC_LPRN, KC_RPRN, /**/ KC_0,    KC_4, KC_5, KC_6, KC_PEQL, KC_PDOT, \
        GD_QWERTY, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, /**/ KC_NO, KC_1, KC_2, KC_3, KC_BSLS, KC_TRNS, \
        _______, _______, _______, /**/ _______, _______, _______),

	[_IDE_ACTIONS] = LAYOUT_split_4x6_3( \
        RESET, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, KC_MPRV, /**/ KC_CALC, KC_MAIL, KC_MSEL, KC_MYCM, KC_NO, GD_INFO, \
        _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /**/ GD_ARROW, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /**/ GD_FARROW, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /**/ GD_ABRACKET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        _______, _______, _______, /**/ _______, _______, _______),

	[_OS_ACTIONS] = LAYOUT_split_4x6_3( \
        KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, KC_MPRV,   KC_CALC, KC_MAIL, KC_MSEL, KC_MYCM, KC_WSCH, KC_WHOM, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        _______, _______, _______, /**/ _______, _______, _______),
};

// // custom tapping term lengths.
// uint16_t get_tapping_term(uint16_t keycode) {
//     switch (keycode) {
//         case LT(_MOV, KC_TAB):
//             return TAPPING_TERM ;
//             break;
//         default:
//         return TAPPING_TERM;
//     }
// }
