#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1

#define KC_ESCC MT(MOD_LCTL, KC_ESC)   // Control (hold), Escape (tap)
#define KC_LOWR MO(_LOWER)
#define KC_DELL LT(_LOWER, KC_DEL)   // Lower Layer (hold), Delete (tap)
#define KC_ENTL LT(_LOWER, KC_ENT)   // Lower Layer (hold), Return (tap)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
};

/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  |      | LOWER|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_pretty(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_FN0,   KC_1,
    KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                                                      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                                                      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_ESCC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                                                      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                                                      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,
            KC_GRV,   KC_INS,  KC_LEFT,  KC_RGHT,                                                                                          KC_UP,    KC_DOWN,  KC_LBRC,  KC_RBRC,
                                                      KC_LCTL,  KC_LALT,                                               KC_RALT, KC_RCTL,
                                                                KC_LALT,                                               KC_PGUP,
                                            KC_BSPC,  KC_DELL,  KC_LGUI,                                               KC_PGDN, KC_ENTL, KC_SPC),

  [_LOWER] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                                                _______, _______, _______, _______, _______, _______,
  _______, _______,   KC_UP, _______, _______, _______,                                                                _______, _______, _______, _______, _______, _______,
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                                                                KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______,                                                                _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______,                                                                                  _______, _______, _______, _______,
                                                        _______, _______,                            _______, _______,
                                                                 _______,                            _______,
                                               _______, _______, _______,                            _______, _______, _______
  )
};

void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_enable_noeeprom();                             // enables Rgb, without saving settings
  rgblight_sethsv_noeeprom(HSV_TEAL);                     // sets the color to teal/cyan without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT);  // sets mode to Fast breathing without saving
  /* rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
