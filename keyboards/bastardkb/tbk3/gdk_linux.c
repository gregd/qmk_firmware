/*  A library to output the right key shortcut in any common app.
Given a global variable gdk_mode to show the environment and a
key that calls the paste macro, do the right type of paste.
Setting the context is done by another macro, or TBD interaction with the host.

Huge thanks to https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
and https://github.com/qmk/qmk_firmware/blob/master/keyboards/planck/keymaps/jeebak/keymap.c
*/

#include QMK_KEYBOARD_H

#ifdef USE_GDK_MACRO
#    include "gdkMacro.h"

#    ifdef GD_LINUX

bool gdkMacro_linux(uint16_t keycode) {
#        ifdef GD_MOVE
    GDM(GD_GO_LEFT_1C, SS_TAP(X_LEFT));
    GDM(GD_GO_RIGHT_1C, SS_TAP(X_RIGHT));
    GDM(GD_GO_LW, IMCTL(X_LEFT));
    GDM(GD_GO_RW, IMCTL(X_RIGHT));
    GDM(GD_GO_SL, SS_TAP(X_HOME));
    GDM(GD_GO_EL, SS_TAP(X_END));
    GDM(GD_GO_SD, IMCTL(X_HOME));
    GDM(GD_GO_ED, IMCTL(X_END));
    GDM(GD_GO_NLINE, SS_TAP(X_DOWN));
    GDM(GD_GO_PLINE, SS_TAP(X_UP));
    GDM(GD_GO_PARA_START, IMCTL(X_UP));
    GDM(GD_GO_PARA_END, IMCTL(X_DOWN));
    GDM(GD_PGDN, SS_TAP(X_PGDOWN));
    GDM(GD_PGUP, SS_TAP(X_PGUP));
    GDM(GD_DEL_RIGHT_1C, SS_TAP(X_DELETE));
    GDM(GD_DEL_LWORD, IMCTL(X_BSPACE));
    GDM(GD_DEL_RWORD, IMCTL(X_DELETE));
    GDM(GD_DEL_2LNE, IMSFT(X_END) SS_TAP(X_DELETE));
    GDM(GD_DEL_2LNS, IMSFT(X_HOME) SS_TAP(X_DELETE));
    GDM(GD_DEL_LINE, IMCTL(X_Y));
    GDM(GD_MODE, "Linux ");
#        endif
#        ifdef GD_OSKEYS
    GDM(GD_UNDO, SS_LCTL("z"));
    GDM(GD_REDO, SS_LCTL("y"));
    GDM_CLR_OSM(GD_CUT, SS_LCTL("x"));
    GDM_CLR_OSM(GD_COPY, SS_LCTL("c"));
    GDM(GD_PASTE, SS_LCTL("v"));
    GDM(GD_PA_REC, OMSFT(IMCTL(X_V)));
    GDM(GD_SE_ALL, SS_LCTL("a"));
    GDM(GD_FIND, SS_LCTL("f"));
    GDM(GD_FNEXT, SS_LCTL("g"));       // Gnome*/
    GDM(GD_FPREV, OMSFT(IMCTL(X_G)));  // Gnome*/
    /* GDM( GD_REPLACE , (SS_LCTL("r"))	); // KDE */
    GDM(GD_REPLACE, SS_LCTL("h"));  // Gnome*/
    GDM(GD_APP_CLOSE, IMALT(X_F4));
    GDM(GD_RUNAPP, SS_TAP(X_LGUI));
    GDM(GD_APP_NEXT, IMALT(X_TAB));
    GDM(GD_APP_LAST, OMSFT(IMALT(X_TAB)));
    GDM(GD_APP_SAVE, SS_LCTL("s"));
    GDM(GD_WIN_NEXT, IMALT(X_GRV));  // Gnome, sometimes
    GDM(GD_WIN_PREV, OMCTL(IMALT(X_PGDOWN)));
    GDM(GD_WIN_NEW, IMCTL(X_N));
    GDM(GD_WIN_HIDE, OMALT(IMCTL(X_KP_0)));
    GDM(GD_WIN_FULL, OMALT(IMCTL(X_KP_5)));
    GDM(GD_WIN_CEN, OMALT(IMCTL(X_KP_8)));
    GDM(GD_WIN_LFT, OMALT(IMCTL(X_KP_4)));
    GDM(GD_WIN_RGT, OMALT(IMCTL(X_KP_6)));
    // GDM( GD_HELP,		(SS_TAP(X_F1))	); // NA?

    GDM(GD_LOCK, OMCTL(IMALT(X_L)));
    GDM(GD_SCR_CFULL, SS_TAP(X_PSCREEN));
    GDM(GD_SCR_CSEL, IMSFT(X_PSCREEN));
#        endif
#        ifdef GD_BROWSER
    GDM(GD_B_NEWT, SS_LCTL("t"));
    GDM(GD_B_CTAB, IMCTL(X_F4));
    GDM(GD_B_REOPEN, OMSFT(IMCTL(X_T)));
    GDM(GD_B_NTAB, IMCTL(X_PGDOWN));
    GDM(GD_B_PTAB, IMCTL(X_PGUP));
    GDM(GD_B_URL, SS_LCTL("l"));
    GDM(GD_B_FORWARD, IMALT(X_RIGHT));
    GDM(GD_B_BACK, IMALT(X_LEFT));
    GDM(GD_B_FIND, SS_LCTL("f"));
    GDM(GD_B_BOOKM, SS_LCTL("d"));
    GDM(GD_B_DTOOLS, OMSFT(IMCTL(X_I)));  // Chrome
    // chrome
    GDM(GD_B_RLOAD, IMCTL(X_F5));             // hard reload w/o cache
    GDM(GD_B_FULLS, SS_TAP(X_F11));       // command shift F
    GDM(GD_B_ZOOMI, OMSFT(IMCTL(X_EQUAL)));  // ctr+ +
    GDM(GD_B_ZOOMO, IMCTL(X_MINUS));
#        endif
#        ifdef GD_IDE
    GDM(GD_I_WIN_SEA, IMALT(X_3));
    GDM(GD_I_WIN_RUN, IMALT(X_4));
    GDM(GD_I_WIN_STRU, IMALT(X_7));
    GDM(GD_I_WIN_GITH, IMALT(X_9));
    GDM(GD_I_WIN_GITC, IMALT(X_0));
    GDM(GD_I_REC_FILE, IMCTL(X_E));
    GDM(GD_I_REC_LOC, OMSFT(IMCTL(X_E)));
    GDM(GD_I_FINF, OMSFT(IMCTL(X_F)));
    GDM(GD_I_RINF, OMSFT(IMCTL(X_R)));
    GDM(GD_I_FACT, OMSFT(IMCTL(X_A)));
    GDM(GD_I_REL_FILE, OMSFT(IMCTL(X_9)));             // RubyMine goto-view / controller
    GDM(GD_I_REL_SYM, OMALT(IMCTL(X_HOME)));
    GDM(GD_I_EX_SEL, SS_LCTL("w"));
    GDM(GD_I_COMPLETE, IMCTL(X_SPACE));
    GDM(GD_I_FIXES, IMALT(X_ENTER));
    GDM(GD_I_QDOC, SS_LCTL("q"));
    GDM(GD_I_GO_L_ED, OMSFT(IMCTL(X_BSPACE)));
    GDM(GD_I_GO_DEF, SS_LCTL("b"));
    GDM(GD_I_GO_BACK, OMALT(IMCTL(X_LEFT)));
    GDM(GD_I_GO_FWD, OMALT(IMCTL(X_RIGHT)));
    GDM(GD_I_GOTOL, OMSFT(OMALT(IMCTL(X_G))));
    GDM(GD_I_GO_FILE, OMSFT(IMCTL(X_N)));
    GDM(GD_I_NEXT_FN, IMALT(X_DOWN));
    GDM(GD_I_PREV_FN, IMALT(X_UP));
    GDM(GD_I_USAGES, IMALT(X_F7));
    GDM(GD_I_RENAME, IMSFT(X_F6));
    GDM(GD_I_REFACTOR, OMSFT(OMALT(IMCTL(X_T))));
    GDM(GD_I_COMMENT, IMCTL(X_SLASH));
    GDM(GD_I_REFORMAT, OMALT(IMCTL(X_L)));
    GDM(GD_I_COLM, OMALT(IMSFT(X_INSERT)));
    GDM(GD_I_SE_DUP, IMCTL(X_D));
    GDM(GD_I_TGL_CASE, OMSFT(IMCTL(X_U)));
    GDM(GD_I_BUILD, IMCTL(X_F9));
    GDM(GD_I_RUNL, IMSFT(X_F10));
    GDM(GD_I_RUNS, OMSFT(IMALT(X_F10)));
    GDM(GD_I_RUNA,  OMSFT(OMALT(IMCTL(X_A))));
    GDM(GD_T_CREATE, IMCTL(X_A) "c" IMCTL(X_A) ",");
    GDM(GD_T_NEXT, IMCTL(X_A) "n");
    GDM(GD_T_PREV, IMCTL(X_A) "p");
    GDM(GD_T_EDIT, IMCTL(X_A) "[");
    GDM(GD_T_NORM, IMCTL(X_BSLASH) IMCTL(X_N));
#        endif

    // Todo, ring bell, flash light, show user this isn't supported
    return false;
}

#    endif /* linux mode */
#endif
