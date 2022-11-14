/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_german_mac_iso.h"
#include <stdio.h>

enum corne_layers {
  _QWERTY,
  _UMLAUTS,
  _SYMBOLS,
};

#define LOWER MO(_UMLAUTS)
#define RAISE MO(_SYMBOLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                         DE_Y,    DE_U,    DE_I,    DE_O,   DE_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,    DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                         DE_H,    DE_J,    DE_K,    DE_L, DE_SCLN, DE_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    DE_Z,    DE_X,    DE_C,    DE_V,    DE_B,                         DE_N,    DE_M, DE_COMM,  DE_DOT, DE_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LCTL,  KC_LALT, KC_RGUI,    KC_SPC , RAISE  , LOWER
                                      //`--------------------------'  `--------------------------'

  ),

  [_UMLAUTS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, DE_UDIA, XXXXXXX, DE_ODIA, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, DE_ADIA, DE_SS,   XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DE_CIRC, DE_EXLM, DE_DQUO, DE_SECT, DE_DLR, DE_PERC,                       DE_AMPR, DE_SLSH, DE_ASTR, DE_LPRN, DE_RPRN, DE_QUES,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DE_ACUT, DE_1,   DE_2,    DE_3,    DE_4,    DE_5,                          DE_6,   DE_7,    DE_8,    DE_9,    DE_0,     DE_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, DE_LABK, DE_RABK, DE_MINS, DE_UNDS, DE_PLUS,                      DE_HASH, DE_LCBR, DE_RCBR, DE_LBRC, DE_RBRC, DE_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______,  _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_270;
  }
  return rotation;
}

#define L_STANDARD 0
#define L_UMLAUTE 1
#define L_SYMBOLE 2

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    if (layer_state_is(_QWERTY)){
        oled_write_ln_P(PSTR("Standard"), false);
    }
    if (layer_state_is(_UMLAUTS)){
        oled_write_ln_P(PSTR("Umlaute"), false);
    }
    if (layer_state_is(_SYMBOLS)){
        oled_write_ln_P(PSTR("Symbole"), false);
    }
}

char keylog_str[14] = {};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    snprintf(keylog_str, sizeof(keylog_str), "Row %d x Col %d", record->event.key.row, record->event.key.col);
  }
  return true;
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

//#include "music-bars.c"
//#define ANIM_INVERT false
//#define ANIM_RENDER_WPM true
//#define FAST_TYPE_WPM 45 //Switch to fast animation when over words per minute

char wpm_str[10];
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        sprintf(wpm_str, "WPM: %03d", get_current_wpm());
        oled_write(wpm_str, false);
        //oled_render_anim();

    }
    return false;
}

#endif // OLED_ENABLE
