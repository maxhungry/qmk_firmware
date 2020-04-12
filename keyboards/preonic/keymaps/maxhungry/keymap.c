/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _XCODE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

#define LT_LOWER(kc) LT(_LOWER, kc)
#define LT_RAISE(kc) LT(_RAISE, kc)

#define KM_LTAB LGUI(LSFT(KC_LBRC))
#define KM_RTAB LGUI(LSFT(KC_RBRC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ct/Es|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  ]   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  |Lower |Ct/Esc|    Space    | Bksp | RS/et|      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,        KC_1,    KC_2,    KC_3,             KC_4,          KC_5,           KC_6,           KC_7,           KC_8,             KC_9,       KC_0,    KC_DEL,  \
  KC_TAB,        KC_Q,    KC_W,    KC_E,             KC_R,          KC_T,           KC_Y,           KC_U,           KC_I,             KC_O,       KC_P,    KC_LBRC, \
  CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,             KC_F,          KC_G,           KC_H,           KC_J,           KC_K,             KC_L,       KC_SCLN, KC_RBRC, \
  KC_LSFT,       KC_Z,    KC_X,    KC_C,             KC_V,          KC_B,           KC_N,           KC_M,           KC_COMM,          KC_DOT,     KC_SLSH, KC_ENT,  \
  BACKLIT,       KC_LCTL, KC_LALT, LT_LOWER(KC_ESC), CTL_T(KC_ESC), LGUI_T(KC_SPC), LGUI_T(KC_SPC), SFT_T(KC_BSPC), LT_RAISE(KC_ENT), MO(_XCODE), _______, _______  \
),

/*  xcode
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_XCODE] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______ \
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  F10 |  F11 |  F12 |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | TAB  | TASK |  UP  |SPTLGT| Vol+ |      |  F7  |  F8  |  F9  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | LEFT | DOWN | RIGHT| Vol- |      |  F4  |  F5  |  F6  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | L-TAB| R-TAB|      | TMUX | PLAY |      |  F1  |  F2  |  F3  | END  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | PREV | NEXT |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  _______, _______,      _______,      _______, _______,      _______, _______, KC_F10,  KC_F11,  KC_F12,  _______, _______, \
  _______, LGUI(KC_GRV), LGUI(KC_TAB), KC_UP,   LGUI(KC_SPC), KC_VOLU, _______, KC_F7,   KC_F8,   KC_F9,   _______, _______, \
  _______, _______,      KC_LEFT,      KC_DOWN, KC_RIGHT,     KC_VOLD, _______, KC_F4,   KC_F5,   KC_F6,   _______, _______, \
  _______, KM_LTAB,      KM_RTAB,      _______, LCTL(KC_SPC), KC_MPLY, _______, KC_F1,   KC_F2,   KC_F3,   KC_END,  _______, \
  _______, KC_MPRV,      KC_MNXT,      _______, _______,      _______, _______, _______, _______, _______, _______, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   !  |   @  |   (  |   )  |   %  |   *  |   7  |   8  |   9  |   -  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   {  |   }  |   =  |   _  |   "  |   &  |   4  |   5  |   6  |   +  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   ^  |   $  |   [  |   ]  |   '  |   #  |   1  |   2  |   3  |   0  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |RAISE |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = LAYOUT_preonic_grid( \
  KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, \
  KC_GRV,  KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_PERC, KC_ASTR, KC_7,    KC_8,    KC_9,    KC_MINS, KC_DEL,  \
  KC_DEL,  KC_LCBR, KC_RCBR, KC_EQL,  KC_UNDS, KC_DQT,  KC_AMPR, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_PIPE, \
  _______, KC_CIRC, KC_DLR,  KC_LBRC, KC_RBRC, KC_QUOT, KC_HASH, KC_1,    KC_2,    KC_3,    KC_0,    KC_BSLS, \
  _______, KC_GRV,  KC_TILD, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______,  _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______  \
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
