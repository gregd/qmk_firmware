/*  A library to output the right key shortcut in any common app.
Given a global variable gdk_mode to show the environment and a
key that calls the paste macro, do the right type of paste.
Setting the context is done by another macro, or TBD interaction with the host.

Huge thanks to https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
and https://github.com/qmk/qmk_firmware/blob/master/keyboards/planck/keymaps/jeebak/keymap.c
*/

#include QMK_KEYBOARD_H
#include "gdkMacro.h"
#include "tbk3.h"

// small function that we might also want to call from a keymap.

// GLOBAL variable to determine mode.  Sets startup default if no eeppom
uint8_t gdk_mode = 0;
bool gdk_was_mac_mode = false;

// function to tell the user that the mode has changed
__attribute__((weak)) void gdk_led_user(void) {}

uint8_t gdk_get_mode(void) {
    return gdk_mode;
}

void gdk_set_mode(uint8_t id, bool update_eeprom) {
    gdk_mode = id;

    switch (gdk_mode) {
        case GD_MAC_MODE:
            gdk_was_mac_mode = true;
            if (update_eeprom) {
                user_config.mac_mode = true;
                eeconfig_update_user(user_config.raw);
            }
            break;
#    ifdef GD_WINDOWS
        case GD_WINDOWS_MODE:
#    endif
        case GD_LINUX_MODE:
            gdk_was_mac_mode = false;
            if (update_eeprom) {
                user_config.mac_mode = false;
                eeconfig_update_user(user_config.raw);
            }
            break;
        // intentionally ignore other modes here
    }
}

void gdk_clear_mods(void) {
    uint8_t mods = get_oneshot_locked_mods();
    if (mods) {
        clear_oneshot_locked_mods();
        clear_oneshot_mods();
        if (mods & get_mods()) {
            unregister_mods(mods);
        }
    }
}

bool gdk_was_mac(void) {
    return gdk_was_mac_mode;
}

/* this function runs the appropriate gdkMacro, given
the global gdk_mode and a keycode defined in the gdk_keycodes enum.

This could be made faster by splitting into two functions sorted by keycode range
But that makes for a *lot* of ifdefs.
*/
bool gdkMacro(uint16_t keycode) {
    // handle the OS/mode  switching first

#    ifdef GD_VI
    if (keycode == GD_DO_VI) {
        gdk_set_mode(GD_VI_MODE, false);
        gdk_led_user();
        return true;
    }
    if (gdk_mode == GD_VI_MODE) {
        if (gdkMacro_vi(keycode)) {
            return true;
        }
        if (gdk_was_mac()) {
            if (gdkMacro_mac(keycode)) {
                return true;
            }
        } else {
            if (gdkMacro_linux(keycode)) {
                return true;
            }
        }
    }
#    endif

#    ifdef GD_MAC
    if (keycode == GD_DO_MAC) {
        gdk_set_mode(GD_MAC_MODE, true);
        gdk_led_user();
        return true;
    }

    if (gdk_mode == GD_MAC_MODE) {
        if (gdkMacro_mac(keycode)) {
            return true;
        }
    }
#    endif

#    ifdef GD_VI
    if (keycode == GD_DO_VI) {
        gdk_set_mode(GD_VI_MODE, false);
        gdk_led_user();
        return true;
    }
    if (gdk_mode == GD_VI_MODE) {
        if (gdkMacro_vi(keycode)) {
            return true;
        }
    }
#    endif
#    ifdef GD_WINDOWS
    if (keycode == GD_DO_WINDOWS) {
        gdk_set_mode(GD_WINDOWS_MODE, true);
        gdk_led_user();
        return true;
    }
    if (gdk_mode == GD_WINDOWS_MODE) {
        if (gdkMacro_win(keycode)) {
            return true;
        }
    }
#    endif
#    ifdef GD_LINUX
    if (keycode == GD_DO_LINUX) {
        gdk_set_mode(GD_LINUX_MODE, true);
        gdk_led_user();
        return true;
    }
    if (gdk_mode == GD_LINUX_MODE) {
        if (gdkMacro_linux(keycode)) {
            return true;
        }
    }
#    endif
#    ifdef GD_EMACS
    if (keycode == GD_DO_EMACS) {
        gdk_set_mode(GD_EMACS_MODE, false);
        gdk_led_user();
        return true;
    }
    if (gdk_mode == GD_EMACS_MODE) {
        if (gdkMacro_emacs(keycode)) {
            return true;
        }
    }
#    endif
#    ifdef GD_READMUX
    if (keycode == GD_DO_READMUX) {
        gdk_set_mode(GD_READMUX_MODE, false);
        gdk_led_user();
        return true;
    }
    if (gdk_mode == GD_READMUX_MODE) {
        if (gdkMacro_readmux(keycode)) {
            return true;
        }
    }
#    endif

    return false;
}

