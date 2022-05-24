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

enum my_keycodes {
  CUSTOM_COPY = SAFE_RANGE,
  CUSTOM_PASTE
};

// Keyboard Layers
enum layer_names {
    _QW,
    _FN,
};
enum {
    TD_FAST_F12 = 0,
};
// Some short-cut aliases
#define Z_LALT LALT_T(KC_ESC)
#define RGBLIGHT_SLEEP

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_FAST_F12] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_F12),
};
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 2, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 4, HSV_RED}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer    // Overrides other layers
);

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QW));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN));
    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_ESC,  KC_1,     KC_2,    KC_3,       KC_4,    KC_5,    XXXXXXX, XXXXXXX, XXXXXXX, KC_6,   KC_7,     KC_8,     KC_9,    KC_0,    TD(TD_FAST_F12), \
    KC_TAB,  KC_Q,     KC_W,    KC_E,       KC_R,    KC_T,    XXXXXXX, XXXXXXX, XXXXXXX, KC_Y,   KC_U,     KC_I,     KC_O,    KC_P,    KC_QUOT, \
    Z_LALT,  KC_A,     KC_S,    KC_D,       KC_F,    KC_G,    XXXXXXX, XXXXXXX, XXXXXXX, KC_H,   KC_J,     KC_K,     KC_L,    KC_SCLN, KC_RALT,  \
    KC_LSFT, KC_Z,     KC_X,    KC_C,       KC_V,    KC_B,    XXXXXXX, XXXXXXX, XXXXXXX, KC_N,   KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, XXXXXXX, CUSTOM_COPY, CUSTOM_PASTE,     TG(_FN), KC_BSPC, KC_DEL,  KC_EQL, KC_ENT,  KC_SPC, KC_MINUS, KC_GRAVE, KC_LBRC, KC_RBRC, KC_PSCR \
 ),

 [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, RESET,   XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_END, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, _______, _______, TG(_FN), _______, _______, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
 ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CUSTOM_COPY:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_C);
      } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_C);
      }
      return true; 

    case CUSTOM_PASTE:
      if (record->event.pressed) { 
        register_code(KC_LCTL);
        register_code(KC_V);
      } else {
         unregister_code(KC_LCTL);
         unregister_code(KC_V);
      }
      return true; 
    default:
      return true; 
  }
}