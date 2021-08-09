#include QMK_KEYBOARD_H
#include "keymap.h"

void up_down_arrows(bool clockwise) {
    if (clockwise) {
        for (int i = 0; i < 5; i++) tap_code(KC_UP);
    } else {
        for (int i = 0; i < 5; i++) tap_code(KC_DOWN);
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            } else if (index == 1) {
                up_down_arrows(clockwise);
            }
            break;
        case _NAV:
            if (index == 0) {
                if (clockwise) {
                    tap_code16(KC_MEDIA_NEXT_TRACK);
                } else {
                    tap_code16(KC_MEDIA_PREV_TRACK);
                }
            } else if (index == 1) {
                up_down_arrows(clockwise);
            }
            break;
        case _SYM:
            if (index == 0) {
                if (clockwise) {
                    tap_code16(C(KC_Y));
                } else {
                    tap_code16(C(KC_Z));
                }
            } else if (index == 1) {
                if (clockwise) {
                    tap_code16(C(KC_RGHT));
                } else {
                    tap_code16(C(KC_LEFT));
                }
            }
            break;
        case _ADJUST:
            break;
        default:
            break;
    }
    return true;
}
