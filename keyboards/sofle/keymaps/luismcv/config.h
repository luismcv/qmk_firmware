#pragma once

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#define TAPPING_TERM 200
#endif

//#define ONESHOT_TIMEOUT 5000

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Prevent accidental repeats of the tap-hold keys when typing quickly.
#define TAPPING_FORCE_HOLD_PER_KEY

#define COMBO_COUNT 1

#define OLED_TIMEOUT 20000
#define OLED_FADE_OUT true
//#define OLED_SCROLL_TIMEOUT 15000

#define MOUSEKEY_DELAY          0
#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_WHEEL_DELAY    0
#define MOUSEKEY_MAX_SPEED      6
#define MOUSEKEY_TIME_TO_MAX    64
