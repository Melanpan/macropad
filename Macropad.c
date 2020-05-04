/* Copyright 2020 Melan
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

#include "Macropad.h"
#include "rgb.h"
#include "rgblight.h"
#include "rgblight_list.h"
// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.


void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up    
    
    // Disable red leds
    DDRD &= ~(1<<5);
    PORTD &= ~(1<<5);

    DDRB &= ~(1<<0);
    PORTB &= ~(1<<0);

    // Enable RGB
    rgblight_enable();
    rgblight_sethsv (  0,   0, 255);
    rgblight_mode(0);

    // Set unicode mode to windows
    set_unicode_input_mode(UC_WINC);

    matrix_init_user();
}

void matrix_init_user(void) { // Runs boot tasks for keyboard
    set_unicode_input_mode(UC_WINC);
};

void eeconfig_init_user(void) {
    set_unicode_input_mode(UC_WINC);
}

// void matrix_scan_kb(void) {
//     // put your looping keyboard code here
//     // runs every cycle (a lot)

//     matrix_scan_user();
// }

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // put your per-action keyboard code here
    // runs for every action, just before processing by the firmware

    return process_record_user(keycode, record);
}

bool led_update_kb(led_t led_state) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

    return led_update_user(led_state);
}

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case 0: // First Layer
            rgblight_sethsv (128, 255, 128); // Set leds to Cyan
            break;
        case 1: // Second Layer
            rgblight_sethsv( 191, 255, 255); // Set leds to Blue
            break;

    }
};