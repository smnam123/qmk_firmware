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
    BASE,
    FUNC,
    SYST,
    MOBI
};

enum rgb_layer_index {
    //L_1,
    L_2,
    L_3,
    L_4,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Keymap BASE: Default Layer
    * ,----------------------------------.
    * |   /  |   *  |   -  | Vol- | Vol+ |
    * |------+------+------+------+------|
    * |   7  |   8  |   9  |   +  | Home |
    * |------+------+------+------+------|
    * |   4  |   5  |   6  | PgUp | End  |
    * |------+------+------+------+------|
    * |   1  |   2  |   3  |   ↑  | PgDn |
    * |------+------+------+------+------|
    * |   0  | MO(1)|   ←  |   ↓  |   →  |
    * `----------------------------------'
    */
    [BASE] = LAYOUT(
        KC_PSLS,  KC_PAST,  KC_PMNS, KC_VOLD,  KC_VOLU,
        KC_7,     KC_8,     KC_9,    KC_PPLS,  KC_HOME,
        KC_4,     KC_5,     KC_6,    KC_PGUP,  KC_END,
        KC_1,     KC_2,     KC_3,    KC_UP,    KC_PGDN,
        KC_0,     MO(FUNC), KC_LEFT, KC_DOWN,  KC_RGHT
    ),

    /* Keymap FUNC: Function Layer
    * ,----------------------------------.
    * |      | Mute | Play |  |<  |  >|  |
    * |------+------+------+------+------|
    * |      |      | Bksp | Entr | RGB- |
    * |------+------+------+------+------|
    * |      |  Esc |  Ins |      | RGB+ |
    * |------+------+------+------+------|
    * |      |      |  Del |      | RTOG |
    * |------+------+------+------+------|
    * |      | TRNS | MO(2)|      |      |
    * `----------------------------------'
    */
    [FUNC] = LAYOUT(
        _______,   KC_MUTE,   KC_MPLY,   KC_MPRV,   KC_MNXT,
        _______,   _______,   KC_BSPC,   KC_ENT,    RGB_RMOD,
        _______,   KC_ESC,    KC_INS,    _______,   RGB_MOD,
        _______,   _______,   KC_DEL,    _______,   RGB_TOG,
        _______,   KC_TRNS,   MO(SYST),  _______,   _______
    ),

    /* Keymap SYST: System Layer
    * ,----------------------------------.
    * |   ×  |   ×  | NKRO |   ×  | TG(3)|
    * |------+------+------+------+------|
    * |   ×  |   ×  |   ×  |   ×  |   ×  |
    * |------+------+------+------+------|
    * |ClrROM|   ×  | BtLdr|   ×  |   ×  |
    * |------+------+------+------+------|
    * |   ×  |   ×  |   ×  |   ×  |   ×  |
    * |------+------+------+------+------|
    * |   ×  | TRNS | TRNS |   ×  | Sleep|
    * `----------------------------------'
    */
    [SYST] = LAYOUT(
        XXXXXXX,   XXXXXXX,   NK_TOGG,   XXXXXXX,   TG(MOBI),
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        EE_CLR,    XXXXXXX,   QK_BOOT,   XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        XXXXXXX,   KC_TRNS,   KC_TRNS,   XXXXXXX,   KC_SLEP
    ),

    /* Keymap MOBI: Mobile Layer
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
    [MOBI] = LAYOUT(
        KC_ESC,     KC_G,       KC_M,       KC_J,     KC_TRNS,
        KC_I,       KC_Q,       KC_W,       KC_E,     KC_R,
        KC_LCTL,    KC_A,       KC_S,       KC_D,     KC_F,
        QK_LOCK,    KC_Z,       KC_X,       KC_C,     KC_V,
        KC_LGUI,    KC_TRNS,    KC_TRNS,    KC_LSFT,  KC_SPC
    )
};

/*
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {25, 1, HSV_PURPLE}, //down glow from here
    {26, 1, HSV_PURPLE},
    {27, 1, HSV_PURPLE},
    {28, 1, HSV_PURPLE},
    {29, 1, HSV_PURPLE},
    {30, 1, HSV_PURPLE},
    {31, 1, HSV_PURPLE},
    {32, 1, HSV_PURPLE}                                         
);
*/
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS( 
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
    //[L_1]=my_layer1_layer,
    [L_2]=my_layer2_layer,
    [L_3]=my_layer3_layer,
    [L_4]=my_layer4_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    //rgblight_set_layer_state(L_1, layer_state_cmp(state, BASE));
    rgblight_set_layer_state(L_2, layer_state_cmp(state, FUNC));
    rgblight_set_layer_state(L_3, layer_state_cmp(state, SYST));
    rgblight_set_layer_state(L_4, layer_state_cmp(state, MOBI));
    return state;
}
