#include QMK_KEYBOARD_H
#include "user_config.h"

user_config_t user_config;

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) {
  user_config.raw = 0;
  user_config.shifted_numbers = false;
  eeconfig_update_user(user_config.raw);
}