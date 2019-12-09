#include "atreus.h"
#include "action_layer.h"

#define PREVENT_STUCK_MODIFIERS

#define ALPH 0
#define NUMS 1
#define MISC 2

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KM_LTAB LCTL(LSFT(KC_TAB))
#define KM_RTAB LCTL(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ALPH] = {
    {KC_Q,    KC_W,   KC_E,          KC_R,             KC_T,          XXXXXXX,       KC_Y,           KC_U,    KC_I,    KC_O,          KC_P},
    {KC_A,    KC_S,   KC_D,          KC_F,             KC_G,          XXXXXXX,       KC_H,           KC_J,    KC_K,    KC_L,          KC_SCLN},
    {KC_Z,    KC_X,   KC_C,          KC_V,             KC_B,          GUI_T(KC_SPC), KC_N,           KC_M,    KC_COMM, KC_DOT,        KC_SLSH},
    {KC_LSFT, KC_MEH, KC_LALT, LT(MISC, KC_TAB), CTL_T(KC_ESC), ALT_T(KC_ENT), SFT_T(KC_BSPC), LT(NUMS, KC_TAB), ALT_T(KC_TAB), XXXXXXX,  XXXXXXX}
  },
  [NUMS] = {
    {KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_PERC, XXXXXXX, KC_ASTR, KC_7,    KC_8, KC_9,    KC_MINS},
    {KC_LCBR, KC_RCBR, KC_EQL,  KC_UNDS, KC_DQT,  XXXXXXX, KC_AMPR, KC_4,    KC_5, KC_6,    KC_PLUS},
    {KC_CIRC, KC_DLR,  KC_LBRC, KC_RBRC, KC_QUOT, _______, KC_HASH, KC_1,    KC_2, KC_3,    KC_PIPE},
    {KC_GRV,  KC_TILD, KC_LALT, XXXXXXX, _______, KC_ENT,  _______, _______, KC_0, XXXXXXX, KC_BSLS}
  },
  [MISC] = {
    {LGUI(KC_GRV), LGUI(KC_TAB), KC_UP,   LGUI(KC_SPC), KC_VOLU, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10},
    {XXXXXXX,      KC_LEFT,      KC_DOWN, KC_RIGHT,     KC_VOLD, XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11},
    {KM_LTAB,      KM_RTAB,      XXXXXXX, LCTL(KC_SPC), KC_MPLY, _______, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12},
    {KC_MPRV,      KC_MNXT,      XXXXXXX, _______,      KC_MUTE, KC_ENT,  _______, KC_LSFT, _______,  _______, RESET}
  }
};

const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {}

  return MACRO_NONE;
};
