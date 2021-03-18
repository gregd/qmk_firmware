#include QMK_KEYBOARD_H

#include <print.h>
#include "tbk3.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_split_4x6_3( \
        KC_LEAD, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT,     /**/ KC_UNDERSCORE, KC_AMPERSAND, KC_ASTERISK, KC_MINS, KC_PLUS, KC_CIRCUMFLEX, \
        OSM(MOD_LALT), KC_Q, KC_W, KC_E, KC_R, KC_T,                /**/ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL, \
        OSM(MOD_LSFT), KC_A, KC_S, KC_D, KC_F, KC_G,                /**/ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        OSM(MOD_LCTL), KC_Z, KC_X, KC_C, KC_V, KC_B,                /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RCTL), \
        LT(_IDE, KC_LGUI), LT(_NAV, KC_BSPC), LT(_SYMBOLS, KC_ESC), /**/ LT(_SYMBOLS, KC_ENT), LT(_NAV, KC_SPC), LT(_IDE, KC_TAB)),

	[_POLISH] = LAYOUT_split_4x6_3( \
        GD_QWERTY, RALT(KC_X), RALT(KC_S), RALT(KC_E), RALT(KC_A), RALT(KC_C), /**/ RALT(KC_Z), RALT(KC_N), RALT(KC_L), RALT(KC_O), _______, _______, \
        _______, _______, _______, _______, _______, _______,   /**/ _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,   /**/ _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,   /**/ _______, _______, _______, _______, _______, _______, \
        _______, _______, MT(MOD_RALT, KC_ESC),            /**/ MT(MOD_RALT, KC_ENT), _______, _______),

	[_NAV] = LAYOUT_split_4x6_3( \
        GD_QWERTY, KC_TILD,  KC_CIRC,  KC_PERC, GD_ARROW, GD_FARROW, /**/ BABL_DEL_LINE, BABL_DEL_2LNS, BABL_DEL_2LNE, BABL_IDE_DUP_LINE, KC_MY_COMPUTER, KC_MAIL, \
        KC_AT,     KC_EXLM,  KC_MINS,  KC_LCBR, KC_RCBR,  KC_GRV,    /**/ BABL_GO_SLINE, BABL_GO_LWORD, BABL_GO_RWORD, BABL_GO_ELINE,     BABL_PASTE,     BABL_PASTE_RECENT, \
        KC_DLR,    KC_ASTR,  KC_UNDS,  KC_LPRN, KC_RPRN,  KC_BSLASH, /**/ KC_LEFT,       KC_DOWN,       KC_UP,         KC_RIGHT,          BABL_COPY,      BABL_IDE_EX_SEL, \
        KC_HASH,   KC_AMPR,  KC_PLUS,  KC_LBRC, KC_RBRC,  KC_PIPE,   /**/ BABL_GO_EDOC,  KC_PGDN,       KC_PGUP,       BABL_GO_SDOC,      BABL_CUT,       BABL_SELECT_ALL, \
        KC_APP, BABL_DEL_LWORD, KC_DEL,                              /**/ _______, _______, _______),

	[_SYMBOLS] = LAYOUT_split_4x6_3( \
        GD_QWERTY,        KC_F1,                KC_F2,              KC_F3,            KC_F4,          KC_F5,              /**/ KC_F6,      KC_F7,     KC_F8,       KC_F9,   BABL_SCR_CAP_SEL, BABL_SCR_CAP_FULL, \
        BABL_WINDOW_NEXT, BABL_SWITCH_APP_NEXT, BABL_APP_SAVE,      BABL_BR_NEW_TAB,  BABL_FIND,      BABL_FIND_REPLACE,  /**/ KC_1,       KC_2,      KC_3,        KC_4,    KC_5,             KC_F10, \
        BABL_BR_ZOOM_IN,  GD_ALT_TAB,           BABL_BR_URL_BAR,    BABL_BR_NEXT_TAB, BABL_FIND_NEXT, BABL_UNDO,          /**/ KC_6,       KC_7,      KC_8,        KC_9,    KC_0,             KC_F11, \
        BABL_BR_ZOOM_OUT, BABL_CLOSE_APP,       BABL_BR_CLOSE_TAB,  BABL_BR_PREV_TAB, BABL_FIND_PREV, BABL_REDO,          /**/ GD_FARROW,  GD_ARROW,  GD_ABRACKET, GD_HDIR, GD_UDIR,          KC_F12, \
        _______, _______, KC_LEAD,                                                                                        /**/ BABL_IDE_NEW_LINE, BABL_IDE_COMPLETE, BABL_IDE_FIXES),

	[_IDE] = LAYOUT_split_4x6_3( \
        RESET,   KC_MUTE,         KC_VOLD,           KC_VOLU,           KC_MPLY,           KC_MNXT,            /**/ BABL_IDE_WIN_STR,   BABL_IDE_WIN_GCOM,  BABL_IDE_WIN_GHIS, BABL_IDE_GO_LINE,    KC_NO,             GD_INFO, \
        _______, KC_NO,           KC_NO,             KC_NO,             BABL_IDE_FINF,     BABL_IDE_WIN_SEA,   /**/ BABL_IDE_REL_FILE,  BABL_IDE_QDOC,      BABL_IDE_PREV_FN,  BABL_IDE_REC_FILE,   BABL_IDE_REFACTOR, BABL_IDE_COL_MODE, \
        _______, KC_NO,           KC_NO,             KC_NO,             BABL_IDE_FIND_ALL, BABL_IDE_WIN_FTREE, /**/ BABL_IDE_USAGES,    BABL_IDE_GO_DEF,    BABL_IDE_NEXT_FN,  BABL_IDE_GO_LAST_ED, BABL_IDE_RENAME,   BABL_IDE_REFORMAT, \
        _______, BABL_IDE_BUILD,  BABL_IDE_RUN_ANY,  BABL_IDE_RUN_LAST, BABL_IDE_RUN_SEL,  BABL_IDE_WIN_RUN,   /**/ BABL_IDE_GO_FWD,    BABL_IDE_GO_BACK,   BABL_IDE_REL_SYM,  BABL_IDE_REC_LOC,    BABL_IDE_COMMENT,  BABL_IDE_TGL_CASE, \
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
