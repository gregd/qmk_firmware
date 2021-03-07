#pragma once
#include "quantum.h"
#include "version.h"
#include "eeprom.h"
#include "gdkMacro.h"

#define LAYOUT_split_4x6_3( \
	k00, k01, k02, k03, k04, k05,			k55, k54, k53, k52, k51, k50, \
	k10, k11, k12, k13, k14, k15,			k65, k64, k63, k62, k61, k60, \
	k20, k21, k22, k23, k24, k25,			k75, k74, k73, k72, k71, k70, \
	k30, k31, k32, k33, k34, k35,			k85, k84, k83, k82, k81, k80, \
		       k43, k44, k41,		        k91, k94, k93 \
)\
{\
	{ k00, k01, k02, k03, k04, k05 }, \
	{ k10, k11, k12, k13, k14, k15 }, \
	{ k20, k21, k22, k23, k24, k25 }, \
	{ k30, k31, k32, k33, k34, k35 }, \
	{ KC_NO, k41, KC_NO, k43, k44, KC_NO }, \
	{ k50, k51, k52, k53, k54, k55 }, \
	{ k60, k61, k62, k63, k64, k65 }, \
	{ k70, k71, k72, k73, k74, k75 }, \
	{ k80, k81, k82, k83, k84, k85 }, \
	{ KC_NO, k91, KC_NO, k93, k94, KC_NO }, \
}

/* Define layer names */
enum userspace_layers {
    _QWERTY=0,
    _POLISH,
    _FAST_SPC,
    _NAV,
    _SYMBOLS,
    _IDE_LEFT,
    _IDE_RIGHT
};

/*
define modifiers here, since MOD_* doesn't seem to work for these
 */
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI_MASK  (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))

enum userspace_custom_keycodes {
    GD_RST = GDK_END_RANGE,
    GD_M_MAC,
    GD_M_LINUX,
    GD_TGL_POL,
    GD_TGL_FSPC,
    GD_TGL_VIM,
    GD_TGL_NAV,
    GD_TGE_SHT,
    GD_ALT_TAB,
    GD_CAPS,
    GD_ARROW,
    GD_FARROW,
    GD_EQSP,
    GD_HDIR,
    GD_DCOLN,
    GD_TMUX,
    GD_XCOPY,
    GD_XPASTE,
    GD_FUP,
    GD_FDOWN,
    GD_INFO
};

typedef union {
    uint32_t raw;
    struct {
        bool mac_mode:1;
    };
} user_config_t;
extern user_config_t user_config;
