#include QMK_KEYBOARD_H

enum layers {
  _DEFAULT,
  _COLOR,
  _RGBMODE,
  _RESET
};

enum custom_keycodes {
  SLEEP = SAFE_RANGE
};

#define TASKMAN LCTL(LSFT(KC_ESC))
#define COLOR_OR_F13 LT(_COLOR, KC_F13)
#define RGBMODE_OR_F14 LT(_RGBMODE, KC_F14)
#define RESET_OR_MUTE LT(_RESET, KC_MUTE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* DEFAULT
  ,--------------------------------------------.
  | Task Manager |  Toggle RGB  |    Sleep     |
  |--------------+--------------+--------------|
  |  _COLOR/F13  | _RGBMODE/F14 |     F15      |
  |--------------+--------------+--------------|
  | Volume Down  |  Volume Up   |  _RESET/Mute |
  `--------------------------------------------'
  */
  [_DEFAULT] = LAYOUT(
    TASKMAN,      RGB_TOG,        SLEEP,
    COLOR_OR_F13, RGBMODE_OR_F14, KC_F15,
    KC_VOLD,      KC_VOLU,        RESET_OR_MUTE
  ),

  /* COLOR
  ,--------------------------------------------.
  |              |  Hue Down    |    Hue Up    |
  |--------------+--------------+--------------|
  |   *COLOR*    |  Sat Down    |    Sat Up    |
  |--------------+--------------+--------------|
  |              |Brightness Up |Brightness Dn |
  `--------------------------------------------'
  */
  [_COLOR] = LAYOUT(
    KC_NO, RGB_HUD, RGB_HUI,
    KC_NO, RGB_SAD, RGB_SAI,
    KC_NO, RGB_VAD, RGB_VAI
  ),

  /* RGBMODE
  ,--------------------------------------------.
  |              |  RGB Toggle  |              |
  |--------------+--------------+--------------|
  |  Next Mode   |  *RGB Mode*  | Next Mode    |
  |--------------+--------------+--------------|
  |  Shift       |              |              |
  `--------------------------------------------'
  */
  [_RGBMODE] = LAYOUT(
    KC_NO,   _______, KC_NO,
    RGB_MOD, KC_NO,   RGB_MOD,
    KC_RSFT,   KC_NO,   KC_NO
  ),

  /* RESET
  ,--------------------------------------------.
  |   Reset      |              |              |
  |--------------+--------------+--------------|
  |              |              |              |
  |--------------+--------------+--------------|
  |              |              |   *RESET*    |
  `--------------------------------------------'
  */
  [_RESET] = LAYOUT(
    RESET,   _______, _______,
    _______, _______, _______,
    _______, _______, _______
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
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
  }

  return true;
}