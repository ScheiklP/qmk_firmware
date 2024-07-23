// Copyright 2024 Paul Maria Scheikl (@ScheiklP)
// SPDX-License-Identifier: GPL-2.0-or-later


#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "mac_keys.h"

#define DE_DOTS RALT(KC_DOT) // …
#define DE_MAC_DOTS RALT(KC_DOT) // …
#define DE_UNDO LCTL(DE_Z) // CTRL+Z


typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    TD_COPY_PASTE_CUT,
    TD_UE,
    TD_OE,
    TD_AE,
};

td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void copy_paste_cut_finished(tap_dance_state_t *state, void *user_data);
void copy_paste_cut_reset(tap_dance_state_t *state, void *user_data);

enum custom_layers {
    _1,
    _1MAC,
    _3,
    _3MAC,
    _4,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_1] = LAYOUT_split_4x6_5(
     KC_ESC  , DE_1 , DE_2    , DE_3      , DE_4      , DE_5      ,                     DE_6 , DE_7 , DE_8    , DE_9 , DE_0 , KC_BSPC ,
     KC_TAB  , DE_K , DE_DOT  , DE_O      , DE_COMM   , DE_Y      ,                     DE_V , DE_G , DE_C    , DE_L , DE_SS, DE_Z     ,
     MO(_3)  , DE_H , DE_A    , DE_E      , DE_I      , DE_U      ,                     DE_D , DE_T , DE_R    , DE_N , DE_S , DE_F    ,
     KC_LSFT , DE_X , DE_Q    , TD(TD_AE) , TD(TD_UE) , TD(TD_OE) ,                     DE_B , DE_P , DE_W    , DE_M , DE_J , KC_RSFT ,

                                KC_LALT,  KC_SPC,   TD(TD_COPY_PASTE_CUT),    KC_ESC,  MO(_3),  MO(_4),
                                          KC_LCTL,  KC_LGUI,                  KC_BSPC, KC_ENTER
  ),

  [_1MAC] = LAYOUT_split_4x6_5(
     KC_ESC  , DE_MAC_1 , DE_MAC_2    , DE_MAC_3      , DE_MAC_4      , DE_MAC_5      ,                     DE_MAC_6 , DE_MAC_7 , DE_MAC_8    , DE_MAC_9 , DE_MAC_0 , KC_BSPC ,
     KC_TAB  , DE_MAC_K , DE_MAC_DOT  , DE_MAC_O      , DE_MAC_COMM   , DE_MAC_Y      ,                     DE_MAC_V , DE_MAC_G , DE_MAC_C    , DE_MAC_L , DE_MAC_SS, DE_MAC_Z     ,
     MO(_3)  , DE_MAC_H , DE_MAC_A    , DE_MAC_E      , DE_MAC_I      , DE_MAC_U      ,                     DE_MAC_D , DE_MAC_T , DE_MAC_R    , DE_MAC_N , DE_MAC_S , DE_MAC_F    ,
     KC_LSFT , DE_MAC_X , DE_MAC_Q    , TD(TD_AE) , TD(TD_UE) , TD(TD_OE) ,                     DE_MAC_B , DE_MAC_P , DE_MAC_W    , DE_MAC_M , DE_MAC_J , KC_RSFT ,

                                KC_LALT,  KC_SPC,   TD(TD_COPY_PASTE_CUT),    KC_ESC,  MO(_3MAC),  MO(_4),
                                          KC_LCTL,  KC_LGUI,                  KC_BSPC, KC_ENTER
  ),

  [_3] = LAYOUT_split_4x6_5(
     KC_ESC  , KC_F1   ,  KC_F2    , KC_F3   , KC_F4   , KC_F5   ,       KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_BSPC,
     KC_TAB  , DE_DOTS ,  DE_UNDS  , DE_LBRC , DE_RBRC , DE_DEG  ,       DE_EXLM , DE_LABK , DE_RABK , DE_EQL  , DE_AMPR , DE_ACUT,
     KC_TRNS , DE_BSLS ,  DE_SLSH  , DE_LCBR , DE_RCBR , DE_ASTR ,       DE_QUES , DE_LPRN , DE_RPRN , DE_MINS , DE_COLN , DE_AT  ,
     KC_LSFT , DE_HASH ,  DE_DLR   , DE_PIPE , DE_TILD , DE_GRV  ,       DE_PLUS , DE_PERC , DE_DQUO , DE_QUOT , DE_SCLN , KC_RSFT,

                                KC_LALT,  KC_SPC,   TD(TD_COPY_PASTE_CUT),    KC_ESC,  KC_TRNS,  KC_TRNS,
                                          KC_LCTL,  KC_LGUI,                  KC_BSPC, KC_ENTER
  ),

  [_3MAC] = LAYOUT_split_4x6_5(
     KC_ESC  , KC_F1   ,  KC_F2    , KC_F3   , KC_F4   , KC_F5   ,       KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_BSPC,
     KC_TAB  , DE_MAC_DOTS ,  DE_MAC_UNDS  , DE_MAC_LBRC , DE_MAC_RBRC , DE_MAC_DEG  ,       DE_MAC_EXLM , DE_MAC_LABK , DE_MAC_RABK , DE_MAC_EQL  , DE_MAC_AMPR , DE_MAC_ACUT,
     KC_TRNS , DE_MAC_BSLS ,  DE_MAC_SLSH  , DE_MAC_LCBR , DE_MAC_RCBR , DE_MAC_ASTR ,       DE_MAC_QUES , DE_MAC_LPRN , DE_MAC_RPRN , DE_MAC_MINS , DE_MAC_COLN , DE_MAC_AT  ,
     KC_LSFT , DE_MAC_HASH ,  DE_MAC_DLR   , DE_MAC_PIPE , DE_MAC_TILD , DE_MAC_GRV  ,       DE_MAC_PLUS , DE_MAC_PERC , DE_MAC_DQUO , DE_MAC_QUOT , DE_MAC_SCLN , KC_RSFT,

                                KC_LALT,  KC_SPC,   TD(TD_COPY_PASTE_CUT),    KC_ESC,  KC_TRNS,  KC_TRNS,
                                          KC_LCTL,  KC_LGUI,                  KC_BSPC, KC_ENTER
  ),

  [_4] = LAYOUT_split_4x6_5(
     KC_ESC  , KC_F11  , KC_F12  , KC_F3   , KC_F4    , KC_F5,            KC_F6          , KC_F7 , KC_F8 , KC_F9 , KC_F10      , KC_BSPC,
     KC_TAB  , KC_PGUP , KC_BSPC , KC_UP   , KC_DEL   , KC_PGDN,          KC_KP_SLASH    , KC_7  , KC_8  , KC_9  , KC_KP_MINUS , RGB_TOG,
     KC_TRNS , KC_HOME , KC_LEFT , KC_DOWN , KC_RIGHT , KC_END,           KC_KP_ASTERISK , KC_4  , KC_5  , KC_6  , KC_KP_PLUS  , RGB_MODE_FORWARD,
     KC_LSFT , KC_ESC  , KC_TAB  , KC_INS  , KC_ENTER , DE_UNDO,          KC_0           , KC_1  , KC_2  , KC_3  , KC_KP_DOT   , KC_RSFT,

                                KC_LALT,  KC_0,   TD(TD_COPY_PASTE_CUT),      RGB_HUI,  KC_TRNS,  KC_TRNS,
                                          KC_LCTL,  KC_LGUI,                  RGB_SAI, RGB_VAI
  ),
};

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void copy_paste_cut_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            register_mods(MOD_BIT(KC_LCTL));
            register_code(KC_C);
            break;
        case TD_DOUBLE_TAP:
            register_mods(MOD_BIT(KC_LCTL));
            register_code(KC_X);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LCTL));
            register_code(KC_V);
            break;
        default: break;
    }
}

void copy_paste_cut_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            unregister_mods(MOD_BIT(KC_LCTL));
            unregister_code(KC_C);
            break;
        case TD_DOUBLE_TAP:
            unregister_mods(MOD_BIT(KC_LCTL));
            unregister_code(KC_X);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCTL));
            unregister_code(KC_V);
            break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void shift_umlaut_u_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            register_code(DE_UDIA);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT));
            register_code(DE_UDIA);
            break;
        default: break;
    }
}

void shift_umlaut_u_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(DE_UDIA);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT));
            unregister_code(DE_UDIA);
            break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void shift_umlaut_o_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            register_code(DE_ODIA);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT));
            register_code(DE_ODIA);
            break;
        default: break;
    }
}

void shift_umlaut_o_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(DE_ODIA);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT));
            unregister_code(DE_ODIA);
            break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void shift_umlaut_a_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            register_code(DE_ADIA);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT));
            register_code(DE_ADIA);
            break;
        default: break;
    }
}

void shift_umlaut_a_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(DE_ADIA);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT));
            unregister_code(DE_ADIA);
            break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}



tap_dance_action_t tap_dance_actions[] = {
    [TD_COPY_PASTE_CUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, copy_paste_cut_finished, copy_paste_cut_reset),
    [TD_UE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shift_umlaut_u_finished, shift_umlaut_u_reset),
    [TD_OE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shift_umlaut_o_finished, shift_umlaut_o_reset),
    [TD_AE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shift_umlaut_a_finished, shift_umlaut_a_reset),
};

bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_MACOS:
            set_single_persistent_default_layer(_1MAC);
            break;
        case OS_IOS:
            set_single_persistent_default_layer(_1MAC);
            break;
        case OS_WINDOWS:
            set_single_persistent_default_layer(_1);
            break;
        case OS_LINUX:
            set_single_persistent_default_layer(_1);
            break;
        case OS_UNSURE:
            set_single_persistent_default_layer(_1);
            break;
    }

    return true;
}

