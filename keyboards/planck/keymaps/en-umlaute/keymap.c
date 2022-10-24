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
  _NUMPAD,
  _SYMBOLS,
  _UMLAUTS,
  _ADJUST
};

#define LOWER MO(_UMLAUTS)
#define RAISE MO(_SYMBOLS)
#define FN TT(_NUMPAD)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | ENTER|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FN   | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down | Up   |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Y,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
    KC_ESC,  DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN, DE_QUOT,
    KC_LSFT, DE_Z,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_SLSH, KC_ENT,
    FN, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
),

/* SYMBOLS
 * ,-----------------------------------------------------------------------------------.
 * |   ^  |   !  |   "  |   §  |   $  |   %  |   &  |   /  |   *  |   (  |   )  |   ?  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ´   |  1   |  2   |  3   |  4   |   5  |   6  |   7  |   8  |  9   |   0  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  <   |   >  |   -  |   _  |   +  |   #  |   {  |   }  |  [   |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT_planck_grid(
    DE_CIRC,    DE_EXLM,    DE_DQUO,    DE_SECT,    DE_DLR,     DE_PERC,    DE_AMPR,    DE_SLSH,    DE_ASTR,    DE_LPRN,    DE_RPRN,    DE_QUES,
    DE_ACUT,    DE_1,       DE_2,       DE_3,       DE_4,       DE_5,       DE_6,       DE_7,       DE_8,       DE_9,       DE_0,       DE_PIPE,
    _______,    DE_LABK,    DE_RABK,    DE_MINS,    DE_UNDS,    DE_PLUS,    DE_HASH,    DE_LCBR,    DE_RCBR,    DE_LBRC,    DE_RBRC,    DE_BSLS,
    XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * |      |      |   UP |      |      |  DEL |  7   |  8   |  9   |   =  |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | LFT  | DWN  | RGHT |      |   *  |  4   |  5   |  6   |   /  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SHIFT|      |      |      |      |   +  |  1   |  2   |  3   |   -  |      |ENTER |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |    Space    |Raise |  0   |   .  | ENTER|      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    XXXXXXX,  XXXXXXX,     KC_UP,       XXXXXXX,    XXXXXXX,   KC_DEL,           KC_KP_7,       KC_KP_8,     KC_KP_9,        DE_EQL,        XXXXXXX,    _______,
    XXXXXXX,  KC_LEFT,     KC_DOWN,     KC_RIGHT,   XXXXXXX,   KC_KP_ASTERISK,   KC_KP_4,       KC_KP_5,     KC_KP_6,        KC_KP_SLASH,   XXXXXXX,    XXXXXXX,
    _______,  XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,   KC_KP_PLUS,       KC_KP_1,       KC_KP_2,     KC_KP_3,        KC_KP_MINUS,   XXXXXXX,    KC_KP_ENTER,
    _______,  _______,     _______,     _______,    _______,   _______,          _______,       _______,     KC_KP_0,        KC_KP_DOT,     XXXXXXX,    XXXXXXX
),

/* Umlaut
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   ü  |      |   ö  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ä  |  ß   |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SHIFT|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_UMLAUTS] = LAYOUT_planck_grid(
    XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  DE_UDIA, XXXXXXX, DE_ODIA, XXXXXXX, XXXXXXX,
    XXXXXXX,  DE_ADIA,   DE_SS,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  _______,   _______,   _______,   _______,   _______,   _______,  _______, _______, _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------------------------------------------------.
 * |  RES |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
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
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case 2:
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case 3:
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case 4:
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(HSV_GOLD);
            break;
  }
  return nstate;
}

void keyboard_post_init_user(void) {
    rgblight_disable_noeeprom();
    //rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    //rgblight_sethsv_noeeprom(HSV_PURPLE);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
