// Copyright 2021 Paul Maria Scheikl (@ScheiklP)
// SPDX-License-Identifier: GPL-2.0-or-later


#include QMK_KEYBOARD_H
#include "koy_keys_on_quertz_de_latin1.h"

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
    _3,
    _4,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_1] = LAYOUT_split_4x6_5(
     KC_ESC  , KC_1 , KC_2    , KC_3      , KC_4      , KC_5      ,                     KC_6 , KC_7 , KC_8    , KC_9 , KC_0 , KC_BSPC ,
     KC_TAB  , KC_K , KC_DOT  , KC_O      , KC_COMM   , N_Y       ,                     KC_V , KC_G , KC_C    , KC_L , N_SS , N_Z     ,
     MO(_3)  , KC_H , KC_A    , KC_E      , KC_I      , KC_U      ,                     KC_D , KC_T , KC_R    , KC_N , KC_S , KC_F    ,
     KC_LSFT , KC_X , KC_Q    , TD(TD_AE) , TD(TD_UE) , TD(TD_OE) ,                     KC_B , KC_P , KC_W    , KC_M , KC_J , KC_RSFT ,

                                KC_LALT,  KC_SPC,   TD(TD_COPY_PASTE_CUT),    KC_ESC,  MO(_3),  MO(_4),
                                          KC_LCTL,  KC_LGUI,                  KC_BSPC, KC_ENTER
  ),

  [_3] = LAYOUT_split_4x6_5(
     KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
     KC_TAB  , N_DOTS ,  N_USC   , N_LSQBR , N_RSQBR , N_CIRC  ,       N_EXKL , N_LT      , N_GT    , N_EQ    , N_AMP  , N_ACUT  ,
     KC_TRNS , N_BSLS ,  N_SLSH  , N_LCUBR , N_RCUBR , N_ASTR  ,       N_QUES , N_LPARN   , N_RPARN , N_MINS  , N_COLN , N_AT    ,
     KC_LSFT , N_HASH ,  N_DLR   , N_PIPE  , N_TILD  , N_GRAVE ,       N_PLUS , N_PERC    , N_QUOT  , N_SING  , N_SEMI , KC_RSFT ,

                                KC_LALT,  KC_SPC,   TD(TD_COPY_PASTE_CUT),    KC_ESC,  KC_TRNS,  KC_TRNS,
                                          KC_LCTL,  KC_LGUI,                  KC_BSPC, KC_ENTER
  ),

  [_4] = LAYOUT_split_4x6_5(
     KC_ESC,  KC_F11,   KC_F12,   KC_F3,   KC_F4,    KC_F5,                      KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,      KC_BSPC,
     KC_TAB,  KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,   KC_PGDN,                    KC_KP_SLASH,    KC_7,    KC_8,    KC_9,    KC_KP_MINUS, RGB_TOG,
     KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,                     KC_KP_ASTERISK, KC_4,    KC_5,    KC_6,    KC_KP_PLUS,  RGB_MODE_FORWARD,
     KC_LSFT, KC_ESC,  KC_TAB,  KC_INS,  KC_ENTER, N_UNDO,                     KC_0,           KC_1,    KC_2,    KC_3,    KC_KP_DOT,   KC_RSFT,

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
            register_code(N_UE);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT));
            register_code(N_UE);
            break;
        default: break;
    }
}

void shift_umlaut_u_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(N_UE);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT));
            unregister_code(N_UE);
            break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void shift_umlaut_o_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            register_code(N_OE);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT));
            register_code(N_OE);
            break;
        default: break;
    }
}

void shift_umlaut_o_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(N_OE);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT));
            unregister_code(N_OE);
            break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void shift_umlaut_a_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            register_code(N_AE);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT));
            register_code(N_AE);
            break;
        default: break;
    }
}

void shift_umlaut_a_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(N_AE);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT));
            unregister_code(N_AE);
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
