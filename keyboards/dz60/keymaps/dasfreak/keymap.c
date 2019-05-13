
#include QMK_KEYBOARD_H

// Layer Names
enum {
    BS_LAYER = 0,
    FN_LAYER,
    SYS_LAYER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Base Layer (ANSI Qwerty)i
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * |   Tab  |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * |    FN   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * |   Shift   |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | sft |  U  |PgDn |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Cmd  |  Alt  |              Space                | RAlt  | FN |  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_directional(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      MO(FN_LAYER), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_PGUP), KC_UP, KC_PGDN,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, MO(FN_LAYER), KC_LEFT, KC_DOWN, KC_RIGHT
    ),

  /* Function Layer (F-Keys + Umlaut + Navigation)
   * ,-----------------------------------------------------------------------------------------.
   * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |   DEL     |
   * |-----------------------------------------------------------------------------------------+
   * |        |     |     |  €  |     |     |     |  Ü  |     |  Ö  |     |     |     |        |
   * |-----------------------------------------------------------------------------------------+
   * |   SYS   |  Ä  |  ß  |     |     |     |     |     |     |     |     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     | INS |PgUp | DEL |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     | SYS  |Home |PgDn | End |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_directional(
      KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_DEL,
      _______, _______, _______, RALT(KC_5), _______, _______, _______, RALT(KC_Y), _______, RALT(KC_P), _______, _______, _______, _______,
      TO(SYS_LAYER), RALT(KC_Q), RALT(KC_S), _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS, KC_PGUP, KC_DEL,
      _______, _______, _______, _______, _______, _______, _______, TO(SYS_LAYER), KC_HOME, KC_PGDN, KC_END
      ),

    /* System Layer (Underglow + RESET)
     * ,-----------------------------------------------------------------------------------------.
     * |  BS |     |     |     |     |     |     |     |     |     |     |     |     |   RESET   |
     * |-----------------------------------------------------------------------------------------+
     * |        |RGB T|RGBH+|RGBS+|RGBV+|     |     |     |     |     |     |     |     |        |
     * |-----------------------------------------------------------------------------------------+
     * |         |RGB M|RGBH-|RGBS-|RGBV-|     |     |     |     |     |     |     |             |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
     * |-----------------------------------------------------------------------------------------+
     * |      |       |       |                                   |     |      |     |     |     |
     * `-----------------------------------------------------------------------------------------'
     */

    LAYOUT_directional(
        TO(BS_LAYER), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET, RESET,
        XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        ),
};
