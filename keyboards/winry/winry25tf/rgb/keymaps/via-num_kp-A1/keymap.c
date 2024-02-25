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
    LY0,
    LY1,
    LY2,
    LY3,
    LY4,
    LY5,
    LY6,
    LY7,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LY0] = LAYOUT(
        KC_ESC,  KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_I,    KC_HOME, KC_UP,   KC_PGUP, KC_BSPC,
        KC_K,    KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT,
        KC_COMM, KC_END,  KC_EQL,  KC_PGDN, KC_ENT,
        KC_P0,   MO(LY1), KC_MINS, KC_DEL,  KC_BSLS
    ),
    [LY1] = LAYOUT(
        MO(LY2),    _______,    KC_F5,      _______,  TG(LY3),
        RGB_VAI,    KC_MPRV,    KC_VOLU,    KC_MNXT,  _______,
        RGB_VAD,    KC_MPLY,    KC_VOLD,    KC_MUTE,  _______,
        KC_NUM,     TG(KC_A),   _______,    _______,  KC_F10,
        _______,    _______,    _______,    RGB_SPD,  RGB_SPI
    ),
    [LY2] = LAYOUT(
        _______,   KC_SLEP,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   QK_BOOT,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______
    ),
    [LY3] = LAYOUT(
        KC_ESC,    KC_ENT,    KC_SCLN,   KC_RALT,   _______,
        KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,
        KC_H,      KC_J,      KC_K,      KC_L,      KC_BSPC,
        KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_B,
        KC_RSFT,   _______,   KC_SPC,    KC_SLSH,   KC_QUOT
    ),
    [LY4] = LAYOUT(
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______
    ),
    [LY5] = LAYOUT(
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______
    ),
    [LY6] = LAYOUT(
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______
    ),
    [LY7] = LAYOUT(
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______
    )
};

