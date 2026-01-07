/* Copyright 2025 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

void set_color_on_gaming_layer(uint8_t led_min, uint8_t led_max, uint8_t r, uint8_t g, uint8_t b, uint8_t r2, uint8_t g2, uint8_t b2);
void set_color_on_keys_used_by_layer(uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t r, uint8_t g, uint8_t b);

enum layers {
    BASE,
    GAMING,
    NAV,
    NUM,
    FN,
    FN1,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ansi_61(
        KC_GRV,           KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,             KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        LT(NUM, KC_TAB),  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,             KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        CTL_T(KC_ESC),    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,             KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,                    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,             KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
        KC_LCTL,          KC_LGUI,  KC_LALT,                                LT(NAV, KC_SPC),                                KC_RALT,  MO(FN),   MO(FN1),  KC_RCTL),

    [GAMING] = LAYOUT_ansi_61(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(FN),   MO(FN1),  KC_RCTL),

    [NAV] = LAYOUT_ansi_61(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BSPC,
        _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_INS,   KC_DEL,
        _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            KC_ENT,
        KC_LSFT,            KC_INS,   KC_DEL,   _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  QK_LLCK,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                _______,                                _______,  _______,  _______,  _______),

    [NUM] = LAYOUT_ansi_61(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_P7,    KC_P8,    KC_P9,  KC_PMNS,  _______,  _______,   KC_BSPC,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_P4,    KC_P5,    KC_P6,  KC_PPLS,  _______,  _______,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_P1,    KC_P2,    KC_P3,  KC_PAST,  _______,             KC_NUM,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  KC_PEQL,  KC_P0,  KC_PDOT,  KC_PSLS,  QK_LLCK,
        _______,  _______,  _______,                                KC_PENT,                              _______,  _______,  _______,   _______),

    [FN] = LAYOUT_ansi_61(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  UG_VALD,  UG_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        UG_TOGG,  UG_NEXT,  UG_VALU,  UG_HUEU,  UG_SATU,  UG_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            UG_PREV,  UG_VALD,  UG_HUED,  UG_SATD,  UG_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

    [FN1] = LAYOUT_ansi_61(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    KC_PSCR,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  _______,  _______,  _______,  _______,  _______,  TO(BASE),
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,   TO(GAMING))
};

// Keymap-level callback function to add custom layer indicators
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);
    switch(layer) {
        case 1: // GAMING
            set_color_on_gaming_layer(led_min, led_max, RGB_RED, RGB_WHITE);
            break;
        case 2: // NAV
            set_color_on_keys_used_by_layer(led_min, led_max, layer, RGB_CYAN);
            break;
        case 3: // NUM
            set_color_on_keys_used_by_layer(led_min, led_max, layer, RGB_GREEN);
            break;
        case 4: // FN
            set_color_on_keys_used_by_layer(led_min, led_max, layer, RGB_PURPLE);
            break;
        case 5: // FN1
            set_color_on_keys_used_by_layer(led_min, led_max, layer, RGB_ORANGE);
            break;
        default: // Let the RGB matrix effect for the base layer
            break;
    }
    return false;
}

void set_color_on_gaming_layer(uint8_t led_min, uint8_t led_max, uint8_t r, uint8_t g, uint8_t b, uint8_t r2, uint8_t g2, uint8_t b2) {
    uint8_t indexes[] = {16, 29, 30, 31}; // WASD
    uint8_t indexes2[] = {1, 2, 3, 4, 5, 15, 17, 18, 19, 32, 33, 41, 45, 53, 55};
    uint8_t length = sizeof(indexes);
    uint8_t length2 = sizeof(indexes2);

    for (uint8_t i = led_min; i < led_max; ++i) {
        if (i != NO_LED) {
            rgb_matrix_set_color(i, RGB_OFF);
        }
    }
    for(uint8_t i = 0; i < length; ++i) {
        if(indexes[i] != NO_LED) {
            rgb_matrix_set_color(indexes[i], r, g, b);
        }
    }
    for(uint8_t i = 0; i < length2; ++i) {
        if(indexes2[i] != NO_LED) {
            rgb_matrix_set_color(indexes2[i], r2, g2, b2);
        }
    }
}

// Function to set a color only on keys with configured keycodes
void set_color_on_keys_used_by_layer(uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED) {
                if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, r, g, b);
                } else {
                    rgb_matrix_set_color(index, RGB_OFF);
                }
            }
        }
    }
}
