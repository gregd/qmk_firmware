#include QMK_KEYBOARD_H

#include <print.h>
#include "tbk3.h"

// #define SSFT ACTION_MODS_ONESHOT(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_split_4x6_3( \
        KC_GRV,  KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT,      KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_UNDERSCORE, KC_PLUS, KC_EQL, \
        OSM(MOD_LALT), KC_Q, KC_W, KC_E, KC_R, KC_T,          KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, \
        OSM(MOD_LSFT), KC_A, KC_S, KC_D, KC_F, KC_G,          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        OSM(MOD_LCTL), KC_Z, KC_X, KC_C, KC_V, KC_B,          KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LEAD, \
        LT(_IDE_ACTIONS,KC_LGUI), LT(_MOVE,KC_BSPC), LT(_SYMBOLS,KC_ESC),     LT(_SYMBOLS,KC_ENT), LT(_MOVE,KC_SPC), LT(_IDE_ACTIONS,KC_TAB)),

	[_POLISH] = LAYOUT_split_4x6_3( \
        _______, RALT(KC_A), RALT(KC_S), RALT(KC_E), RALT(KC_Z), RALT(KC_C),     RALT(KC_X), RALT(KC_L), RALT(KC_N), RALT(KC_O), GD_PL_SZ, KC_UNDS, \
        _______, KC_Q, KC_W, KC_E, KC_R, KC_T,          KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, \
        _______, KC_A, KC_S, KC_D, KC_F, KC_G,          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        _______, KC_Z, KC_X, KC_C, KC_V, KC_B,          KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, _______, \
        _______, _______, _______,     _______, _______, _______),

	[_MOVE] = LAYOUT_split_4x6_3( \
        _______, BABL_CLOSE_APP,  KC_NO,              GD_MOVE,              GD_QWERTY,      GD_POLISH,                  BABL_DO_LINUX,      BABL_DO_MAC,        BABL_DO_VI,         BABL_DO_READMUX ,   BABL_DO_WINDOWS,        KC_EQL, \
        _______, BABL_REDO,       BABL_WINDOW_NEXT,   BABL_SWITCH_APP_NEXT, GD_ALT_TAB,     BABL_DEL_TO_LINE_END,       BABL_GO_START_DOC,  BABL_PGUP,          BABL_GO_PREV_LINE,  BABL_PGDN,          BABL_GO_PARA_START,     _______, \
        _______, BABL_SELECT_ALL, BABL_FIND_PREV,     BABL_FIND_NEXT,       BABL_FIND,      BABL_DEL_LEFT_WORD,         BABL_GO_START_LINE, BABL_GO_LEFT_1C,    BABL_GO_NEXT_LINE,  BABL_GO_RIGHT_1C,   BABL_GO_END_LINE,       BABL_SCREENCAPTURE, \
        _______, BABL_UNDO,       BABL_CUT,           BABL_COPY,            BABL_PASTE,     BABL_DEL_TO_LINE_START,     BABL_GO_END_DOC,    BABL_GO_LEFT_WORD,  KC_APP,             BABL_GO_RIGHT_WORD, BABL_GO_PARA_END,       _______, \
        _______, _______, _______,                                                   _______, _______, _______),

	[_SYMBOLS] = LAYOUT_split_4x6_3( \
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,              KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, \
        _______, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR,               KC_PIPE, KC_7, KC_8, KC_9, KC_PPLS, KC_PCMM, \
        _______, KC_NO, KC_NO, KC_NO, KC_LPRN, KC_RPRN,               KC_0,    KC_4, KC_5, KC_6, KC_PEQL, KC_PDOT, \
        _______, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC,               KC_NO, KC_1, KC_2, KC_3, KC_BSLS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS),

	[_IDE_ACTIONS] = LAYOUT_split_4x6_3( \
        RESET, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, KC_MPRV,   KC_CALC, KC_MAIL, KC_MSEL, KC_MYCM, KC_NO, GD_INFO, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               GD_ARROW, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               GD_FARROW, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               GD_ABRACKET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO),

	[_OS_ACTIONS] = LAYOUT_split_4x6_3( \
        KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, KC_MPRV,   KC_CALC, KC_MAIL, KC_MSEL, KC_MYCM, KC_WSCH, KC_WHOM, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO)
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
