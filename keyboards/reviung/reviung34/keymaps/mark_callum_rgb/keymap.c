#include QMK_KEYBOARD_H
// Use callum-oakley's one-shot implementation, to avoid OSM bug in stock firmware.
// See https://github.com/qmk/qmk_firmware/issues/3963
#include "../../../users/callum/oneshot.h"
#include "../../../users/callum/oneshot.c"

enum ferris_layers {
  _QWERTY,
  _SYMBOLS,
  _ARROWS,
  _NUMBERS
};

#define LA_SYM MO(_SYMBOLS)
#define LA_ARR MO(_ARROWS)

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QWERTY] = LAYOUT_reviung34(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, 
                    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
                    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                    MO(_ARROWS), KC_LSFT, KC_SPC, MO(_SYMBOLS)),

 [_SYMBOLS] = LAYOUT_reviung34(KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, 
                    KC_ESC, KC_NO, KC_NO, KC_NO, KC_GRV, KC_QUOT, OS_CMD, OS_ALT, OS_CTRL, OS_SHFT, 
                    KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, 
                    MO(_NUMBERS), KC_TRNS, KC_TRNS, KC_TRNS),

 [_ARROWS] = LAYOUT_reviung34(KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, 
                    OS_SHFT, OS_CTRL, OS_ALT, OS_CMD, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DEL, 
                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_ENT, 
                    KC_TRNS, KC_TRNS, KC_TRNS, MO(_NUMBERS)),

 [_NUMBERS] = LAYOUT_reviung34(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, 
                    OS_SHFT, OS_CTRL, OS_ALT, OS_CMD, KC_NO, KC_NO, OS_CMD, OS_ALT, OS_CTRL, OS_SHFT, 
                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS) 

};

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_ARR:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_ARR:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(104, 255, 135);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif
