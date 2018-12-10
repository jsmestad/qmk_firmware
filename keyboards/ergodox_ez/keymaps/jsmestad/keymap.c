#include QMK_KEYBOARD_H
#include "version.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EPRM = SAFE_RANGE,
  LOWER,
  RAISE,
  VRSN,
  RGB_SLD
};

#define KC_ KC_TRNS
#define KC_____ KC_TRNS
#define ____ KC_TRNS
#define _______ KC_TRNS

#define KC_ESCC MT(MOD_LCTL, KC_ESC)    // Control (hold), Escape (tap)
#define KC_LOWR LOWER
#define KC_RASE RAISE

// TODO check out these configs for ideas:
// - qmk_firmware/keyboards/ergodox_infinity/keymaps/dudeofawesome/keymap.c
// - https://github.com/qmk/qmk_firmware/tree/master/layouts/community/ergodox/replicaJunction
      

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_ergodox_pretty_kc(
    //,-----+----+----+----+----+----+----.                 ,----+----+----+----+----+----+-----.
       EQL  , 1  , 2  , 3  , 4  , 5  ,____,                  ____, 6  , 7  , 8  , 9  , 0  , MINS,
    //|-----+----+----+----+----+----+----|                 |----+----+----+----+----+----+-----|
       TAB  , Q  , W  , E  , R  , T  ,____,                  ____, Y  , U  , I  , O  , P  , BSLS,
    //|-----+----+----+----+----+----|    |                 |    |----+----+----+----+----+-----|
       ESCC , A  , S  , D  , F  , G  ,                             H  , J  , K  , L  ,SCLN, QUOT,
    //|-----+----+----+----+----+----+----|                 |----+----+----+----+----+----+-----|
       LSFT , Z  , X  , C  , V  , B  ,____,                  ____, N  , M  ,COMM, DOT,SLSH, RSFT,
    //|-----+----+----+----+----+----|    |                 |    |----+----+----+----+----+-----|
        ____, GRV,____,____,LOWR,                                      ____,____,LBRC,RBRC,RASE,
    // |----+----+----+----+----+    +----|                 |----+    +----+----+----+----+----|
  
    //                            ,----+----,             ,----+----,
                                   APP ,LALT,              LALT,RCTL,
    //                            |----+----+----|   |----+----+----|
                                             HOME,    PGUP,
    //                            |    .    .----|   |----.    .    |
                                   BSPC,DEL ,END ,    PGDN, ENT, SPC 
    //                            ,----+----+----,   ,----+----+----,
  ),

  [_RAISE] = LAYOUT_ergodox_pretty_kc(
    //,-----+----+----+----+----+----+----.                 ,----+----+----+----+----+----+-----.
       F12  , F1 , F2 , F3 , F4 , F5 ,    ,                      , F6 , F7 , F8 , F9 , F10, F11 ,
    //|-----+----+----+----+----+----+----|                 |----+----+----+----+----+----+-----|
            ,    ,    ,    ,    ,    ,    ,                      ,    ,    ,    ,    ,    ,     ,
    //|-----+----+----+----+----+----|    |                 |    |----+----+----+----+----+-----|
            ,    ,    ,    ,    ,    ,                                ,    ,    ,    ,    ,     ,
    //|-----+----+----+----+----+----+----|                 |----+----+----+----+----+----+-----|
            ,    ,    ,    ,    ,    ,    ,                      ,    ,    ,    ,    ,    ,     ,
    //|-----+----+----+----+----+----|    |                 |    |----+----+----+----+----+-----|
            ,    ,    ,    ,    ,                                          ,    ,    ,    ,    ,
    // |----+----+----+----+----+    +----|                 |----+    +----+----+----+----+----|
  
    //                            ,----+----,             ,----+----,
                                       ,    ,                  ,    ,
    //                            |----+----+----|   |----+----+----|
                                                 ,        ,
    //                            |    .    .----|   |----.    .    |
                                       ,    ,    ,        ,    ,
    //                            ,----+----+----,   ,----+----+----,
  ),

  [_LOWER] = LAYOUT_ergodox_pretty_kc(
    //,-----+----+----+----+----+----+----.                 ,----+----+----+----+----+----+-----.
            ,    ,    ,    ,    ,    ,    ,                      ,MPRV,MPLY,MNXT,VOLD,VOLU,     ,
    //|-----+----+----+----+----+----+----|                 |----+----+----+----+----+----+-----|
            ,    , UP ,    ,    ,    ,    ,                      ,    ,    ,    ,    ,    ,     ,
    //|-----+----+----+----+----+----|    |                 |    |----+----+----+----+----+-----|
            ,LEFT,DOWN,RGHT,    ,    ,                            LEFT,DOWN, UP ,RGHT,    ,     ,
    //|-----+----+----+----+----+----+----|                 |----+----+----+----+----+----+-----|
            ,    ,    ,    ,    ,    ,    ,                      ,    ,    ,    ,    ,    ,     ,
    //|-----+----+----+----+----+----|    |                 |    |----+----+----+----+----+-----|
            ,    ,    ,    ,    ,                                          ,    ,    ,    ,    ,
    // |----+----+----+----+----+    +----|                 |----+    +----+----+----+----+----|
  
    //                            ,----+----,             ,----+----,
                                       ,    ,                  ,    ,
    //                            |----+----+----|   |----+----+----|
                                                 ,        ,
    //                            |    .    .----|   |----.    .    |
                                       ,    ,    ,        ,    ,
    //                            ,----+----+----,   ,----+----+----,
  ),
};

/* const uint16_t PROGMEM fn_actions[] = { */
/*     [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols) */
/* }; */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
