#include QMK_KEYBOARD_H
#include <color.h>
//#include "print.h"

enum layers {
    _QUIRKY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _SPECIAL,
    _QWERTY,
    _LAYERS_END
};

enum keycodes {
    QUIRKY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    QWERTY,
    BSP_DEL,
};

/*
#define LOWER  FN_MO13
#define RAISE  FN_MO23
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Quirky
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;:  |  "'  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,<  |  .>  |  Up  |  /?  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Super| Alt  | Enter| Lower|    Space    | Raise| Bspc | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QUIRKY] = LAYOUT_ortho_4x12_1x2uC(
    KC_ESC , KC_Q   , KC_W   , KC_E        , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_DEL ,
    KC_TAB , KC_A   , KC_S   , KC_D        , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C        , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_UP  , KC_SLSH,
    KC_LCTL, KC_LGUI, KC_LALT, MO(_SPECIAL), LOWER  , KC_SPC          , RAISE  , KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | `~   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |  [{  |  ]}  |  +=  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      | PgUp |  |\  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Home | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12_1x2uC(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
    KC_DEL , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, KC_WBAK, KC_PGUP, KC_WFWD,
    _______, _______, _______, KC_MPLY, _______, KC_ENT          , _______, _______, KC_HOME, KC_PGDN, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Rwnd | Vol+ | Ffwd |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Play | Prev | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
    KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_INS ,
    KC_DEL , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, KC_MRWD, KC_VOLU, KC_MFFD,
    _______, _______, _______, _______, _______, BSP_DEL         , _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Clear|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
    RESET  , DEBUG  , _______, _______, _______, _______, RGB_TOG, RGB_MOD , RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,
    EE_CLR , _______, _______, _______, _______, _______, RGB_M_P, RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,
    _______, _______, _______, _______, _______, _______, _______, _______ , _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______         , _______ , _______, _______, _______, _______
),

[_SPECIAL] = LAYOUT_ortho_4x12_1x2uC(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL2, KC_BTN4, KC_WH_U, KC_BTN5,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_REC1, DM_REC2, XXXXXXX, KC_ACL1, KC_WH_L, KC_WH_D, KC_WH_R,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_PLY1, DM_PLY2, XXXXXXX, KC_ACL0, KC_BTN1, KC_MS_U, KC_BTN2,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, DM_RSTP         , XXXXXXX, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BLTog| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    RGB_TOG, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
};

HSV brighten(HSV hsv, uint8_t amount, bool limit_to_board_val) {
    // Brighten
    hsv.v += amount;

    // Enforce current default limit
    if (limit_to_board_val && hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }

    return hsv;
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    const uint8_t layer = get_highest_layer(layer_state);

    /*
    // Ignore layer 0
    if (get_highest_layer(layer_state) == 0) { return; }
    */

    // Color definitions
    const HSV hsv_f = {71, 211, 130};
    const HSV hsv_num = {122, 205, 72};
    /*const HSV hsv_qmk = {68, 56, 150};
    const HSV hsv_qmk_layers = {0, 0, 150};
    const HSV hsv_media = {234, 128, 150};*/
    const HSV hsv_reset = {0, 255, 150};

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            // Skip
            if (index < led_min || index > led_max || index == NO_LED) {
                continue;
            }

            // Read keycode from position
            const int keycode = keymap_key_to_keycode(layer, (keypos_t){col,row});

            HSV hsv = {0, 0, 0};
            if ((keycode >= KC_F1 && keycode <= KC_F12) || (keycode >= KC_F13 && keycode <= KC_F24)) {
                hsv = hsv_f;
            }
            else if (keycode == RESET || keycode == EE_CLR) {
                hsv = hsv_reset;
            }
            else if ((keycode >= KC_1 && keycode <= KC_0) || (keycode >= KC_KP_SLASH && keycode <= KC_KP_DOT) || keycode == KC_KP_EQUAL || keycode == KC_KP_COMMA || keycode == KC_KP_EQUAL_AS400) {
                hsv = hsv_num;
            }
            /*
            else if (keycode >= MACRO00 && keycode <= MACRO15) {
                continue;
            }
            else if (keycode >= USER00 && keycode <= USER15) {
                continue;
            }
            */
            /*
            else if (keycode >= LOWER && keycode <= ADJUST) {
                hsv = (HSV){rgb_matrix_get_hue(), rgb_matrix_get_sat(), 255};
                hsv = brighten(hsv, 255, false);
            }
            */
            else if (keycode == KC_TRNS) {
                // Resolve key below
                uint16_t keycode_below = keymap_key_to_keycode(layer_switch_get_layer((keypos_t){col,row}), (keypos_t){col,row});

                // Check if key below is a layer shift key
                if (keycode_below >= LOWER && keycode_below <= ADJUST) {
                    // Brighten default board color
                    hsv = (HSV){rgb_matrix_get_hue(), rgb_matrix_get_sat(), 255};
                    hsv = brighten(hsv, 255, false);
                }
                else {
                    // Blank KC_TRNS
                    rgb_matrix_set_color(index, 0, 0, 0);
                    continue;
                }
            }
            else if (keycode == KC_NO) {
                // Blank KC_NO
                rgb_matrix_set_color(index, 0, 0, 0);
                continue;
            }
            else {
                continue;  // Skip unknown keycodes
            }

            // Enforce config limit
            if (hsv.v > RGBLIGHT_LIMIT_VAL) {
                hsv.v = RGBLIGHT_LIMIT_VAL;
            }

            // Apply color
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t saved_mods   = 0;
    uint16_t       temp_keycode = keycode;

    // Filter out the actual keycode from MT and LT keys.
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        temp_keycode &= 0xFF;
    }

    switch (temp_keycode) {
        case BSP_DEL:
            if (record->event.pressed) {
                saved_mods = get_mods() & MOD_MASK_SHIFT;

                if (saved_mods == MOD_MASK_SHIFT) {  // Both shifts pressed
                    register_code(KC_DEL);
                } else if (saved_mods) {   // One shift pressed
                    del_mods(saved_mods);  // Remove any Shifts present
                    register_code(KC_DEL);
                    add_mods(saved_mods);  // Add shifts again
                } else {
                    register_code(KC_BSPC);
                }
            } else {
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
            }
            return false;
            break;
        /*
        case QK_CLEAR_EEPROM:
            eeconfig_init();
            reset_keyboard();
            break;
        */
        /*
        case RESET:
            //eeconfig_init();  // Force eeprom clear to reset changes in VIA.
            rgb_matrix_set_color_all(155, 0, 0);
            break;
        */
        case QUIRKY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QUIRKY);
            }
            return false;
            break;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
    }
    return true;
}
