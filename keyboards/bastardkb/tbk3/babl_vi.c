/*
Vi is stateful, so you have to track the modes yourself. Otherwise motion is awful (bell, bell, bell)

*/

#include QMK_KEYBOARD_H

#ifdef USE_BABBLEPASTE
#    include "babblePaste.h"

#    ifdef GD_VI

bool babblePaste_vi(uint16_t keycode) {
#        ifdef GD_MOVE
    GDM(GD_GO_LEFT_1C, "h");
    GDM(GD_GO_RIGHT_1C, "l");
    GDM(GD_GO_LWORD, "b");
    GDM(GD_GO_RWORD, "w");
    GDM(GD_GO_SLINE, IMSFT(X_6));
    GDM(GD_GO_ELINE, IMSFT(X_4));
    GDM(GD_GO_SDOC, "gg");
    GDM(GD_GO_EDOC, IMSFT(X_G));
    GDM(GD_GO_NLINE, "j");
    GDM(GD_GO_PLINE, "k");
    GDM(GD_GO_PARA_START, IMSFT(X_LBRACKET));
    GDM(GD_GO_PARA_END, IMSFT(X_RBRACKET));
    GDM(GD_PGDN, SS_LCTRL("f"));
    GDM(GD_PGUP, SS_LCTRL("b"));
    GDM(GD_DEL_RIGHT_1C, "x");
    GDM(GD_DEL_LWORD, "dge");
    GDM(GD_DEL_RWORD, "dw");
    GDM(GD_DEL_2LNE, "d" IMSFT(X_4));
    GDM(GD_DEL_2LNS, "d" IMSFT(X_6));
    GDM(GD_MODE, "Vi ");
#        endif
#        ifdef GD_OSKEYS
    GDM(GD_UNDO, "h");
    GDM(GD_REDO, SS_LCTRL("r"));
    GDM(GD_CUT, "x");
    GDM(GD_COPY, "y");
    GDM(GD_PASTE, "p");
    GDM(GD_SELECT_ALL, IMSFT(X_SCOLON) SS_TAP(X_5) "y");  // wrong but helpful?
    GDM(GD_FIND, SS_TAP(X_SLASH));
    GDM(GD_FNEXT, "n");
    GDM(GD_FPREV, IMSFT(X_N));
    GDM(GD_REPLACE, OMALT(IMSFT(X_5)));
    GDM(GD_RUNAPP, ":split");                // requires VIM, is vsplit better?
    GDM(GD_APP_NEXT, IMCTL(X_DOWN));  // Or Right?
    GDM(GD_APP_NEXT, IMCTL(X_UP));    // or Left?
    GDM(GD_APP_CLOSE, IMCTL(X_SCOLON) "q");
    GDM(GD_HELP, SS_LSFT(SS_TAP(X_SCOLON)) "h");  // start search in help
                                                      // GDM( GD_LOCK,		()	); Perhaps VI is not an OS?
                                                      // GDM( GD_SCR_CAP_FULL,		()	); // capture a buffer?
#        endif

#        ifdef GD_BROWSER
/* what _is_ the VI browser now that vimpirator is dead?*/
#        endif

#        ifdef GD_APP
    GDM(GD_APP_SAVE, SS_TAP(X_ESCAPE) ":w");
#            ifdef GD_APP_WINDOWSPLITTING
    GDM(GD_SPLIT_FRAME_VERT, SS_TAP(X_ESCAPE) ":vsplit");
    GDM(GD_UNSPLIT_FRAME_VERT, SS_TAP(X_ESCAPE) ":hide");  // debatable.
    GDM(GD_SPLIT_FRAME_HORIZONTAL, SS_TAP(X_ESCAPE) ":vsplit");
    GDM(GD_UNSPLIT_FRAME_HORIZONTAL, SS_TAP(X_ESCAPE) ":hide");
    GDM(GD_NEXT_FRAME, SS_LCTRL("w") "w");
    GDM(GD_PREV_FRAME, SS_LCTRL("w") SS_LSFT("w"));
#            endif
#        endif  // app
    // Todo, ring bell, flash light, show user this isn't supported
    return false;
}

#    endif  // VI
#endif      // Babblepaste
