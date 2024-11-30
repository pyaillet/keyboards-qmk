#pragma once

#define MASTER_RIGHT

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_LED_COUNT 36
  #define RGBLED_SPLIT {18, 18}
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 16
  #define RGBLIGHT_LIMIT_VAL 150 /* The maximum brightness level for RGBLIGHT_ENABLE */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
#endif


