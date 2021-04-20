/*
Vi is stateful, so you have to track the modes yourself. Otherwise motion is awful (bell, bell, bell)

*/

#include QMK_KEYBOARD_H

#ifdef USE_GDK_MACRO
#    include "gdkMacro.h"

#    ifdef GD_VI

bool gdkMacro_vi(uint16_t keycode) {
#        ifdef GD_MOVE
    GDM(GD_GO_LEFT_1C, "h");
    GDM(GD_GO_RIGHT_1C, "l");
    GDM(GD_GO_LW, "b");
    GDM(GD_GO_RW, "w");
    GDM(GD_GO_SL, IMSFT(X_6));
    GDM(GD_GO_EL, IMSFT(X_4));
    GDM(GD_GO_SD, "gg");
    GDM(GD_GO_ED, IMSFT(X_G));
    GDM(GD_GO_NLINE, "j");
    GDM(GD_GO_PLINE, "k");
//    GDM(GD_GO_PARA_START, IMSFT(X_LBRACKET));
//    GDM(GD_GO_PARA_END, IMSFT(X_RBRACKET));
    GDM(GD_PGDN, SS_LCTRL("f"));
    GDM(GD_PGUP, SS_LCTRL("b"));
    GDM(GD_DEL_RIGHT_1C, "x");
    GDM(GD_DEL_LWORD, "dge");
    GDM(GD_DEL_RWORD, "dw");
    GDM(GD_DEL_2LNE, "d" IMSFT(X_4));
    GDM(GD_DEL_2LNS, "d" IMSFT(X_6));
    GDM(GD_MODE, "Vim ");
#        endif
#        ifdef GD_OSKEYS
    GDM(GD_UNDO, "u");
    GDM(GD_REDO, SS_LCTRL("r"));
    GDM(GD_CUT, "d");
    GDM(GD_COPY, "y");
    GDM(GD_PASTE, "p");
    GDM(GD_PA_REC, " fp");
    GDM(GD_SE_ALL, "ggVG");
    GDM(GD_FIND, " fs");
    GDM(GD_FNEXT, IMCTL(X_J));
    GDM(GD_FPREV, IMCTL(X_K));
//    GDM(GD_REPLACE, SS_LCTL("h"));  // Gnome*/
    GDM(GD_APP_CLOSE, IMCTL(X_A) "x");
    GDM(GD_RUNAPP, IMCTL(X_A) "c" IMCTL(X_A) ",");
    GDM(GD_APP_NEXT, IMCTL(X_A) "p");
    GDM(GD_ALT_TAB, IMCTL(X_A) "n");
    GDM(GD_APP_SAVE, IMCTL(X_A) "[");
#        endif
#        ifdef GD_BROWSER
    GDM(GD_B_NEWT, " nf");
    GDM(GD_B_CTAB, " bc");
    GDM(GD_B_NTAB, IMCTL(X_RIGHT));
    GDM(GD_B_PTAB, IMCTL(X_LEFT));
    GDM(GD_B_URL, " fb");
//    GDM(GD_B_RLOAD, IMCTL(X_A) "[");
    GDM(GD_B_ZOOMI, IMGUI(X_KP_PLUS));
    GDM(GD_B_ZOOMO, IMGUI(X_KP_MINUS));
#        endif
#        ifdef GD_IDE
    GDM(GD_I_WIN_SEA, " fq");
//    GDM(GD_I_WIN_RUN, IMALT(X_4));
//    GDM(GD_I_WIN_STRU, IMALT(X_7));
//    GDM(GD_I_WIN_GITH, IMALT(X_9));
//    GDM(GD_I_WIN_GITC, IMALT(X_0));
    GDM(GD_I_REC_FILE, " fo");
//    GDM(GD_I_REC_LOC, OMSFT(IMCTL(X_E)));
    GDM(GD_I_FINF, " fg");
//    GDM(GD_I_RINF, OMSFT(IMCTL(X_R)));
    GDM(GD_I_FACT, " fc");
//    GDM(GD_I_REL_FILE, "");             // RubyMine goto-view / controller
//    GDM(GD_I_REL_SYM, OMALT(IMCTL(X_HOME)));
    GDM(GD_I_EX_SEL, " ss");
//    GDM(GD_I_COMPLETE, IMCTL(X_SPACE));
//    GDM(GD_I_FIXES, IMALT(X_ENTER));
    GDM(GD_I_QDOC, " lh");
//    GDM(GD_I_GO_L_ED, OMSFT(IMCTL(X_BSPACE)));
    GDM(GD_I_GO_DEF, " fd");
    GDM(GD_I_GO_BACK, IMCTL(X_O));
    GDM(GD_I_GO_FWD, IMCTL(X_I));
    GDM(GD_I_GOTOL, " ga");
    GDM(GD_I_GO_FILE, " ff");
//    GDM(GD_I_NEXT_FN, IMALT(X_DOWN));
//    GDM(GD_I_PREV_FN, IMALT(X_UP));
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
#        endif
    return false;
}

#    endif  // VI
#endif
