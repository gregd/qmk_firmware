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

#    ifdef BABL_MAC

bool babblePaste_mac(uint16_t keycode) {
#        ifdef BABL_MOVE
    BABLM(BABL_GO_LEFT_1C, SS_TAP(X_LEFT));
    BABLM(BABL_GO_RIGHT_1C, SS_TAP(X_RIGHT));
    BABLM(BABL_GO_LEFT_WORD, IMALT(X_LEFT));
    BABLM(BABL_GO_RIGHT_WORD, IMALT(X_RIGHT));
    BABLM(BABL_GO_START_LINE, IMGUI(X_LEFT));
    BABLM(BABL_GO_END_LINE, IMGUI(X_RIGHT));
    BABLM(BABL_GO_START_DOC, IMGUI(X_UP));
    BABLM(BABL_GO_END_DOC, IMGUI(X_DOWN));
    BABLM(BABL_GO_NEXT_LINE, SS_TAP(X_DOWN));
    BABLM(BABL_GO_PREV_LINE, SS_TAP(X_UP));
    BABLM(BABL_GO_PARA_START, IMALT(X_UP));
    BABLM(BABL_DEL_RIGHT_1C, SS_TAP(X_DELETE));
    BABLM(BABL_GO_PARA_END, IMALT(X_DOWN));
    BABLM(BABL_PGDN, SS_TAP(X_PGDOWN));
    BABLM(BABL_PGUP, SS_TAP(X_PGUP));
    BABLM(BABL_DEL_LEFT_WORD, IMALT(X_BSPACE));
    BABLM(BABL_DEL_RIGHT_WORD, IMALT(X_DELETE));
    BABLM(BABL_DEL_TO_LINE_END, OMSFT(IMGUI(X_RIGHT)) SS_TAP(X_BSPACE));  // this is more app agnostic than ctrl-k
    BABLM(BABL_DEL_TO_LINE_START, OMSFT(IMGUI(X_LEFT)) SS_TAP(X_BSPACE));
    BABLM(BABL_MODE, "Mac ");
#        endif
#        ifdef BABL_OSKEYS
    BABLM(BABL_UNDO, SS_LGUI("z"));
    BABLM(BABL_REDO, SS_LGUI("y"));
    BABLM_CLR_OSM(BABL_CUT, SS_LGUI("x"));
    BABLM_CLR_OSM(BABL_COPY, SS_LGUI("c"));
    BABLM(BABL_PASTE, SS_LGUI("v"));
    BABLM(BABL_SELECT_ALL, SS_LGUI("a"));
    BABLM(BABL_FIND, SS_LGUI("f"));
    BABLM(BABL_FIND_NEXT, SS_LGUI("g"));
    // BABLM( BABL_FIND_NEXT, 	OMSFT(X_F4)) ); // Mac office
    BABLM(BABL_FIND_PREV, OMSFT(IMGUI(X_G)));  // Sublime, browser
    //BABLM(BABL_FIND_PREV, SS_LGUI("g"));
    BABLM(BABL_FIND_REPLACE, SS_LGUI("f"));
    BABLM(BABL_RUNAPP, SS_LGUI(" "));
    BABLM(BABL_SWITCH_APP_NEXT, IMGUI(X_TAB));
    BABLM(BABL_SWITCH_APP_LAST, OMSFT(IMGUI(X_TAB)));
    // Apps vary, but this is  usually tab movement, same as B_NXTB
    /*
    BABLM( BABL_WINDOW_NEXT, OMSFT(IMGUI(X_RBRACKET)) ); // GUI Grav isn't everywhere
    BABLM( BABL_WINDOW_PREV, OMSFT(IMGUI(X_LBRACKET)) );
    */
    BABLM(BABL_WINDOW_NEXT, IMGUI(X_GRAVE));
    BABLM(BABL_WINDOW_PREV, OMSFT(IMGUI(X_GRAVE)));
    BABLM(BABL_WINDOW_NEW, IMGUI(X_N));
    BABLM(BABL_CLOSE_APP, SS_LGUI("q"));
    BABLM(BABL_HELP, OMSFT(IMGUI(X_SLASH)));
    // Locking screen from external keyboard requires automator https://apple.stackexchange.com/questions/73995
    BABLM(BABL_LOCK, OMCTL(IMALT(X_L)));
    BABLM(BABL_SCREENCAPTURE, OMSFT(OMGUI(IMALT(X_4))) IMGUI(X_SPACE) "preview" SS_LGUI("d"));
    BABLM(BABL_SWITCH_KEYBOARD_LAYOUT, IMCTL(X_SPACE));
#        endif
#        ifdef BABL_BROWSER
    BABLM(BABL_BR_NEW_TAB, IMGUI(X_T));
    BABLM(BABL_BR_CLOSE_TAB, SS_LGUI("w"));
    BABLM(BABL_BR_REOPEN_LAST_TAB, OMSFT(SS_LGUI("t")));
    BABLM(BABL_BR_NEXT_TAB, OMGUI(IMALT(X_RIGHT)));
    BABLM(BABL_BR_PREV_TAB, OMGUI(IMALT(X_LEFT)));
    BABLM(BABL_BR_URL_BAR, SS_LGUI("l"));
    BABLM(BABL_BR_FORWARD, IMGUI(X_RIGHT));
    BABLM(BABL_BR_BACK, IMGUI(X_LEFT));
    BABLM(BABL_BR_FIND, SS_LGUI("f"));
    BABLM(BABL_BR_BOOKMARK, SS_LGUI("d"));
    BABLM(BABL_BR_RELOAD, OMGUI(SS_LSFT("r")));  // hard reload w/o cache
    BABLM(BABL_BR_FULLSCREEN, OMGUI(SS_LCTRL("p")));
    BABLM(BABL_BR_ZOOM_IN, IMGUI(X_KP_PLUS));  // ctr+ +
    BABLM(BABL_BR_ZOOM_OUT, IMGUI(X_KP_MINUS));
#            ifdef BABL_BR_CHROME
    BABLM(BABL_BR_VIEWSRC, SS_LGUI("u"));           // Chrome or firefox
    BABLM(BABL_BR_DEV_TOOLS, OMGUI(SS_LALT("i")));  // Chrome or Firefox
#            endif
#            ifdef BABL_BR_SAFARI
    BABLM(BABL_BR_VIEWSRC, OMGUI(IMALT(X_U)));  // Safari
                                                     // BABLM( BABL_BR_DEV_TOOLS,	// No real equivalent for Safari
#            endif
#        endif  //  BABL_BROWSER

#        ifdef BABL_APP
    BABLM(BABL_APP_SAVE, SS_LGUI("s"));

#            ifdef BABL_APP_WINDOWSPLITTING
    // These are for os X terminal, and are pretty useless.
    BABLM(BABL_SPLIT_FRAME_HORIZONTAL, SS_LGUI("d"));
    BABLM(BABL_UNSPLIT_FRAME_HORIZONTAL, OMSFT(IMGUI(X_D)));
#            endif  // BABL_APP_WINDOWSPLITTING

#        endif  // BABL_APP

    // Todo, ring bell, flash light, show user this isn't supported
    return false;
}

#    endif /* mac mode*/
#endif     // Babblepaste
