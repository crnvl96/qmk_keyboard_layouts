#pragma once

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// defines what is a tap and what is a hold
#undef TAPPING_TERM
#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY

// disables hold auto-repeat.
#undef QUICK_TAP_TERM
#define QUICK_TAP_TERM 0

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64
