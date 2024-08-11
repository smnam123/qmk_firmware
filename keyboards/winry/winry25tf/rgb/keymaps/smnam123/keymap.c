/* Copyright 2022 Nikolay N
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

enum my_layers {
    _BASE,
    _NAVI,
    _SYST,
    _MOBI
};

enum custom_macros {
    MACRO_0 = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Keymap _BASE: Default Layer
    * ,----------------------------------.
    * | Calc |   /  |   ↑  | Vol- | Vol+ |
    * |------+------+------+------+------|
    * |   -  |   7  |   8  |   9  | Mute |
    * |------+------+------+------+------|
    * |   +  |   4  |   5  |   6  | Ent  |
    * |------+------+------+------+------|
    * |  App |   1  |   2  |   3  | RShft|
    * |------+------+------+------+------|
    * | TT(1)|   0  |  00  |   .  | Bksp |
    * `----------------------------------'
    */
    [_BASE] = LAYOUT(
        KC_CALC,   KC_PSLS, KC_PAST, KC_VOLD, KC_VOLU,
        KC_PMNS,   KC_7,    KC_8,    KC_9,    KC_MUTE,
        KC_PPLS,   KC_4,    KC_5,    KC_6,    KC_ENT,
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_RSFT,
        TT(_NAVI), KC_0,    MACRO_0, KC_DOT,  KC_BSPC
    ),

    /* Keymap _NAVI: Navigation Layer
    * ,----------------------------------.
    * |      |  <<  |  >>  |      |      |
    * |------+------+------+------+------|
    * |  >|  |  Hom |   ↑  |  PgU |      |
    * |------+------+------+------+------|
    * |      |   ←  |   ↓  |   →  |      |
    * |------+------+------+------+------|
    * |      |  End |      |  PgD |      |
    * |------+------+------+------+------|
    * | TRNS |  Ins | MO(2)|  Del |      |
    * `----------------------------------'
    */
    [_NAVI] = LAYOUT(
        _______,   KC_MPRV,   KC_MNXT,   _______,   _______,
        KC_MPLY,   KC_HOME,   KC_UP,     KC_PGUP,   _______,
        _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,   _______,
        _______,   KC_END,    _______,   KC_PGDN,   _______,
        KC_TRNS,   KC_INS,    MO(_SYST), KC_DEL,    _______
    ),

    /* Keymap _SYST: System Layer
    * ,----------------------------------.
    * |   ×  |   ×  |   ×  |   ×  | TG(3)|
    * |------+------+------+------+------|
    * |   ×  |   ×  |   ×  |   ×  |   ×  |
    * |------+------+------+------+------|
    * |ClrROM|   ×  | BtLdr|   ×  |   ×  |
    * |------+------+------+------+------|
    * |   ×  |   ×  |   ×  |   ×  |   ×  |
    * |------+------+------+------+------|
    * | TRNS |   ×  | TRNS |   ×  | Sleep|
    * `----------------------------------'
    */
    [_SYST] = LAYOUT(
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   TG(_MOBI),
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        EE_CLR,    XXXXXXX,   QK_BOOT,   XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        KC_TRNS,   XXXXXXX,   KC_TRNS,   XXXXXXX,   KC_SLEP
    ),

    /* Keymap _MOBI: Mobile Layer
    * ,----------------------------------.
    * |  Esc |   G  |   M  |   J  | TRNS |
    * |------+------+------+------+------|
    * |   I  |   Q  |   W  |   E  |   R  |
    * |------+------+------+------+------|
    * | LCtl |   A  |   S  |   D  |   F  |
    * |------+------+------+------+------|
    * |KeyLoc|   Z  |   X  |   C  |   V  |
    * |------+------+------+------+------|
    * | TRNS |  Win | TRNS | LShft|  Spc |
    * `----------------------------------'
    */
    [_MOBI] = LAYOUT(
        KC_ESC,     KC_G,       KC_M,       KC_J,     KC_TRNS,
        KC_I,       KC_Q,       KC_W,       KC_E,     KC_R,
        KC_LCTL,    KC_A,       KC_S,       KC_D,     KC_F,
        QK_LOCK,    KC_Z,       KC_X,       KC_C,     KC_V,
        KC_TRNS,    KC_LGUI,    KC_TRNS,    KC_LSFT,  KC_SPC
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_0:
            if (record->event.pressed) {
                SEND_STRING(
                    //0+0
                    SS_DOWN(X_0) SS_UP(X_0) SS_DOWN(X_0) SS_UP(X_0)
                );
            }
            break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    case _NAVI:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case _SYST:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case _MOBI:
        rgblight_setrgb (0x7A,  0x00, 0xFF);
        break;
    }
  return state;
}