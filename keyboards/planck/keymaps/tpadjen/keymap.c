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


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ARROW,
  _COMMAND,
  _FN
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  SLEEP
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ARROW MO(_ARROW)
#define COMMAND MO(_COMMAND)
#define FN MO(_FN)
#define CMD_GRV LGUI(KC_GRV)
#define CMD_TAB LGUI(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
,-------------------------------------------------------------------------------------------------.
| Tab   |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   | Bksp    |
|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|---------|
| Esc   |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   | Enter   |
|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|---------|
| Shift |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   | '/Shift |
|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|---------|
| Ctrl  | Alt   |  Cmd  |COMMAND| LOWER | Space | ARROW | RAISE |  FN   | CapsL | Alt   | Ctrl    |
`-------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_QUOT),
    KC_LCTL,  KC_LALT, KC_LGUI, COMMAND, LOWER,   KC_SPC,  ARROW, RAISE, FN,      KC_CAPS, KC_RALT, KC_RCTL
),

/* Lower
,------------------------------------------------------------------------------------.
|   ~  |   !  |   @  |   #  |   $   |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
|------+------+------+------+-------+------+------+------+------+------+------+------|
|      |      |      |      |   +   |   \  |   =  |   [  |   ]  |   {  |   }  |   |  |
|------+------+------+------+-------+------+------+------+------+------+------+------|
|      |      |      |      |   -   |   *  |   _  |      |      |      |   \  |   `  |
|------+------+------+------+-------+------+------+------+------+------+------+------|
|      |      |      |      |*LOWER*|      |      |      | Next | Vol- | Vol+ | Play |
`------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_NO,   KC_NO,   KC_NO,   KC_PLUS, KC_BSLS, KC_EQL,  KC_LBRC,  KC_RBRC,  KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_ASTR, KC_UNDS, KC_NO,    KC_NO,    KC_NO,   KC_BSLS, KC_GRV,
    _______, _______, _______, _______, _______, _______, _______, _______,  KC_MNXT,  KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7   |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+-------+------+------+------+------|
 * |      |      |   ,  |   .  |   +  |   \  |   =  |   4   |   5  |   6  |   +  |  \   |
 * |------+------+------+------+------+------+------+-------+------+------+------+------|
 * |      |      |      |      |   -  |   *  |   _  |   1   |   2  |   3  |   -  |  *   |
 * |------+------+------+------+------+------+------+-------+------+------+------+------|
 * |      |      |      |      |      |      |      |*RAISE*|   0  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8, KC_9,  KC_0,    KC_BSPC,
    _______, _______, KC_COMM, KC_DOT,  KC_PLUS, KC_BSLS, KC_EQL,  KC_4,    KC_5, KC_6,  KC_PLUS, KC_BSLS,
    _______, _______, _______, _______, KC_MINS, KC_ASTR, KC_UNDS, KC_1,    KC_2, KC_3,  KC_MINS, KC_ASTR,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_NO, KC_NO,   KC_NO
),

/* ARROW
 ,------------------------------------------------------------------------------------------.
 | CMD+T| CMD+SHFT+T |      |      |      |      | PG_UP | HOME |  Up  | END  |      |      |
 |------+------------+------+------+------+------+-------+------+------+------+------+------|
 |      |            |      |      |      |      | PG_DN | Left | Down |Right |  ALT |      |
 |------+------------+------+------+------+------+-------+------+------+------+------+------|
 |      |            |      |      |      |      |       |      |      |      |      |      |
 |------+------------+------+------+------+------+-------+------+------+------+------+------|
 |      |            |      |      |      |SPACE |*ARROW*|      |      |      |      |      |
 `------------------------------------------------------------------------------------------'
 */
[_ARROW] = LAYOUT_planck_grid(
    LGUI(KC_T), G(S(KC_T)), KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PGUP, KC_HOME, KC_UP,   KC_END,   KC_NO,   KC_NO,
    _______,    KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RALT, KC_NO,
    _______,    KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   _______,
    _______,    _______,    _______, _______, _______, _______, _______, _______, KC_NO,   KC_NO,    KC_NO,   KC_NO
),

/* FN
,------------------------------------------------------------------------------------.
|      |      |      |      |      |      |      |      |       |      |      |      |
|------+------+------+------+------+------+------+------+-------+------+------+------|
|      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |       |      |      |      |
|------+------+------+------+------+------+------+------+-------+------+------+------|
|      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |AppleFn| Prev | Play | Next |
|------+------+------+------+------+------+------+------+-------+------+------+------|
|      |      |      |      |      |      |      |      | *FN*  | Mute | Vol- | Vol+ |
`------------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_NO,   KC_NO,   _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_APFN, KC_MPRV, KC_MPLY, KC_MNXT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU
),

/* COMMAND
- The gui key is held for all transparent keys
- gui key is released and reset around the press of listed keys (handled automatically by process_record_user)
,-------------------------------------------------------------------------------------------------.
|CMD+Tab|   !   |   @   |         |       |       |       |       |       |   (   |       |  Del  |
|-------+-------+-------+---------+-------+-------+-------+-------+-------+-------+-------|-------|
| CMD+` |       |       |         |       |       |       |       |       |       |       |       |
|-------+-------+-------+---------+-------+-------+-------+-------+-------+-------+-------|-------|
|       |       |       |         |       |       |   _   |       |       |       |       |       |
|-------+-------+-------+---------+-------+-------+-------+-------+-------+-------+-------|-------|
|       |       |       |*COMMAND*|       |       |       |       |       |       |       |       |
`-------------------------------------------------------------------------------------------------'
 */
[_COMMAND] = LAYOUT_planck_grid(
    CMD_TAB, KC_EXLM, KC_AT,   _______, _______, _______, _______, _______, _______, KC_LPRN, _______, KC_DEL,
    CMD_GRV, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_UNDS, _______, _______, _______, _______, _______,
    _______, _______, KC_NO,   _______, _______, _______, _______, _______, _______, KC_CAPS, _______, _______
),

/* Adjust (Lower + Raise)
                     v------------------------RGB CONTROL------------------------v
,-----------------------------------------------------------------------------------------.
|      | Reset|Debug | RGB  |RGBMOD  | HUE+ | HUE- | SAT+   | SAT- |BRGTH+|BRGTH-|  Sleep |
|------+------+------+------+--------+------+------+--------+------+------+------+--------|
|      |      |MUSmod|Aud on|Audoff  |AGnorm|AGswap|Qwerty  |      |      |      |        |
|------+------+------+------+--------+------+------+--------+------+------+------+--------|
|      |Voice-|Voice+|Mus on|Musoff  |MIDIon|MIDIof|TermOn  |TermOf|      |      |        |
|------+------+------+------+--------+------+------+--------+------+------+------+--------|
|      |      |      |      |*ADJUST*|      |      |*ADJUST*|      |      |      |        |
`-----------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, SLEEP,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};


#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool is_keycode_excluded(uint16_t keycode) {
  return keycode == CMD_GRV || keycode == CMD_TAB;
}

bool is_key_on_layer(uint16_t keycode, int layer) {
  for (int row = 0; row < MATRIX_ROWS; row++) {
    for (int col = 0; col < MATRIX_COLS; col++) {
      if (keycode == keymaps[layer][row][col]) {
        return true;
      }
    }
  }
  return false;
}

bool should_remove_gui(uint16_t keycode, bool key_pressed) {
  return !is_keycode_excluded(keycode) && key_pressed && is_key_on_layer(keycode, _COMMAND);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // unset GUI on COMMAND Layer keys that exist on its map, except CMD keys
  uint16_t current_layer = biton32(layer_state);
  if (current_layer == _COMMAND && keycode != COMMAND) {
    if (should_remove_gui(keycode, record->event.pressed)) {
      unregister_mods(MOD_LGUI);
    } else {
      register_mods(MOD_LGUI);
    }
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case SLEEP:
      if (record->event.pressed) {
        // Mac
        register_code(KC_LGUI);
        register_code(KC_LALT);
        tap_code(KC_POWER);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);

        // Windows
        tap_code(KC_SLEP);
      }
      return false;
    case COMMAND: // set GUI when COMMAND layer active
      if (record->event.pressed) {
        register_mods(MOD_LGUI);
      } else {
        unregister_mods(MOD_LGUI);
      }
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
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
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
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
