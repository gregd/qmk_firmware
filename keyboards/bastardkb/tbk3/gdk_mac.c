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
    GDM(GD_GO_LWORD, IMALT(X_LEFT));
    GDM(GD_GO_RWORD, IMALT(X_RIGHT));
    GDM(GD_GO_SLINE, IMGUI(X_LEFT));
    GDM(GD_GO_ELINE, IMGUI(X_RIGHT));
    GDM(GD_GO_SDOC, IMGUI(X_UP));
    GDM(GD_GO_EDOC, IMGUI(X_DOWN));
    GDM(GD_GO_NLINE, SS_TAP(X_DOWN));
    GDM(GD_GO_PLINE, SS_TAP(X_UP));
    GDM(GD_GO_PARA_START, IMALT(X_UP));
    GDM(GD_DEL_RIGHT_1C, SS_TAP(X_DELETE));
    GDM(GD_GO_PARA_END, IMALT(X_DOWN));
    GDM(GD_PGDN, SS_TAP(X_PGDOWN));
    GDM(GD_PGUP, SS_TAP(X_PGUP));
    GDM(GD_DEL_LWORD, IMALT(X_BSPACE));
    GDM(GD_DEL_RWORD, IMALT(X_DELETE));
    GDM(GD_DEL_2LNE, OMSFT(IMGUI(X_RIGHT)) SS_TAP(X_BSPACE));  // this is more app agnostic than ctrl-k
    GDM(GD_DEL_2LNS, OMSFT(IMGUI(X_LEFT)) SS_TAP(X_BSPACE));
    GDM(GD_MODE, "Mac ");
#        endif
#        ifdef GD_OSKEYS
    GDM(GD_UNDO, SS_LGUI("z"));
    GDM(GD_REDO, SS_LGUI("y"));
    GDM_CLR_OSM(GD_CUT, SS_LGUI("x"));
    GDM_CLR_OSM(GD_COPY, SS_LGUI("c"));
    GDM(GD_PASTE, SS_LGUI("v"));
    GDM(GD_SE_ALL, SS_LGUI("a"));
    GDM(GD_FIND, SS_LGUI("f"));
    GDM(GD_FNEXT, SS_LGUI("g"));
    // GDM( GD_FNEXT, 	OMSFT(X_F4)) ); // Mac office
    GDM(GD_FPREV, OMSFT(IMGUI(X_G)));  // Sublime, browser
    //GDM(GD_FPREV, SS_LGUI("g"));
    GDM(GD_REPLACE, SS_LGUI("f"));
    GDM(GD_RUNAPP, SS_LGUI(" "));
    GDM(GD_APP_NEXT, IMGUI(X_TAB));
    GDM(GD_APP_LAST, OMSFT(IMGUI(X_TAB)));
    // Apps vary, but this is  usually tab movement, same as B_NXTB
    /*
    GDM( GD_WIN_NEXT, OMSFT(IMGUI(X_RBRACKET)) ); // GUI Grav isn't everywhere
    GDM( GD_WIN_PREV, OMSFT(IMGUI(X_LBRACKET)) );
    */
    GDM(GD_WIN_NEXT, IMGUI(X_GRAVE));
    GDM(GD_WIN_PREV, OMSFT(IMGUI(X_GRAVE)));
    GDM(GD_WIN_NEW, IMGUI(X_N));
    GDM(GD_APP_CLOSE, SS_LGUI("q"));
    GDM(GD_HELP, OMSFT(IMGUI(X_SLASH)));
    // Locking screen from external keyboard requires automator https://apple.stackexchange.com/questions/73995
    GDM(GD_LOCK, OMCTL(IMALT(X_L)));
    GDM(GD_SCR_CAP_FULL, OMSFT(OMGUI(IMALT(X_4))) IMGUI(X_SPACE) "preview" SS_LGUI("d"));
    GDM(GD_SWITCH_KEYBOARD_LAYOUT, IMCTL(X_SPACE));
#        endif
#        ifdef GD_BROWSER
    GDM(GD_B_NEWT, IMGUI(X_T));
    GDM(GD_B_CTAB, SS_LGUI("w"));
    GDM(GD_B_REOPEN_LAST_TAB, OMSFT(SS_LGUI("t")));
    GDM(GD_B_NTAB, OMGUI(IMALT(X_RIGHT)));
    GDM(GD_B_PTAB, OMGUI(IMALT(X_LEFT)));
    GDM(GD_B_URL, SS_LGUI("l"));
    GDM(GD_B_FORWARD, IMGUI(X_RIGHT));
    GDM(GD_B_BACK, IMGUI(X_LEFT));
    GDM(GD_B_FIND, SS_LGUI("f"));
    GDM(GD_B_BOOKMARK, SS_LGUI("d"));
    GDM(GD_B_RELOAD, OMGUI(SS_LSFT("r")));  // hard reload w/o cache
    GDM(GD_B_FULLSCREEN, OMGUI(SS_LCTRL("p")));
    GDM(GD_B_ZOOMI, IMGUI(X_KP_PLUS));  // ctr+ +
    GDM(GD_B_ZOOMO, IMGUI(X_KP_MINUS));
#            ifdef GD_B_CHROME
    GDM(GD_B_VIEWSRC, SS_LGUI("u"));           // Chrome or firefox
    GDM(GD_B_DEV_TOOLS, OMGUI(SS_LALT("i")));  // Chrome or Firefox
#            endif
#            ifdef GD_B_SAFARI
    GDM(GD_B_VIEWSRC, OMGUI(IMALT(X_U)));  // Safari
                                                     // GDM( GD_B_DEV_TOOLS,	// No real equivalent for Safari
#            endif
#        endif  //  GD_BROWSER

#        ifdef GD_APP
    GDM(GD_APP_SAVE, SS_LGUI("s"));

#            ifdef GD_APP_WINDOWSPLITTING
    // These are for os X terminal, and are pretty useless.
    GDM(GD_SPLIT_FRAME_HORIZONTAL, SS_LGUI("d"));
    GDM(GD_UNSPLIT_FRAME_HORIZONTAL, OMSFT(IMGUI(X_D)));
#            endif  // GD_APP_WINDOWSPLITTING

#        endif  // GD_APP
#        ifdef GD_IDE
    GDM(GD_I_WIN_FTREE, IMALT(X_1));
    GDM(GD_I_WIN_SEA, IMALT(X_3));
    GDM(GD_I_WIN_RUN, IMALT(X_4));
    GDM(GD_I_WIN_STRU, IMALT(X_7));
    GDM(GD_I_WIN_GITH, IMALT(X_9));
    GDM(GD_I_WIN_GITC, IMALT(X_0));
    GDM(GD_I_REC_FILE, IMCTL(X_E));
    GDM(GD_I_REC_LOC, OMSFT(IMCTL(X_E)));
    GDM(GD_I_SE_EV, SS_LCTL("l"));
    GDM(GD_I_FINF, OMSFT(IMCTL(X_F)));
    GDM(GD_I_FACTION, OMSFT(IMCTL(X_A)));
    GDM(GD_I_REL_FILE, SS_LCTL("t"));             // RubyMine goto-view / controller
    GDM(GD_I_REL_SYM, OMALT(IMCTL(X_HOME)));
    GDM(GD_I_EX_SEL, SS_LCTL("w"));
    GDM(GD_I_COMPLETE, OMSFT(IMCTL(X_SPACE)));
    GDM(GD_I_FIXES, IMALT(X_ENTER));
    GDM(GD_I_QDOC, SS_LCTL("q"));
    GDM(GD_I_GO_L_ED, OMSFT(IMCTL(X_BSPACE)));
    GDM(GD_I_GO_DEF, SS_LCTL("b"));
    GDM(GD_I_GO_BACK, OMALT(IMCTL(X_LEFT)));
    GDM(GD_I_GO_FWD, OMALT(IMCTL(X_RIGHT)));
    GDM(GD_I_GO_LINE, OMSFT(OMALT(IMCTL(X_G))));
    GDM(GD_I_GO_FILE, OMSFT(IMCTL(X_N)));
    GDM(GD_I_NEXT_FN, IMALT(X_DOWN));
    GDM(GD_I_PREV_FN, IMALT(X_UP));
    GDM(GD_I_USAGES, IMALT(X_F7));
    GDM(GD_I_RENAME, IMSFT(X_F6));
    GDM(GD_I_REFACTOR, OMSFT(OMALT(IMCTL(X_T))));
    GDM(GD_I_COMMENT, IMCTL(X_SLASH));
    GDM(GD_I_REFORMAT, OMALT(IMCTL(X_L)));
    GDM(GD_I_COL_MODE, OMALT(IMSFT(X_INSERT)));
    GDM(GD_I_NEW_LINE, IMSFT(X_ENTER));
    GDM(GD_I_DUP_LINE, IMCTL(X_D));
    GDM(GD_I_TGL_CASE, OMSFT(IMCTL(X_U)));
    GDM(GD_I_BUILD, IMCTL(X_F9));
    GDM(GD_I_RUNL, IMSFT(X_F10));
    GDM(GD_I_RUNS, OMSFT(IMALT(X_F10)));
    GDM(GD_I_RUNA,  OMSFT(OMALT(IMCTL(X_A))));
#        endif

    // Todo, ring bell, flash light, show user this isn't supported
    return false;
}

#    endif /* mac mode*/
#endif
