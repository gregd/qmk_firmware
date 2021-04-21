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
//    GDM(GD_I_WIN_STRU, IMALT(X_7));
    GDM(GD_I_WIN_GITH, " gitl");
    GDM(GD_I_WIN_GITC, " gitd");
    GDM(GD_I_REC_FILE, " fo");
    GDM(GD_I_REC_LOC, " fb");
    GDM(GD_I_FINF, " fg");
//    GDM(GD_I_RINF, OMSFT(IMCTL(X_R)));
    GDM(GD_I_FACT, " fc");
//    GDM(GD_I_REL_FILE, "");             // RubyMine goto-view / controller
//    GDM(GD_I_REL_SYM, OMALT(IMCTL(X_HOME)));
    GDM(GD_I_EX_SEL, " ss");
//    GDM(GD_I_COMPLETE, IMCTL(X_SPACE));
//    GDM(GD_I_FIXES, IMALT(X_ENTER));
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
//    GDM(GD_I_REFORMAT, OMALT(IMCTL(X_L)));
    GDM(GD_I_COLM, IMCTL(X_V));
//    GDM(GD_I_NEW_LINE, IMSFT(X_ENTER));
//    GDM(GD_I_SE_DUP, IMCTL(X_D));
//    GDM(GD_I_TGL_CASE, OMSFT(IMCTL(X_U)));
//    GDM(GD_I_BUILD, IMCTL(X_F9));
//    GDM(GD_I_RUNL, IMSFT(X_F10));
//    GDM(GD_I_RUNS, OMSFT(IMALT(X_F10)));
//    GDM(GD_I_RUNA,  OMSFT(OMALT(IMCTL(X_A))));
    GDM(GD_T_CREATE, IMCTL(X_A) "c" IMCTL(X_A) ",");
    GDM(GD_T_NEXT, IMCTL(X_A) "n");
    GDM(GD_T_PREV, IMCTL(X_A) "p");
    GDM(GD_T_EDIT, IMCTL(X_A) "[");
#        endif
    return false;
}

#    endif  // VI
#endif
