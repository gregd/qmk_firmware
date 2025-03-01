#include QMK_KEYBOARD_H

#include <print.h>
#include "tbk3.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_4x6_3( \
    /*                 pinky  ring   middle index                                                          index         middle       ring     pinky */
    GD_RST,            KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                               /**/ KC_6,          KC_7,         KC_8,        KC_9,    KC_0,     GD_TGL_POL, \
    GD_CAPS,           KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                               /**/ KC_Y,          KC_U,         KC_I,        KC_O,    KC_P,     OSM(MOD_LSFT), \
    OSM(MOD_LCTL),     KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                               /**/ KC_H,          KC_J,         KC_K,        KC_L,    KC_SCLN,  OSM(MOD_RCTL), \
    KC_LGUI,           KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                               /**/ KC_N,          KC_M,         KC_COMM,     KC_DOT,  KC_SLSH,  KC_RGUI, \
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

  [_NAV] = LAYOUT_split_4x6_3( \
    /*            pinky         ring          middle        index                                        index        middle     ring         pinky */
    GD_RST,       GD_APP_CLOSE, GD_WIN_HIDE,  GD_REPLACE,   GD_B_ZOOMI, GD_B_ZOOMO,    /**/ GD_GO_SD,    GD_UNDO,     GD_SE_ALL, GD_DEL_2LNE, GD_PA_REC,     GD_B_DTOOLS, \
    GD_WIN_LFT,   GD_WIN_FULL,  GD_WIN_NEXT,  GD_FIND,      GD_B_NEWT,  GD_B_CTAB,     /**/ GD_GO_SL,    GD_GO_LW,    KC_PGUP,   GD_SE_WORD,  GD_CUT,        GD_TGE_SHT, \
    GD_WIN_CEN,   GD_RUNAPP,    GD_ALT_TAB,   GD_FNEXT,     GD_B_URL,   KC_APP,        /**/ KC_LEFT,     KC_DOWN,     KC_UP,     KC_RIGHT,    GD_COPY,       GD_XCOPY, \
    GD_WIN_RGT,   GD_APP_SAVE,  GD_APP_NEXT,  GD_B_PTAB,    GD_B_NTAB,  GD_B_REOPEN,   /**/ GD_GO_ED,    KC_PGDN,     GD_GO_RW,  GD_GO_EL,    GD_PASTE,      GD_XPASTE, \
    \
    _______, _______, _______,                                                         /**/ _______, _______, _______),

  [_SYMBOLS] = LAYOUT_split_4x6_3( \
    /*            pinky     ring      middle    index                                                  index      middle    ring       pinky */
    GD_RST,       KC_NO,    KC_CIRC,  GD_ARROW, GD_FARROW, GD_SA_CA,                   /**/ KC_GRV,    KC_LABK,   KC_RABK,  GD_ELVIS,  KC_NO,     _______, \
    GD_HDIR,      KC_BSLASH,KC_1,     KC_2,     KC_3,      KC_PIPE,                    /**/ KC_QUOT,   KC_LCBR,   KC_RCBR,  KC_MINS,   KC_PLUS,   KC_DLR, \
    GD_EQSP,      KC_GRV,   KC_4,     KC_5,     KC_6,      KC_0,                       /**/ KC_DQUO,   KC_LPRN,   KC_RPRN,  KC_UNDS,   KC_PEQL,   KC_AT, \
    KC_TILD,      KC_PERC,  KC_7,     KC_8,     KC_9,      KC_COLN,                    /**/ KC_EXLM,   KC_LBRC,   KC_RBRC,  KC_ASTR,   KC_AMPR,   KC_HASH, \
    \
    KC_NO, KC_NO, KC_NO,                                                               /**/ GD_I_FIXES, GD_I_COMPLETE, GD_DEL_LWORD),

  [_IDE_LEFT] = LAYOUT_split_4x6_3( \
    /*         pinky         ring        middle       index                                                index           middle         ring           pinky */
    RESET,     KC_NO,        KC_NO,      KC_NO,       KC_NO,       KC_NO,              /**/ KC_F6,         KC_F7,          KC_F8,         KC_F9,         KC_F10,        GD_INFO, \
    KC_NO,     KC_NO,        KC_F1,      KC_F2,       KC_F3,       KC_NO,              /**/ GD_I_REL_FILE, GD_I_QDOC,      GD_I_USAGES,   GD_I_RENAME,   GD_I_REFACTOR, KC_F11, \
    KC_NO,     GD_SCR_CSEL,  KC_F4 ,     KC_F5,       KC_CALC,     KC_NO,              /**/ GD_I_REL_SYM,  GD_I_GO_DEF,    GD_I_NEXT_FN,  GD_I_REFORMAT, GD_I_RINF,     KC_F12, \
    KC_NO,     GD_SCR_CFULL, KC_MAIL,    KC_WSCH,     KC_MYCM,     KC_NO,              /**/ GD_I_GO_FWD,   GD_I_GO_BACK,   GD_I_PREV_FN,  GD_I_COMMENT,  GD_I_TGL_CASE, KC_NO, \
    \
    _______, _______, _______,                                                         /**/ _______, _______, _______),

  [_IDE_RIGHT] = LAYOUT_split_4x6_3( \
    /*            pinky       ring           middle        index                                         index         middle       ring          pinky */
    RESET,        KC_F1,      KC_F2,         KC_F3,        KC_F4,         KC_F5,       /**/ KC_NO,       KC_MUTE,      KC_NO,       KC_NO,        GD_M_MAC,    GD_INFO, \
    KC_NO,        GD_I_FACT,  GD_I_WIN_GITH, GD_I_FINF,    GD_I_REC_LOC,  GD_I_GO_L_ED,/**/ KC_NO,       KC_MPLY,      KC_MNXT,     KC_MPRV,      GD_M_LINUX,  KC_NO, \
    GD_I_WIN_STRU,GD_I_BUILD, GD_I_WIN_GITC, GD_I_GOTOL,   GD_I_REC_FILE, GD_I_WIN_RUN,/**/ KC_NO,       GD_WIN_D1,    GD_WIN_D2,   KC_WBAK,      KC_INS,      KC_NO, \
    KC_NO,        GD_I_RUNA,  GD_I_RUNL,     GD_I_WIN_SEA, GD_I_GO_FILE,  GD_I_RUNS,   /**/ KC_NO,       GD_WIN_D3,    GD_WIN_D4,   KC_WFWD,      KC_NO,       KC_NO, \
    \
    _______, _______, _______,                                                         /**/ _______, _______, _______),
};
