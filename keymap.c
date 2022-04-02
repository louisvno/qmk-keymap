/* Copyright 2020 Drew Smathers
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

// Keyboard Layers
enum layer_names {
    _QW,
    _FN,
};

// Some short-cut aliases
#define Z_LALT LALT_T(KC_ESC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_ESC,  KC_1,     KC_2,    KC_3,       KC_4,    KC_5,    XXXXXXX, XXXXXXX, XXXXXXX, KC_6,   KC_7,     KC_8,     KC_9,    KC_0,    KC_BSLS, \
    KC_TAB,  KC_Q,     KC_W,    KC_E,       KC_R,    KC_T,    XXXXXXX, XXXXXXX, XXXXXXX, KC_Y,   KC_U,     KC_I,     KC_O,    KC_P,    KC_QUOT, \
    Z_LALT,  KC_A,     KC_S,    KC_D,       KC_F,    KC_G,    XXXXXXX, KC_UP,   XXXXXXX, KC_H,   KC_J,     KC_K,     KC_L,    KC_SCLN, KC_RALT,  \
    KC_LSFT, KC_Z,     KC_X,    KC_C,       KC_V,    KC_B,    KC_LEFT, KC_DOWN, KC_RGHT, KC_N,   KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, TT(_FN), XXXXXXX, XXXXXXX,   KC_EQL,  KC_BSPC, KC_DEL,  XXXXXXX, KC_ENT,  KC_SPC, KC_MINUS, KC_GRAVE, KC_LBRC, KC_RBRC, XXXXXXX \
 ),

 [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, RESET,   XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,   _______, XXXXXXX, KC_HOME, KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, TT(_FN), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
 ),
};
