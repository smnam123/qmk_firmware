/* Copyright 2021 MT
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

enum layer_names {
    _BASE,
    _FUNC,
    _SYST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Keymap _BASE: Base Layer (Default Layer)
    * ,--------------------------------------------------------------------------------------------------------.
    * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |  F5  |  F10 |  F11 |  F12 |   -  |   =  | PrtSc| Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   7  |  F4  |   Y  |   U  |   I  |   O  |   P  |   [  |  ]   |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | Caps |   A  |   S  |   D  |   F  |   G  |   8  |  F3  |   H  |   J  |   K  |   L  |   ;  |   '  |RShft |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | LShft|   Z  |   X  |   C  |   V  |   B  |   9  |  F2  |   N  |   M  |   ,  |   .  |   /  |   ↑  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | LCtl |  Win | LAlt |   `  | LSpc |  Fn1 |   0  |  F1  | RAlt | RSpc | PgDn | PgUp |   ←  |   ↓  |   →  |
    * `--------------------------------------------------------------------------------------------------------'
    */
    [_BASE] = LAYOUT_ortho_5x15(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_F5,   KC_F10,  KC_F11,  KC_F12,  KC_MINS, KC_EQL,  KC_PSCR, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,    KC_F4,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_8,    KC_F3,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_RSFT,
        KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_9,    KC_F2,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_GRV,  KC_SPC,  MO(1),   KC_0,    KC_F1,   KC_RALT, KC_SPC,  KC_PGDN, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Keymap _FUNC: Function Layer
    * ,--------------------------------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |      |      |   (  |   )  | Spd- | Spd+ |  Ins |  Del |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |   ↑  |      | Home |      |      |      |      |      |      |      | RTog |   \  |   |  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |   ←  |   ↓  |   →  |  End |  Fn2 |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | Prev | Play | Next |      |KeyLoc|      |      |      |      |      |      |      |  Br+ |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |  Fn1 |      |      | RCtl |      |      |      | Mod← |  Br- | Mod→ |
    * `--------------------------------------------------------------------------------------------------------'
    */
    [_FUNC] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, KC_F6,   _______, _______, KC_LPRN, KC_RPRN, RGB_SPD, RGB_SPI, KC_INS,  KC_DEL,
        _______, _______, KC_UP,   _______, KC_HOME, _______, KC_F7,   _______, _______, _______, _______, _______, RGB_TOG, KC_BSLS, KC_PIPE,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  MO(2),   KC_F8,   _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, QK_LOCK, KC_F9,   _______, _______, _______, _______, _______, _______, RGB_VAI, _______,
        _______, _______, _______, _______, _______, KC_TRNS, _______, _______, KC_RCTL, _______, _______, _______, RGB_RMOD,RGB_VAD, RGB_MOD
    ),

    /* Keymap _SYST: System Layer
    * ,--------------------------------------------------------------------------------------------------------.
    * |ClrROM|   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | BtLdr|   ×  |   ×  |   ×  |   ×  |  Fn2 |   ×  | Sleep|   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  | NKRO |   ×  |   ×  |   ×  |   ×  |   ×  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |   ×  |   ×  |   ×  |   ×  |   ×  |  Fn1 |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |
    * `--------------------------------------------------------------------------------------------------------'
    */
    [_SYST] = LAYOUT_ortho_5x15(
        EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};