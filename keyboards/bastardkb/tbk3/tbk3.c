#include "tbk3.h"

// bool move_is_on = false;  // track if we are in _MOV layer
// bool sym_is_on  = false;  // track if we are in _SYM layer

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void print_default_layer(void);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode > BABBLE_START && keycode < BABBLE_END_RANGE) {
        if (record->event.pressed) {
            babblePaste(keycode);
            return true;
        } else {
            return true;
        }
    }

    switch (keycode) {
        case GD_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        case GD_POLISH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_POLISH);
            }
            return false;

        case GD_MOVE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MOVE);
            }
            return false;

        case GD_SYMBOLS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_SYMBOLS);
            }
            return false;

        case GD_ALT_TAB:
            // https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros#advanced-example
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;

        case GD_INFO:
            if (record->event.pressed) {
                print_default_layer();
                babblePaste(BABL_MODE);
            }
            return false;

        case GD_PL_SZ:
            if (record->event.pressed) {
                SEND_STRING("sz");
            }
            return false;

        case GD_PL_CZ:
            if (record->event.pressed) {
                SEND_STRING("cz");
            }
            return false;

        case GD_PL_RZ:
            if (record->event.pressed) {
                SEND_STRING("rz");
            }
            return false;

        case GD_PL_DZ:
            if (record->event.pressed) {
                SEND_STRING("dz");
            }
            return false;

        default:
            return true;
    }

    return true;
}

unsigned char get_default_layer(void)  {
    if (layer_state_cmp(default_layer_state, _QWERTY)) return _QWERTY;
    if (layer_state_cmp(default_layer_state, _POLISH)) return _POLISH;
    if (layer_state_cmp(default_layer_state, _MOVE)) return _MOVE;
    if (layer_state_cmp(default_layer_state, _SYMBOLS)) return _SYMBOLS;
    return 99;
}

void print_default_layer(void) {
    switch (get_default_layer()) {
        case _QWERTY: SEND_STRING("Qwerty "); break;
        case _POLISH: SEND_STRING("Polish "); break;
        case _MOVE: SEND_STRING("Move "); break;
        case _SYMBOLS: SEND_STRING("Symbols "); break;
        default: SEND_STRING("??? "); break;
    }
}

void keyboard_post_init_user(void) {
  //debug_enable=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

void matrix_scan_user(void) {
  // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 2000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
