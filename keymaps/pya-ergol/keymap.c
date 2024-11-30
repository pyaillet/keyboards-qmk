#include QMK_KEYBOARD_H

// led effects
#define LED_FLASH_INTERVAL 100
#define RGBLIGHT_DEFAULT_VAL 255
#define RGBLIGHT_DEFAULT_HUE 169
#define RGBLIGHT_DEFAULT_SAT 255

#define DELAY_TAP_CODE 10

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY,
  _ERGOL,
  //_ADJUST,
  _SPEC1,
  _SPEC2,
  _NAV,
  _ALT
};

#define MY_MUTE KC_KB_MUTE
#define MY_VOLU KC_KB_VOLUME_UP
#define MY_VOLD KC_KB_VOLUME_DOWN

enum my_keycodes {
  MY_ATRE = SAFE_RANGE,
  MY_ETRE,
  MY_HTRE,
  MY_ITRE,
  MY_OTRE,
  MY_TTRE,
  MY_UTRE,
  MY_WTRE,
  MY_XTRE,
  MY_YTRE,
  MY_ACIR,
  MY_ECIR,
  MY_ICIR,
  MY_OCIR,
  MY_UCIR,
  MY_AGRV,
  MY_EGRV,
  MY_UGRV,
  MY_EACT,
  MY_APST,
  MY_3DTS,
  MY_AE,
  MY_OE,
  MY_MICR,
  MY_DSH1,
  MY_DSH2,
  MY_BTAB,
  MY_ESST,
  MY_NTIL,
  MY_MDOT,
  MY_CCDL,
  MY_STAR,
  MY_SWTC,
  MY_RST
};

#define NA_SPC LT(_NAV, KC_SPC)
#define SH_BSPC MT(MOD_LSFT, KC_BSPC)
#define AL_ENT LT(_ALT, KC_ENT)

#define LG_S LGUI_T(KC_S)
#define LA_E LALT_T(KC_E)
#define LC_N LCTL_T(KC_N)
#define RC_R RCTL_T(KC_R)
#define RA_T RALT_T(KC_T)
#define RG_I RGUI_T(KC_I)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     *
     * ,----------------------------------. ,----------------------------------.
     * |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  |
     * |------+------+------+------+------| |------+------+------+------+------|
     * |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |
     * |------+------+------+------+------| |------+------+------+------+------|
     * |   Z  |   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |   /  |
     * `----------------------------------' `----------------------------------'
     *             ,--------------------.    ,--------------------.
     *             | LALT | LGUI |Space |    |Space | RGUI | RALT |
     *             `--------------------'    `--------------------.
     */

    // Default config uses home row mods. So hold each of the keys on the home
    // row to use ctrl, gui, alt, or shift
    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, 
	KC_A,   KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
	KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, 
	                 KC_LALT, KC_LGUI, KC_SPC,     KC_SPC,  KC_RGUI, KC_RALT
    ),

    /* Ergol
     *
     * ,----------------------------------. ,----------------------------------.
     * |   Q  |   C  |   O  |   P  |   W  | |   J  |   M  |   D  | str  |   Y  |
     * |------+------+------+------+------| |------+------+------+------+------|
     * |   A  |   S  |   E  |   N  |   F  | |   L  |   R  |   T  |   I  |   U  |
     * |------+------+------+------+------| |------+------+------+------+------|
     * |   Z  |   X  |   -  |   V  |   B  | |   .  |   H  |   G  |   ,  |   K  |
     * `-------------+--------------------' `----------------------------------'
     *             ,--------------------.    ,--------------------.
     *             | LGUI | BSpc |Space |    |Space |Enter | RGUI |
     *             `--------------------'    `--------------------.
     */

    // Default config uses home row mods. So hold each of the keys on the home
    // row to use ctrl, gui, alt, or shift
    [_ERGOL] = LAYOUT_split_3x5_3(
        KC_Q, KC_C, KC_O,    KC_P,    KC_W,   KC_J,   KC_M,   KC_D,   MY_STAR, KC_Y,
	KC_A, LG_S, LA_E,    LC_N,    KC_F,   KC_L,   RC_R,   RA_T,   RG_I,    KC_U, 
	KC_Z, KC_X, KC_MINS, KC_V,    KC_B,   KC_DOT, KC_H,   KC_G,   KC_COMM, KC_K, 
	            KC_LGUI, SH_BSPC, NA_SPC, NA_SPC, AL_ENT, KC_RGUI
    ),

    /* Nav
     *
     * ,----------------------------------. ,----------------------------------.
     * |  Tab | Home |  Up  | End  | PgUp | |   -  |  7   |   8  |   9  |      |
     * |------+------+------+------+------| |------+------+------+------+------|
     * |  Caps| Left | Down | Right| PgDo | |   :  |  4   |   5  |   6  |   0  |
     * |------+------+------+------+------| |------+------+------+------+------|
     * |  Ctrl|VolDow| Mute | VolUp|BkTab | |      |  1   |   2  |   3  |      |
     * `----------------------------------' `----------------------------------'
     *             ,--------------------.    ,--------------------.
     *             |      |      |      |    |      |      |      |
     *             `--------------------'    `--------------------.
     */
    [_NAV] = LAYOUT_split_3x5_3(
        KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_MINS, KC_7,   KC_8,   KC_9, _______, 
	KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_COLN, KC_4,   KC_5,   KC_6, KC_0, 
	_______, MY_VOLU, MY_MUTE, MY_VOLD, MY_BTAB, _______, KC_1,   KC_2,   KC_3, _______,
                          MY_SWTC, KC_DEL,  _______, _______, KC_ESC, MY_SWTC
    ),

    /* Alt
     *
     * ,----------------------------------. ,----------------------------------.
     * | Circ |   <  |   >  |   $  |   %  | |   @  |   &  |   *  |   '  |   `  |
     * |------+------+------+------+------| |------+------+------+------+------|
     * |  {   |   (  |   )  |   }  |   =  | |   \  |   +  |   -  |   /  |   "  |
     * |------+------+------+------+------| |------+------+------+------+------|
     * |  ~   |   [  |   ]  |   _  |   #  | |   |  |   !  |   ;  |   :  |   ?  |
     * `----------------------------------' `----------------------------------'
     *             ,--------------------.    ,--------------------.
     *             | LOWER|      |      |    |  Del |      | RAISE|
     *             `--------------------'    `--------------------.
     */
    [_ALT] = LAYOUT_split_3x5_3(
        KC_CIRC, KC_LT,   KC_GT,   KC_DLR,  KC_PERC, KC_AT,   KC_AMPR, KC_ASTR, KC_QUOT, KC_GRV,
	KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_EQL,  KC_BSLS, KC_PLUS, KC_MINS, KC_SLSH, KC_DQUO, 
	KC_TILD, KC_LBRC, KC_RBRC, KC_UNDS, KC_HASH, KC_PIPE, KC_EXLM, KC_SCLN, KC_COLN, KC_QUES, 
                          _______, _______, _______, _______, _______, _______
    ),

    /* Spec1
     *
     * ,----------------------------------. ,----------------------------------.
     * | RGB_T| RGB_R| RGB_F|      |QWERTY| |   F1 |  F2  |  F3  |  F4   |  F5 |
     * |------+------+------+------+------| |------+------+------+------+------|
     * | SPD_I| HUE_I| SAT_I| VAL_I|COLEMK| |   F6 |  F7  |  F8  |  F9  |  F10 |
     * |------+------+------+------+------| |------+------+------+------+------|
     * | SPD_D| HUE_D| SAT_D| VAL_D|      | |  F11 |  F12 |      |      | Reset|
     * `----------------------------------' `----------------------------------'
     *             ,--------------------.    ,--------------------.
     *             | LOWER|      |      |    |      |      | RAISE|
     *             `--------------------'    `--------------------.
     */
    /*
    [_ADJUST] =  LAYOUT_split_3x5_3(
      RGB_TOG, RGB_RMOD, RGB_MOD, _______, TO(_QWERTY),       KC_F1,   KC_F2,
    KC_F3,   KC_F4,    KC_F5, RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, TO(_COLEMAK),
    KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10, RGB_SPD, RGB_HUD,  RGB_SAD,
    RGB_VAD, _______,           KC_F11,  KC_F12,  _______, _______,  QK_BOOT,
                         _______, _______, _______,           _______, _______,
    _______
    ),
    */

    /* Spec1
     *
     * ,----------------------------------. ,----------------------------------.
     * |   â  |   ç  |   œ  |   ô  |      | |      |   µ  |   _  |   "  |   û  |
     * |------+------+------+------+------| |------+------+------+------+------|
     * |   à  |   é  |   è  |   ê  |   ñ  | |   (  |   )  |   î  |   ï  |   ù  |
     * |------+------+------+------+------| |------+------+------+------+------|
     * |   æ  |   ß  |      |   –  |   —  | |   …  |      |   µ  |   ·  |      |
     * `----------------------------------' `----------------------------------'
     *             ,--------------------.    ,--------------------.
     *             |      |      |      |    |      |      |      |
     *             `--------------------'    `--------------------.
     */
    [_SPEC1] = LAYOUT_split_3x5_3(
        MY_ACIR, MY_CCDL, MY_OE,   MY_OCIR, MY_RST,  MY_RST,  MY_MICR, KC_UNDS, MY_STAR, MY_UCIR,
	MY_AGRV, MY_EACT, MY_EGRV, MY_ECIR, MY_NTIL, KC_LPRN, KC_RPRN, MY_ICIR, MY_ITRE, MY_UGRV,
	MY_AE,   MY_ESST, MY_RST,  MY_DSH1, MY_DSH2, MY_3DTS, MY_RST,  MY_MICR, MY_MDOT, MY_RST, 
	                  MY_RST,  MY_RST,  MY_RST,  MY_RST,  MY_RST,  MY_RST
    ),

    /* Spec2
     *
     * ,----------------------------------. ,----------------------------------.
     * |      |      |   ö  |      |   ẅ  | |      |      |      |   ’  |   ÿ  |
     * |------+------+------+------+------| |------+------+------+------+------|
     * |   ä  |      |   ë  |      |      | |      |      |   ẗ  |   ï  |   ü  |
     * |------+------+------+------+------| |------+------+------+------+------|
     * |      |   ẍ  |      |      |      | |      |   ḧ  |      |      |      |
     * `----------------------------------' `----------------------------------'
     *             ,--------------------.    ,--------------------.
     *             |      |      |      |    |      |      |      |
     *             `--------------------'    `--------------------.
     */
    [_SPEC2] = LAYOUT_split_3x5_3(
        MY_RST,  MY_RST,  MY_OTRE, MY_RST, MY_WTRE, MY_RST, MY_RST,  MY_RST,  MY_STAR /* MY_APST */, MY_YTRE,
	MY_ATRE, MY_RST,  MY_ETRE, MY_RST, MY_RST,  MY_RST, MY_RST,  MY_TTRE, MY_ITRE, MY_UTRE,
	MY_RST,  MY_XTRE, MY_RST,  MY_RST, MY_RST,  MY_RST, MY_HTRE, MY_RST,  MY_RST,  MY_RST,
                          MY_RST,  MY_RST, MY_RST,  MY_RST, MY_RST,  MY_RST
    )
};

// clang-format on

#if defined(RGBLIGHT_ENABLE)
#define COLOR_QWERTY HSV_RED
#define COLOR_ERGOL HSV_BLUE
#define COLOR_SPEC1 HSV_PURPLE
#define COLOR_SPEC2 HSV_PINK
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  // return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  if (layer_state_is(_SPEC2)) {
    rgblight_sethsv_noeeprom(COLOR_SPEC2);
  } else if (layer_state_is(_SPEC1)) {
    rgblight_sethsv_noeeprom(COLOR_SPEC1);
  } else if (layer_state_is(_ERGOL)) {
    rgblight_sethsv_noeeprom(COLOR_ERGOL);
  } else {
    rgblight_sethsv_noeeprom(COLOR_QWERTY);
  }
  return state;
}

/**************** Switch layer ****************/
// a boolean is needed in addition of the current layer because some action are
// not on the based layer
static bool is_qwerty = true;
static bool is_ergol = false;

void switch_layer_to_qwerty(void) {
  is_qwerty = true;
  is_ergol = false;
  layer_clear();
  layer_move(_QWERTY);
  // notify_color_layer();
}

void switch_layer_to_ergol(void) {
  is_qwerty = false;
  is_ergol = true;
  layer_clear();
  layer_move(_ERGOL);
  // notify_color_layer();
}

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  if (is_keyboard_master()) {
    os_variant_t os_variant = detected_host_os();

    switch (os_variant) {
    case OS_LINUX:
    case OS_WINDOWS:
      // notify_color(HSV_RED);
      break;
    default:
      // notify_color(HSV_PURPLE);
      // switch_layer_to_ergol();
      break;
    }
    switch_layer_to_ergol();
  }
#endif
}

// 1st layer on the cycle
#define LAYER_CYCLE_START _ERGOL
// Last layer on the cycle
#define LAYER_CYCLE_END _SPEC2

bool handle_star(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MY_STAR:
    // Our logic will happen on presses, nothing is done on releases
    if (!record->event.pressed) {
      // We've already handled the keycode (doing nothing), let QMK know so no
      // further code is run unnecessarily
      return false;
    }

    uint8_t current_layer = get_highest_layer(layer_state);

    // Check if we are within the range, if not quit
    if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
      return false;
    }

    uint8_t next_layer = current_layer + 1;
    if (next_layer > LAYER_CYCLE_END) {
      next_layer = LAYER_CYCLE_START;
      layer_clear();
    }
    layer_move(next_layer);
    return false;

  // Process other keycodes normally
  default:
    return true;
  }
}

void reset_layer_cycle(void) {
  uint8_t current_layer = get_highest_layer(layer_state);
  if ((current_layer == _SPEC1) || (current_layer == _SPEC2)) {
    switch_layer_to_ergol();
  }
}

bool special_tap(keyrecord_t *record, uint16_t k1, uint16_t k2, uint16_t km,
                 bool shift) {
  if (record->event.pressed) {
    if (shift) {
      register_mods(MOD_LSFT);
    }
    register_mods(MOD_LALT);
    tap_code(k1);
    wait_ms(DELAY_TAP_CODE);
    unregister_mods(MOD_LALT);
    if (shift) {
      unregister_mods(MOD_LSFT);
    }
    tap_code(km);
    tap_code(k2);
    reset_layer_cycle();
    return false;
  }
  return true;
}

bool process_ergol(uint16_t keycode, keyrecord_t *record) {
  if (!handle_star(keycode, record)) {
    return false;
  }

  bool shift = false;
  if (get_mods() & MOD_MASK_SHIFT) {
    shift = true;
  }
  switch (keycode) {
  case MY_ATRE:
    if (!special_tap(record, KC_U, KC_A, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_ETRE:
    if (!special_tap(record, KC_U, KC_E, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_HTRE:
    if (!special_tap(record, KC_U, KC_H, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_ITRE:
    if (!special_tap(record, KC_U, KC_I, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_OTRE:
    if (!special_tap(record, KC_U, KC_O, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_TTRE:
    if (!special_tap(record, KC_U, KC_T, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_UTRE:
    if (!special_tap(record, KC_U, KC_U, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_WTRE:
    if (!special_tap(record, KC_U, KC_W, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_XTRE:
    if (!special_tap(record, KC_U, KC_X, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_YTRE:
    if (!special_tap(record, KC_U, KC_Y, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_ACIR:
    if (!special_tap(record, KC_6, KC_A, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_ECIR:
    if (!special_tap(record, KC_6, KC_E, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_ICIR:
    if (!special_tap(record, KC_6, KC_I, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_OCIR:
    if (!special_tap(record, KC_6, KC_O, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_UCIR:
    if (!special_tap(record, KC_6, KC_U, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_AGRV:
    if (!special_tap(record, KC_GRV, KC_A, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_EGRV:
    if (!special_tap(record, KC_GRV, KC_E, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_UGRV:
    if (!special_tap(record, KC_GRV, KC_U, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_EACT:
    if (!special_tap(record, KC_E, KC_E, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_APST:
  case MY_3DTS:
  case MY_AE:
  case MY_OE:
  case MY_MICR:
  case MY_DSH1:
  case MY_DSH2:
  case MY_BTAB:
  case MY_ESST:
  case MY_NTIL:
  case MY_MDOT:
  case MY_RST:
    reset_layer_cycle();
    return false;
  case MY_CCDL:
    if (!special_tap(record, KC_C, KC_C, KC_LALT, shift)) {
      return false;
    }
    break;
  case MY_SWTC:
    if (is_ergol) {
      switch_layer_to_qwerty();
    } else {
      switch_layer_to_ergol();
    }
    break;
  }

  return true;
}

// Add the behaviour of this new keycode
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_ergol(keycode, record)) {
    return false;
  }
  return true;
}
