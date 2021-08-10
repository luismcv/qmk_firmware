#pragma once

#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

enum sofle_layers
{
    _QWERTY,
    _COLEMAK,
    _SYM,
    _SYM_L,
    _SYM_R,
    _NAV,
    _MOUSE,
    _NUM,
    _ACUT,
    _DIAE,
    _ADJUST,
};

#define LAYER_NAMES layer_name[11][5] = {"Qwrt", "Clmk", "Sym", "SymL", "SymR", "Nav", "Mous", "Num", "Acut", "Diae", "Adj"};

extern bool layer_lock;