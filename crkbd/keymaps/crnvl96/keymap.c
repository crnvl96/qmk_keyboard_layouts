#include QMK_KEYBOARD_H

#define NOOP     KC_NO
#define MOD_A    LGUI_T(KC_A)
#define ALT_S    LALT_T(KC_S)
#define CTL_D    RCTL_T(KC_D)
#define SFT_F    LSFT_T(KC_F)
#define ALGR_X   ALGR_T(KC_X)
#define SFT_J    RSFT_T(KC_J)
#define CTL_K    RCTL_T(KC_K)
#define ALT_L    LALT_T(KC_L)
#define MOD_QUOT LGUI_T(KC_QUOT)
#define ALGR_DOT ALGR_T(KC_DOT)

#define U_FUN_N   LT(_U_FUN,   KC_N)

#define U_NAV   LT(_U_NAV,   KC_TAB)
#define U_SYM   LT(_U_SYM,   KC_SPC)
#define U_NUM   LT(_U_NUM,   KC_BSPC)

enum combos {
    WE_ESC,
    IO_DEL
};

const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};

combo_t key_combos[] = {
    [WE_ESC] = COMBO(we_combo, KC_ESC),
    [IO_DEL] = COMBO(io_combo, KC_DEL),
};

enum layer {
    _U_BASE = 0,
    _U_NAV,
    _U_SYM,
    _U_NUM,
    _U_FUN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_U_BASE] = LAYOUT_split_3x6_3(
    NOOP,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     NOOP,
    NOOP,    MOD_A,   ALT_S,   CTL_D,   SFT_F,   KC_G, KC_H,    SFT_J,   CTL_K,   ALT_L,    MOD_QUOT, NOOP,
    NOOP,    KC_Z,    ALGR_X,  KC_C,    KC_V,    KC_B, U_FUN_N, KC_M,    KC_COMM, ALGR_DOT, KC_SLSH,  NOOP,
    NOOP,    U_NAV,   KC_ENT,  U_SYM,   U_NUM,   NOOP
  ),

  [_U_NAV] = LAYOUT_split_3x6_3(
    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    KC_CAPS, NOOP,    NOOP,    NOOP,     NOOP,
    NOOP,    KC_LGUI, KC_LALT, KC_RCTL, KC_LSFT, NOOP,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, NOOP,     NOOP,
    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  NOOP,     NOOP,
    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP
  ),

  [_U_SYM] = LAYOUT_split_3x6_3(
    NOOP,    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, NOOP,    NOOP,    NOOP,    NOOP,    NOOP,     NOOP,
    NOOP,    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, NOOP,    KC_RSFT, KC_RCTL, KC_LALT, KC_LGUI,  NOOP,
    NOOP,    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, NOOP,    NOOP,    NOOP,    NOOP,    NOOP,     NOOP,
    NOOP,    KC_RPRN, KC_UNDS, NOOP,    NOOP,    NOOP
  ),

  [_U_NUM] = LAYOUT_split_3x6_3(
    NOOP,    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, NOOP,    NOOP,    NOOP,    NOOP,    NOOP,     NOOP,
    NOOP,    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  NOOP,    KC_RSFT, KC_RCTL, KC_LALT, KC_LGUI,  NOOP,
    NOOP,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, NOOP,    NOOP,    NOOP,    NOOP,    NOOP,     NOOP,
    NOOP,    KC_0,    KC_MINS, NOOP,    NOOP,    NOOP
  ),

  [_U_FUN] = LAYOUT_split_3x6_3(
    NOOP,    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, NOOP,    NOOP,    NOOP,    NOOP,    NOOP,     NOOP,
    NOOP,    KC_F11,  KC_F4,   KC_F5,   KC_F6,   NOOP,    NOOP,    KC_RSFT, KC_RCTL, KC_LALT, KC_LGUI,  NOOP,
    NOOP,    KC_F10,  KC_F1,   KC_F2,   KC_F3,   NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,     NOOP,
    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP
  ),
};
