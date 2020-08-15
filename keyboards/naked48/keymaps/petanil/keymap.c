#include QMK_KEYBOARD_H
#include "koy_keys_on_quertz_de_latin1.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _1 = 0,
  _3,
  _4,
  _7,
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_1] = LAYOUT( /* KOY */
    KC_ESC,  KC_K,     KC_DOT,  KC_O,    KC_COMM,  N_Y,                      KC_V,     KC_G,    KC_C,    KC_L,    N_SS,    N_Z,
    MO(_3),  KC_H,     KC_A,    KC_E,    KC_I,     KC_U,                     KC_D,     KC_T,    KC_R,    KC_N,    KC_S,    KC_F,
    KC_LSFT, KC_X,     KC_Q,    N_AE,    N_UE,     N_OE,                     KC_B,     KC_P,    KC_W,    KC_M,    KC_J,    KC_RSFT,
             KC_LCTRL, MO(_4),  KC_HOME, KC_LALT,  KC_SPC,  N_COPY, N_PASTE, KC_ENTER, MO(_4),  KC_RCTL, KC_TRNS, MO(_7)
  ),

  [_3] = LAYOUT( /* Layer 3 */
    KC_ESC,  N_DOTS,   N_USC,   N_LSQBR, N_RSQBR, N_CIRC,                   N_EXKL,   N_LT,    N_GT,    N_EQ,    N_AMP,   KC_TRNS,
    KC_TRNS, N_BSLS,   N_SLSH,  N_LCUBR, N_RCUBR, N_ASTR,                   N_QUES,   N_LPARN, N_RPARN, N_MINS,  N_COLN,  N_AT,
    KC_LSFT, N_HASH,   N_DLR,   N_PIPE,  N_TILD,  N_GRAVE,                  N_PLUS,   N_PERC,  N_QUOT,  N_SING,  N_SEMI,  KC_RSFT,
             KC_LCTRL, KC_TRNS, KC_HOME, KC_LALT, KC_SPC,  N_COPY, N_PASTE, KC_ENTER, KC_TRNS, KC_RCTL, KC_TRNS, KC_TRNS
  ),

  [_4] = LAYOUT( /* Layer 4 */
    KC_ESC,  KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,   KC_PGDN,                    KC_7,    KC_8,    KC_9,    KC_KP_MINUS, KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,                     KC_4,    KC_5,    KC_6,    KC_KP_PLUS,  KC_TRNS,  KC_TRNS,
    KC_LSFT, KC_ESC,  KC_TAB,  KC_INS,  KC_ENTER, N_UNDO,                     KC_1,    KC_2,    KC_3,    KC_KP_DOT,   KC_RSFT,  KC_RSFT,
             KC_LCTRL, KC_TRNS, KC_HOME, KC_LALT, KC_SPC,  N_COPY, N_PASTE, KC_ENTER, KC_TRNS, KC_RCTL, KC_TRNS, KC_TRNS
  ),

  [_7] = LAYOUT( /* Layer 7 */
    KC_ESC,  KC_MS_WH_UP,  KC_MS_BTN2, KC_MS_UP,   KC_MS_BTN1,  KC_MS_WH_DOWN,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
    KC_TRNS, KC_MS_ACCEL0, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_LSFT, KC_MS_ACCEL1, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,                           RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI,
             KC_LCTRL, KC_TRNS, KC_HOME, KC_LALT, KC_SPC,  N_COPY, N_PASTE, KC_ENTER, KC_TRNS, KC_RCTL, KC_TRNS, KC_TRNS
  )

};

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}

void matrix_init_user(void) {

}
