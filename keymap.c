#include QMK_KEYBOARD_H

#define NOOP     KC_NO
#define MOD_A    LGUI_T(KC_A)
#define ALT_S    LALT_T(KC_S)
#define CTL_D    RCTL_T(KC_D)
#define SFT_F    LSFT_T(KC_F)
#define SFT_J    RSFT_T(KC_J)
#define CTL_K    RCTL_T(KC_K)
#define ALT_L    LALT_T(KC_L)
#define MOD_QUOT LGUI_T(KC_QUOT)

#define U_MEDIA LT(_U_MEDIA, KC_ESC)
#define U_NAV   LT(_U_NAV,   KC_TAB)
#define U_MOUSE LT(_U_MOUSE, KC_ENT)
#define U_SYM   LT(_U_SYM,   KC_SPC)
#define U_NUM   LT(_U_NUM,   KC_BSPC)
#define U_FUN   LT(_U_FUN,   KC_DEL)

const uint16_t PROGMEM cedilla_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_W, KC_E, COMBO_END};
combo_t key_combos[] = {
    COMBO_ACTION(cedilla_combo),
    COMBO(ent_combo, KC_ENT),
    COMBO(esc_combo, KC_ESC),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case 0:
      if (pressed) {
        tap_code16(G(KC_SPC));
        tap_code16(KC_SCLN);
        tap_code16(G(KC_SPC));
      }
      break;
  }
}

enum layer {
    _U_BASE = 0,
    _U_MEDIA,
    _U_NAV,
    _U_MOUSE,
    _U_SYM,
    _U_NUM,
    _U_FUN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_U_BASE] = LAYOUT_split_3x6_3(
    NOOP,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     NOOP,
    NOOP,    MOD_A,   ALT_S,   CTL_D,   SFT_F,   KC_G,    KC_H,    SFT_J,   CTL_K,   ALT_L,   MOD_QUOT, NOOP,
    NOOP,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  NOOP,
    U_MEDIA, U_NAV,   U_MOUSE, U_SYM,   U_NUM,   U_FUN
  ),
  [_U_MEDIA] = LAYOUT_split_3x6_3(
    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    KC_QUES, KC_QUOT, KC_DQT,  KC_SLSH, NOOP,     NOOP,
    NOOP,    KC_LGUI, KC_LALT, KC_RCTL, KC_LSFT, NOOP,    KC_MUTE, KC_VOLD, KC_VOLU, NOOP,    KC_CAPS,  NOOP,
    NOOP,    NOOP,    KC_ALGR, NOOP,    NOOP,    NOOP,    NOOP,    KC_BRID, KC_BRIU, NOOP,    NOOP,     NOOP,
    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    KC_WSCH
  ),

  [_U_NAV] = LAYOUT_split_3x6_3(
    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO,  NOOP,
    NOOP,    KC_LGUI, KC_LALT, KC_RCTL, KC_LSFT, NOOP,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CW_TOGG,  NOOP,
    NOOP,    NOOP,    KC_ALGR, NOOP,    NOOP,    NOOP,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,   NOOP,
    NOOP,    NOOP,    NOOP,    KC_ENT,  KC_BSPC, KC_DEL
  ),

  [_U_MOUSE] = LAYOUT_split_3x6_3(
    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    NOOP,    KC_QUES, KC_QUOT, KC_DQT,  KC_SLSH, NOOP,     NOOP,
    NOOP,    KC_LGUI, KC_LALT, KC_RCTL, KC_LSFT, NOOP,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, NOOP,     NOOP,
    NOOP,    NOOP,    KC_ALGR, NOOP,    NOOP,    NOOP,    NOOP,    KC_WH_D, KC_WH_U, NOOP,    NOOP,     NOOP,
    NOOP,    NOOP,    NOOP,    KC_BTN2, KC_BTN1, KC_BTN3
  ),

  [_U_SYM] = LAYOUT_split_3x6_3(
    NOOP,    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, NOOP,    NOOP,    NOOP,    NOOP,    NOOP,     NOOP,
    NOOP,    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, NOOP,    KC_RSFT, KC_RCTL, KC_LALT, KC_LGUI,  NOOP,
    NOOP,    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, NOOP,    NOOP,    NOOP,    KC_ALGR, NOOP,     NOOP,
    KC_LPRN, KC_RPRN, KC_UNDS, NOOP,    NOOP,    NOOP
  ),

  [_U_NUM] = LAYOUT_split_3x6_3(
    NOOP,    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, NOOP,    NOOP,    NOOP,    NOOP,    NOOP,     NOOP,
    NOOP,    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  NOOP,    KC_RSFT, KC_RCTL, KC_LALT, KC_LGUI,  NOOP,
    NOOP,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, NOOP,    NOOP,    NOOP,    KC_ALGR, NOOP,     NOOP,
    KC_DOT,  KC_0,    KC_MINS, NOOP,    NOOP,    NOOP
  ),

  [_U_FUN] = LAYOUT_split_3x6_3(
    NOOP,    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, NOOP,    NOOP,    NOOP,    NOOP,    NOOP,     NOOP,
    NOOP,    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, NOOP,    KC_RSFT, KC_RCTL, KC_LALT, KC_LGUI,  NOOP,
    NOOP,    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, NOOP,    NOOP,    NOOP,    KC_ALGR, NOOP,     NOOP,
    KC_APP,  KC_SPC,  KC_TAB,  NOOP,    NOOP,    NOOP
  ),
};
