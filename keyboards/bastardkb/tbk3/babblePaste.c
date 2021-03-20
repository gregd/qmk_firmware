/*  A library to output the right key shortcut in any common app.
Given a global variable babble_mode to show the environment and a
key that calls the paste macro, do the right type of paste.
Setting the context is done by another macro, or TBD interaction with the host.

Huge thanks to https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
and https://github.com/qmk/qmk_firmware/blob/master/keyboards/planck/keymaps/jeebak/keymap.c
*/

#include QMK_KEYBOARD_H
#include "babblePaste.h"
#include "tbk3.h"

// small function that we might also want to call from a keymap.

// GLOBAL variable to determine mode.  Sets startup default if no eeppom
uint8_t babble_mode = 0;
bool babble_was_mac_mode = false;

// function to tell the user that the mode has changed
__attribute__((weak)) void babble_led_user(void) {}

void set_babble_mode(uint8_t id, bool update_eeprom) {
    babble_mode = id;

    switch (babble_mode) {
        case BABL_MAC_MODE:
            babble_was_mac_mode = true;
            if (update_eeprom) {
                user_config.mac_mode = true;
                eeconfig_update_user(user_config.raw);
            }
            break;
#    ifdef BABL_WINDOWS
        case BABL_WINDOWS_MODE:
#    endif
        case BABL_LINUX_MODE:
            babble_was_mac_mode = false;
            if (update_eeprom) {
                user_config.mac_mode = false;
                eeconfig_update_user(user_config.raw);
            }
            break;
        // intentionally ignore other modes here
    }
}

void babble_clear_mods(void) {
    uint8_t mods = get_mods();
    if (get_oneshot_mods() && !has_oneshot_mods_timed_out()) {
        clear_oneshot_mods();
    }
    if (get_oneshot_locked_mods()) {
        clear_oneshot_locked_mods();
    }
    clear_mods();
    unregister_mods(mods);
}

bool babble_was_mac(void) {
    return babble_was_mac_mode;
}

/* this function runs the appropriate babblepaste macro, given
the global babble_mode and a keycode defined in the babble_keycodes enum.

This could be made faster by splitting into two functions sorted by keycode range
But that makes for a *lot* of ifdefs.
*/
bool babblePaste(uint16_t keycode) {
    // handle the OS/mode  switching first

#    ifdef BABL_MAC
    if (keycode == BABL_DO_MAC) {
        set_babble_mode(BABL_MAC_MODE, true);
        babble_led_user();
        return true;
    }

    if (babble_mode == BABL_MAC_MODE) {
        babblePaste_mac(keycode);
    }
#    endif

#    ifdef BABL_VI
    if (keycode == BABL_DO_VI) {
        set_babble_mode(BABL_VI_MODE, true);
        babble_led_user();
        return true;
    }
    if (babble_mode == BABL_VI_MODE) {
        babblePaste_vi(keycode);
    }
#    endif
#    ifdef BABL_WINDOWS
    if (keycode == BABL_DO_WINDOWS) {
        set_babble_mode(BABL_WINDOWS_MODE, true);
        babble_led_user();
        return true;
    }
    if (babble_mode == BABL_WINDOWS_MODE) {
        babblePaste_win(keycode);
    }
#    endif
#    ifdef BABL_LINUX
    if (keycode == BABL_DO_LINUX) {
        set_babble_mode(BABL_LINUX_MODE, true);
        babble_led_user();
        return true;
    }
    if (babble_mode == BABL_LINUX_MODE) {
        babblePaste_linux(keycode);
    }
#    endif
#    ifdef BABL_EMACS
    if (keycode == BABL_DO_EMACS) {
        set_babble_mode(BABL_EMACS_MODE, true);
        babble_led_user();
        return true;
    }
    if (babble_mode == BABL_EMACS_MODE) {
        babblePaste_emacs(keycode);
    }
#    endif
#    ifdef BABL_READMUX
    if (keycode == BABL_DO_READMUX) {
        set_babble_mode(BABL_READMUX_MODE, true);
        babble_led_user();
        return true;
    }
    if (babble_mode == BABL_READMUX_MODE) {
        babblePaste_readmux(keycode);
    }
#    endif

    return false;
}

