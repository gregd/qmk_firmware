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

#    ifdef GD_MAC

bool gdkMacro_mac(uint16_t keycode) {
#        ifdef GD_MOVE
    GDM(GD_GO_LEFT_1C, SS_TAP(X_LEFT));
    GDM(GD_GO_RIGHT_1C, SS_TAP(X_RIGHT));
    GDM(GD_GO_LW, IMALT(X_LEFT));
    GDM(GD_GO_RW, IMALT(X_RIGHT));
    GDM(GD_GO_SL, IMGUI(X_LEFT));
    GDM(GD_GO_EL, IMGUI(X_RIGHT));
    GDM(GD_GO_SD, IMGUI(X_UP));
    GDM(GD_GO_ED, IMGUI(X_DOWN));
    GDM(GD_GO_NLINE, SS_TAP(X_DOWN));
    GDM(GD_GO_PLINE, SS_TAP(X_UP));
    GDM(GD_GO_PARA_START, IMALT(X_UP));
    GDM(GD_GO_PARA_END, IMALT(X_DOWN));
    GDM(GD_PGDN, SS_TAP(X_PGDOWN));
    GDM(GD_PGUP, SS_TAP(X_PGUP));
    GDM(GD_DEL_RIGHT_1C, SS_TAP(X_DELETE));
    GDM(GD_DEL_LWORD, IMALT(X_BSPACE));
    GDM(GD_DEL_RWORD, IMALT(X_DELETE));
    GDM(GD_DEL_2LNE, OMSFT(IMGUI(X_RIGHT)) SS_TAP(X_DELETE));  // this is more app agnostic than ctrl-k
    GDM(GD_DEL_2LNS, OMSFT(IMGUI(X_LEFT)) SS_TAP(X_DELETE));
    GDM(GD_DEL_LINE, IMGUI(X_BSPACE));
    GDM(GD_MODE, "Mac ");
#        endif
#        ifdef GD_OSKEYS
    GDM(GD_UNDO, SS_LGUI("z"));
    GDM(GD_REDO, SS_LGUI("y"));
    GDM_CLR_OSM(GD_CUT, SS_LGUI("x"));
    GDM_CLR_OSM(GD_COPY, SS_LGUI("c"));
    GDM(GD_PASTE, SS_LGUI("v"));
    GDM(GD_PA_REC, OMSFT(IMGUI(X_V)));
    GDM(GD_SE_ALL, SS_LGUI("a"));
    GDM(GD_FIND, SS_LGUI("f"));
    GDM(GD_FNEXT, SS_LGUI("g"));
    GDM(GD_FPREV, OMSFT(IMGUI(X_G)));  // Sublime, browser
    //GDM(GD_FPREV, SS_LGUI("g"));
    GDM(GD_REPLACE, SS_LGUI("f"));
    GDM(GD_APP_CLOSE, SS_LGUI("q"));
    GDM(GD_RUNAPP, SS_LGUI(" "));
    GDM(GD_APP_NEXT, IMGUI(X_TAB));
    GDM(GD_APP_LAST, OMSFT(IMGUI(X_TAB)));
    GDM(GD_APP_SAVE, SS_LGUI("s"));
    GDM(GD_WIN_NEXT, IMGUI(X_GRAVE));
    GDM(GD_WIN_PREV, OMSFT(IMGUI(X_GRAVE)));
    GDM(GD_WIN_NEW, IMGUI(X_N));
    GDM(GD_WIN_HIDE, IMGUI(X_H));
    GDM(GD_WIN_FULL, OMALT(IMCTL(X_KP_5)));
    GDM(GD_WIN_CEN, OMALT(IMCTL(X_KP_8)));
    GDM(GD_WIN_LFT, OMALT(IMCTL(X_KP_4)));
    GDM(GD_WIN_RGT, OMALT(IMCTL(X_KP_6)));
    // GDM(GD_HELP, OMSFT(IMGUI(X_SLASH)));
    // Locking screen from external keyboard requires automator https://apple.stackexchange.com/questions/73995
    GDM(GD_LOCK, OMCTL(IMALT(X_L)));
    GDM(GD_SCR_CFULL, OMSFT(OMGUI(IMALT(X_3))));
    GDM(GD_SCR_CSEL, OMSFT(OMGUI(IMALT(X_4))));
#        endif
#        ifdef GD_BROWSER
    GDM(GD_B_NEWT, IMGUI(X_T));
    GDM(GD_B_CTAB, SS_LGUI("w"));
    GDM(GD_B_REOPEN, OMSFT(SS_LGUI("t")));
    GDM(GD_B_NTAB, OMGUI(IMALT(X_RIGHT)));
    GDM(GD_B_PTAB, OMGUI(IMALT(X_LEFT)));
    GDM(GD_B_URL, SS_LGUI("l"));
    GDM(GD_B_FORWARD, IMGUI(X_RIGHT));
    GDM(GD_B_BACK, IMGUI(X_LEFT));
    GDM(GD_B_FIND, SS_LGUI("f"));
    GDM(GD_B_BOOKM, SS_LGUI("d"));
    GDM(GD_B_RLOAD, OMGUI(SS_LSFT("r")));  // hard reload w/o cache
    GDM(GD_B_FULLS, OMGUI(SS_LCTRL("p")));
    GDM(GD_B_ZOOMI, IMGUI(X_KP_PLUS));  // ctr+ +
    GDM(GD_B_ZOOMO, IMGUI(X_KP_MINUS));
    GDM(GD_B_DTOOLS, OMGUI(SS_LALT("i")));  // Chrome or Firefox
#        endif  //  GD_BROWSER

#        ifdef GD_IDE
    GDM(GD_I_WIN_SEA, IMGUI(X_3));
    GDM(GD_I_WIN_RUN, IMGUI(X_4));
    GDM(GD_I_WIN_STRU, IMGUI(X_7));
    GDM(GD_I_WIN_GITH, IMGUI(X_9));
    GDM(GD_I_WIN_GITC, IMGUI(X_0));
    GDM(GD_I_REC_FILE, IMGUI(X_E));
    GDM(GD_I_REC_LOC, OMSFT(IMGUI(X_E)));
    GDM(GD_I_FINF, OMSFT(IMGUI(X_F)));
    GDM(GD_I_RINF, OMSFT(IMGUI(X_R)));
    GDM(GD_I_FACT, OMSFT(IMGUI(X_A)));
    GDM(GD_I_REL_FILE, OMSFT(IMGUI(X_9)));             // RubyMine goto-view / controller
    GDM(GD_I_REL_SYM, OMCTL(IMGUI(X_UP)));
    GDM(GD_I_EX_SEL, IMALT(X_UP));
    GDM(GD_I_COMPLETE, IMCTL(X_SPACE));
    GDM(GD_I_FIXES, IMALT(X_ENTER));
    GDM(GD_I_QDOC, SS_LCTL("j"));
    GDM(GD_I_GO_L_ED, OMSFT(IMGUI(X_BSPACE)));
    GDM(GD_I_GO_DEF, SS_LGUI("b"));
    GDM(GD_I_GO_BACK, IMGUI(X_LBRACKET));
    GDM(GD_I_GO_FWD, IMGUI(X_RBRACKET));
    GDM(GD_I_GOTOL, OMSFT(OMALT(IMCTL(X_G))));
    GDM(GD_I_GO_FILE, OMSFT(IMGUI(X_O)));
    GDM(GD_I_NEXT_FN, IMCTL(X_DOWN));
    GDM(GD_I_PREV_FN, IMCTL(X_UP));
    GDM(GD_I_USAGES, IMALT(X_F7));
    GDM(GD_I_RENAME, IMSFT(X_F6));
    GDM(GD_I_REFACTOR, IMCTL(X_T));
    GDM(GD_I_COMMENT, IMGUI(X_SLASH));
    GDM(GD_I_REFORMAT, OMALT(IMGUI(X_L)));
    GDM(GD_I_COLM, OMGUI(IMSFT(X_8)));
    GDM(GD_I_NEW_LINE, IMSFT(X_ENTER));
    GDM(GD_I_SE_DUP, IMGUI(X_D));
    GDM(GD_I_TGL_CASE, OMSFT(IMGUI(X_U)));
    GDM(GD_I_BUILD, IMGUI(X_F9));
    GDM(GD_I_RUNL, IMCTL(X_R));
    GDM(GD_I_RUNS, OMALT(IMCTL(X_R)));
    GDM(GD_I_RUNA, OMSFT(OMALT(IMGUI(X_A))));
    GDM(GD_T_CREATE, IMCTL(X_A) "c" IMCTL(X_A) ",");
    GDM(GD_T_NEXT, IMCTL(X_A) "n");
    GDM(GD_T_PREV, IMCTL(X_A) "p");
    GDM(GD_T_EDIT, IMCTL(X_A) "[");
    GDM(GD_T_NORM, IMCTL(X_BSLASH) IMCTL(X_N));
#        endif

    // Todo, ring bell, flash light, show user this isn't supported
    return false;
}

#    endif /* mac mode*/
#endif
