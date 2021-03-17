/*
Vi is stateful, so you have to track the modes yourself. Otherwise motion is awful (bell, bell, bell)

*/

#include QMK_KEYBOARD_H

#ifdef USE_BABBLEPASTE
#    include "babblePaste.h"

#    ifdef BABL_VI

bool babblePaste_vi(uint16_t keycode) {
#        ifdef BABL_MOVE
    BABLM(BABL_GO_LEFT_1C, "h");
    BABLM(BABL_GO_RIGHT_1C, "l");
    BABLM(BABL_GO_LWORD, "b");
    BABLM(BABL_GO_RWORD, "w");
    BABLM(BABL_GO_SLINE, IMSFT(X_6));
    BABLM(BABL_GO_ELINE, IMSFT(X_4));
    BABLM(BABL_GO_SDOC, "gg");
    BABLM(BABL_GO_EDOC, IMSFT(X_G));
    BABLM(BABL_GO_NLINE, "j");
    BABLM(BABL_GO_PLINE, "k");
    BABLM(BABL_GO_PARA_START, IMSFT(X_LBRACKET));
    BABLM(BABL_GO_PARA_END, IMSFT(X_RBRACKET));
    BABLM(BABL_PGDN, SS_LCTRL("f"));
    BABLM(BABL_PGUP, SS_LCTRL("b"));
    BABLM(BABL_DEL_RIGHT_1C, "x");
    BABLM(BABL_DEL_LWORD, "dge");
    BABLM(BABL_DEL_RWORD, "dw");
    BABLM(BABL_DEL_2LNE, "d" IMSFT(X_4));
    BABLM(BABL_DEL_2LNS, "d" IMSFT(X_6));
    BABLM(BABL_MODE, "Vi ");
#        endif
#        ifdef BABL_OSKEYS
    BABLM(BABL_UNDO, "h");
    BABLM(BABL_REDO, SS_LCTRL("r"));
    BABLM(BABL_CUT, "x");
    BABLM(BABL_COPY, "y");
    BABLM(BABL_PASTE, "p");
    BABLM(BABL_SELECT_ALL, IMSFT(X_SCOLON) SS_TAP(X_5) "y");  // wrong but helpful?
    BABLM(BABL_FIND, SS_TAP(X_SLASH));
    BABLM(BABL_FIND_NEXT, "n");
    BABLM(BABL_FIND_PREV, IMSFT(X_N));
    BABLM(BABL_FIND_REPLACE, OMALT(IMSFT(X_5)));
    BABLM(BABL_RUNAPP, ":split");                // requires VIM, is vsplit better?
    BABLM(BABL_SWITCH_APP_NEXT, IMCTL(X_DOWN));  // Or Right?
    BABLM(BABL_SWITCH_APP_NEXT, IMCTL(X_UP));    // or Left?
    BABLM(BABL_CLOSE_APP, IMCTL(X_SCOLON) "q");
    BABLM(BABL_HELP, SS_LSFT(SS_TAP(X_SCOLON)) "h");  // start search in help
                                                      // BABLM( BABL_LOCK,		()	); Perhaps VI is not an OS?
                                                      // BABLM( BABL_SCREENCAPTURE,		()	); // capture a buffer?
#        endif

#        ifdef BABL_BROWSER
/* what _is_ the VI browser now that vimpirator is dead?*/
#        endif

#        ifdef BABL_APP
    BABLM(BABL_APP_SAVE, SS_TAP(X_ESCAPE) ":w");
#            ifdef BABL_APP_WINDOWSPLITTING
    BABLM(BABL_SPLIT_FRAME_VERT, SS_TAP(X_ESCAPE) ":vsplit");
    BABLM(BABL_UNSPLIT_FRAME_VERT, SS_TAP(X_ESCAPE) ":hide");  // debatable.
    BABLM(BABL_SPLIT_FRAME_HORIZONTAL, SS_TAP(X_ESCAPE) ":vsplit");
    BABLM(BABL_UNSPLIT_FRAME_HORIZONTAL, SS_TAP(X_ESCAPE) ":hide");
    BABLM(BABL_NEXT_FRAME, SS_LCTRL("w") "w");
    BABLM(BABL_PREV_FRAME, SS_LCTRL("w") SS_LSFT("w"));
#            endif
#        endif  // app
    // Todo, ring bell, flash light, show user this isn't supported
    return false;
}

#    endif  // VI
#endif      // Babblepaste
