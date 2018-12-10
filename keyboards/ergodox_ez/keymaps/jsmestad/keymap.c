#include QMK_KEYBOARD_H
#include "version.h"
#include "action_layer.h"
#include "eeconfig.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAMING 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  GAMING,
};

#define KC_PC TO(0)
#define KC_GM TO(3)

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
       EQL  , 1  , 2  , 3  , 4  , 5  ,    ,                      , 6  , 7  , 8  , 9  , 0  , MINS,
    //|-----+----+----+----+----+----+----|                 |----+----+----+----+----+----+-----|
       TAB  , Q  , W  , E  , R  , T  ,    ,                      , Y  , U  , I  , O  , P  , BSLS,
    //|-----+----+----+----+----+----|    |                 |    |----+----+----+----+----+-----|
       ESCC , A  , S  , D  , F  , G  ,                             H  , J  , K  , L  ,SCLN, QUOT,
    //|-----+----+----+----+----+----+----|                 |----+----+----+----+----+----+-----|
       LSFT , Z  , X  , C  , V  , B  ,    ,                      , N  , M  ,COMM, DOT,SLSH, RSFT,
    //|-----+----+----+----+----+----|    |                 |    |----+----+----+----+----+-----|
            , GRV,    ,    ,LOWR,                                      RASE,    ,LBRC,RBRC,    , // R46 (last field, is not working?)
    // |----+----+----+----+----+    +----|                 |----+    +----+----+----+----+----|
    //                            ,----+----,             ,----+----,
                                   LGUI,LALT,              LALT,RCTL,
    //                            |----+----+----|   |----+----+----|
                                                 ,    PGUP,
    //                            |    .    .----|   |----.    .    |
                                   BSPC,DEL ,LGUI,    PGDN, ENT, SPC 
    //                            ,----+----+----,   ,----+----+----,
  ),

  [_GAMING] = LAYOUT_ergodox_pretty_kc(
    //,-----+----+----+----+----+----+----.                 ,----+----+----+----+----+----+-----.
       GRV  , 1  , 2  , 3  , 4  , 5  ,    ,                      , 6  , 7  , 8  , 9  , 0  , MINS,
    //|-----+----+----+----+----+----+----|                 |----+----+----+----+----+----+-----|
       TAB  , Q  , W  , E  , R  , T  ,ESC ,                      , Y  , U  , I  , O  , P  , BSLS,
    //|-----+----+----+----+----+----|    |                 |    |----+----+----+----+----+-----|
       LCTL , A  , S  , D  , F  , G  ,                             H  , J  , K  , L  ,SCLN, QUOT,
    //|-----+----+----+----+----+----+----|                 |----+----+----+----+----+----+-----|
       LSFT , Z  , X  , C  , V  , B  , PC ,                      , N  , M  ,COMM, DOT,SLSH, RSFT,
    //|-----+----+----+----+----+----|    |                 |    |----+----+----+----+----+-----|
        LALT,    ,    ,    ,LOWR,                                      RASE,    ,LBRC,RBRC,    , // R46 (last field, is not working?)
    // |----+----+----+----+----+    +----|                 |----+    +----+----+----+----+----|
    //                            ,----+----,             ,----+----,
                                       ,    ,                  ,    ,
    //                            |----+----+----|   |----+----+----|
                                                 ,        ,
    //                            |    .    .----|   |----.    .    |
                                   SPC , SPC,    ,        ,    ,BSPC
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
            ,    ,    ,    ,    ,    , GM ,                      ,    ,    ,    ,    ,    ,     ,
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

};



// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_led_all_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        break;
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }

  return state;
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
  }
  return true;
}
