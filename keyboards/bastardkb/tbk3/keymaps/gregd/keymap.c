#include QMK_KEYBOARD_H

#include <print.h>
#include "tbk3.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_4x6_3( \
    /*             pinky       ring     middle   index                                                      index         middle       ring     pinky */
    KC_LEAD,       KC_EXCLAIM, KC_AT,   KC_HASH, KC_DOLLAR, KC_PERCENT,                 /**/ KC_UNDERSCORE, KC_AMPERSAND, KC_ASTERISK, KC_MINS, KC_PLUS,  KC_CIRCUMFLEX, \
    OSM(MOD_LALT), KC_Q,       KC_W,    KC_E,    KC_R,      KC_T,                       /**/ KC_Y,          KC_U,         KC_I,        KC_O,    KC_P,     KC_EQL, \
    OSM(MOD_LSFT), KC_A,       KC_S,    KC_D,    KC_F,      KC_G,                       /**/ KC_H,          KC_J,         KC_K,        KC_L,    KC_SCLN,  KC_QUOT, \
    OSM(MOD_LCTL), KC_Z,       KC_X,    KC_C,    KC_V,      KC_B,                       /**/ KC_N,          KC_M,         KC_COMM,     KC_DOT,  KC_SLSH,  OSM(MOD_RCTL), \
    LT(_IDE, KC_LGUI), LT(_NAV, KC_BSPC), LT(_SYMBOLS, KC_ESC),                         /**/ LT(_SYMBOLS, KC_ENT), LT(_NAV, KC_SPC), LT(_IDE, KC_TAB)),

  [_POLISH] = LAYOUT_split_4x6_3( \
    /*      pinky       ring        middle      index                                                    index       middle      ring        pinky */
    GD_QWE, RALT(KC_X), RALT(KC_S), RALT(KC_E), RALT(KC_A), RALT(KC_C),                 /**/ RALT(KC_Z), RALT(KC_N), RALT(KC_L), RALT(KC_O), _______, _______, \
    _______, _______, _______, _______, _______, _______,                               /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                               /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                               /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, MT(MOD_RALT, KC_ESC),                                             /**/ MT(MOD_RALT, KC_ENT), _______, _______),

  [_NAV] = LAYOUT_split_4x6_3( \
    /*         pinky     ring      middle   index                                                         index        middle       ring           pinky */
    GD_QWE,    KC_TILD,  KC_CIRC,  KC_PERC, GD_ARROW, GD_FARROW,                        /**/ GD_DEL_LINE, GD_DEL_2LNS, GD_DEL_2LNE, GD_I_DUP_LINE, KC_WWW_HOME, KC_MY_COMPUTER, \
    KC_AT,     KC_EXLM,  KC_MINS,  KC_LCBR, KC_RCBR,  KC_GRV,                           /**/ GD_GO_SLINE, GD_GO_LWORD, GD_GO_RWORD, GD_GO_ELINE,   GD_PASTE,    GD_PASTE_RECENT, \
    KC_DLR,    KC_ASTR,  KC_UNDS,  KC_LPRN, KC_RPRN,  KC_BSLASH,                        /**/ KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,      GD_COPY,     GD_I_EX_SEL, \
    KC_HASH,   KC_AMPR,  KC_PLUS,  KC_LBRC, KC_RBRC,  KC_PIPE,                          /**/ GD_GO_EDOC,  KC_PGDN,     KC_PGUP,     GD_GO_SDOC,    GD_CUT,      GD_SELECT_ALL, \
    KC_APP, GD_DEL_LWORD, KC_DEL,                                                       /**/ _______, _______, _______),

  [_SYMBOLS] = LAYOUT_split_4x6_3( \
    /*              pinky         ring           middle          index                                   index      middle       ring       pinky */
    GD_QWE,         KC_F1,        KC_F2,         KC_F3,          KC_F4,    KC_F5,       /**/ KC_F6,      KC_F7,     KC_F8,       KC_F9,     GD_SCR_CAP_SEL, GD_SCR_CAP_FULL, \
    GD_APP_SAVE,    GD_WIN_NEXT,  GD_BR_URL_BAR, GD_BR_NEW_TAB,  GD_FIND,  GD_REPLACE,  /**/ KC_1,       KC_2,      KC_3,        KC_4,      KC_5,           KC_F10, \
    GD_BR_ZOOM_IN,  GD_APP_NEXT,  GD_ALT_TAB,    GD_BR_NEXT_TAB, GD_FNEXT, GD_UNDO,     /**/ KC_6,       KC_7,      KC_8,        KC_9,      KC_0,           KC_F11, \
    GD_BR_ZOOM_OUT, GD_CLOSE_APP, GD_BR_CL_TAB,  GD_BR_PREV_TAB, GD_FPREV, GD_REDO,     /**/ GD_FARROW,  GD_ARROW,  GD_ABRACKET, GD_HDIR,   GD_UDIR,        KC_F12, \
    _______, _______, KC_LEAD,                                                          /**/ GD_I_NEW_LINE, GD_I_COMPLETE, GD_I_FIXES),

  [_IDE] = LAYOUT_split_4x6_3( \
    /*       pinky           ring       middle         index                                                index           middle         ring           pinky */
    RESET,   GD_RESET,       KC_NO,     KC_MPRV,       KC_MPLY,    KC_MNXT,             /**/ GD_I_WIN_STR,  GD_I_WIN_GCOM,  GD_I_WIN_GHIS, GD_I_GO_LINE,  KC_NO,         GD_INFO, \
    KC_VOLU, GD_BR_ZOOM_IN,  KC_NO,     GD_I_FACTION,  GD_I_FINF,  GD_I_WIN_SEA,        /**/ GD_I_REL_FILE, GD_I_QDOC,      GD_I_USAGES,   GD_I_REC_LOC,  GD_I_REFACTOR, GD_I_COL_MODE, \
    KC_VOLD, GD_BR_ZOOM_OUT, KC_NO,     GD_I_GO_FILE,  GD_I_FINDA, GD_I_WIN_FTREE,      /**/ GD_I_REL_SYM,  GD_I_GO_DEF,    GD_I_NEXT_FN,  GD_I_REC_FILE, GD_I_RENAME,   GD_I_REFORMAT, \
    KC_MUTE, GD_I_BUILD,     GD_I_RUNA, GD_I_RUNL,     GD_I_RUNS,  GD_I_WIN_RUN,        /**/ GD_I_GO_FWD,   GD_I_GO_BACK,   GD_I_PREV_FN,  GD_I_GO_L_ED,  GD_I_COMMENT,  GD_I_TGL_CASE, \
    _______, _______, _______,                                                          /**/ _______, _______, _______),
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
