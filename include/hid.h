/*
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include "common.h"

//--------------------------------------------------------------------+
// Mouse keys configuration (compile-time, see MOUSE_KEYS.md)
//--------------------------------------------------------------------+

#ifndef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 10 // ms before movement starts after a key press
#endif
#ifndef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 20 // ms between movement steps
#endif
#ifndef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 2 // base step size in counts
#endif
#ifndef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 10 // maximum speed multiplier
#endif
#ifndef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 40 // movement steps until maximum speed
#endif
#ifndef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 10 // ms before scrolling starts after a key press
#endif
#ifndef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 50 // ms between scroll steps
#endif

//--------------------------------------------------------------------+
// HID API
//--------------------------------------------------------------------+

/**
 * @brief Initialize the HID module
 *
 * @return None
 */
void hid_init(void);

/**
 * @brief Add a keycode to the appropriate HID report
 *
 * @param keycode Keycode to add
 *
 * @return None
 */
void hid_keycode_add(uint8_t keycode);

/**
 * @brief Remove a keycode from the appropriate HID report
 *
 * @param keycode Keycode to remove
 *
 * @return None
 */
void hid_keycode_remove(uint8_t keycode);

/**
 * @brief Send all HID reports
 *
 * This function will block until the device is ready to send the reports.
 *
 * @return None
 */
void hid_send_reports(void);

/**
 * @brief Update and send mouse movement reports
 *
 * Generates cursor and scroll deltas for the currently held mouse movement
 * keycodes (SP_MOUSE_UP..SP_MOUSE_WHEEL_DOWN) and sends the mouse report if
 * it changed. Call this once per main loop iteration.
 *
 * @return None
 */
void hid_mouse_task(void);
