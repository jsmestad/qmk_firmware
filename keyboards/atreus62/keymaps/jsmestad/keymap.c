#include QMK_KEYBOARD_H
#include "atreus62.h"
#include "action_layer.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAMING 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER,
  ADJUST,
  GAMING,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS


#define KC_NAV MO(_RAISE)
#define KC_PC TO(0)
#define KC_GM TO(3)
#define KC_ADJ MO(_ADJUST)

#define KC_LOWR LOWER
#define KC_RASE RAISE

#define KC_ESCC MT(MOD_LCTL, KC_ESC)   // Control (hold), Escape (tap)
/* #define KC_BK_C MT(MOD_LGUI, KC_BSPC)  // Win/Cmd (hold), Backspace (tap) */
#define KC_SPCC MT(MOD_LGUI, KC_SPC)   // Win/Cmd (hold), Space (tap)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.           .----+----+----+----+----+----,
     EQL , 1  , 2  , 3  , 4  , 5  ,             6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,             Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
     ESCC, A  , S  , D  , F  , G  ,             H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
     LSPO, Z  , X  , C  , V  , B  ,             N  , M  ,COMM,DOT ,SLSH,RSPC,
  //|----+----+----+----+----+----+----| |----+----+----+----+----+----+----|
         ,LGUI,LALT,    ,LOWR,BSPC,DEL ,  ENT ,SPC ,RASE,LEAD,LBRC,RBRC,
  //,----+----+----+----+----+----+----. .----+----+----+----+----+----+----,
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.           .----+----+----+----+----+----,
     F12 , F1 , F2 , F3 , F4 , F5 ,             F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
         ,    , UP ,    ,    ,    ,                ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
         ,LEFT,DOWN,RGHT,    ,    ,            LEFT,DOWN, UP ,RGHT,LBRC,RBRC,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
         ,    ,    ,    ,    ,                ,    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----| |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,      ,    ,    ,    ,    ,    , GM
  //,----+----+----+----+----+----+----. .----+----+----+----+----+----+----,
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.           .----+----+----+----+----+----,
     GRV ,    ,    ,    ,    ,    ,            MPRV,MPLY,MNXT,VOLD,VOLU,    ,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
     EQL , 1  , 2  , 3  , 4  , 5  ,             6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
     PLUS,EXLM, AT ,HASH,DLR ,PERC,            CIRC,AMPR,ASTR,LPRN,RPRN,UNDS,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
         ,    ,    ,    ,    ,                ,    ,    ,LABK,RABK,QUES,    ,
  //|----+----+----+----+----+----+----| |----+----+----+----+----+----+----|
     ADJ ,    ,    ,    ,    ,    ,    ,      ,    ,    ,    ,    ,    ,
  //,----+----+----+----+----+----+----. .----+----+----+----+----+----+----,
  ),

  [_GAMING] = LAYOUT_kc(
  //,----+----+----+----+----+----.           .----+----+----+----+----+----,
     GRV , 1  , 2  , 3  , 4  , 5  ,             6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,             Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,             H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----|           |----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,             N  , M  ,COMM,DOT ,SLSH,RSPC,
  //|----+----+----+----+----+----+----| |----+----+----+----+----+----+----|
     ESC ,LGUI,LALT,    ,LOWR, SPC,BSPC,  ENT ,SPC ,RASE,LEAD,LBRC,RBRC, PC
  //,----+----+----+----+----+----+----. .----+----+----+----+----+----+----,
  ),

  [_ADJUST] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.               .-------+-------+-------+-------+-------+-------,
     _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
     RGB_TOG,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI,_______,                _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
     _______,_______,RGB_HUD,RGB_SAD,RGB_VAD,_______,                _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------||------+-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RESET
  //,-------+-------+-------+-------+-------+-------+-------..------+-------+-------+-------+-------+-------+-------,
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
  case _GAMING:
    rgblight_sethsv_noeeprom_purple();
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

LEADER_EXTERNS();

volatile bool did_leader_succeed;

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    // Initialize did_leader_succeed as well as leading to be false
    did_leader_succeed = leading = false;

    /* SEQ_ONE_KEY(KC_C) { */
    /*   // When I press KC_LEAD and then c, this sends CTRL + SHIFT + C */
    /*   SEND_STRING(SS_LCTRL(SS_LSFT("C"))); */
    /*   did_leader_succeed = true; */
    /* } */
    /* SEQ_ONE_KEY(KC_V) { */
    /*   // When I press KC_LEAD and then v, this sends CTRL + SHIFT + V */
    /*   SEND_STRING(SS_LCTRL(SS_LSFT("V"))); */
    /*   did_leader_succeed = true; */
    /* } */
    SEQ_TWO_KEYS(KC_I, KC_E) {
      SEND_STRING(SS_LCTRL(SS_LGUI(SS_TAP(X_SPACE)))); // macOS Emoji Selector
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_F, KC_F) {
      SEND_STRING(SS_LGUI(SS_TAP(X_SPACE))); // macOS spotlight
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_F, KC_D) {
      SEND_STRING(SS_TAP(X_ESCAPE)); // fd will trigger escape (matching emacs)
      did_leader_succeed = true;
    }

    // Call leader_end at the end of the function, instead of at
    // the start. This way, we're sure we have set did_leader_succeed.
    leader_end();
  }
}
void leader_start(void) {
  rgblight_sethsv_noeeprom_gold();
}

void leader_end(void) {
  if (did_leader_succeed) {
    rgblight_sethsv_noeeprom_green();
    wait_ms(300);
  } else {
    rgblight_sethsv_noeeprom_white();
    for (int i = 0; i < 4; i++) {
      rgblight_toggle_noeeprom(); // OFF
      wait_ms(100);
      rgblight_toggle_noeeprom(); // ON
      wait_ms(100);
    }
  }
  rgblight_sethsv_noeeprom_red();
}
