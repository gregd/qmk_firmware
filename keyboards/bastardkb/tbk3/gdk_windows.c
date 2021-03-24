/*  A library to output the right key shortcut in any common app.
Given a global variable gdk_mode to show the environment and a
key that calls the paste macro, do the right type of paste.
Setting the context is done by another macro, or TBD interaction with the host.

Huge thanks to https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
https://support.microsoft.com/en-gb/help/12445/windows-keyboard-shortcuts

Remember to check  https://github.com/qmk/qmk_firmware/blob/master/quantum/send_string_keycodes.h

*/

#include QMK_KEYBOARD_H

#ifdef USE_GDK_MACRO
#    include "gdkMacro.h"

#    ifdef GD_WINDOWS

bool gdkMacro_win(uint16_t keycode) {
#        ifdef GD_MOVE
    GDM(GD_GO_LEFT_1C, SS_TAP(X_LEFT));
    GDM(GD_GO_RIGHT_1C, SS_TAP(X_RIGHT));
    GDM(GD_GO_LWORD, IMCTL(X_LEFT));
    GDM(GD_GO_RWORD, IMCTL(X_RIGHT));
    GDM(GD_GO_SLINE, IMGUI(X_LEFT));
    GDM(GD_GO_ELINE, IMGUI(X_RIGHT));
    GDM(GD_GO_SDOC, OMGUI(IMCTL(X_LEFT)));
    GDM(GD_GO_EDOC, OMGUI(IMCTL(X_RIGHT)));
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
    GDM(GD_MODE, "Windows ");
#        endif

#        ifdef GD_OSKEYS
    GDM(GD_UNDO, SS_LCTRL("z"));
    GDM(GD_REDO, SS_LCTRL("y"));
    GDM_CLR_OSM(GD_CUT, SS_LCTRL("x"));
    GDM_CLR_OSM(GD_COPY, SS_LCTRL("c"));
    GDM(GD_PASTE, SS_LCTRL("v"));
    GDM(GD_SE_ALL, SS_LCTRL("a"));
    GDM(GD_FIND, SS_LCTRL("f"));
    GDM(GD_FNEXT, SS_TAP(X_F3));
    // GDM( GD_FPREV, 	SS_TAP(X_F3) ); // doesn't have a standard one?
    GDM(GD_REPLACE, SS_LCTRL("h"));
    GDM(GD_RUNAPP, SS_LGUI("r"));
    GDM(GD_APP_NEXT, IMALT(X_TAB));
    GDM(GD_APP_LAST, OMSFT(IMALT(X_TAB)));
    GDM(GD_WIN_NEXT, IMCTL(X_TAB));
    GDM(GD_WIN_PREV, OMSFT(IMCTL(X_TAB)));
    GDM(GD_WIN_NEW, IMCTL(X_N));
    GDM(GD_APP_CLOSE, IMALT(X_F4));
    GDM(GD_HELP, SS_TAP(X_F1));
    GDM(GD_LOCK, SS_LGUI("l"));
    GDM(GD_SCR_CAP_FULL, OMSFT(SS_LGUI("s")));
    GDM(GD_SWITCH_KEYBOARD_LAYOUT, IMGUI(X_SPACE));

#        endif

#        ifdef GD_BROWSER
    GDM(GD_B_NEWT, SS_LCTRL("t"));
    GDM(GD_B_CTAB, SS_LCTRL("w"));
    GDM(GD_B_REOPEN_LAST_TAB, OMSFT(IMCTL(X_T)));
    GDM(GD_B_NTAB, IMCTL(X_TAB));
    GDM(GD_B_PTAB, OMSFT(IMCTL(X_TAB)));
    GDM(GD_B_URL, SS_LCTRL("l"));
    GDM(GD_B_FORWARD, IMALT(X_RIGHT));
    GDM(GD_B_BACK, OMSFT(IMALT(X_LEFT)));
    ;
    GDM(GD_B_FIND, SS_LCTRL("f"));
    GDM(GD_B_BOOKMARK, SS_LCTRL("d"));
#            ifdef GD_B_MS
    GDM(GD_B_DEV_TOOLS, IMCTL(X_F12));  // EDGE
#            else
    GDM(GD_B_DEV_TOOLS, SS_LCTRL("t"));  // Chrome
    GDM(GD_B_VIEWSRC, SS_LCTRL("u"));    // Chrome or firefox
#            endif
    // chrome
    GDM(GD_B_RELOAD, IMCTL(X_F5));             // hard reload w/o cache
    GDM(GD_B_FULLSCREEN, SS_TAP(X_F11));       // command shift F
    GDM(GD_B_ZOOM_IN, OMSFT(IMCTL(X_EQUAL)));  // ctr+ +
    GDM(GD_B_ZOOM_OUT, IMCTL(X_MINUS));

#        endif

#        ifdef GD_APP
    GDM(GD_APP_SAVE, SS_LCTL("s"));

    // GDM( GD_SPLIT_FRAME_VERT,		()  );// no windows way?
    // GDM( GD_UNSPLIT_FRAME_VERT,		()  );
    GDM(GD_SPLIT_FRAME_HORIZONTAL, OMALT(IMCTL(X_S)));    // word only
    GDM(GD_UNSPLIT_FRAME_HORIZONTAL, OMSFT(IMALT(X_C)));  // word
    // GDM( GD_NEXT_FRAME, () );//no windows way?
    // GDM( GD_PREV_FRAME, () );// no windows way?
#        endif

    // Todo, ring bell, flash light, show user this isn't supported
    return false;
}

#    endif /* GD_WINDOWS*/
#endif
