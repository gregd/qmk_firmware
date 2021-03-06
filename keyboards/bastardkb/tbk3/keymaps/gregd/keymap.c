#include QMK_KEYBOARD_H

#include <print.h>
#include "tbk3.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_4x6_3( \
    /*                 pinky  ring   middle index                                                          index         middle       ring     pinky */
    GD_RST,            KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                               /**/ KC_6,          KC_7,         KC_8,        KC_9,    KC_0,     GD_CAPS, \
    OSM(MOD_LALT),     KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                               /**/ KC_Y,          KC_U,         KC_I,        KC_O,    KC_P,     GD_TGL_NAV, \
    OSM(MOD_LCTL),     KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                               /**/ KC_H,          KC_J,         KC_K,        KC_L,    KC_SCLN,  OSM(MOD_RCTL), \
    KC_LGUI,           KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                               /**/ KC_N,          KC_M,         KC_COMM,     KC_DOT,  KC_SLSH,  OSM(MOD_RSFT), \
    \
    LT(_IDE_LEFT, KC_DEL), LT(_SYMBOLS, KC_ENT), LT(_NAV, KC_ESC),                     /**/ LT(_NAV, KC_TAB), LT(_SYMBOLS, KC_SPC), LT(_IDE_RIGHT, KC_BSPC)),

  [_POLISH] = LAYOUT_split_4x6_3( \
    /*       pinky    ring     middle   index                                                        index    middle   ring     pinky */
    GD_RST,  _______, _______, _______, _______, _______,                              /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                              /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                              /**/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                              /**/ _______, _______, _______, _______, _______, _______, \
    \
    LT(_SYMBOLS, KC_DEL), MT(MOD_RALT, KC_ENT), _______,                               /**/ _______, MT(MOD_RALT, KC_SPC), LT(_SYMBOLS, KC_BSPC)),

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
    GD_RST,       GD_WIN_NEXT,  GD_APP_CLOSE, GD_REPLACE,   GD_B_ZOOMI, GD_B_ZOOMO,    /**/ GD_GO_SD,    GD_I_COLM,   GD_UNDO,   GD_I_SE_DUP, GD_REDO,       GD_SE_ALL, \
    GD_WIN_LFT,   GD_WIN_FULL,  GD_WIN_HIDE,  GD_FIND,      GD_B_NEWT,  GD_B_CTAB,     /**/ GD_GO_SL,    GD_GO_LW,    KC_PGUP,   GD_I_EX_SEL, GD_TGE_SHT,    _______, \
    GD_WIN_CEN,   GD_RUNAPP,    GD_ALT_TAB,   GD_FNEXT,     GD_B_NTAB,  GD_B_URL,      /**/ KC_LEFT,     KC_DOWN,     KC_UP,     KC_RIGHT,    GD_COPY,       GD_CUT, \
    GD_WIN_RGT,   GD_APP_SAVE,  GD_APP_NEXT,  GD_FPREV,     GD_B_PTAB,  GD_B_RLOAD,    /**/ GD_GO_ED,    KC_PGDN,     GD_GO_RW,  GD_GO_EL,    GD_PASTE ,     GD_PA_REC, \
    \
    _______, _______, _______,                                                         /**/ _______, _______, _______),

  [_SYMBOLS] = LAYOUT_split_4x6_3( \
    /*            pinky     ring      middle    index                                                  index      middle    ring       pinky */
    GD_RST,       KC_NO,    KC_CIRC,  GD_ARROW, GD_FARROW, KC_NO,                      /**/ KC_GRV,    KC_LABK,   KC_RABK,  KC_PERC,   KC_QUES,   KC_TILD, \
    KC_GRV,       KC_BSLASH,KC_7,     KC_8,     KC_9,      KC_PIPE,                    /**/ KC_QUOT,   KC_LCBR,   KC_RCBR,  KC_MINS,   KC_PLUS,   KC_DLR, \
    GD_HDIR,      GD_EQSP,  KC_4,     KC_5,     KC_6,      KC_0,                       /**/ KC_DQUO,   KC_LPRN,   KC_RPRN,  KC_UNDS,   KC_PEQL,   KC_AT, \
    KC_NO,        KC_PERC,  KC_1,     KC_2,     KC_3,      KC_COLN,                    /**/ KC_EXLM,   KC_LBRC,   KC_RBRC,  KC_ASTR,   KC_AMPR,   KC_HASH, \
    \
    GD_DEL_2LNE, GD_I_NEW_LINE, KC_APP,                                                /**/ GD_I_FIXES, GD_I_COMPLETE, GD_DEL_LWORD),

  [_IDE_LEFT] = LAYOUT_split_4x6_3( \
    /*            pinky       ring      middle       index                                                  index           middle         ring           pinky */
    RESET,        KC_F1,      KC_F2,    KC_F3,       KC_F4,       KC_F5,                /**/ KC_F6,         KC_F7,          KC_F8,         KC_F9,         KC_NO,         GD_INFO, \
    KC_MUTE,      KC_VOLD,    KC_VOLU,  KC_MPLY,     KC_MNXT,     KC_MPRV,              /**/ GD_I_REL_FILE, GD_I_QDOC,      GD_I_USAGES,   GD_I_RENAME,   KC_NO,         KC_F10, \
    GD_SCR_CSEL,  KC_CALC,    KC_MYCM,  KC_WSCH,     GD_COPY,     GD_B_DTOOLS,          /**/ GD_I_REL_SYM,  GD_I_GO_DEF,    GD_I_NEXT_FN,  GD_I_REFORMAT, GD_I_REFACTOR, KC_F11, \
    GD_SCR_CFULL, KC_NO,      KC_MAIL,  GD_B_REOPEN, GD_PASTE,    KC_NO,                /**/ GD_I_GO_FWD,   GD_I_GO_BACK,   GD_I_PREV_FN,  GD_I_COMMENT,  GD_I_TGL_CASE, KC_F12, \
    \
    _______, _______, _______,                                                         /**/ _______, _______, _______),

  [_IDE_RIGHT] = LAYOUT_split_4x6_3( \
    /*            pinky         ring        middle        index                                          index         middle       ring          pinky */
    RESET,        KC_F1,        KC_F2,      KC_F3,        KC_F4,         KC_F5,        /**/ KC_F6,       KC_F7,        KC_F8,       KC_F9,        GD_M_MAC,    GD_INFO, \
    GD_I_WIN_STRU,GD_I_WIN_GITH,GD_I_FACT,  GD_I_RINF,    GD_I_REC_FILE, GD_I_REC_LOC, /**/ GD_TGL_FSPC, GD_TGL_VIM,   GD_TGL_POL,  GD_T_NORM,    GD_M_LINUX,  KC_F10, \
    GD_I_BUILD,   GD_I_WIN_GITC,GD_I_GOTOL, GD_I_FINF,    GD_I_GO_L_ED,  GD_I_WIN_RUN, /**/ KC_INS,      GD_FDOWN,     GD_FUP,      GD_T_NEXT,    GD_T_EDIT,   KC_F11, \
    KC_NO,        GD_I_RUNA,    GD_I_RUNL,  GD_I_WIN_SEA, GD_I_GO_FILE,  GD_I_RUNS,    /**/ KC_WHOM,     KC_WBAK,      GD_B_CTAB,   GD_T_PREV,    GD_T_CREATE, KC_F12, \
    \
    GD_DEL_LINE, _______, _______,                                                     /**/ _______, _______, _______),
};
