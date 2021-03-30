/*  A library to output the right key shortcut in any common app.
Given a global variable gdk_mode to show the environment and a
key that calls the paste macro, do the right type of paste.
Setting the context is done by another macro, or TBD interaction with the host.

Emacs mode is probably most useful for people who don't usually use emacs

https://www.ast.cam.ac.uk/~vasily/idl/emacs_commands_list.html
*/

#include QMK_KEYBOARD_H

#ifdef USE_GDK_MACRO
#    include "gdkMacro.h"

#    ifdef GD_EMACS

// probably should allow meta to not be ALT
#        define DMETA IMALT

bool gdkMacro_emacs(uint16_t keycode) {
#        ifdef GD_MOVE
    GDM(GD_GO_LEFT_1C, SS_TAP(X_LEFT));
    GDM(GD_GO_RIGHT_1C, SS_TAP(X_RIGHT));
    GDM(GD_GO_LW, IMALT(X_B));
    GDM(GD_GO_RW, IMALT(X_F));
    GDM(GD_GO_SL, SS_LCTRL("a"));
    GDM(GD_GO_EL, SS_LCTRL("e"));
    GDM(GD_GO_SD, OMALT(IMSFT(X_COMMA)));
    GDM(GD_GO_ED, OMALT(IMSFT(X_DOT)));
    GDM(GD_GO_NLINE, SS_LCTRL("n"));
    GDM(GD_GO_PLINE, SS_LCTRL("p"));
    GDM(GD_GO_PARA_START, OMALT(IMSFT(X_LBRACKET)));
    GDM(GD_GO_PARA_END, OMALT(IMSFT(X_RBRACKET)));
    GDM(GD_PGDN, SS_LCTRL("v"));
    GDM(GD_PGUP, IMALT(X_V));
    GDM(GD_DEL_RIGHT_1C, SS_LCTRL("d"));
    GDM(GD_DEL_LWORD, IMCTL(X_BSPACE));
    GDM(GD_DEL_RWORD, IMALT(X_D));
    GDM(GD_DEL_2LNE, SS_LCTRL("k"));
    GDM(GD_DEL_2LNS, SS_TAP(X_ESCAPE) "0" SS_LCTRL("k"));
    GDM(GD_MODE, "Emacs ");
#        endif
#        ifdef GD_OSKEYS
    GDM(GD_UNDO, SS_LCTRL("x") "c");
    GDM(GD_REDO, SS_LCTRL("x") "c");  // arguably
    GDM(GD_CUT, SS_LCTRL("w"));
    GDM(GD_COPY, SS_LALT("w"));  // really?
    GDM(GD_PASTE, SS_LCTRL("y"));
    GDM(GD_SE_ALL, SS_LCTRL("x") "h");
    GDM(GD_FIND, SS_LCTRL("s"));
    GDM(GD_FNEXT, SS_LCTRL("s"));
    GDM(GD_FPREV, SS_LCTRL("r"));
    GDM(GD_REPLACE, OMALT(IMSFT(X_5)));
    // GDM( GD_RUNAPP , 			//(SS_LALT("x") "shell")	 );// arguably
    GDM(GD_RUNAPP, IMALT(X_X) "split-window" SS_TAP(X_ENTER));  // arguably
    GDM(GD_WIN_NEXT, SS_LCTRL("x") "o");
    GDM(GD_WIN_PREV, SS_LCTRL("x") "o");  // arguably
    //	GDM( GD_WIN_NEW,		IMCTL(X_X)"n" ); //
    GDM(GD_APP_CLOSE, SS_LCTRL("x") "c");
    GDM(GD_HELP, SS_LCTRL("h") "a");  // start search in help
                                          // GDM( GD_LOCK,		()	); // lock buffer? Too many options.
    // GDM( GD_SCR_CFULL,		()	); // requires plugin?

#        endif
#        ifdef GD_BROWSER
/* you get to figure w3 out */
#        endif

#        ifdef GD_APP
    GDM(GD_APP_SAVE, SS_LCTL("x") SS_LCTL("s"));
    /// GDM( GD_APP_MULTI_SELECT, 	SS_LCTRL("x") "rt" ); // arguably
    GDM(GD_SPLIT_FRAME_VERT, SS_LCTRL("x") "3");
    GDM(GD_UNSPLIT_FRAME_VERT, SS_LCTRL("u") SS_LCTRL("x") "0");
    GDM(GD_SPLIT_FRAME_HORIZONTAL, SS_LCTRL("x") "2");
    GDM(GD_UNSPLIT_FRAME_HORIZONTAL, SS_LCTRL("u") SS_LCTRL("x") "0");
    GDM(GD_NEXT_FRAME, SS_LCTRL("x") "o");
    GDM(GD_PREV_FRAME, SS_LCTRL("u") "-1" SS_LCTRL("x") "o");
#        endif

    // Todo, ring bell, flash light, show user this isn't supported
    return false;
}
#    endif /* emacs mode*/
#endif
