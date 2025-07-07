#include QMK_KEYBOARD_H

#define W(kc) LGUI(kc)
#define TAP(kc) tap_code16(kc)
#define DELAY(ms) SEND_STRING(SS_DELAY(ms))
#define L_CTRL LM(LEFT_CTRL, MOD_LCTL)

// Print current and previous business days through AHK
#define CURR_BD C(S(KC_F3))
#define PREV_BD C(S(KC_F4))

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
    ARROWS,
    LEFT_CTRL,
    FUNCTION,
    SYMBOL,
    CODE,
    QWERTY,
    BOARD
};

enum custom_keycodes {
    VDI_X_HOME = SAFE_RANGE,
    VDI_X_OFC,
    VDI_MIN,
    WIN_SNAP,
    WWW_POPOUT,
    ZOOM,
    ASSIGN,
    LAMBDA,
    ALT_TAB,
    CTRL_TAB,
    MJ_TOGG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_91_ansi(
        C(KC_0),  KC_ESC,   W(KC_1),       W(KC_2),  W(KC_3),    W(KC_4),       W(KC_5),  W(KC_6),  W(KC_7),  W(KC_8),  W(KC_9),         W(KC_0),     KC_F11,   KC_F12,   KC_PSCR,  C(A(KC_DEL)), KC_MUTE,
        _______,  KC_GRV,   KC_1,          KC_2,     KC_3,       KC_4,          KC_5,     KC_6,     KC_7,     KC_8,     KC_9,            KC_0,        KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,
        ZOOM,     KC_TAB,   KC_Q,          KC_W,     KC_F,       KC_P,          KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,            KC_SLSH,     KC_LBRC,  KC_RBRC,  KC_F9,    KC_HOME,
        CURR_BD,  KC_TAB,   KC_A,          KC_R,     KC_S,       KC_T,          KC_G,     KC_K,     KC_N,     KC_E,     KC_I,            KC_O,        KC_QUOT,  KC_ENT,   KC_END,
        PREV_BD,  KC_LCTL,  LSFT_T(KC_X),  KC_C,     KC_D,       KC_V,          KC_Z,     KC_H,     KC_M,     KC_COMM,  LSFT_T(KC_DOT),  MO(SYMBOL),  CW_TOGG,  KC_F12,
        _______,  L_CTRL,   KC_LGUI,       KC_LALT,  A(KC_SPC),  MO(FUNCTION),  KC_SPC,   KC_RGUI,  KC_RALT,  L_CTRL,   KC_F8,           KC_F11,      KC_F10
    ),

    [ARROWS] = LAYOUT_91_ansi(
        _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_UP,
        TO(BASE),  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT
    ),

    [LEFT_CTRL] = LAYOUT_91_ansi(
        _______,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_LSFT,  KC_X,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_DOT,   KC_SLSH,  KC_LSFT,  KC_UP,
        _______,  _______,  _______,  _______,  _______,  KC_SPC,   _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [FUNCTION] = LAYOUT_91_ansi(
        _______,  _______,     _______,   _______,     _______,     _______,        _______,  _______,  _______,  _______,  _______,     _______,     _______,  _______,    _______,  TO(BOARD),  _______,
        _______,  VDI_X_HOME,  KC_F1,     KC_F2,       KC_F3,       KC_F4,          KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,       KC_F10,      KC_F11,   KC_F12,     _______,  KC_INS,
        _______,  W(KC_LEFT),  WIN_SNAP,  WWW_POPOUT,  W(KC_UP),    C(KC_L),        MS_BTN4,  MS_BTN5,  KC_UP,    ALT_TAB,  CTRL_TAB,    C(KC_BSPC),  _______,  _______,    _______,  KC_PGUP,
        _______,  VDI_MIN,     KC_ESC,    S(KC_ESC),   C(KC_S),     W(S(KC_RGHT)),  C(KC_P),  KC_LEFT,  KC_DOWN,  KC_RGHT,  C(S(KC_P)),  KC_ENT,      KC_RCTL,  C(KC_ENT),  KC_PGDN,
        _______,  KC_LSFT,     A(KC_F4),  C(KC_C),     C(S(KC_I)),  C(KC_GRV),      A(KC_Z),  KC_HOME,  A(KC_Z),  KC_END,   A(KC_DOT),   MO(CODE),    KC_CAPS,  _______,
        _______,  VDI_X_OFC,   KC_SLEP,   _______,     MJ_TOGG,     _______,        C(KC_V),  _______,  _______,  _______,  _______,     _______,     _______
    ),

    [SYMBOL] = LAYOUT_91_ansi(
        _______,  _______,      _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,      _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,      KC_CIRC,      KC_EXLM,  KC_LBRC,  KC_RBRC,  _______,  _______,  KC_PLUS,  KC_PERC,  KC_SCLN,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_UNDS,      KC_AT,        KC_EQL,   KC_LCBR,  KC_RCBR,  KC_AMPR,  KC_PIPE,  KC_MINS,  KC_HASH,  KC_COLN,  _______,  _______,  _______,  _______,
        _______,  C(S(KC_F1)),  C(S(KC_F2)),  KC_LPRN,  KC_RPRN,  KC_DLR,   _______,  KC_ASTR,  KC_GRV,   KC_TILD,  KC_BSLS,  _______,  _______,  _______,
        _______,  _______,      _______,      _______,  _______,  ASSIGN,   LAMBDA,   _______,  _______,  _______,  _______,  _______,  _______
    ),

    [CODE] = LAYOUT_91_ansi(
        _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,       _______,  KC_F19,   KC_F18,   KC_F23,   _______,  _______,  KC_F16,   _______,  KC_F21,   _______,  _______,  _______,  _______,  _______,
        _______,  C(A(KC_DOT)),  KC_F24,   KC_F22,   A(KC_S),  KC_F20,   _______,  _______,  KC_F13,   KC_F17,   KC_F15,   _______,  _______,  _______,  _______,
        _______,  _______,       _______,  _______,  KC_F14,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),

    [QWERTY] = LAYOUT_91_ansi(
        C(KC_0),   KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  KC_MUTE,
        XXXXXXX,   KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,    KC_5,    KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,
        XXXXXXX,   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_HOME,
        XXXXXXX,   KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,    KC_G,    KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_END,
        XXXXXXX,   KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        TO(BASE),  KC_LCTL,  KC_LGUI,  KC_LALT,  _______,  KC_SPC,  KC_SPC,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [BOARD] = LAYOUT_91_ansi(
        QK_BOOT,   _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RM_TOGG,
        _______,   _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,   _______,  TO(QWERTY),  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,   _______,  TO(ARROWS),  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,   _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  DT_UP,
        TO(BASE),  _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  DT_DOWN,  DT_PRNT
    )
};

static bool alt_tab_active = false;
static bool ctrl_tab_active = false;
static bool mouse_jiggle_active = false;

#define MJ_ITERS 15
#define MJ_INTERVAL_MS 10000
uint32_t mouse_jiggle(uint32_t trigger_time, void *cb_arg) {
    if (mouse_jiggle_active) {
        for (int i = 0; i < MJ_ITERS; i++) TAP(MS_UP);
        for (int i = 0; i < MJ_ITERS; i++) TAP(MS_RGHT);
        for (int i = 0; i < MJ_ITERS; i++) TAP(MS_DOWN);
        for (int i = 0; i < MJ_ITERS; i++) TAP(MS_LEFT);
        return MJ_INTERVAL_MS;
    } else {
        return 0;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    switch (keycode) {
        case VDI_X_HOME:
            TAP(C(KC_LALT));
            TAP(A(KC_O));
            SEND_STRING("dd");
            TAP(KC_ENT);
            return false;

        case VDI_X_OFC:
            TAP(C(A(KC_DEL)));
            DELAY(600);
            TAP(KC_DOWN);
            TAP(KC_ENT);
            return false;

        case VDI_MIN:
            TAP(C(KC_LALT));
            TAP(W(KC_2));
            return false;

        case WIN_SNAP:
            TAP(W(KC_LEFT));
            TAP(W(KC_LEFT));
            return false;

        case WWW_POPOUT:
            TAP(S(KC_W));
            DELAY(300);
            TAP(W(KC_UP));
            return false;

        case ZOOM:
            SEND_STRING("/zoom");
            TAP(KC_ENT);
            return false;

        case ASSIGN:
            SEND_STRING(" = ");
            return false;

        case LAMBDA:
            SEND_STRING(" => ");
            return false;
            
        case ALT_TAB:
            if (!alt_tab_active) {
                alt_tab_active = true;
                register_code(KC_LALT);
            }
            TAP(KC_TAB);
            return false;

        case CTRL_TAB:
            if (!ctrl_tab_active) {
                ctrl_tab_active = true;
                register_code(KC_LCTL);
            }
            TAP(KC_TAB);
            return false;
            
        case MJ_TOGG:
            if (!mouse_jiggle_active) {
                mouse_jiggle_active = true;
                defer_exec(100, mouse_jiggle, NULL);
            } else {
                mouse_jiggle_active = false;
            }
            return false;

        default:
            return true;
     }
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (alt_tab_active) {
        alt_tab_active = false;
        unregister_code(KC_LALT);
    }

    if (ctrl_tab_active) {
        ctrl_tab_active = false;
        unregister_code(KC_LCTL);
    }

    return state;
}


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE]      = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [ARROWS]    = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LEFT_CTRL] = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FUNCTION]  = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [SYMBOL]    = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [CODE]      = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [QWERTY]    = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [BOARD]     = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(RM_PREV, RM_NEXT) }
};
#endif // ENCODER_MAP_ENABLE
