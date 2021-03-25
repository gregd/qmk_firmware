#include "tbk3.h"

// bool move_is_on = false;  // track if we are in _MOV layer
// bool sym_is_on  = false;  // track if we are in _SYM layer

user_config_t user_config;
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void print_default_layer(void);
void toggle_locked_shift(void);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode > GDK_START && keycode < GDK_END_RANGE) {
        if (record->event.pressed) {
            gdkMacro(keycode);
        }
        return true;
    }

    switch (keycode) {
        case GD_POL:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_POLISH);
            }
            return false;

        case GD_NAV:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_NAV);
            }
            return false;

        case GD_SYM:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_SYMBOLS);
            }
            return false;

        case GD_ARROW:
            if (record->event.pressed) {
                SEND_STRING(" -> ");
            }
            return false;

        case GD_FARROW:
            if (record->event.pressed) {
                SEND_STRING(" => ");
            }
            return false;

        case GD_HDIR:
            if (record->event.pressed) {
                SEND_STRING("~/");
            }
            return false;

        case GD_RST:
            if (record->event.pressed) {
                clear_oneshot_locked_mods();
                clear_oneshot_mods();
                clear_keyboard();
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        case GD_INFO:
            if (record->event.pressed) {
                print_default_layer();
                gdkMacro(GD_MODE);
            }
            return false;

        case GD_ALT_TAB:
            // https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros#advanced-example
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(gdk_was_mac() ? KC_LGUI : KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;

        case GD_SHT_TGE:
            if (record->event.pressed) {
                toggle_locked_shift();
            }
            return false;

        case LT(_IDE, KC_ESC):
            if (record->event.pressed) {
                if (MOD_BIT(KC_LSHIFT) & get_oneshot_locked_mods()) {
                    toggle_locked_shift();
                }
            }
            return true;

        // default:
        //     return true;
    }

    return true;
}

void toggle_locked_shift(void) {
    uint8_t sft = MOD_BIT(KC_LSHIFT);
    uint8_t mods = get_oneshot_locked_mods();
    clear_oneshot_mods();
    if (sft & mods) {
        clear_oneshot_locked_mods();
        if (mods & get_mods()) {
            unregister_mods(mods);
        }
    } else {
        set_oneshot_locked_mods(sft);
        if (!(sft & get_mods())) {
            register_mods(sft);
        }
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NAV, KC_SPC):
            return true;
        default:
            return false;
    }
}

unsigned char get_default_layer(void)  {
    if (layer_state_cmp(default_layer_state, _QWERTY)) return _QWERTY;
    if (layer_state_cmp(default_layer_state, _POLISH)) return _POLISH;
    if (layer_state_cmp(default_layer_state, _NAV)) return _NAV;
    if (layer_state_cmp(default_layer_state, _SYMBOLS)) return _SYMBOLS;
    return 99;
}

void print_default_layer(void) {
    switch (get_default_layer()) {
        case _QWERTY: SEND_STRING("Qwerty "); break;
        case _POLISH: SEND_STRING("Polish "); break;
        case _NAV: SEND_STRING("Nav "); break;
        case _SYMBOLS: SEND_STRING("Symbols "); break;
        default: SEND_STRING("??? "); break;
    }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1500) {
      unregister_code(gdk_was_mac() ? KC_LGUI : KC_LALT);
      is_alt_tab_active = false;
    }
  }

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(KC_K, KC_P) {
        set_single_persistent_default_layer(_POLISH);
        SEND_STRING("~P");
    }
    SEQ_TWO_KEYS(KC_K, KC_N) {
        set_single_persistent_default_layer(_NAV);
    }
    SEQ_TWO_KEYS(KC_K, KC_S) {
        set_single_persistent_default_layer(_SYMBOLS);
    }
    SEQ_TWO_KEYS(KC_K, KC_M) {
        gdkMacro(GD_DO_MAC);
        SEND_STRING("~M");
    }
    SEQ_TWO_KEYS(KC_K, KC_L) {
        gdkMacro(GD_DO_LINUX);
        SEND_STRING("~L");
    }
    SEQ_TWO_KEYS(KC_K, KC_V) {
        gdkMacro(GD_DO_VI);
    }
    SEQ_TWO_KEYS(KC_K, KC_T) {
        gdkMacro(GD_DO_READMUX);
    }
  }
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    eeconfig_update_user(user_config.raw);
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    // By default Linux mode is set so set the new mode only in case of Mac mode
    if (user_config.mac_mode) {
        gdk_set_mode(GD_MAC_MODE, false);
    }
}

// // custom tapping term lengths.
// uint16_t get_tapping_term(uint16_t keycode) {
//     switch (keycode) {
//         case LT(_MOV, KC_TAB):
//             return TAPPING_TERM ;
//             break;
//         default:
//         return TAPPING_TERM;
//     }
// }
