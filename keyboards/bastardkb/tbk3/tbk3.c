#include "tbk3.h"

user_config_t user_config;

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_caps_on = false;

void print_default_layer(void);
void toggle_locked_shift(void);
unsigned char get_default_layer(void);
bool process_auto_caps(uint16_t keycode, keyrecord_t *record);
bool process_select_word(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //uprintf("process kc: 0x%04X, pressed: %b, count: %u, time: %u, interrupt: %b\n", keycode, record->event.pressed, record->tap.count, record->event.time, record->tap.interrupted);

    if (keycode > GDK_START && keycode < GDK_END_RANGE) {
        if (record->event.pressed) {
            gdkMacro(keycode);
        }
        return true;
    }

    if (!process_auto_caps(keycode, record)) {
        return false;
    }

    if (!process_select_word(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case GD_TGL_POL:
            if (record->event.pressed) {
                if (get_default_layer() != _POLISH) {
                    default_layer_set(1UL << _POLISH);
//                    tap_code(KC_P);
//                    wait_ms(250);
//                    tap_code(KC_BSPACE);
                }
            }
            return false;

        case GD_TGL_FSPC:
            if (record->event.pressed) {
                if (get_default_layer() != _FAST_SPC) {
                    default_layer_set(1UL << _FAST_SPC);
                }
            }
            return false;

        case GD_TGL_NAV:
            if (record->event.pressed) {
                if (get_default_layer() == _NAV) {
                    default_layer_set(1UL << _QWERTY);
                } else {
                    default_layer_set(1UL << _NAV);
                }
            }
            return false;

        case GD_TGL_VIM:
            if (record->event.pressed) {
                if (gdk_get_mode() != GD_VI_MODE) {
                    gdk_set_mode(GD_VI_MODE, false);
                }
            }
            return false;

        case GD_M_MAC:
            if (record->event.pressed) {
                gdkMacro(GD_DO_MAC);
            }
            return false;

        case GD_M_LINUX:
            if (record->event.pressed) {
                gdkMacro(GD_DO_LINUX);
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

        case GD_EQSP:
            if (record->event.pressed) {
                SEND_STRING(" = ");
            }
            return false;

        case GD_LPRN_PIPE:
            if (record->event.pressed) {
                SEND_STRING("(|");
            }
            return false;

        case GD_CN_QU:
            if (record->event.pressed) {
                SEND_STRING(":?");
            }
            return false;

        case GD_TMUX:
            if (record->event.pressed) {
                SEND_STRING(IMCTL(X_A));
            }
            return false;

        case GD_XCOPY:
            if (record->event.pressed) {
                SEND_STRING(OMSFT(IMCTL(X_C)));
            }
            return false;

        case GD_XPASTE:
            if (record->event.pressed) {
                SEND_STRING(OMSFT(IMCTL(X_V)));
            }
            return false;

        case GD_TGE_SHT:
            if (record->event.pressed) {
                toggle_locked_shift();
            }
            return false;

        case LT(_NAV, KC_ESC):
            if (record->event.pressed && record->tap.count == 1) {
                if (MOD_BIT(KC_LSHIFT) & get_oneshot_locked_mods()) {
                    toggle_locked_shift();
                }
            }
            break;

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

        case GD_INFO:
            if (record->event.pressed) {
                print_default_layer();
                gdkMacro(GD_MODE);
            }
            return false;

        case GD_RST:
            if (record->event.pressed) {
                clear_oneshot_locked_mods();
                clear_oneshot_mods();
                clear_keyboard();
                default_layer_set(1UL << _QWERTY);
                if (gdk_was_mac()) {
                    gdk_set_mode(GD_MAC_MODE, false);
                } else {
                    gdk_set_mode(GD_LINUX_MODE, false);
                }
            }
            return false;

        default:
            break;
    }

    // return true means process the keycodes normally
    return true;
}

bool process_auto_caps(uint16_t keycode, keyrecord_t *record) {
    if (keycode == GD_CAPS) {
        if (record->event.pressed) {
            is_caps_on = !is_caps_on;
            if ((is_caps_on && !host_keyboard_led_state().caps_lock) || (
                !is_caps_on && host_keyboard_led_state().caps_lock)) {
                tap_code(KC_CAPS);
            }
        }
        return false;
    }
    if (is_caps_on && record->event.pressed) {
        // Get the base keycode of a mod or layer tap key
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                // Earlier return if this has not been considered tapped yet
                if (record->tap.count == 0) return true;
                keycode = keycode & 0xFF;
                break;
            default:
                break;
        }
        switch (keycode) {
            case KC_A ... KC_Z:
            case KC_MINS:
            case KC_BSPC:
            case KC_UNDS:
                break;
            default:
                is_caps_on = false;
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS);
                }
                break;
        }
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

unsigned char get_default_layer(void)  {
    if (layer_state_cmp(default_layer_state, _QWERTY)) return _QWERTY;
    if (layer_state_cmp(default_layer_state, _POLISH)) return _POLISH;
    if (layer_state_cmp(default_layer_state, _FAST_SPC)) return _FAST_SPC;
    if (layer_state_cmp(default_layer_state, _NAV)) return _NAV;
    return 255;
}

void print_default_layer(void) {
    switch (get_default_layer()) {
        case _QWERTY: SEND_STRING("Qwerty"); break;
        case _POLISH: SEND_STRING("Pol"); break;
        case _FAST_SPC: SEND_STRING("FastSpc"); break;
        case _NAV: SEND_STRING("Nav"); break;
        default: SEND_STRING("??? "); break;
    }
}

//LEADER_EXTERNS();

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1300) {
            unregister_code(gdk_was_mac() ? KC_LGUI : KC_LALT);
            is_alt_tab_active = false;
        }
    }

//  LEADER_DICTIONARY() {
//    leading = false;
//    leader_end();
//
//    SEQ_TWO_KEYS(KC_S, KC_G) {
//        SEND_STRING("Grzegorz Daniluk");
//    }
//  }
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    eeconfig_update_user(user_config.raw);
}

void keyboard_post_init_user(void) {
//    debug_enable = true;
//    debug_matrix=true;
//    debug_keyboard=true;
    user_config.raw = eeconfig_read_user();
    // By default Linux mode is set so set the new mode only in case of Mac mode
    if (user_config.mac_mode) {
        gdk_set_mode(GD_MAC_MODE, false);
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_SYMBOLS, KC_SPC):
            return true;
        default:
            return false;
    }
}

//void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//    uprintf("post    kc: 0x%04X, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
//}

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

// https://github.com/rafaelromao/keyboards/blob/main/src/qmk/users/rafaelromao/features/select_word.c
// https://github.com/getreuer/qmk-keymap/blob/main/features/select_word.c

void clear_locked_and_oneshot_mods(void) {
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();
    uint8_t oneshot_mods = get_oneshot_mods();
    if (oneshot_locked_mods || oneshot_mods) {
        clear_oneshot_mods();
        clear_oneshot_locked_mods();
        unregister_mods(MOD_LSFT);
        unregister_mods(MOD_LCTL);
        unregister_mods(MOD_LALT);
        unregister_mods(MOD_RALT);
        unregister_mods(MOD_LGUI);
    }
}

typedef enum {
    STATE_NONE,
    STATE_LINE_SELECTED,
    STATE_WORD_SELECTED,
    STATE_WORD,
    STATE_FIRST_LINE,
    STATE_LINE
} select_word_state_t;

typedef struct {
    select_word_state_t state;
} select_word_t;

select_word_t select_word = {
    .state = STATE_NONE
};

bool process_select_word(uint16_t keycode, keyrecord_t* record) {
    if (keycode == GD_SE_WORD && record->event.pressed) {
        bool isShifted = get_mods() & MOD_MASK_SHIFT ||
                         get_oneshot_mods() & MOD_MASK_SHIFT ||
                         get_oneshot_locked_mods() & MOD_MASK_SHIFT;
        if (isShifted || select_word.state == STATE_LINE_SELECTED) {
            // Select Line
            clear_mods();
            clear_locked_and_oneshot_mods();
            if (select_word.state == STATE_NONE) {
                tap_code(KC_HOME);
                register_mods(MOD_LSFT);
                tap_code(KC_END);
                select_word.state = STATE_FIRST_LINE;
            } else {
                register_mods(MOD_LSFT);
                register_code(KC_DOWN);
                select_word.state = STATE_LINE;
            }
        } else {
            // Select Word
            if (gdk_was_mac()) {
                register_code(KC_LALT);
            } else {
                register_code(KC_LCTL);
            }
            if (select_word.state == STATE_NONE) {
                tap_code(KC_RIGHT);
                tap_code(KC_LEFT);
            }
            register_mods(MOD_LSFT);
            register_code(KC_RGHT);
            select_word.state = STATE_WORD;
        }
        return false;
    }

    switch (select_word.state) {
        case STATE_WORD:
            unregister_code(KC_RGHT);
            unregister_mods(MOD_LSFT);
            if (gdk_was_mac()) {
                unregister_code(KC_LALT);
            } else {
                unregister_code(KC_LCTL);
            }
            select_word.state = STATE_WORD_SELECTED;
            break;

        case STATE_FIRST_LINE:
            unregister_mods(MOD_LSFT);
            select_word.state = STATE_LINE_SELECTED;
            break;

        case STATE_LINE:
            unregister_mods(MOD_LSFT);
            unregister_code(KC_DOWN);
            select_word.state = STATE_LINE_SELECTED;
            break;

        case STATE_WORD_SELECTED:
        case STATE_LINE_SELECTED:
            if (keycode != GD_SE_WORD && record->event.pressed) {
                unregister_mods(MOD_LSFT);
                tap_code(KC_RGHT);
                select_word.state = STATE_NONE;
                return true;
            }
        default:
            select_word.state = STATE_NONE;
    }

    return true;
}
