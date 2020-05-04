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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LAY2
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    TOMORI,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        TO(_LAY2),  KC_Q,    KC_VOLD,    KC_VOLU,    KC_MUTE,    
        TOMORI,    KC_MSTP,    KC_MPRV,   KC_MNXT, KC_MPLY
    ),

    
    [_LAY2] = LAYOUT(
       TO(_BASE),  KC_Q,    KC_W,    KC_E,    KC_R,    
       LCTL(KC_LSFT),    KC_Y,    KC_U,    KC_I,    KC_O
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TOMORI:
            if (record->event.pressed) {
                send_unicode_hex_string("53CB 5229 5948 7DD2"); // Write 友利奈緒(Tomori Nao)
            } else {
            }
            break;
    }
    return true;
}
