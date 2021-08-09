#pragma once

#include QMK_KEYBOARD_H

typedef union {
  uint32_t raw;
  struct {
    bool shifted_numbers : 1;
  };
} user_config_t;

extern user_config_t user_config;
