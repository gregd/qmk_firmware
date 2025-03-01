/*  A library to output the right key shortcut in any common app.
Given a global variable gdk_mode to show the environment and a
key that calls the paste macro, do the right type of paste.

Setting the bable_mode is done by another macro, or TBD interaction with the host.

Huge thanks to https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
and jeebak & algernon's keymap
*/

#pragma once
#include "quantum.h"

void gdk_set_mode(uint8_t id, bool update_eeprom);
uint8_t gdk_get_mode(void);
void gdk_led_user(void);
void gdk_clear_mods(void);
bool gdk_was_mac(void);

// manually re-order these if you want to set the order or default.
enum gdk_modes {
#    ifdef GD_LINUX
    GD_LINUX_MODE,
#    endif
#    ifdef GD_MAC
    GD_MAC_MODE,
#    endif
#    ifdef GD_WINDOWS
    GD_WINDOWS_MODE,
#    endif
    GD_MODEMAX
};

// void gdk_led_user( uint8_t id)

/// Hacks to make it easier to create sendstring macros

//"outer" versions wrap text
#    define OMCTL(arg) SS_DOWN(X_LCTRL) arg SS_UP(X_LCTRL)
#    define OMGUI(arg) SS_DOWN(X_LGUI) arg SS_UP(X_LGUI)
#    define OMALT(arg) SS_DOWN(X_LALT) arg SS_UP(X_LALT)
#    define OMSFT(...) SS_DOWN(X_LSHIFT) __VA_ARGS__ SS_UP(X_LSHIFT)
//"inner" versions wrap a key tap
#    define IMCTL(arg) SS_DOWN(X_LCTRL) SS_TAP(arg) SS_UP(X_LCTRL)
#    define IMGUI(arg) SS_DOWN(X_LGUI) SS_TAP(arg) SS_UP(X_LGUI)
#    define IMALT(arg) SS_DOWN(X_LALT) SS_TAP(arg) SS_UP(X_LALT)
#    define IMSFT(arg) SS_DOWN(X_LSHIFT) SS_TAP(arg) SS_UP(X_LSHIFT)

#    define GDM(ent, ...)             \
        if (ent == keycode) {         \
            SEND_STRING(__VA_ARGS__); \
            return true;              \
        }

#    define GDM_CLR_OSM(ent, ...)     \
        if (ent == keycode) {         \
            gdk_clear_mods();      \
            SEND_STRING(__VA_ARGS__); \
            return true;              \
        }

// gdkMacro should be loaded first (header in userspace .h file, before all else)
// if not,we'll do our best.
#    if defined(NEW_SAFE_RANGE)
#        define GDK_START NEW_SAFE_RANGE
#    else
#        if defined(KEYMAP_SAFE_RANGE)
#            define GDK_START KEYMAP_SAFE_RANGE
#        else
#            define GDK_START SAFE_RANGE
#        endif
#    endif

enum gdk_keycodes {
    FIRST = GDK_START,
#    ifdef GD_MOVE
    // Movement macros
    // left & right
    GD_GO_LEFT_1C,
    GD_GO_RIGHT_1C,
    GD_GO_LW,
    GD_GO_RW,
    GD_GO_SL,
    GD_GO_EL,
    // now up & down
    GD_GO_SD,
    GD_GO_ED,
    GD_GO_NLINE,
    GD_GO_PLINE,
    GD_GO_PARA_START,
    GD_GO_PARA_END,
    GD_PGDN,
    GD_PGUP,
    // And the delete options
    GD_DEL_LEFT_1C,   // == backspace, so why bother?
    GD_DEL_RIGHT_1C,  // usually = Del
    GD_DEL_LWORD,
    GD_DEL_RWORD,
    GD_DEL_2LNE,    // delete from cursor to end of line
    GD_DEL_2LNS,  // delete from cursor to begining line
    GD_DEL_LINE,           // delete whole line
    GD_MODE,               // print out string saying what mode we're in.
#    endif
#    ifdef GD_OSKEYS
    GD_UNDO,
    GD_REDO,
    GD_CUT,
    GD_COPY,
    GD_PASTE,
    GD_PA_REC,
    GD_SE_ALL,
    /* not yet implemented
    GD_SWAP_LAST2C, // swap last characters before the cursor
    GD_SWAP_LAST2W, // Swap the last two words before the cursor
    */
    // find & replace
    GD_FIND,
    GD_FNEXT,
    GD_FPREV,
    GD_REPLACE,
    // GUI or app
    GD_RUNAPP,
    GD_APP_NEXT,
    GD_APP_LAST,  // previous
    GD_APP_SAVE,
    GD_WIN_NEXT,
    GD_WIN_PREV,
    GD_WIN_NEW,
    GD_WIN_HIDE,
    GD_WIN_FULL,
    GD_WIN_CEN,
    GD_WIN_LFT,
    GD_WIN_RGT,
    GD_WIN_D1,
    GD_WIN_D2,
    GD_WIN_D3,
    GD_WIN_D4,
    GD_APP_CLOSE,
    GD_HELP,
    GD_LOCK,
    GD_SCR_CFULL,
    GD_SCR_CSEL,
    GD_SWITCH_KEYBOARD_LAYOUT,
#    endif
#    ifdef GD_BROWSER
    GD_B_NEWT,
    GD_B_CTAB,
    GD_B_REOPEN,
    GD_B_NTAB,
    GD_B_PTAB,
    GD_B_URL,
    GD_B_FORWARD,
    GD_B_BACK,
    GD_B_FIND,
    GD_B_BOOKM,
    GD_B_DTOOLS,  // hard one to remember
    GD_B_RLOAD,
    GD_B_FULLS,
    GD_B_ZOOMI,
    GD_B_ZOOMO,
#    endif
#    ifdef GD_IDE
    GD_I_WIN_FTREE,
    GD_I_WIN_SEA,
    GD_I_WIN_RUN,
    GD_I_WIN_STRU,
    GD_I_WIN_GITH,
    GD_I_WIN_GITC,
    GD_I_REC_FILE,
    GD_I_REC_LOC,
    GD_I_SE_EV,
    GD_I_FINF,
    GD_I_RINF,
    GD_I_FACT,
    GD_I_REL_FILE,
    GD_I_REL_SYM,
    GD_I_EX_SEL,
    GD_I_COMPLETE,
    GD_I_FIXES,
    GD_I_QDOC,
    GD_I_GO_L_ED,
    GD_I_GO_DEF,
    GD_I_GO_BACK,
    GD_I_GO_FWD,
    GD_I_GOTOL,
    GD_I_GO_FILE,
    GD_I_NEXT_FN,
    GD_I_PREV_FN,
    GD_I_USAGES,
    GD_I_RENAME,
    GD_I_REFACTOR,
    GD_I_COMMENT,
    GD_I_REFORMAT,
    GD_I_COLM,
    GD_I_SE_DUP,
    GD_I_TGL_CASE,
    GD_I_BUILD,
    GD_I_RUNL,
    GD_I_RUNS,
    GD_I_RUNA,
#    endif

// Macros for mode switching
#    ifdef GD_WINDOWS
    GD_DO_WINDOWS,
#    endif
#    ifdef GD_MAC
    GD_DO_MAC,
#    endif
#    ifdef GD_LINUX
    GD_DO_LINUX,
#    endif
    GDK_END_RANGE
};

// primary function.
bool gdkMacro(uint16_t keycode);

/****************************************************/
/* All per-os includes and short mode switch macros*/
#    ifdef GD_WINDOWS
bool gdkMacro_win(uint16_t keycode);
#    endif
#    ifdef GD_MAC
bool gdkMacro_mac(uint16_t keycode);
#    endif
#    ifdef GD_LINUX
bool gdkMacro_linux(uint16_t keycode);
#    endif
