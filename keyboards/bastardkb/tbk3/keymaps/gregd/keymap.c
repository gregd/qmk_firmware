#include QMK_KEYBOARD_H

#include <print.h>
#include "tbk3.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_4x6_3( \
    /*                     pinky  ring   middle index                                                       index         middle       ring     pinky */
    OSM(MOD_LALT),         KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                            /**/ KC_6,          KC_7,         KC_8,        KC_9,    KC_0,     KC_CAPS, \
    OSM(MOD_LGUI),         KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                            /**/ KC_Y,          KC_U,         KC_I,        KC_O,    KC_P,     KC_LEAD, \
    OSM(MOD_LSFT),         KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                            /**/ KC_H,          KC_J,         KC_K,        KC_L,    KC_SCLN,  KC_QUOT, \
    OSM(MOD_LCTL),         KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                            /**/ KC_N,          KC_M,         KC_COMM,     KC_DOT,  KC_SLSH,  OSM(MOD_RCTL), \
    \
    LT(_IDE, KC_DEL), LT(_SYMBOLS, KC_ENT), LT(_NAV, KC_ESC),                          /**/ LT(_NAV, KC_TAB), LT(_SYMBOLS, KC_SPC), LT(_IDE, KC_BSPC)),

  [_POLISH] = LAYOUT_split_4x6_3( \
    /*       pinky    ring     middle   index                                                         index    middle   ring     pinky */
    GD_RST,  _______, _______, _______, _______, _______,                               /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                               /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                               /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                               /**/ _______, _______, _______, _______, _______, _______, \
    \
    _______, MT(MOD_RALT, KC_BSPC), _______,                                            /**/ _______, MT(MOD_RALT, KC_SPC), _______),

  [_NAV] = LAYOUT_split_4x6_3( \
    /*            pinky         ring          middle        index                                         index        middle     ring          pinky */
    GD_RST,       GD_APP_CLOSE, GD_WIN_NEXT,  GD_REPLACE,   GD_B_ZOOMI, GD_B_ZOOMO,     /**/ GD_REDO,     GD_UNDO,     KC_PGUP,   GD_SE_ALL,    GD_I_DUP_SEL,  GD_I_COL_MODE, \
    GD_WIN_LFT,   GD_WIN_FULL,  GD_APP_NEXT,  GD_FPREV,     GD_B_PTAB,  GD_B_CTAB,      /**/ GD_GO_SDOC,  GD_GO_SLINE, KC_UP ,    GD_GO_ELINE,  GD_COPY,       GD_CUT, \
    GD_WIN_CEN,   GD_RUNAPP,    GD_ALT_TAB,   GD_FNEXT,     GD_B_NTAB,  GD_B_URL,       /**/ KC_APP,      KC_LEFT,     KC_DOWN,   KC_RIGHT,     GD_PASTE,      GD_I_EX_SEL, \
    GD_WIN_RGT,   GD_APP_SAVE,  GD_WIN_HIDE,  GD_FIND,      GD_B_NEWT,  GD_B_RLOAD,     /**/ GD_GO_EDOC,  GD_GO_LWORD, KC_PGDN,   GD_GO_RWORD,  GD_SHT_TGE,    GD_PA_REC, \
    \
    _______, _______, _______,                                                          /**/ _______, _______, _______),

  [_SYMBOLS] = LAYOUT_split_4x6_3( \
    /*              pinky     ring      middle    index                                                 index      middle    ring       pinky */
    GD_RST,         KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPLY,  KC_MNXT,                    /**/ GD_ARROW,  KC_LABK,   KC_RABK,  GD_FARROW, KC_PERC,   KC_TILD, \
    KC_WWW_HOME,    GD_DCOLN, KC_7,     KC_8,     KC_9,     KC_GRV,                     /**/ KC_BSLASH, KC_LCBR,   KC_RCBR,  KC_MINS,   KC_PLUS,   KC_DLR, \
    KC_MAIL,        GD_EQSP,  KC_4,     KC_5,     KC_6,     KC_0,                       /**/ KC_EXLM,   KC_LPRN,   KC_RPRN,  KC_UNDS,   KC_ASTR,   KC_AT, \
    GD_SCR_CAP_SEL, GD_HDIR,  KC_1,     KC_2,     KC_3,     KC_PERC,                    /**/ KC_PIPE,   KC_LBRC,   KC_RBRC,  KC_PEQL,   KC_AMPR,   KC_HASH, \
    \
    GD_DEL_2LNE, GD_I_NEW_LINE, _______,                                                /**/ GD_I_FIXES, GD_I_COMPLETE, GD_DEL_LWORD),

  [_IDE] = LAYOUT_split_4x6_3( \
    /*          pinky          ring        middle        index                                               index           middle         ring           pinky */
    RESET,      KC_F1,         KC_F2,      KC_F3,        KC_F4,         KC_F5,          /**/ KC_F6,         KC_F7,          KC_F8,         KC_F9,         KC_NO,         GD_INFO, \
    GD_I_GOTOL, GD_I_WIN_GITH, GD_I_FACT,  GD_I_RINF,    GD_I_REC_FILE, GD_I_GO_L_ED,   /**/ GD_I_REL_FILE, GD_I_QDOC,      GD_I_USAGES,   KC_NO,         GD_I_REFACTOR, KC_F10, \
    GD_I_BUILD, GD_I_WIN_GITC, GD_I_RUNA,  GD_I_WIN_SEA, GD_I_REC_LOC,  GD_I_WIN_RUN,   /**/ GD_I_REL_SYM,  GD_I_GO_DEF,    GD_I_NEXT_FN,  GD_I_REFORMAT, GD_I_RENAME,   KC_F11, \
    KC_NO,      GD_I_WIN_STRU, GD_I_RUNL,  GD_I_FINF,    GD_I_GO_FILE,  GD_I_RUNS,      /**/ GD_I_GO_FWD,   GD_I_GO_BACK,   GD_I_PREV_FN,  GD_I_TGL_CASE, GD_I_COMMENT,  KC_F12, \
    \
    GD_DEL_LINE, _______, _______,                                                      /**/ _______, _______, _______),
};
