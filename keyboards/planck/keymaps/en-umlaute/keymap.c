/* Copyright 2015-2021 Jack Humbert
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
#include "keymap_german_mac_iso.h"


enum planck_layers {
  _QWERTY,
  _SYMBOLS,
  _UMLAUTS,
  _ADJUST
};

#define LOWER MO(_UMLAUTS)
#define RAISE MO(_SYMBOLS)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_MUTE, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
),


[_SYMBOLS] = LAYOUT_planck_grid(
    _______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    _______,
    _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_GRV,
    _______,    KC_MINS,     KC_EQL,    KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,     KC_PIPE,    KC_TILDE,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),


[_UMLAUTS] = LAYOUT_planck_grid(
    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  DE_UDIA, XXXXXXX,        DE_ODIA,        XXXXXXX,        XXXXXXX,
    XXXXXXX,  DE_ADIA,   DE_SS,     XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    _______,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    _______,  _______,   _______,   _______,   _______,   _______,   _______,  _______, KC_MS_WH_RIGHT, KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MS_WH_LEFT
),


[_ADJUST] = LAYOUT_planck_grid(
    QK_BOOT,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t nstate = update_tri_layer_state(state, _UMLAUTS, _SYMBOLS, _ADJUST);
    switch (biton32(nstate)) {
        case 0:
            rgblight_disable_noeeprom();
            break;
        case 1:
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case 2:
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case 3:
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(HSV_GOLD);
            break;
  }
  return nstate;
}

void keyboard_post_init_user(void) {
    rgblight_disable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}
