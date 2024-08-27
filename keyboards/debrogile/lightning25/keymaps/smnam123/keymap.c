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

#define RGBLIGHT_LAYERS

enum my_layers {
    _BASE,
    _NAVI,
    _SYST,
    _MOBI
};

enum custom_macros {
    MACRO_0 = SAFE_RANGE
};

enum rgb_layer_index {
    L_1,
    L_2,
    L_3,
    L_4,
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
    * |  App |   1  |   2  |   3  | TT(1)|
    * |------+------+------+------+------|
    * | TT(1)|   0  |  00  |   .  | Bksp |
    * `----------------------------------'
    */
    [_BASE] = LAYOUT(
        KC_CALC,   KC_PSLS, KC_PAST, KC_VOLD, KC_VOLU,
        KC_PMNS,   KC_7,    KC_8,    KC_9,    KC_MUTE,
        KC_PPLS,   KC_4,    KC_5,    KC_6,    KC_ENT,
        KC_ESC,    KC_1,    KC_2,    KC_3,    TT(_NAVI),
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
    * |      |  End |      |  PgD | TRNS |
    * |------+------+------+------+------|
    * | TRNS |  Ins | MO(2)|  Del |      |
    * `----------------------------------'
    */
    [_NAVI] = LAYOUT(
        _______,   KC_MPRV,   KC_MNXT,   _______,   _______,
        KC_MPLY,   KC_HOME,   KC_UP,     KC_PGUP,   _______,
        _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,   _______,
        _______,   KC_END,    _______,   KC_PGDN,   KC_TRNS,
        KC_TRNS,   KC_INS,    MO(_SYST), KC_DEL,    _______
    ),

    /* Keymap _SYST: System Layer
    * ,----------------------------------.
    * |   ×  |   ×  | NKRO |   ×  | TG(3)|
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
        XXXXXXX,   XXXXXXX,   NK_TOGG,   XXXXXXX,   TG(_MOBI),
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


const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 4, 1, HSV_TEAL},
    {11, 1, HSV_TEAL},
    {15, 1, HSV_TEAL},
    {16, 1, HSV_TEAL}, //bottom left led
    {17, 1, HSV_TEAL},
    {25, 1, HSV_TEAL}, //down glow from here
    {26, 1, HSV_TEAL},
    {27, 1, HSV_TEAL},
    {28, 1, HSV_TEAL},
    {29, 1, HSV_TEAL},
    {30, 1, HSV_TEAL},
    {31, 1, HSV_TEAL},
    {32, 1, HSV_TEAL}                                         
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, HSV_RED},
    { 1, 1, HSV_RED},
    { 5, 1, HSV_RED},
    { 7, 1, HSV_RED},
    {11, 1, HSV_RED},
    {16, 1, HSV_RED}, //bottom left led    
    {25, 1, HSV_RED}, //down glow from here
    {26, 1, HSV_RED},
    {27, 1, HSV_RED},
    {28, 1, HSV_RED},
    {29, 1, HSV_RED},
    {30, 1, HSV_RED},
    {31, 1, HSV_RED},
    {32, 1, HSV_RED}  
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, HSV_CHARTREUSE},
    {12, 1, HSV_CHARTREUSE},
    {14, 1, HSV_CHARTREUSE},
    {16, 1, HSV_CHARTREUSE}, //bottom left led
    {18, 1, HSV_CHARTREUSE},
    {24, 1, HSV_CHARTREUSE},
    {25, 1, HSV_CHARTREUSE}, //down glow from here
    {26, 1, HSV_CHARTREUSE},
    {27, 1, HSV_CHARTREUSE},
    {28, 1, HSV_CHARTREUSE},
    {29, 1, HSV_CHARTREUSE},
    {30, 1, HSV_CHARTREUSE},
    {31, 1, HSV_CHARTREUSE},
    {32, 1, HSV_CHARTREUSE} 
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, HSV_PURPLE},
    { 1, 1, HSV_PURPLE},
    { 5, 1, HSV_PURPLE},
    { 7, 1, HSV_PURPLE},
    {12, 1, HSV_PURPLE},
    {16, 1, HSV_PURPLE}, //bottom left led
    {25, 1, HSV_PURPLE}, //down glow from here
    {26, 1, HSV_PURPLE},
    {27, 1, HSV_PURPLE},
    {28, 1, HSV_PURPLE},
    {29, 1, HSV_PURPLE},
    {30, 1, HSV_PURPLE},
    {31, 1, HSV_PURPLE},
    {32, 1, HSV_PURPLE} 
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    [L_1]=my_layer1_layer,
    [L_2]=my_layer2_layer,
    [L_3]=my_layer3_layer,
    [L_4]=my_layer4_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(L_1, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(L_2, layer_state_cmp(state, _NAVI));
    rgblight_set_layer_state(L_3, layer_state_cmp(state, _SYST));
    rgblight_set_layer_state(L_4, layer_state_cmp(state, _MOBI));
    return state;
}
