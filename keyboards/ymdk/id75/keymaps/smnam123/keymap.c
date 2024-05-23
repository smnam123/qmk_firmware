/* Copyright (C) 2023 jonylee@hfd
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

/*
 - Each layer gets a name for readability, which is then used in the keymap matrix below.
 - The underscores don't mean anything - you can have a layer called STUFF or any other name.
 - Layer names don't all need to be of the same length, obviously, and you can also skip them
   entirely and just use numbers.   */
enum layer_names {
    _BASE,
    _FUNC,
    _SYST
};

//Macros won't work properly without SAFE_RANGE.
enum custom_macros {
    MACRO_0 = SAFE_RANGE,
    MACRO_1,
    MACRO_2,
    MACRO_3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Keymap _BASE: Base Layer (Default Layer)
    * ,--------------------------------------------------------------------------------------------------------.
    * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |   \  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |  F1  |  F2  |  F3  |   Y  |   U  |   I  |   O  |   P  |  "   |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | Caps |   A  |   S  |   D  |   F  |   G  |  F4  |  F5  |  F6  |   H  |   J  |   K  |   L  |   ;  |RShft |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | LShft|   Z  |   X  |   C  |   V  |   B  |  F7  |  F8  |  F9  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * | LCtl | LGUI | LAlt |   `  | LSpc |  Fn  |  F10 |  F11 |  F12 | PrtSc| RSpc | RAlt |   [  |   ]  |RCtrl |
    * `--------------------------------------------------------------------------------------------------------'
    */
    [_BASE] = LAYOUT_ortho_5x15(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_F1,   KC_F2,   KC_F3,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F4,   KC_F5,   KC_F6,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT,
        KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F7,   KC_F8,   KC_F9,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_GRV,  KC_SPC,  MO(1),   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SPC,  KC_RALT, KC_LBRC, KC_RBRC, KC_RCTL
    ),

    /* Keymap _FUNC: Function Layer
    * ,--------------------------------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |      |      |      |      | Spd- | Spd+ |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      | Mcr3 | Mcr2 | Mcr0 |      |      |      |      |  Br+ |      |      | RTog |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      | Mcr1 |  Fn2 |      |      |      |      |  Br- |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      | Calc |      |KeyLoc|      |      |      |      |      | Mod← | Mod→ |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |  Fn  |      |      |      |      |      |      |      |      |      |
    * `--------------------------------------------------------------------------------------------------------'
    */
    [_FUNC] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPD, RGB_SPI, _______, _______,
        _______, _______, _______, MACRO_3, MACRO_2, MACRO_0, _______, _______, _______, _______, RGB_VAI, _______, _______, RGB_TOG, _______,
        _______, _______, _______, _______, MACRO_1, MO(2),   _______, _______, _______, _______, RGB_VAD, _______, _______, _______, _______,
        _______, _______, _______, KC_CALC, _______, QK_LOCK, _______, _______, _______, _______, _______, RGB_RMOD,RGB_MOD, _______, _______,
        _______, _______, _______, _______, _______, KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Keymap _SYST: System Layer
    * ,--------------------------------------------------------------------------------------------------------.
    * |ClrROM|   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |BtLdr |   ×  |   ×  |   ×  |   ×  |  Fn2 |   ×  |Sleep |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  | NKRO |   ×  |   ×  |   ×  |   ×  |   ×  |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |   ×  |   ×  |   ×  |   ×  |   ×  |  Fn  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |   ×  |
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

//Macros for arcade-style commands
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_0:
            if (record->event.pressed) {
                SEND_STRING(
                    //🡱+🡱+🡳+🡳+D
                    SS_DOWN(X_UP) SS_DELAY(11) SS_UP(X_UP) SS_DELAY(12) SS_DOWN(X_UP) SS_DELAY(11) SS_UP(X_UP) SS_DELAY(13)
                    SS_DOWN(X_DOWN) SS_DELAY(11) SS_UP(X_DOWN) SS_DELAY(13) SS_DOWN(X_DOWN) SS_DELAY(12) SS_UP(X_DOWN) SS_DELAY(11)
                    SS_DOWN(X_D) SS_DELAY(12) SS_UP(X_D) SS_DELAY(5)
                );
            }
            break;

        case MACRO_1:
            if (record->event.pressed) {
                SEND_STRING(
                    //🡱+🡳+⎵
                    SS_DOWN(X_UP) SS_DELAY(11) SS_UP(X_UP) SS_DELAY(13)
                    SS_DOWN(X_DOWN) SS_DELAY(12) SS_UP(X_DOWN) SS_DELAY(11)
                    SS_DOWN(X_SPC) SS_DELAY(11) SS_UP(X_SPC) SS_DELAY(5)
                );
            }
            break;

        case MACRO_2:
            if (record->event.pressed) {
                SEND_STRING(
                    //🡲+🡲+⎵
                    SS_DOWN(X_RIGHT) SS_DELAY(11) SS_UP(X_RIGHT) SS_DELAY(13) SS_DOWN(X_RIGHT) SS_DELAY(12) SS_UP(X_RIGHT) SS_DELAY(13)
                    SS_DOWN(X_SPC) SS_DELAY(11) SS_UP(X_SPC) SS_DELAY(5)
                );   
            }
            break;

        case MACRO_3:
            if (record->event.pressed) {
                SEND_STRING(
                    //🡱+🡱+⎵
                    SS_DOWN(X_UP) SS_DELAY(12) SS_UP(X_UP) SS_DELAY(13) SS_DOWN(X_UP) SS_DELAY(11) SS_UP(X_UP) SS_DELAY(12)
                    SS_DOWN(X_SPC) SS_DELAY(12) SS_UP(X_SPC) SS_DELAY(5)
                );
            }
            break;
    }
    return true;
}