#include QMK_KEYBOARD_H
#include "keymap.h"

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_MS_WH_RIGHT);
                } else {
                    tap_code(KC_MS_WH_LEFT);
                }
            } else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_MS_WH_UP);
                } else {
                    tap_code(KC_MS_WH_DOWN);
                }
            }
            break;
        case _NAV:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            } else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_PGDOWN);
                } else {
                    tap_code(KC_PGUP);
                }
            }
            break;
        case _SYM:
            break;
        case _ADJUST:
            break;
        default:
            break;
    }
    return true;
}
