#pragma once

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// defines what is a tap and what is a hold
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// disables hold auto-repeat.
#undef QUICK_TAP_TERM
#define QUICK_TAP_TERM 0

// combos config
#define COMBO_TERM 40
#define EXTRA_SHORT_COMBOS

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_MOVE_DELTA
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_DELAY

#define MOUSEKEY_DELAY          0
#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_MOVE_DELTA     4
#define MOUSEKEY_MAX_SPEED      3
#define MOUSEKEY_TIME_TO_MAX    64
#define MOUSEKEY_WHEEL_DELAY    0
