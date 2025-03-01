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
//#define MASTER_RIGHT
#define USE_I2C
#define EE_HANDS

#define TAPPING_TERM 190
#define PERMISSIVE_HOLD
#define RETRO_TAPPING_PER_KEY

#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 3000  /* Time (in ms) before the one shot key is released */

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 1000

#define AUTO_SHIFT_TIMEOUT 190
#define AUTO_SHIFT_REPEAT
//#define NO_AUTO_SHIFT_SPECIAL
//#define NO_AUTO_SHIFT_NUMERIC

#define USE_GDK_MACRO
//#define GD_WINDOWS
#define GD_MAC
#define GD_LINUX

//// These enable subsets of gdk macros. Disable options to save space
#define GD_MOVE // Uncomment to add basic cursor movement
#define GD_OSKEYS // This adds Cut, paste, window movement and common OS shortcuts
#define GD_BROWSER // Browser shortcuts
#define GD_IDE // IDE shortcuts

//// What Browser shortcuts?
#define GD_B_CHROME // Chrome browser, Google apps
//#define GD_B_MS
//#define GD_B_SAFARI // Safari, Apple defaults.
