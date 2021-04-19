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
    GDM(GD_GO_PARA_START, IMSFT(X_LBRACKET));
    GDM(GD_GO_PARA_END, IMSFT(X_RBRACKET));
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
    GDM(GD_SE_ALL, "ggVG");
    //GDM(GD_FIND, SS_TAP(X_SLASH));
    //GDM(GD_FNEXT, "n");
    //GDM(GD_FPREV, IMSFT(X_N));
    //GDM(GD_REPLACE, ":noh" SS_TAP(X_ENTER));
    //GDM(GD_RUNAPP, ":split");
    //GDM(GD_APP_NEXT, IMCTL(X_DOWN));  // Or Right?
    //GDM(GD_APP_NEXT, IMCTL(X_UP));    // or Left?
    //GDM(GD_APP_SAVE, SS_TAP(X_ESCAPE) ":wa" SS_TAP(X_ENTER));
    //GDM(GD_APP_CLOSE, IMCTL(X_SCOLON) ":qa" SS_TAP(X_ENTER));
#        endif
#        ifdef GD_BROWSER
    GDM(GD_B_NEWT, IMCTL(X_A) "c" IMCTL(X_A) ",");
    GDM(GD_B_CTAB, IMCTL(X_A) "x");
    GDM(GD_B_NTAB, IMCTL(X_A) "n");
    GDM(GD_B_PTAB, IMCTL(X_A) "p");
    GDM(GD_B_URL, IMCTL(X_A) IMCTL(X_A));
    GDM(GD_B_RLOAD, IMCTL(X_A) "[");
    GDM(GD_B_ZOOMI, IMGUI(X_KP_PLUS));
    GDM(GD_B_ZOOMO, IMGUI(X_KP_MINUS));
#        endif

    return false;
}

#    endif  // VI
#endif
