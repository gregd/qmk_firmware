/*  A library to output the right key shortcut in any common app.
Given a global variable babble_mode to show the environment and a
key that calls the paste macro, do the right type of paste.
Setting the context is done by another macro, or TBD interaction with the host.

Huge thanks to https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
and
https://github.com/qmk/qmk_firmware/blob/master/keyboards/planck/keymaps/jeebak/keymap.c
*/

#include QMK_KEYBOARD_H

#ifdef USE_BABBLEPASTE
#    include "babblePaste.h"

#    ifdef BABL_LINUX

bool babblePaste_linux(uint16_t keycode) {
#        ifdef BABL_MOVE
    BABLM(BABL_GO_LEFT_1C, SS_TAP(X_LEFT));
    BABLM(BABL_GO_RIGHT_1C, SS_TAP(X_RIGHT));
    BABLM(BABL_GO_LWORD, IMCTL(X_LEFT));
    BABLM(BABL_GO_RWORD, IMCTL(X_RIGHT));
    BABLM(BABL_GO_SLINE, SS_TAP(X_HOME));
    BABLM(BABL_GO_ELINE, SS_TAP(X_END));
    BABLM(BABL_GO_SDOC, IMCTL(X_HOME));
    BABLM(BABL_GO_EDOC, IMCTL(X_END));
    BABLM(BABL_GO_NLINE, SS_TAP(X_DOWN));
    BABLM(BABL_GO_PLINE, SS_TAP(X_UP));
    BABLM(BABL_GO_PARA_START, IMCTL(X_UP));
    BABLM(BABL_GO_PARA_END, IMCTL(X_DOWN));
    BABLM(BABL_PGDN, SS_TAP(X_PGDOWN));
    BABLM(BABL_PGUP, SS_TAP(X_PGUP));
    BABLM(BABL_DEL_RIGHT_1C, SS_TAP(X_DELETE));
    BABLM(BABL_DEL_LWORD, IMCTL(X_BSPACE));
    BABLM(BABL_DEL_RWORD, IMCTL(X_DELETE));
    BABLM(BABL_DEL_2LNE, IMSFT(X_END) SS_TAP(X_DELETE));
    BABLM(BABL_DEL_2LNS, IMSFT(X_HOME) SS_TAP(X_DELETE));
    BABLM(BABL_DEL_LINE, IMCTL(X_Y));
    BABLM(BABL_MODE, "Linux ");
#        endif
#        ifdef BABL_OSKEYS
    BABLM(BABL_UNDO, SS_LCTL("z"));
    BABLM(BABL_REDO, SS_LCTL("y"));
    BABLM_CLR_OSM(BABL_CUT, SS_LCTL("x"));
    BABLM_CLR_OSM(BABL_COPY, SS_LCTL("c"));
    BABLM(BABL_PASTE, SS_LCTL("v"));
    BABLM(BABL_PASTE_RECENT, OMSFT(IMCTL(X_V)));
    BABLM(BABL_SELECT_ALL, SS_LCTL("a"));
    BABLM(BABL_FIND, SS_LCTL("f"));
    BABLM(BABL_CLOSE_APP, IMALT(X_F4));
    BABLM(BABL_HELP, SS_TAP(X_F1));
    // BABLM(BABL_FIND_NEXT  (SS_LALT(X_F3))	); //KDE */
    BABLM(BABL_FIND_NEXT, SS_LCTL("g"));       // Gnome*/
    BABLM(BABL_FIND_PREV, OMSFT(IMCTL(X_G)));  // Gnome*/
    /* BABLM( BABL_FREPLACE , (SS_LCTL("r"))	); // KDE */
    BABLM(BABL_FREPLACE, SS_LCTL("h"));  // Gnome*/
    BABLM(BABL_RUNAPP, IMALT(X_F2));         // Gnome
    BABLM(BABL_APP_NEXT, IMALT(X_TAB));
    BABLM(BABL_APP_LAST, OMSFT(IMALT(X_TAB)));
    BABLM(BABL_WINDOW_NEXT, OMCTL(IMALT(X_PGUP)));  // Gnome, sometimes
    BABLM(BABL_WINDOW_PREV, OMCTL(IMALT(X_PGDOWN)));
    BABLM(BABL_WINDOW_NEW, IMCTL(X_N));
    // BABLM( BABL_HELP,		(SS_TAP(X_F1))	); // NA?
    BABLM(BABL_LOCK, OMCTL(IMALT(X_L)));
    BABLM(BABL_SCR_CAP_FULL, SS_TAP(X_PSCREEN));
    BABLM(BABL_SCR_CAP_SEL, IMSFT(X_PSCREEN));
#        endif
#        ifdef BABL_BROWSER
    BABLM(BABL_BR_NEW_TAB, SS_LCTL("t"));
    BABLM(BABL_BR_CLOSE_TAB, IMCTL(X_F4));
    BABLM(BABL_BR_REOPEN_LAST_TAB, OMSFT(IMCTL(X_T)));
    BABLM(BABL_BR_NEXT_TAB, IMCTL(X_PGDOWN));
    BABLM(BABL_BR_PREV_TAB, IMCTL(X_PGUP));
    BABLM(BABL_BR_URL_BAR, SS_LCTL("l"));
    BABLM(BABL_BR_FORWARD, IMALT(X_RIGHT));
    BABLM(BABL_BR_BACK, IMALT(X_LEFT));
    BABLM(BABL_BR_FIND, SS_LCTL("f"));
    BABLM(BABL_BR_BOOKMARK, SS_LCTL("d"));
    BABLM(BABL_BR_DEV_TOOLS, SS_LCTL("t"));  // Chrome
    // chrome
    BABLM(BABL_BR_RELOAD, IMCTL(X_F5));             // hard reload w/o cache
    BABLM(BABL_BR_FULLSCREEN, SS_TAP(X_F11));       // command shift F
    BABLM(BABL_BR_ZOOM_IN, OMSFT(IMCTL(X_EQUAL)));  // ctr+ +
    BABLM(BABL_BR_ZOOM_OUT, IMCTL(X_MINUS));
    BABLM(BABL_BR_VIEWSRC, SS_LCTL("u"));  // Chrome or firefox
#        endif
#        ifdef BABL_APP
    BABLM(BABL_APP_SAVE, SS_LCTL("s"));
    // on linux we'd probably use tmux or screen. Some terminal software also
    // allows this.
    // BABLM( BABL_SPLIT_FRAME_VERT,		()  );
    // BABLM( BABL_UNSPLIT_FRAME_VERT,		()  );
    // BABLM( BABL_SPLIT_FRAME_HORIZONTAL, ()	);
    // BABLM( BABL_UNSPLIT_FRAME_HORIZONTAL, () );
    // BABLM( BABL_NEXT_FRAME, ()	);
    // BABLM( BABL_PREV_FRAME, ()	);
#        endif
#        ifdef BABL_IDE
    BABLM(BABL_IDE_WIN_FTREE, IMALT(X_1));
    BABLM(BABL_IDE_WIN_SEA, IMALT(X_3));
    BABLM(BABL_IDE_WIN_RUN, IMALT(X_4));
    BABLM(BABL_IDE_WIN_STR, IMALT(X_7));
    BABLM(BABL_IDE_WIN_GHIS, IMALT(X_9));
    BABLM(BABL_IDE_WIN_GCOM, IMALT(X_0));
    BABLM(BABL_IDE_REC_FILE, IMCTL(X_E));
    BABLM(BABL_IDE_REC_LOC, OMSFT(IMCTL(X_E)));
    BABLM(BABL_IDE_FIND_ALL, SS_LCTL("l"));
    BABLM(BABL_IDE_FINF, OMSFT(IMCTL(X_F)));
    BABLM(BABL_IDE_FACTION, OMSFT(IMCTL(X_A)));
    BABLM(BABL_IDE_REL_FILE, SS_LCTL("t"));             // RubyMine goto-view / controller
    BABLM(BABL_IDE_REL_SYM, OMALT(IMCTL(X_HOME)));
    BABLM(BABL_IDE_EX_SEL, SS_LCTL("w"));
    BABLM(BABL_IDE_COMPLETE, OMSFT(IMCTL(X_SPACE)));
    BABLM(BABL_IDE_FIXES, IMALT(X_ENTER));
    BABLM(BABL_IDE_QDOC, SS_LCTL("q"));
    BABLM(BABL_IDE_GO_LAST_ED, OMSFT(IMCTL(X_BSPACE)));
    BABLM(BABL_IDE_GO_DEF, SS_LCTL("b"));
    BABLM(BABL_IDE_GO_BACK, OMALT(IMCTL(X_LEFT)));
    BABLM(BABL_IDE_GO_FWD, OMALT(IMCTL(X_RIGHT)));
    BABLM(BABL_IDE_GO_LINE, OMSFT(OMALT(IMCTL(X_G))));
    BABLM(BABL_IDE_GO_FILE, OMSFT(IMCTL(X_N)));
    BABLM(BABL_IDE_NEXT_FN, IMALT(X_DOWN));
    BABLM(BABL_IDE_PREV_FN, IMALT(X_UP));
    BABLM(BABL_IDE_USAGES, IMALT(X_F7));
    BABLM(BABL_IDE_RENAME, IMSFT(X_F6));
    BABLM(BABL_IDE_REFACTOR, OMSFT(OMALT(IMCTL(X_T))));
    BABLM(BABL_IDE_COMMENT, IMCTL(X_SLASH));
    BABLM(BABL_IDE_REFORMAT, OMALT(IMCTL(X_L)));
    BABLM(BABL_IDE_COL_MODE, OMALT(IMSFT(X_INSERT)));
    BABLM(BABL_IDE_NEW_LINE, IMSFT(X_ENTER));
    BABLM(BABL_IDE_DUP_LINE, IMCTL(X_D));
    BABLM(BABL_IDE_TGL_CASE, OMSFT(IMCTL(X_U)));
    BABLM(BABL_IDE_BUILD, IMCTL(X_F9));
    BABLM(BABL_IDE_RUN_LAST, IMSFT(X_F10));
    BABLM(BABL_IDE_RUN_SEL, OMSFT(IMALT(X_F10)));
    BABLM(BABL_IDE_RUN_ANY,  OMSFT(OMALT(IMCTL(X_A))));
#        endif

    // Todo, ring bell, flash light, show user this isn't supported
    return false;
}

#    endif /* linux mode */
#endif
