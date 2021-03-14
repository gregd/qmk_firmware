/*  A library to output the right key shortcut in any common app.
Given a global variable babble_mode to show the environment and a
key that calls the paste macro, do the right type of paste.

Setting the bable_mode is done by another macro, or TBD interaction with the host.

Huge thanks to https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
and jeebak & algernon's keymap
*/

#pragma once
#include "quantum.h"

void set_babble_mode(uint8_t id);
// void babble_mode_increment(void);
// void babble_mode_decrement(void);
void babble_led_user(void);

// manually re-order these if you want to set the order or default.
enum babble_modes {
#    ifdef BABL_LINUX
    BABL_LINUX_MODE,
#    endif
#    ifdef BABL_MAC
    BABL_MAC_MODE,
#    endif
#    ifdef BABL_READMUX
    BABL_READMUX_MODE,
#    endif
#    ifdef BABL_WINDOWS
    BABL_WINDOWS_MODE,
#    endif
#    ifdef BABL_VI
    BABL_VI_MODE,
#    endif
#    ifdef BABL_EMACS
    BABL_EMACS_MODE,
#    endif
#    ifdef BABL_CHROMEOS
    BABL_CHROMEOS_MODE,
#    endif
    BABL_MODEMAX
};

// void babble_led_user( uint8_t id)

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

#    define BABLM(ent, ...)           \
        if (ent == keycode) {         \
            SEND_STRING(__VA_ARGS__); \
            return true;              \
        }

#    define BABLM_CLR_OSM(ent, ...)   \
        if (ent == keycode) {         \
            uint8_t mods = 0;         \
            if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out()) { \
                clear_oneshot_mods();                                           \
                unregister_mods(mods);                                          \
            }                                                                   \
            if ((mods = get_oneshot_locked_mods())) {                           \
                clear_oneshot_locked_mods();                                    \
                unregister_mods(mods);                                          \
            }                         \
            SEND_STRING(__VA_ARGS__); \
            return true;              \
        }


// BabblePaste should be loaded first (header in userspace .h file, before all else)
// if not,we'll do our best.
#    if defined(NEW_SAFE_RANGE)
#        define BABBLE_START NEW_SAFE_RANGE
#    else
#        if defined(KEYMAP_SAFE_RANGE)
#            define BABBLE_START KEYMAP_SAFE_RANGE
#        else
#            define BABBLE_START SAFE_RANGE
#        endif
#    endif

enum babble_keycodes {
    FIRST = BABBLE_START,
#    ifdef BABL_MOVE
    // Movement macros
    // left & right
    BABL_GO_LEFT_1C,
    BABL_GO_RIGHT_1C,
    BABL_GO_LEFT_WORD,
    BABL_GO_RIGHT_WORD,
    BABL_GO_START_LINE,
    BABL_GO_END_LINE,
    // now up & down
    BABL_GO_START_DOC,
    BABL_GO_END_DOC,
    BABL_GO_NEXT_LINE,
    BABL_GO_PREV_LINE,
    BABL_GO_PARA_START,
    BABL_GO_PARA_END,
    BABL_PGDN,
    BABL_PGUP,
    // And the delete options
    BABL_DEL_LEFT_1C,   // == backspace, so why bother?
    BABL_DEL_RIGHT_1C,  // usually = Del
    BABL_DEL_LEFT_WORD,
    BABL_DEL_RIGHT_WORD,
    BABL_DEL_TO_LINE_END,    // delete from cursor to end of line
    BABL_DEL_TO_LINE_START,  // delete from cursor to begining line
    BABL_DEL_LINE,           // delete whole line
    BABL_MODE,               // print out string saying what mode we're in.
#    endif
#    ifdef BABL_OSKEYS
    BABL_UNDO,
    BABL_REDO,
    BABL_CUT,
    BABL_COPY,
    BABL_PASTE,
    BABL_PASTE_RECENT,
    BABL_SELECT_ALL,
    /* not yet implemented
    BABL_SWAP_LAST2C, // swap last characters before the cursor
    BABL_SWAP_LAST2W, // Swap the last two words before the cursor
    */
    // find & replace
    BABL_FIND,
    BABL_FIND_NEXT,
    BABL_FIND_PREV,
    BABL_FIND_REPLACE,
    // GUI or app
    BABL_RUNAPP,
    BABL_SWITCH_APP_NEXT,
    BABL_SWITCH_APP_LAST,  // previous
    BABL_WINDOW_NEXT,
    BABL_WINDOW_PREV,
    BABL_WINDOW_NEW,
    BABL_CLOSE_APP,
    BABL_HELP,
    BABL_LOCK,
    BABL_SCREENCAPTURE,
    BABL_SWITCH_KEYBOARD_LAYOUT,
#    endif
#    ifdef BABL_BROWSER
    BABL_BROWSER_NEW_TAB,
    BABL_BROWSER_CLOSE_TAB,
    BABL_BROWSER_REOPEN_LAST_TAB,
    BABL_BROWSER_NEXT_TAB,
    BABL_BROWSER_PREV_TAB,
    BABL_BROWSER_URL_BAR,
    BABL_BROWSER_FORWARD,
    BABL_BROWSER_BACK,
    BABL_BROWSER_FIND,
    BABL_BROWSER_BOOKMARK,
    BABL_BROWSER_DEV_TOOLS,  // hard one to remember
    BABL_BROWSER_RELOAD,
    BABL_BROWSER_FULLSCREEN,
    BABL_BROWSER_ZOOM_IN,
    BABL_BROWSER_ZOOM_OUT,
    BABL_BROWSER_VIEWSRC,
#    endif
#    ifdef BABL_APP
    BABL_APP_SAVE,                // save file blurs app & os. Move?
    BABL_APP_PASTE_VALUES,        // paste only values, or with some special formatting. ctrl shift v chrome, // Ctrl+Alt+V, excel
                                  // App hotkeys will be flawed, since you may use different spreadsheets across OSes.
#        ifdef BABL_APP_WINDOWSPLITTING
    // These aren't useful on most oses.
    BABL_SPLIT_FRAME_VERT,
    BABL_UNSPLIT_FRAME_VERT,
    BABL_SPLIT_FRAME_HORIZONTAL,
    BABL_UNSPLIT_FRAME_HORIZONTAL,
    BABL_NEXT_FRAME,
    BABL_PREV_FRAME,
#        endif

#    endif

#    ifdef BABL_IDE
    BABL_IDE_WIN_FTREE,
    BABL_IDE_WIN_SEARCH,
    BABL_IDE_WIN_RUN,
    BABL_IDE_WIN_STRUCT,
    BABL_IDE_WIN_GHIS,
    BABL_IDE_WIN_GCOM,
    BABL_IDE_RECENT_FILE,
    BABL_IDE_RECENT_LOC,
    BABL_IDE_FILE_FIND,
    BABL_IDE_REL_FILE,
    BABL_IDE_REL_SYM,
    BABL_IDE_EXTEND_SEL,
    BABL_IDE_COMPLETION,
    BABL_IDE_FIXES,
    BABL_IDE_QUICK_DOC,
    BABL_IDE_GO_LAST_ED,
    BABL_IDE_GO_DEF,
    BABL_IDE_GO_BACK,
    BABL_IDE_GO_FWD,
    BABL_IDE_GO_LINE,
    BABL_IDE_NEXT_FN,
    BABL_IDE_PREV_FN,
    BABL_IDE_USAGES,
    BABL_IDE_RENAME,
    BABL_IDE_REFACTOR,
    BABL_IDE_COMMENT,
    BABL_IDE_REFORMAT,
    BABL_IDE_COL_MODE,
    BABL_IDE_NEW_LINE,
    BABL_IDE_DUP_LINE,
    BABL_IDE_TOOGLE_CASE,
    BABL_IDE_BUILD,
    BABL_IDE_RUN_LAST,
    BABL_IDE_RUN_SELECT,
    BABL_IDE_RUN_ANY,

#    endif

// Macros for mode switching
#    ifdef BABL_WINDOWS
    BABL_DO_WINDOWS,
#    endif
#    ifdef BABL_MAC
    BABL_DO_MAC,
#    endif
#    ifdef BABL_LINUX
    BABL_DO_LINUX,
#    endif
#    ifdef BABL_EMACS
    BABL_DO_EMACS,
#    endif
#    ifdef BABL_VI
    BABL_DO_VI,
#    endif
#    ifdef BABL_READMUX
    BABL_DO_READMUX,
#    endif
#    ifdef BABL_CHROMEOS
    BABL_DO_CHROMEOS,
#    endif
    BABBLE_END_RANGE
};

// primary function.
bool babblePaste(uint16_t keycode);

/****************************************************/
/* All per-os includes and short mode switch macros*/
#    ifdef BABL_WINDOWS
#        define B_WIN BABL_DO_WINDOWS
bool babblePaste_win(uint16_t keycode);
#    endif
#    ifdef BABL_MAC
#        define B_MAC BABL_DO_MAC
bool babblePaste_mac(uint16_t keycode);
#    endif
#    ifdef BABL_LINUX
#        define B_LINUX BABL_DO_LINUX
bool babblePaste_linux(uint16_t keycode);
#    endif
#    ifdef BABL_EMACS
#        define B_EMACS BABL_DO_EMACS
bool babblePaste_emacs(uint16_t keycode);
#    endif
#    ifdef BABL_VI
#        define B_VI BABL_DO_VI
bool babblePaste_vi(uint16_t keycode);
#    endif
#    ifdef BABL_READMUX
#        define B_READ BABL_DO_READMUX
bool babblePaste_readmux(uint16_t keycode);
#    endif
#    ifdef BABL_CHROMEOS
#        define B_CROM BABL_DO_CHROMEOS
bool babblePaste_chromeos(uint16_t keycode);
#    endif

#    define BABL_INC babble_mode_increment();
#    define BABL_DEC babble_mode_decrement();

/****************************************************
**    All keyboard macros for Babble Actions
*****************************************************/

#    ifdef BABL_MOVE
#        define B_L1C BABL_GO_LEFT_1C
#        define B_R1C BABL_GO_RIGHT_1C
#        define B_L1W BABL_GO_LEFT_WORD
#        define B_R1W BABL_GO_RIGHT_WORD
#        define B_GSOL BABL_GO_START_LINE
#        define B_GEOL BABL_GO_END_LINE
#        define B_GTOP BABL_GO_START_DOC
#        define B_GEND BABL_GO_END_DOC
#        define B_DOWN BABL_GO_NEXT_LINE
#        define B_UP BABL_GO_PREV_LINE
#        define B_PTOP BABL_GO_PARA_START
#        define B_PEND BABL_GO_PARA_END
#        define B_PGDN BABL_PGDN
#        define B_PGUP BABL_PGUP
//#define B_BKSP  BABL_DEL_LEFT_1C == backspace so why bother.
#        define B_DEL BABL_DEL_RIGHT_1C  // usually = Del
#        define B_DLW BABL_DEL_LEFT_WORD
#        define B_DRW BABL_DEL_RIGHT_WORD
#        define B_DEOL BABL_DEL_TO_LINE_END    // delete from cursor to end of line
#        define B_DSOL BABL_DEL_TO_LINE_START  // delete from cursor to begining line
#        define B_MODE BABL_MODE               // type out name of current mode.
#    endif

#    ifdef BABL_OSKEYS
#        define B_UNDO BABL_UNDO
#        define B_REDO BABL_REDO
#        define B_CUT BABL_CUT
#        define B_COPY BABL_COPY
#        define B_PASTE BABL_PASTE
#        define B_SELALL BABL_SELECT_ALL
#        define B_SELA BABL_SELECT_ALL
#        define B_FIND BABL_FIND
#        define B_FINDN BABL_FIND_NEXT
#        define B_FINDP BABL_FIND_PREV
#        define B_RPLACE BABL_FIND_REPLACE
#        define B_RUNAPP BABL_RUNAPP
#        define B_NAPP BABL_SWITCH_APP_NEXT
#        define B_PAPP BABL_SWITCH_APP_LAST  // previous
#        define B_NWIN BABL_WINDOW_NEXT
#        define B_PWIN BABL_WINDOW_PREV
#        define B_WINN BABL_WINDOW_NEW
#        define B_CAPP BABL_CLOSE_APP
#        define B_HELP BABL_HELP
#        define B_LOCK BABL_LOCK
#        define B_SCAP BABL_SCREENCAPTURE
#        define B_KEYB BABL_SWITCH_KEYBOARD_LAYOUT
#    endif

#    ifdef BABL_BROWSER
#        define B_NTAB BABL_BROWSER_NEW_TAB
#        define B_CTAB BABL_BROWSER_CLOSE_TAB
#        define B_ROTB BABL_BROWSER_REOPEN_LAST_TAB
#        define B_NXTB BABL_BROWSER_NEXT_TAB
#        define B_PTAB BABL_BROWSER_PREV_TAB
#        define B_NURL BABL_BROWSER_URL_BAR
#        define B_BFWD BABL_BROWSER_FORWARD
#        define B_BBAK BABL_BROWSER_BACK
#        define B_BFND BABL_BROWSER_FIND
#        define B_BOOK BABL_BROWSER_BOOKMARK
#        define B_BDEV BABL_BROWSER_DEV_TOOLS  // hard one to remember
#        define B_BRLD BABL_BROWSER_RELOAD
#        define B_BFULL BABL_BROWSER_FULLSCREEN
#        define B_ZIN BABL_BROWSER_ZOOM_IN
#        define B_ZOUT BABL_BROWSER_ZOOM_OUT
#    endif

#    ifdef BABL_APP
#        define B_SAVE BABL_APP_SAVE
#        ifdef BABL_APP_WINDOWSPLITTING
#            define B_VSPLIT BABL_SPLIT_FRAME_VERT
#            define B_VUNSPT BABL_UNSPLIT_FRAME_VERT
#            define B_HSPLIT BABL_SPLIT_FRAME_HORIZONTAL
#            define B_HUNSPT BABL_UNSPLIT_FRAME_HORIZONTAL
#            define B_NXTFM BABL_NEXT_FRAME
#            define B_PRVFM BABL_PREV_FRAME
#        endif  // BABL_APP_WINDOWSPLITTING
#    endif      // BABL_APP
