#include QMK_KEYBOARD_H

#include <print.h>
#include "tbk3.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_split_4x6_3( \
        KC_LEAD, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, /**/ KC_UNDERSCORE, KC_AMPERSAND, KC_ASTERISK, KC_MINS, KC_PLUS, KC_CIRCUMFLEX, \
        OSM(MOD_LALT), KC_Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL, \
        OSM(MOD_LSFT), KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        OSM(MOD_LCTL), KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RCTL), \
        LT(_IDE,KC_LGUI), LT(_NAV,KC_BSPC), LT(_SYMBOLS,KC_ESC), /**/ LT(_SYMBOLS,KC_ENT), LT(_NAV,KC_SPC), LT(_IDE,KC_TAB)),

	[_POLISH] = LAYOUT_split_4x6_3( \
        GD_QWERTY, RALT(KC_A), RALT(KC_S), RALT(KC_E), RALT(KC_Z), RALT(KC_C), /**/ GD_PL_DZ, RALT(KC_N), RALT(KC_L), RALT(KC_O), GD_PL_CZ, GD_PL_RZ, \
        _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, GD_PL_SZ, \
        _______, _______, _______, MT(MOD_RALT, KC_D), _______, _______, /**/ _______, _______, MT(MOD_RALT, KC_K), _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, \
        KC_RALT, _______, KC_RALT, /**/ KC_RALT, _______, KC_RALT),

	[_NAV] = LAYOUT_split_4x6_3( \
        GD_QWERTY, KC_TILD,  KC_CIRC,  KC_PERC, GD_ARROW, GD_FARROW, /**/ KC_NO,              BABL_DEL_TO_LINE_START, BABL_DEL_TO_LINE_END, KC_NO,             KC_NO,       KC_NO, \
        KC_AT,     KC_EXLM,  KC_MINS,  KC_LCBR, KC_RCBR, KC_GRV,     /**/ BABL_GO_START_LINE, BABL_GO_LEFT_WORD,      BABL_GO_RIGHT_WORD,   BABL_GO_END_LINE,  BABL_PASTE,  BABL_PASTE_RECENT, \
        KC_DLR,    KC_ASTR,  KC_UNDS,  KC_LPRN, KC_RPRN, KC_BSLASH,  /**/ KC_LEFT,            KC_DOWN,                KC_UP,                KC_RIGHT,          BABL_COPY,   BABL_IDE_EXTEND_SEL, \
        KC_HASH,   KC_AMPR,  KC_PLUS,  KC_LBRC, KC_RBRC, KC_PIPE,    /**/ BABL_GO_END_DOC,    KC_PGDN,                KC_PGUP,              BABL_GO_START_DOC, BABL_CUT,    BABL_SELECT_ALL, \
        KC_APP, BABL_DEL_LEFT_WORD, KC_DEL, /**/ _______, _______, _______),

	[_SYMBOLS] = LAYOUT_split_4x6_3( \
        GD_QWERTY, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,         /**/ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______, \
        BABL_WINDOW_NEXT, BABL_CLOSE_APP,       BABL_IDE_FILE_FIND, BABL_BR_PREV_TAB, BABL_FIND_NEXT, BABL_IDE_QUICK_DOC, /**/ KC_1,  KC_2,  KC_3,  KC_4,  KC_5,   KC_F11, \
        BABL_BR_ZOOM_IN,  GD_ALT_TAB,           BABL_BR_URL_BAR,    BABL_BR_NEXT_TAB, BABL_FIND,      BABL_UNDO,          /**/ KC_6,  KC_7,  KC_8,  KC_9,  KC_0,   KC_F12, \
        BABL_BR_ZOOM_OUT, BABL_SWITCH_APP_NEXT, BABL_BR_CLOSE_TAB,  BABL_BR_NEW_TAB,  BABL_FIND_PREV, BABL_REDO,          /**/ KC_MINS, GD_ARROW, GD_FARROW, GD_ABRACKET, KC_TILDE, _______, \
        KC_LEAD, _______, _______, /**/ _______, _______, _______),

	[_IDE] = LAYOUT_split_4x6_3( \
        RESET, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, KC_MPRV, /**/ KC_CALC, KC_MAIL, KC_MSEL, KC_MYCM, KC_NO, GD_INFO, \
        _______, KC_ASUP, KC_NO, KC_NO, KC_NO, KC_NO, /**/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        KC_ASTG, KC_ASDN, KC_NO, KC_NO, KC_NO, KC_NO, /**/ KC_NO, KC_A, KC_NO, KC_NO, KC_NO, KC_NO, \
        _______, KC_ASRP, KC_NO, KC_NO, KC_NO, KC_NO, /**/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
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
