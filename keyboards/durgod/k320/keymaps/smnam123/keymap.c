/* Copyright 2021 Maxime Coirault, Don Kjer, Tyler Tidman
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

// Layer shorthand
enum _layer {
    _BL,
    _FL,
    _SL,
    _ML
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BASE: Base Layer (Default Layer)
   * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
   * │Esc│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PSc│Slk│Pse│
   * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
   * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │Ins│Hom│PgU│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
   * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │Del│End│PgD│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬────┤ └───┴───┴───┘
   * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ # │Entr│
   * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤     ┌───┐
   * │Shft│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │     │ ↑ │
   * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐
   * │Ctrl│GUI │Alt │                        │ Alt│Func│ App│Ctrl│ │ ← │ ↓ │ → │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘
   */
  [_BL] = LAYOUT_tkl_ansi( /* Base Layer */
      KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_PSCR, KC_SCRL, KC_PAUS,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,
      KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FL), KC_APP,  KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
  ),
  /* Keymap _FN: Function Layer
   * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
   * │   │   │Ply│Stp│Prv│Nxt│ │Mut│Vo+│Vo-│   │ │   │   │   │   │ │   │   │   │
   * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │ │   │   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
   * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │ │   │   │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬────┤ └───┴───┴───┘
   * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │
   * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤     ┌───┐
   * │    │   │   │   │   │   │   │   │   │   │   │   │          │     │   │
   * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐
   * │    │Lock│    │                        │    │Func│ Sys│    │ │   │   │   │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘
   */
  [_FL] = LAYOUT_tkl_ansi( /* Function Layer */
      _______,          KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, TG(_ML),    _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_LOCK,          _______,             _______,
      _______, GUI_TOG, _______,                            _______,                            _______, KC_TRNS, MO(_SL), _______,    _______, _______, _______
  ),
  [_SL] = LAYOUT_tkl_ansi( /* System Layer */
      EE_CLR,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
      QK_BOOT, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
      XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,             XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, KC_TRNS, KC_TRNS, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_ML] = LAYOUT_tkl_ansi(  /* MR Layer */
      _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_UP,  KC_RGHT,  _______,    _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, _______,
      _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,             _______,
      _______, _______, _______,                            _______,                            _______, KC_TRNS, KC_TRNS, _______,    _______, _______, _______
  )
};


// Make use of mr led as layer indicator
void layer_indicator_led(void) {
    if(layer_state_is(_ML)){
        writePinHigh(LED_MR_LOCK_PIN);
    }
    else{
        writePinLow(LED_MR_LOCK_PIN);
    }
}

// When toggle key for mr layer (_ML) is pressed, checks for which layer is on, and turns mr led on if it's _ML
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG(_ML):
            if (!record->event.pressed) {  // When release after keypress
                layer_indicator_led(); // Toggle MR layer indicator
            }
            break;
        case QK_BOOT:
            if (record->event.pressed) { // When keypress
                on_all_leds(); // Flash LEDs to indicate bootloader mode is enabled.
            }
            break; 
        default:
            return true;           
    } 
    return true;
}