/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include "config_common.h"
#define VENDOR_ID 0xA8F8
#define PRODUCT_ID 0x1828
#define DEVICE_VER 0x0001
#define MANUFACTURER Bastard Keyboards
#define PRODUCT The Bastard Keyboard

#define MATRIX_ROWS 10
#define MATRIX_COLS 6
#define DIODE_DIRECTION ROW2COL
#define MATRIX_ROW_PINS { D7, B5, F7, F6, B6 }
#define MATRIX_COL_PINS { B4, E6, C6, B1, B3, B2 }

#define DEBOUNCE 5
#define MASTER_RIGHT
#define USE_I2C

#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#define USE_BABBLEPASTE
#define BABL_WINDOWS
#define BABL_MAC
#define BABL_LINUX
#define BABL_READMUX
#define BABL_VI
//#define BABL_EMACS

//// These enable subsets of babble macros. Disable options to save space
#define BABL_MOVE // Uncomment to add basic cursor movement
#define BABL_OSKEYS // This adds Cut, paste, window movement and common OS shortcuts
#define BABL_BROWSER // Browser shortcuts

//// What Browser shortcuts?
#define BABL_BROWSER_CHROME // Chrome browser, Google apps
//#define BABL_BROWSER_MS
//#define BABL_BROWSER_SAFARI // Safari, Apple defaults.

//// applications vary even more between OSes. We'll do our best.
#define BABL_APP
// To enable specific App options.
//#define BABL_APP_CELLS // spreadsheets and tables
#define BABL_APP_EDITOR // Fancy editor commands
#define BABL_APP_WINDOWSPLITTING // splitting frames & windows

//// What App keybinding is assumed?
//#define BABL_APP_GOOGLE // Google office
//#define BABL_APP_MSOFFICE // MS office
//#define BABL_APP_APPLE // Apple office
//#define BABL_APP_SUBLIME
