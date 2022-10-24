#include QMK_KEYBOARD_H
#include "keymap_german_mac_iso.h"

enum mlego_layers {
  _QWERTY,
  _NUMPAD,
  _SYMBOLS,
  _UMLAUTS,
  _MOUSE,
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_UMLAUTS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SYMBOLS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUMPAD] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MOUSE] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

#define LOWER MO(_UMLAUTS)
#define RAISE MO(_SYMBOLS)
#define MOUSE TT(_MOUSE)
#define FN TT(_NUMPAD)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_ortho_5x13(
        XXXXXXX,    DE_1,       DE_2,       DE_3,       DE_4,       DE_5,     KC_POWER,  DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    MOUSE,
        KC_TAB,     DE_Q,       DE_W,       DE_E,       DE_R,       DE_T,     XXXXXXX,   DE_Y,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
        KC_ESC,     DE_A,       DE_S,       DE_D,       DE_F,       DE_G,     XXXXXXX,   DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN, DE_QUOT,
        KC_LSFT,    DE_Z,       DE_X,       DE_C,       DE_V,       DE_B,     XXXXXXX,   DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_SLSH, KC_ENT,
        FN,         KC_LCTL,    KC_LALT,    KC_LGUI,    LOWER,      KC_SPC,   KC_MUTE,   KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),

    [_SYMBOLS] = LAYOUT_ortho_5x13(
        _______,    _______,    _______,    _______,    _______,    _______, XXXXXXX, _______,    _______,    _______,    _______,    _______,    _______,
        DE_CIRC,    DE_EXLM,    DE_DQUO,    DE_SECT,    DE_DLR,     DE_PERC, XXXXXXX, DE_AMPR,    DE_SLSH,    DE_ASTR,    DE_LPRN,    DE_RPRN,    DE_QUES,
        DE_ACUT,    DE_1,       DE_2,       DE_3,       DE_4,       DE_5,    XXXXXXX, DE_6,       DE_7,       DE_8,       DE_9,       DE_0,       DE_PIPE,
        _______,    DE_LABK,    DE_RABK,    DE_MINS,    DE_UNDS,    DE_PLUS, XXXXXXX, DE_HASH,    DE_LCBR,    DE_RCBR,    DE_LBRC,    DE_RBRC,    DE_BSLS,
        XXXXXXX,    _______,    _______,    _______,    _______,    _______, XXXXXXX, _______,    _______,    _______,    _______,    _______,    _______
    ),

    [_NUMPAD] = LAYOUT_ortho_5x13(
        _______,    XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,   XXXXXXX,   KC_KP_SLASH,  KC_KP_ASTERISK,       KC_KP_MINUS,    XXXXXXX,       XXXXXXX,   XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,     KC_UP,       XXXXXXX,    XXXXXXX,   KC_KP_7,   KC_KP_8,      KC_KP_9,              KC_KP_PLUS,     XXXXXXX,       XXXXXXX,   XXXXXXX,    _______,
        XXXXXXX,    KC_LEFT,     KC_DOWN,     KC_RIGHT,   XXXXXXX,   KC_KP_4,   KC_KP_5,      KC_KP_6,              KC_KP_PLUS,     XXXXXXX,       XXXXXXX,   XXXXXXX,    XXXXXXX,
        _______,    XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,   KC_KP_1,   KC_KP_2,      KC_KP_3,              KC_KP_ENTER,    XXXXXXX,       XXXXXXX,   XXXXXXX,    KC_KP_ENTER,
        _______,    _______,     _______,     _______,    _______,   KC_KP_0,   KC_KP_0,      KC_KP_DOT,            KC_KP_ENTER,    XXXXXXX,       XXXXXXX,   XXXXXXX,    XXXXXXX
    ),

    [_UMLAUTS] = LAYOUT_ortho_5x13(
        _______,    _______,     _______,     _______,    _______,   _______, XXXXXXX,   _______,  _______, _______, _______, _______, _______,
        XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX  ,XXXXXXX,  DE_UDIA, XXXXXXX, DE_ODIA, XXXXXXX, XXXXXXX,
        XXXXXXX,    DE_ADIA,     DE_SS,       XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX  ,XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,    XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX  ,XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,    _______,     _______,     _______,    _______,   _______, XXXXXXX  ,_______,  _______, _______, _______, _______, _______
    ),

    [_MOUSE] = LAYOUT_ortho_5x13(
        XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,      XXXXXXX,       XXXXXXX,    XXXXXXX,       XXXXXXX,   XXXXXXX,    _______,
        XXXXXXX,    XXXXXXX,     KC_MS_U,     XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,      XXXXXXX,       XXXXXXX,    XXXXXXX,       KC_WH_D,   XXXXXXX,    XXXXXXX,
        XXXXXXX,    KC_MS_L,     KC_MS_D,     KC_MS_R,    XXXXXXX,   XXXXXXX,   XXXXXXX,      XXXXXXX,       XXXXXXX,    KC_WH_R,       KC_WH_U,   KC_WH_L,    XXXXXXX,
        XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,      XXXXXXX,       XXXXXXX,    XXXXXXX,       XXXXXXX,   XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,    KC_BTN1,   KC_BTN2,   XXXXXXX,      XXXXXXX,       XXXXXXX,    XXXXXXX,       XXXXXXX,   XXXXXXX,    XXXXXXX
    ),
};

bool led_update_user(led_t led_state) {
    // Disable the default LED update code, so that lock LEDs could be reused to show layer status.
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _SYMBOLS:
            led_rse(false);
            led_lwr(true);
            break;
        case _UMLAUTS:
            led_rse(true);
            led_lwr(false);
            break;
        case _NUMPAD:
            led_rse(true);
            led_lwr(true);
            break;
        case _MOUSE:
            led_rse(true);
            led_lwr(true);
            break;
        default: //  for any other layers, or the default layer
            led_rse(false);
            led_lwr(false);
            break;
    }
    return state;
}
