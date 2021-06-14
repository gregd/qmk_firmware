/*
Vi is stateful, so you have to track the modes yourself. Otherwise motion is awful (bell, bell, bell)

*/

#include QMK_KEYBOARD_H

#ifdef USE_GDK_MACRO
#    include "gdkMacro.h"

#    ifdef GD_VI

bool gdkMacro_vi(uint16_t keycode) {
#        ifdef GD_MOVE
    GDM(GD_MODE, "Vim ");
#        endif
#        ifdef GD_OSKEYS
#        endif
#        ifdef GD_BROWSER
#        endif
#        ifdef GD_IDE
    GDM(GD_I_WIN_SEA, " fq");
//    GDM(GD_I_WIN_RUN, IMALT(X_4));
    GDM(GD_I_WIN_STRU, " nt");
    GDM(GD_I_WIN_GITH, " gitl");
    GDM(GD_I_WIN_GITC, " gitd");
    GDM(GD_I_REC_FILE, " fo");
    GDM(GD_I_REC_LOC, " fb");
    GDM(GD_I_FINF, " fg");
    GDM(GD_I_RINF, " sr");
    GDM(GD_I_FACT, " fc");
//    GDM(GD_I_REL_FILE, "");             // RubyMine goto-view / controller
    GDM(GD_I_REL_SYM, " fs");
    GDM(GD_I_EX_SEL, " ss");
    GDM(GD_I_COMPLETE, IMCTL(X_SPACE));
    GDM(GD_I_FIXES, " la");
    GDM(GD_I_QDOC, " lh");
    GDM(GD_I_GO_L_ED, "`.");
    GDM(GD_I_GO_DEF, " fd");
    GDM(GD_I_GO_BACK, IMCTL(X_O));
    GDM(GD_I_GO_FWD, IMCTL(X_I));
    GDM(GD_I_GOTOL, " ga");
    GDM(GD_I_GO_FILE, " ff");
    GDM(GD_I_NEXT_FN, "]m");
    GDM(GD_I_PREV_FN, "[m");
    GDM(GD_I_USAGES, " fr");
    GDM(GD_I_RENAME, " lr");
    GDM(GD_I_REFACTOR, " la");
    GDM(GD_I_COMMENT, " cc");
    GDM(GD_I_REFORMAT, " lf");
    GDM(GD_I_COLM, IMCTL(X_V));
    GDM(GD_I_NEW_LINE, SS_TAP(X_ESCAPE) "o");
    GDM(GD_I_SE_DUP, "y'>p");
    GDM(GD_I_TGL_CASE, "g~w");
//    GDM(GD_I_BUILD, IMCTL(X_F9));
//    GDM(GD_I_RUNL, IMSFT(X_F10));
//    GDM(GD_I_RUNS, OMSFT(IMALT(X_F10)));
//    GDM(GD_I_RUNA,  OMSFT(OMALT(IMCTL(X_A))));

    GDM(GD_PA_REC, " fp");
#        endif
    return false;
}

#    endif  // VI
#endif
