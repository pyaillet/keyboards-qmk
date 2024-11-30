#include QMK_KEYBOARD_H

// led effects
#define LED_FLASH_INTERVAL 100
#define RGBLIGHT_DEFAULT_VAL 255
#define RGBLIGHT_DEFAULT_HUE 169
#define RGBLIGHT_DEFAULT_SAT 255


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | LOWER| Enter|   '  |    |BckSpc| Space| RAISE|
 *                  `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_split_3x5_3(
  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
  KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                              KC_LALT,      KC_LGUI,      KC_SPC,       KC_SPC,  KC_RGUI,      KC_RALT
),

/* Colemak
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |           |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   /  |
 * `-------------+--------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | LOWER| Enter|   '  |    |BckSpc| Space| RAISE|
 *                  `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_COLEMAK] = LAYOUT_split_3x5_3(
  KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,         KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN,
  LCTL_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_G,         KC_M,    RSFT_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), RCTL_T(KC_O),
  KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,         KC_K,    KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,
                              LOWER,        KC_ENT,       KC_QUOT,      KC_BSPC, KC_SPC,       RAISE
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Left | Down |  Up  | Right| Tab |           |      |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Ctrl|   `  |  GUI |  Alt |      |           |      |      |      |   \  |   '  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | LOWER|      |      |    |      |      | RAISE|
 *                  `--------------------'    `--------------------.
 */
[_RAISE] = LAYOUT_split_3x5_3(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,       _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
  KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, _______,      _______, _______, _______, KC_BSLS, KC_QUOT,
                    _______, _______, _______,      _______, _______, _______
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |      |      |      |      |           |      |   _  |   +  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Caps|   ~  |      |      |      |           |      |      |      |   |  |   "  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | LOWER|      |      |    |  Del |      | RAISE|
 *                  `--------------------'    `--------------------.
 */
[_LOWER] = LAYOUT_split_3x5_3(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_ESC,  _______, _______, _______, _______,      _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  KC_CAPS, KC_TILD, _______, _______, _______,      _______, _______, _______, KC_PIPE,  KC_DQT,
                    _______, _______, _______,      KC_DEL,  _______, _______
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * | RGB_T| RGB_R| RGB_F|      |QWERTY|           |   F1 |  F2  |  F3  |  F4  |  F5 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SPD_I| HUE_I| SAT_I| VAL_I|COLEMK|           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SPD_D| HUE_D| SAT_D| VAL_D|      |           |  F11 |  F12 |      |      | Reset|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | LOWER|      |      |    |      |      | RAISE|
 *                  `--------------------'    `--------------------.
 */
[_ADJUST] =  LAYOUT_split_3x5_3(
  RGB_TOG, RGB_RMOD, RGB_MOD, _______, TO(_QWERTY),       KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,
  RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, TO(_COLEMAK),      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,
  RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, _______,           KC_F11,  KC_F12,  _______, _______,  QK_BOOT,
                     _______, _______, _______,           _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/**************** Led effects ****************/

#if defined(RGBLIGHT_ENABLE)

bool              is_notify_color_layer = false;
uint8_t           notif_color[2];
uint8_t           flash_nb                 = 0;
bool              led_fade_off_in_progress = false;
rgblight_config_t previous_rgblight;

void rgblight_show_solid_color_noeeprom(uint8_t h, uint8_t s, uint8_t v) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(h, s, v);
}

void store_rgb_mode(void) {
    previous_rgblight.mode  = rgblight_get_mode();
    previous_rgblight.hue   = rgblight_get_hue();
    previous_rgblight.sat   = rgblight_get_sat();
    previous_rgblight.val   = rgblight_get_val();
    previous_rgblight.speed = rgblight_get_speed();
}

void restore_previous_rgb_mode(void) {
    rgblight_mode_noeeprom(previous_rgblight.mode);
#    ifdef RGBLIGHT_USE_TIMER
    // don't restart the animation to continue the rainbow mood at the previous hue
    // taken from rgblight_mode_eeprom_helper() in quantum/rgblight/rgblight.c
    animation_status.restart = false;
#    endif
    rgblight_sethsv_noeeprom(previous_rgblight.hue, previous_rgblight.sat, previous_rgblight.val);
    rgblight_set_speed_noeeprom(previous_rgblight.speed);
}

uint32_t led_off_callback(uint32_t trigger_time, void *cb_arg) {
    rgblight_sethsv_noeeprom(HSV_OFF);
    return 0;
}

void delay_led_off(void) {
    defer_exec(2000, led_off_callback, NULL);
}

uint32_t led_restore_mode_callback(uint32_t trigger_time, void *cb_arg) {
    restore_previous_rgb_mode();
    return 0;
}

uint32_t led_fade_off_callback(uint32_t trigger_time, void *cb_arg) {
    rgblight_decrease_val_noeeprom();
    if (rgblight_get_val() > 0) {
        return 35;
    } else {
        led_fade_off_in_progress = false;
        return 0;
    }
}

void delay_led_fade_off(void) {
    if (led_fade_off_in_progress) {
        return;
    }
    led_fade_off_in_progress = true;
    defer_exec(3000, led_fade_off_callback, NULL);
}

void led_fade_off(void) {
    if (led_fade_off_in_progress) {
        return;
    }
    led_fade_off_in_progress = true;
    defer_exec(1, led_fade_off_callback, NULL);
}

uint32_t flash_led_callback(uint32_t trigger_time, void *cb_arg) {
    rgblight_sethsv_noeeprom(notif_color[0], notif_color[1], RGBLIGHT_DEFAULT_VAL);
    flash_nb--;
    if (flash_nb > 0) {
        defer_exec(LED_FLASH_INTERVAL, led_off_callback, NULL);
        return LED_FLASH_INTERVAL * 2;
    } else {
        defer_exec(LED_FLASH_INTERVAL, led_restore_mode_callback, NULL);
        return 0;
    }
}

void notify_color(uint8_t hue, uint8_t sat, uint8_t val) {
    if (flash_nb <= 0) { // poor man lock
        store_rgb_mode();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);

        flash_nb            = 3;
        uint8_t color_cmd[] = {hue, sat, val};
        for (uint8_t i = 0; i < sizeof notif_color; i++) {
            notif_color[i] = color_cmd[i];
        }
        defer_exec(1, flash_led_callback, NULL);
    }
}

void notify_ko(void) {
    notify_color(HSV_RED);
}

void notify_warning(void) {
    notify_color(200, 255, 255);
}

#else
void notify_ko(void) {}
void notify_warning(void) {}
#endif

/**************** Switch layer ****************/


void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    if (is_keyboard_master()) {
	notif_color[0] = RGBLIGHT_DEFAULT_HUE;
	notif_color[1] = RGBLIGHT_DEFAULT_SAT;
        os_variant_t os_variant = detected_host_os();

        switch (os_variant) {
            case OS_LINUX:
            case OS_WINDOWS:
                //notify_color(HSV_RED);
                break;
            default:
                //notify_color(HSV_PURPLE);
                break;
        }
	rgblight_setrgb(RGB_ORANGE);
        is_notify_color_layer = true;
	rgblight_setrgb(RGB_ORANGE);
        rgblight_enable_noeeprom();
	rgblight_setrgb(RGB_ORANGE);
    }
    rgblight_setrgb(RGB_ORANGE);
    rgblight_sethsv_noeeprom(RGBLIGHT_DEFAULT_HUE,RGBLIGHT_DEFAULT_SAT,RGBLIGHT_DEFAULT_VAL);
#endif
}


