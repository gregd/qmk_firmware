// Readline command line editing + tmux windowing
// I haven't decided how much to do readline and how much tmux
// see https://tiswww.case.edu/php/chet/readline/rluserman.html for other possible
// keybindings.

#include QMK_KEYBOARD_H

#ifdef USE_GDK_MACRO
#    include "gdkMacro.h"

#    ifdef GD_READMUX

// Redefine if you use something other than CTRL-B to activate tmux.
#        define TMUX SS_LCTL("b")

bool gdkMacro_readmux(uint16_t keycode) {
#        ifdef GD_MOVE
    GDM(GD_GO_LEFT_1C, SS_TAP(X_LEFT));
    GDM(GD_GO_RIGHT_1C, SS_TAP(X_RIGHT));
    GDM(GD_GO_LWORD, SS_LALT("b"));
    GDM(GD_GO_RWORD, SS_LALT("f"));
    GDM(GD_GO_SLINE, SS_LCTL("a"));
    GDM(GD_GO_ELINE, SS_LCTL("e"));
    // GDM( GD_GO_SDOC		,END );// tmux?
    // GDM( GD_GO_EDOC		,END );  // tmux?
    GDM(GD_GO_NLINE, SS_LCTL("n"));
    GDM(GD_GO_PLINE, SS_LCTL("p"));
    // GDM( GD_GO_PARA_START,	// undefined
    // GDM( GD_GO_PARA_END,	 	// undefinedGDM( GD_PGDN ,

    GDM(GD_PGUP, SS_TAP(X_PGUP));
    GDM(GD_PGDN, SS_TAP(X_PGDOWN));
    GDM(GD_DEL_RIGHT_1C, SS_LCTL("d"));
    GDM(GD_DEL_LWORD, SS_LCTL("w"));  // meta-DEL instead?
    GDM(GD_DEL_RWORD, SS_LALT("d"));
    GDM(GD_DEL_2LNE, SS_LCTL("k"));
    GDM(GD_DEL_2LNS, SS_LCTL("u"));
    GDM(GD_MODE, "Readline ");
#        endif
#        ifdef GD_OSKEYS
    GDM(GD_UNDO, SS_LALT("r"));
    GDM(GD_REDO, SS_LCTL("x") "c");  // arguably
    GDM(GD_CUT, SS_LCTL("k"));       // wrong half the time
    // GDM( GD_COPY		,END );
    GDM(GD_PASTE, SS_LCTL("y"));
    GDM(GD_SELECT_ALL, SS_LCTL("aky"));
    GDM(GD_FIND, SS_LCTL("r"));  // search history
    GDM(GD_FNEXT, SS_LCTL("r"));
    GDM(GD_FPREV, SS_LCTL("s"));
    // GDM( GD_REPLACE		,END ); // not offered in readline
    GDM(GD_RUNAPP, TMUX "c");           // tmux
    GDM(GD_APP_NEXT, TMUX "n");  // tmux
    GDM(GD_APP_LAST, TMUX "p");  // tmux
    GDM(GD_APP_CLOSE, TMUX "d");        // usually what I want
    GDM(GD_HELP, TMUX IMSFT(X_SLASH));
    GDM(GD_LOCK, TMUX "L");  // assuming you set up VLOCK yourself
    GDM(GD_SCR_CAP_FULL, TMUX ":capture-pane");
#        endif
#        ifdef GD_BROWSER
/* Add lynx shortcuts, brow.sh?
 */
#            ifdef GD_MAC
    // this is stock OS X Terminal, alter for windows &etc.
    GDM(GD_B_NEW_TAB, IMGUI(X_T));
    GDM(GD_B_CL_TAB, SS_LGUI("w"));
    GDM(GD_B_NEXT_TAB, IMCTL(X_TAB));
    GDM(GD_B_PREV_TAB, OMSFT(IMCTL(X_TAB)));
#            endif
#        endif
#        ifdef GD_APP
    // Save makes no sense here
    GDM(GD_SPLIT_FRAME_VERT, TMUX IMSFT(X_5));
    // BUG - misleading. This is currently set to convert frame to a window.
    GDM(GD_UNSPLIT_FRAME_VERT, TMUX IMSFT(X_1));
    GDM(GD_SPLIT_FRAME_HORIZONTAL, TMUX IMSFT(X_QUOTE));
    // This one closes the current pane.
    GDM(GD_UNSPLIT_FRAME_HORIZONTAL, SS_LCTL("b") "x");
    GDM(GD_NEXT_FRAME, SS_LCTL("b") "o");
    GDM(GD_PREV_FRAME, SS_LCTL("w") SS_TAP(X_SCOLON));
#        endif

    // Todo, ring bell, flash light, show user this isn't supported
    return false;
}
#    endif /* readmux*/
#endif
