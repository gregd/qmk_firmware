#include QMK_KEYBOARD_H

#include <print.h>
#include "tbk3.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_4x6_3( \
    /*                     pinky  ring   middle index                                                      index         middle       ring     pinky */
    OSM(MOD_LALT),         KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                           /**/ KC_6,          KC_7,         KC_8,        KC_9,    KC_0,     GD_CAPS, \
    OSM(MOD_LGUI),         KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                           /**/ KC_Y,          KC_U,         KC_I,        KC_O,    KC_P,     GD_TGL_NAV, \
    OSM(MOD_LSFT),         KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                           /**/ KC_H,          KC_J,         KC_K,        KC_L,    KC_SCLN,  OSM(MOD_RSFT), \
    OSM(MOD_LCTL),         KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                           /**/ KC_N,          KC_M,         KC_COMM,     KC_DOT,  KC_SLSH,  OSM(MOD_RCTL), \
    \
    LT(_IDE_LEFT, KC_DEL), LT(_SYMBOLS, KC_ENT), LT(_NAV, KC_ESC),                     /**/ LT(_NAV, KC_TAB), LT(_SYMBOLS, KC_SPC), LT(_IDE_RIGHT, KC_BSPC)),

  [_POLISH] = LAYOUT_split_4x6_3( \
    /*       pinky    ring     middle   index                                                        index    middle   ring     pinky */
    GD_RST,  _______, _______, _______, _______, _______,                              /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                              /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                              /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                              /**/ _______, _______, _______, _______, _______, _______, \
    \
    _______, MT(MOD_RALT, KC_ENT), _______,                                           /**/ _______, MT(MOD_RALT, KC_SPC), _______),

  [_FAST_SPC] = LAYOUT_split_4x6_3( \
    /*       pinky    ring     middle   index                                                        index    middle   ring     pinky */
    GD_RST,  _______, _______, _______, _______, _______,                              /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                              /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                              /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                              /**/ _______, _______, _______, _______, _______, _______, \
    \
    _______, LT(_SYMBOLS, KC_ENT), _______,                                            /**/ _______, KC_SPC, _______),

  [_NAV] = LAYOUT_split_4x6_3( \
    /*            pinky         ring          middle        index                                        index        middle     ring         pinky */
    GD_RST,       GD_APP_CLOSE, GD_WIN_NEXT,  GD_REPLACE,   GD_B_ZOOMI, GD_B_ZOOMO,    /**/ GD_GO_SD,    GD_I_COLM,   GD_UNDO,   GD_I_SE_DUP, GD_REDO,       GD_SE_ALL, \
    GD_WIN_LFT,   GD_WIN_FULL,  GD_APP_NEXT,  GD_FPREV,     GD_B_PTAB,  GD_B_CTAB,     /**/ GD_GO_SL,    GD_GO_LW,    KC_PGUP,   GD_I_EX_SEL, GD_COPY,       _______, \
    GD_WIN_CEN,   GD_RUNAPP,    GD_ALT_TAB,   GD_FNEXT,     GD_B_NTAB,  GD_B_URL,      /**/ KC_LEFT,     KC_DOWN,     KC_UP,     KC_RIGHT,    GD_TGE_SHT,    GD_CUT, \
    GD_WIN_RGT,   GD_APP_SAVE,  GD_WIN_HIDE,  GD_FIND,      GD_B_NEWT,  GD_B_RLOAD,    /**/ GD_GO_ED,    KC_PGDN,     GD_GO_RW,  GD_GO_EL,    GD_PASTE ,     GD_PA_REC, \
    \
    _______, _______, _______,                                                         /**/ _______, _______, _______),

  [_SYMBOLS] = LAYOUT_split_4x6_3( \
    /*            pinky     ring      middle    index                                                  index      middle    ring       pinky */
    GD_RST,       KC_NO,    KC_CIRC,  GD_ARROW, GD_FARROW, KC_NO,                      /**/ KC_QUOT,   KC_LABK,   KC_RABK,  KC_PERC,   KC_QUES,   KC_TILD, \
    KC_NO,        KC_GRV,   KC_7,     KC_8,     KC_9,      KC_BSLASH,                  /**/ KC_DQUO,   KC_LCBR,   KC_RCBR,  KC_MINS,   KC_PLUS,   KC_DLR, \
    GD_HDIR,      GD_EQSP,  KC_4,     KC_5,     KC_6,      KC_0,                       /**/ KC_EXLM,   KC_LPRN,   KC_RPRN,  KC_UNDS,   KC_ASTR,   KC_AT, \
    KC_NO,        KC_PERC,  KC_1,     KC_2,     KC_3,      KC_COLN,                    /**/ KC_PIPE,   KC_LBRC,   KC_RBRC,  KC_PEQL,   KC_AMPR,   KC_HASH, \
    \
    GD_DEL_2LNE, GD_I_NEW_LINE, KC_APP,                                                /**/ GD_I_FIXES, GD_I_COMPLETE, GD_DEL_LWORD),

  [_IDE_LEFT] = LAYOUT_split_4x6_3( \
    /*            pinky       ring       middle     index                                                 index           middle         ring           pinky */
    RESET,        KC_F1,      KC_F2,     KC_F3,     KC_F4,       KC_F5,                /**/ KC_F6,         KC_F7,          KC_F8,         KC_F9,         KC_NO,         GD_INFO, \
    KC_MUTE,      KC_VOLD,    KC_VOLU,   KC_MPLY,   KC_MNXT,     KC_MPRV,              /**/ GD_I_REL_FILE, GD_I_QDOC,      GD_I_USAGES,   KC_NO,         GD_I_REFACTOR, KC_F10, \
    GD_SCR_CSEL,  KC_MYCM,    KC_WSCH,   KC_WBAK,   GD_B_REOPEN, GD_B_BOOKM,           /**/ GD_I_REL_SYM,  GD_I_GO_DEF,    GD_I_NEXT_FN,  GD_I_REFORMAT, GD_I_RENAME,   KC_F11, \
    GD_SCR_CFULL, KC_CALC,    KC_MAIL,   KC_WHOM,   GD_B_DTOOLS, KC_WFAV,              /**/ GD_I_GO_FWD,   GD_I_GO_BACK,   GD_I_PREV_FN,  GD_I_TGL_CASE, GD_I_COMMENT,  KC_F12, \
    \
    _______, _______, _______,                                                         /**/ _______, _______, _______),

  [_IDE_RIGHT] = LAYOUT_split_4x6_3( \
    /*          pinky          ring        middle        index                                           index         middle       ring          pinky */
    RESET,      KC_F1,         KC_F2,      KC_F3,        KC_F4,         KC_F5,         /**/ KC_F6,       KC_F7,        KC_F8,       KC_F9,        GD_M_MAC,    GD_INFO, \
    GD_I_GOTOL, GD_I_WIN_GITH, GD_I_FACT,  GD_I_RINF,    GD_I_REC_FILE, GD_I_GO_L_ED,  /**/ GD_TGL_FSPC, GD_TGL_VIM,   GD_TGL_POL,  KC_NO,        GD_M_LINUX,  KC_F10, \
    GD_I_BUILD, GD_I_WIN_GITC, GD_I_RUNA,  GD_I_WIN_SEA, GD_I_REC_LOC,  GD_I_WIN_RUN,  /**/ KC_NO,       KC_NO,        KC_NO,       KC_NO,        KC_NO,       KC_F11, \
    KC_NO,      GD_I_WIN_STRU, GD_I_RUNL,  GD_I_FINF,    GD_I_GO_FILE,  GD_I_RUNS,     /**/ KC_NO,       KC_NO,        KC_NO,       KC_NO,        KC_NO,       KC_F12, \
    \
    GD_DEL_LINE, _______, _______,                                                     /**/ _______, _______, _______),
};
