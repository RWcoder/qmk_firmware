#include QMK_KEYBOARD_H

/**
 * 17
 * 16
 * 16
 * 15
 * 14
 * 13
 */

enum layers {
    BASE,
    CONTROL,
    SYMBOL,
    CODE,
    QWERTY,
    BOARD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_91_ansi(
        C(KC_0),     KC_ESC,   G(KC_1),  G(KC_2),  G(KC_3),    G(KC_4),      G(KC_5),  G(KC_6),  G(KC_7),  G(KC_8),  G(KC_9),  G(KC_0),     KC_F11,   KC_F12,   LCA(KC_DEL),  KC_PSCR, KC_MUTE,
        _______,     KC_GRV,   KC_1,     KC_2,     KC_3,       KC_4,         KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,        KC_MINS,  KC_EQL,   KC_BSPC,      KC_DEL,
        QK_MACRO_7,  KC_TAB,   KC_Q,     KC_W,     KC_F,       KC_P,         KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SLSH,     KC_LBRC,  KC_RBRC,  KC_F9,        KC_HOME,
        _______,     KC_ENT,   KC_A,     KC_R,     KC_S,       KC_T,         KC_G,     KC_K,     KC_N,     KC_E,     KC_I,     KC_O,        KC_QUOT,  KC_ENT,   KC_END,
        _______,     KC_LSFT,  KC_X,     KC_C,     KC_D,       KC_V,         KC_Z,     KC_H,     KC_M,     KC_COMM,  KC_DOT,   MO(SYMBOL),  CW_TOGG,  KC_F12,
        _______,     KC_LCTL,  KC_LGUI,  KC_LALT,  A(KC_SPC),  MO(CONTROL),  KC_SPC,   KC_RGUI,  KC_RALT,  KC_RCTL,  KC_F8,    KC_F11,      KC_F10
    ),

    [CONTROL] = LAYOUT_91_ansi(
        _______,  _______,     _______,     _______,     _______,    _______,       _______,  _______,  _______,  _______,    _______,    _______,     _______,  _______,    _______,  _______,  TO(BOARD),
        _______,  QK_MACRO_0,  KC_F1,       KC_F2,       KC_F3,      KC_F4,         KC_F5,    KC_F6,    KC_F7,    KC_F8,      KC_F9,      KC_F10,      KC_F11,   KC_F12,     _______,  KC_INS,
        _______,  G(KC_LEFT),  QK_MACRO_1,  QK_MACRO_2,  G(KC_UP),   C(KC_L),       MS_BTN4,  MS_BTN5,  KC_UP,    A(KC_TAB),  C(KC_TAB),  C(KC_BSPC),  _______,  _______,    _______,  KC_PGUP,
        _______,  QK_MACRO_3,  KC_ESC,      S(KC_ESC),   C(KC_S),    LSG(KC_RGHT),  C(KC_P),  KC_LEFT,  KC_DOWN,  KC_RGHT,    RCS(KC_P),  MO(CODE),    KC_BSPC,  C(KC_ENT),  KC_PGDN,
        _______,  KC_LSFT,     A(KC_F4),    C(KC_C),     RCS(KC_I),  C(KC_GRV),     _______,  KC_HOME,  KC_END,   A(KC_Z),    A(KC_DOT),  KC_RCTL,     KC_CAPS,  _______,
        _______,  QK_MACRO_4,  KC_SLEP,     _______,     _______,    _______,       C(KC_V),  _______,  _______,  _______,    _______,    _______,     _______
    ),

    [SYMBOL] = LAYOUT_91_ansi(
        _______,  _______,     _______,     _______,  _______,  _______,     _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,     _______,     _______,  _______,  _______,     _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,     KC_CIRC,     KC_EXLM,  KC_LBRC,  KC_RBRC,     _______,     _______,  KC_PLUS,  KC_PERC,  KC_SCLN,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_UNDS,     KC_AT,       KC_EQL,   KC_LCBR,  KC_RCBR,     KC_AMPR,     KC_PIPE,  KC_MINS,  KC_HASH,  KC_COLN,  _______,  _______,  _______,  _______,
        _______,  RCS(KC_F1),  RCS(KC_F2),  KC_LPRN,  KC_RPRN,  KC_DLR,      _______,     KC_ASTR,  KC_GRV,   KC_TILD,  KC_BSLS,  _______,  _______,  _______,
        _______,  _______,     _______,     _______,  _______,  QK_MACRO_5,  QK_MACRO_6,  _______,  _______,  _______,  _______,  _______,  _______
    ),

    [CODE] = LAYOUT_91_ansi(
        _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,      _______,  KC_F19,   KC_F18,   KC_F23,   _______,  _______,  KC_F16,   _______,  KC_F21,   _______,  _______,  _______,  _______,  _______,
        _______,  LCA(KC_DOT),  KC_F24,   KC_F22,   A(KC_S),  KC_F20,   _______,  _______,  KC_F13,   KC_F17,   KC_F15,   _______,  _______,  _______,  _______,
        _______,  _______,      _______,  _______,  KC_F14,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),

    [QWERTY] = LAYOUT_91_ansi(
        C(KC_0),   KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  KC_MUTE,
        _______,   KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,    KC_5,    KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,
        _______,   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_HOME,
        _______,   KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,    KC_G,    KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_END,
        _______,   KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        TO(BASE),  KC_LCTL,  KC_LGUI,  KC_LALT,  _______,  KC_SPC,  KC_SPC,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [BOARD] = LAYOUT_91_ansi(
        _______,   _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RM_TOGG,
        _______,   _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,   _______,  TO(QWERTY),  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,   _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,   _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  AS_UP,
        TO(BASE),  _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  AS_TOGG,  AS_DOWN,  AS_RPT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case QK_MACRO_0:
                SEND_STRING(
                    SS_DOWN(X_LCTL) SS_TAP(X_LALT) SS_UP(X_LCTL)
                    SS_DOWN(X_LALT) SS_TAP(X_O) SS_UP(X_LALT)
                    "dd"
                    SS_TAP(X_ENT)
                );
                return false;
            case QK_MACRO_1:
                SEND_STRING(
                    SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI)
                    SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI)
                );
                return false;
            case QK_MACRO_2:
                SEND_STRING(
                    SS_DOWN(X_LSFT) SS_TAP(X_W) SS_UP(X_LSFT)
                    SS_DELAY(300)
                    SS_DOWN(X_LGUI) SS_TAP(X_UP) SS_UP(X_LGUI)
                );
                return false;
            case QK_MACRO_3:
                SEND_STRING(
                    SS_DOWN(X_LCTL) SS_TAP(X_LALT) SS_UP(X_LCTL)
                    SS_DOWN(X_LGUI) SS_TAP(X_2) SS_UP(X_LGUI)
                );
                return false;
            case QK_MACRO_4:
                SEND_STRING(
                    SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_DEL) SS_UP(X_LALT) SS_UP(X_LCTL)
                    SS_DELAY(600)
                    SS_TAP(X_DOWN)
                    SS_TAP(X_ENT)
                );
                return false;
            case QK_MACRO_5:
                SEND_STRING(" = ");
                return false;
            case QK_MACRO_6:
                SEND_STRING(" => ");
                return false;
            case QK_MACRO_7:
                SEND_STRING("/zoom" SS_TAP(X_ENT));
                return false;
        }
    }

    return true;
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE]    = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [CONTROL] = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [SYMBOL]  = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [CODE]    = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [QWERTY]  = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [BOARD]   = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(RM_PREV, RM_NEXT) }
};
#endif // ENCODER_MAP_ENABLE
