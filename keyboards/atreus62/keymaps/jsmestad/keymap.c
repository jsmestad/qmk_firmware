// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "atreus62.h"
#include "action_layer.h"
/* #include "eeconfig.h" */

/* extern keymap_config_t keymap_config; */

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER,
  ADJUST,
  /* GAMING, */
};

#define KC_ KC_TRNS
#define _______ KC_TRNS


#define KC_NAV MO(_RAISE)
#define KC_PC TO(0)
#define KC_ADJ MO(_ADJUST)

#define KC_LOWR LOWER
#define KC_RASE RAISE

#define KC_ESCC MT(MOD_LCTL, KC_ESC)    // Control (hold), Escape (tap)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.           .----+----+----+----+----+----,
     EQL , 1  , 2  , 3  , 4  , 5  ,             6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,             Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
     ESCC, A  , S  , D  , F  , G  ,             H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,             N  , M  ,COMM,DOT ,SLSH,RSFT,
  //|----+----+----+----+----+----+----| |----+----+----+----+----+----+----|
         ,LGUI,LALT,    ,LOWR,BSPC,DEL ,  ENT ,SPC ,RASE,    ,LBRC,RBRC,
  //,----+----+----+----+----+----+----. .----+----+----+----+----+----+----,
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.           .----+----+----+----+----+----,
     GRV ,    ,    ,    ,    ,    ,            MPRV,MPLY,MNXT,VOLD,VOLU,    ,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
         ,    , UP ,    ,    ,    ,                ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
         ,LEFT,DOWN,RGHT,    ,    ,            LEFT,DOWN, UP ,RGHT,    ,    ,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
         ,    ,    ,    ,    ,                ,    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----| |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,      ,    ,    ,    ,    ,    ,
  //,----+----+----+----+----+----+----. .----+----+----+----+----+----+----,
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.           .----+----+----+----+----+----,
     F12 , F1 , F2 , F3 , F4 , F5 ,             F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
     ADJ ,    ,    ,    ,    ,                ,    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----| |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,      ,    ,    ,    ,    ,    ,
  //,----+----+----+----+----+----+----. .----+----+----+----+----+----+----,
  ),

  [_ADJUST] = LAYOUT(
    //,----+----+----+----+----+----.           .----+----+----+----+----+----,
       _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    //|----+----+----+----+----+----|           |----+----+----+----+----+----|
       RGB_TOG,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI,_______,_______,_______,_______,_______,_______,_______,
    //|-------+-------+-------+-------+-------+-------|           |----+----+----+----+----+----|
       _______,RGB_RMOD,RGB_HUD,RGB_SAD,RGB_VAD,_______,_______,_______,_______,_______,_______,_______,
    //|----+----+----+----+----+----|           |----+----+----+----+----+----|
       _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    //|----+----+----+----+----+----+----| |----+----+----+----+----+----+----|
       _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RESET
           /* ,    ,    ,    ,    ,    ,    ,      ,    ,    ,    ,    ,    ,RESET */
    //,----+----+----+----+----+----+----. .----+----+----+----+----+----+----,
  )
};



void matrix_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_setrgb_red();
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
  case _RAISE:
    rgblight_sethsv_noeeprom_azure();
    break;
  case _LOWER:
    rgblight_sethsv_noeeprom_springgreen();
    break;
  /* case _PLOVER: */
  /*   rgblight_setrgb (0x00,  0xFF, 0x00); */
  /*   break; */
  case _ADJUST:
    rgblight_sethsv_noeeprom_white();
    break;
  default: //  for any other layers, or the default layer
    rgblight_sethsv_noeeprom_red();
    break;
  }
  return state;
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
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
