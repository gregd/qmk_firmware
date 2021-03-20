/*  A library to output the right key shortcut in any common app.
Given a global variable babble_mode to show the environment and a
key that calls the paste macro, do the right type of paste.
Setting the context is done by another macro, or TBD interaction with the host.

Huge thanks to https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
and https://github.com/qmk/qmk_firmware/blob/master/keyboards/planck/keymaps/jeebak/keymap.c
*/

#include QMK_KEYBOARD_H

#ifdef USE_BABBLEPASTE
#    include "babblePaste.h"

#    ifdef GD_MAC

bool babblePaste_mac(uint16_t keycode) {
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
    GDM(GD_SELECT_ALL, SS_LGUI("a"));
    GDM(GD_FIND, SS_LGUI("f"));
    GDM(GD_FIND_NEXT, SS_LGUI("g"));
    // GDM( GD_FIND_NEXT, 	OMSFT(X_F4)) ); // Mac office
    GDM(GD_FIND_PREV, OMSFT(IMGUI(X_G)));  // Sublime, browser
    //GDM(GD_FIND_PREV, SS_LGUI("g"));
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
    GDM(GD_CLOSE_APP, SS_LGUI("q"));
    GDM(GD_HELP, OMSFT(IMGUI(X_SLASH)));
    // Locking screen from external keyboard requires automator https://apple.stackexchange.com/questions/73995
    GDM(GD_LOCK, OMCTL(IMALT(X_L)));
    GDM(GD_SCR_CAP_FULL, OMSFT(OMGUI(IMALT(X_4))) IMGUI(X_SPACE) "preview" SS_LGUI("d"));
    GDM(GD_SWITCH_KEYBOARD_LAYOUT, IMCTL(X_SPACE));
#        endif
#        ifdef GD_BROWSER
    GDM(GD_BR_NEW_TAB, IMGUI(X_T));
    GDM(GD_BR_CL_TAB, SS_LGUI("w"));
    GDM(GD_BR_REOPEN_LAST_TAB, OMSFT(SS_LGUI("t")));
    GDM(GD_BR_NEXT_TAB, OMGUI(IMALT(X_RIGHT)));
    GDM(GD_BR_PREV_TAB, OMGUI(IMALT(X_LEFT)));
    GDM(GD_BR_URL_BAR, SS_LGUI("l"));
    GDM(GD_BR_FORWARD, IMGUI(X_RIGHT));
    GDM(GD_BR_BACK, IMGUI(X_LEFT));
    GDM(GD_BR_FIND, SS_LGUI("f"));
    GDM(GD_BR_BOOKMARK, SS_LGUI("d"));
    GDM(GD_BR_RELOAD, OMGUI(SS_LSFT("r")));  // hard reload w/o cache
    GDM(GD_BR_FULLSCREEN, OMGUI(SS_LCTRL("p")));
    GDM(GD_BR_ZOOM_IN, IMGUI(X_KP_PLUS));  // ctr+ +
    GDM(GD_BR_ZOOM_OUT, IMGUI(X_KP_MINUS));
#            ifdef GD_BR_CHROME
    GDM(GD_BR_VIEWSRC, SS_LGUI("u"));           // Chrome or firefox
    GDM(GD_BR_DEV_TOOLS, OMGUI(SS_LALT("i")));  // Chrome or Firefox
#            endif
#            ifdef GD_BR_SAFARI
    GDM(GD_BR_VIEWSRC, OMGUI(IMALT(X_U)));  // Safari
                                                     // GDM( GD_BR_DEV_TOOLS,	// No real equivalent for Safari
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

    // Todo, ring bell, flash light, show user this isn't supported
    return false;
}

#    endif /* mac mode*/
#endif     // Babblepaste
