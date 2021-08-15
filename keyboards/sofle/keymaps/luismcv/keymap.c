#include QMK_KEYBOARD_H
#include "keymap.h"
#include "user_config.h"

enum custom_keycodes
{
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    COMM_SCLN,
    DOT_COLN,
    DEAD_QUOT,
    SCROLL,
    LYRLCK,
    ALT_TAB,
    SFT_NUM
};

// Mappings for EurKEY layout
#define A_ACUT ALGR(KC_X)
#define E_ACUT ALGR(KC_G)
#define I_ACUT ALGR(KC_B)
#define O_ACUT ALGR(KC_DOT)
#define U_ACUT ALGR(KC_J)

#define A_DIAE ALGR(KC_A)
#define E_DIAE ALGR(KC_E)
#define I_DIAE ALGR(KC_I)
#define O_DIAE ALGR(KC_O)
#define U_DIAE ALGR(KC_U)

#define MUL ALGR(KC_EQL)
#define DIV S(MUL)
#define IEXCL ALGR(KC_1)
#define FORD ALGR(KC_2)
#define MORD ALGR(KC_3)
#define UKPND ALGR(KC_4)
#define EUR ALGR(KC_5)
#define LDQUO ALGR(KC_9)
#define RDQUO ALGR(KC_0)
#define CCED ALGR(KC_C)
#define IQUES ALGR(KC_SLASH)
// ----------------------

#define SPC_NAV LT(_NAV, KC_SPC)
#define DEL_SYM LT(_SYM, KC_DEL)
#define BSPC_NUM LT(_NUM, KC_BSPC)
#define ENT_SYM LT(_SYM, KC_ENT)
#define MOUSE MO(_MOUSE)

#define PREV_TAB C(KC_PGUP)
#define NEXT_TAB C(KC_PGDOWN)
#define PWD_MNGR C(KC_SLASH)
#define UNDO C(KC_Z)
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define PASTEU LCTL(KC_U)
#define FILTER LSA(KC_F)
#define RESFIL LSA(KC_R)
#define DUPLIC RCTL(KC_D)
#define LINBRK RCTL(KC_ENT)

#define N_TILD KC_INT1
#define C_N_TILD ALGR(KC_N)

// Left-hand home row mods QWERTY
#define MT_A LSFT_T(KC_A)
#define MT_S LCTL_T(KC_S)
#define MT_D LGUI_T(KC_D)
#define MT_F LALT_T(KC_F)

// Right-hand home row mods QWERTY
#define MT_J LALT_T(KC_J)
#define MT_K RGUI_T(KC_K)
#define MT_L RCTL_T(KC_L)
#define MT_NT RSFT_T(N_TILD)

// Left-hand home row mods Colemak-DHm
#define MT_C_A LSFT_T(KC_A)
#define MT_C_R LCTL_T(KC_R)
#define MT_C_S LGUI_T(KC_S)
#define MT_C_T LALT_T(KC_T)

// Right-hand home row mods Colemak-DHm
#define MT_C_N LALT_T(KC_N)
#define MT_C_E RGUI_T(KC_E)
#define MT_C_I RCTL_T(KC_I)
#define MT_C_O RSFT_T(KC_O)

bool          layer_lock       = false;
bool          layer_lock_done  = false;
layer_state_t prev_layer_state = 0;

bool     is_alt_tab_active = false;
uint16_t alt_tab_timer     = 0;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ,-----------------------------------------.                ,-----------------------------------------.
 * | ESC  | ! 1  | @ 2  | # 3  | $ 4  | % 5  |                | ^ 6  | & 7  | * 8  | ( 9  | ) 0  | - _  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |ALTAB |  Q   |  W   |  E   |  R   |  T   |                |  Y   |  U   |  I   |  O   |  P   | \ |  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | TAB  | A/⇧  | S/⎈  | D/◆  | F/⎇  |  G   |                |  H   | J/⎇  | K/◆  | L/⎈  | Ñ/⇧  | ´ ¨  |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |LSFT⇧ |  Z   |  X   |  C   |  V   |  B   | MUTE |  | MPLY |  N   |  M   | , ;  | . :  | / ?  |RSFT⇧ |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               | BTN2 |SCROLL| BTN1 |SP/NAV|DL/SYM|  |EN/SYM|BS/NUM|AltGr |RGUI◆ |RCTL⎈ |
 *               `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
[_QWERTY] = LAYOUT( \
  KC_ESC,    KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,   KC_7,   KC_8,      KC_9,     KC_0,     KC_MINUS, \
  ALT_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,   KC_U,   KC_I,      KC_O,     KC_P,     KC_BSLASH, \
  KC_TAB,    MT_A,   MT_S,    MT_D,    MT_F,    KC_G,                      KC_H,   MT_J,   MT_K,      MT_L,     MT_NT,    DEAD_QUOT, \
  KC_LSFT,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,  KC_MPLY,   KC_N,   KC_M,   COMM_SCLN, DOT_COLN, KC_SLASH, KC_RSFT, \
                KC_BTN2, SCROLL, KC_BTN1, SPC_NAV, DEL_SYM,      ENT_SYM,  BSPC_NUM, KC_RALT, KC_RGUI, KC_RCTL \
),

/* ,-----------------------------------------.                ,-----------------------------------------.
 * | ESC  | ! 1  | @ 2  | # 3  | $ 4  | % 5  |                | ^ 6  | & 7  | * 8  | ( 9  | ) 0  | - _  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |ALTAB |  Q   |  W   |  F   |  P   |  B   |                |  J   |  L   |  U   |  Y   |  ;   | \ |  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | TAB  | A/⇧  | R/⎈  | S/◆  | T/⎇  |  G   |                |  M   | N/⎇  | E/◆  | I/⎈  | O/⇧  |  '   |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |LSFT⇧ |  Z   |  X   |  C   |  D   |  V   | MUTE |  | MPLY |  K   |  H   |  ,   |  .   |  /   |RSFT⇧ |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               | BTN2 |SCROLL| BTN1 |SP/NAV|DL/SYM|  |EN/SYM|BS/NUM|AltGr |RGUI◆ |RCTL⎈ |
 *               `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
[_COLEMAK] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINUS, \
  ALT_TAB,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_BSLASH, \
  KC_TAB,   MT_C_A, MT_C_R,  MT_C_S,  MT_C_T,  KC_G,                      KC_M,    MT_C_N,  MT_C_E,  MT_C_I, MT_C_O,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_MUTE,   KC_MPLY,  KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
                KC_BTN2, SCROLL, KC_BTN1, SPC_NAV, DEL_SYM,      ENT_SYM,  BSPC_NUM, KC_RALT, KC_RGUI, KC_RCTL \
),

/* ,-----------------------------------------.                ,-----------------------------------------.
 * | LOCK |  ¡   |  ª   |  º   |  £   |  €   |                |  ^   |  &   |  *   |  “   |  ”   | BSPC |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |  ×   |  !   |  @   |  #   |  $   |  %   |                |  '   |  "   |  {   |  }   |  /   |  \   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  +   |  -   |  *   |  =   |  ~   |                |  ;   |  :   |  (   |  )   |  ¿   |  ÷   |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |      |  |   |  _   |  Ç   |  &   |  `   |      |  |      |  ,   |  .   |  <   |  >   |  ?   |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               |      |      |      |      |      |  |      |  [   |  ]   |      |      |
 *               `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
[_SYM] = LAYOUT( \
  LYRLCK,  IEXCL,   FORD,    MORD,    UKPND,   EUR,                         KC_CIRC, KC_AMPR, KC_ASTR, LDQUO,   RDQUO,   KC_BSPC,\
  MUL,     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_QUOT, KC_DQUO, KC_LCBR, KC_RCBR, KC_SLSH, KC_NUBS, \
  _______, KC_PLUS, KC_MINS, KC_ASTR, KC_EQL,  KC_TILD,                     KC_SCLN, KC_COLN, KC_LPRN, KC_RPRN, IQUES,   DIV, \
  _______, KC_PIPE, KC_UNDS, CCED,    KC_AMPR, KC_GRV, _______,    _______, KC_COMM, KC_DOT,  KC_LT,   KC_GT,   KC_QUES, _______, \
                   _______, _______, _______, _______, _______,       _______, KC_LBRC, KC_RBRC, _______, _______ \
),

/* ,-----------------------------------------.                ,-----------------------------------------.
 * | LOCK |NumLck|  P7  |  P8  |  P9  |  P-  |                |  ^   |  &   |  *   |  “   |  ”   | BSPC |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  P/  |  P4  |  P5  |  P6  |  P+  |                |  '   |  "   |  {   |  }   |  /   |  \   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  P*  |  P1  |  P2  |  P3  | PENT |                |  ;   |  :   |  (   |  )   |  ¿   |  ÷   |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |      | DEL  |  P0  |  P0  |  P.  | PENT |      |  |      |  ,   |  .   |  <   |  >   |  ?   |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               |      |      |      |      |      |  |      |  [   |  ]   |      |      |
 *               `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
[_SYM_L] = LAYOUT( \
  LYRLCK,  KC_NLCK, KC_P7,    KC_P8,  KC_P9,   KC_PMNS,                      KC_CIRC, KC_AMPR, KC_ASTR, LDQUO,   RDQUO,   KC_BSPC,\
  XXXXXXX, KC_PSLS, KC_P4,    KC_P5,  KC_P6,   KC_PPLS,                      KC_QUOT, KC_DQUO, KC_LCBR, KC_RCBR, KC_SLSH, KC_NUBS, \
  _______, KC_PAST, KC_P1,    KC_P2,  KC_P3,   KC_PENT,                      KC_SCLN, KC_COLN, KC_LPRN, KC_RPRN, IQUES,   DIV, \
  _______, KC_DEL,  KC_P0,    KC_P0,  KC_PDOT, KC_PENT, _______,    _______, KC_COMM, KC_DOT,  KC_LT,   KC_GT,   KC_QUES, _______, \
                   _______, _______, _______, _______, _______,       _______, KC_LBRC, KC_RBRC, _______, _______ \
),

/* ,-----------------------------------------.                ,-----------------------------------------.
 * | LOCK |  ¡   |  ª   |  º   |  £   |  €   |                |NumLck|  P7  |  P8  |  P9  |  P-  | BSPC |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |  ×   |  !   |  @   |  #   |  $   |  %   |                |  P/  |  P4  |  P5  |  P6  |  P+  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  +   |  -   |  *   |  =   |  ~   |                |  P*  |  P1  |  P2  |  P3  | PENT |      |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |      |  |   |  _   |  Ç   |  &   |  `   |      |  |      | DEL  |  P0  |  P0  |  P.  | PENT |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               |      |      |      |      |      |  |      |      |      |      |      |
 *               `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
[_SYM_R] = LAYOUT( \
  LYRLCK,  IEXCL,   FORD,    MORD,    UKPND,   EUR,                         KC_NLCK,  KC_P7,   KC_P8,  KC_P9,   KC_PMNS, KC_BSPC,\
  MUL,     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_PSLS,  KC_P4,   KC_P5,  KC_P6,   KC_PPLS, XXXXXXX, \
  _______, KC_PLUS, KC_MINS, KC_ASTR, KC_EQL,  KC_TILD,                     KC_PAST,  KC_P1,   KC_P2,  KC_P3,   KC_PENT, XXXXXXX, \
  _______, KC_PIPE, KC_UNDS, CCED,    KC_AMPR, KC_GRV, _______,    _______, KC_DEL,   KC_P0,   KC_P0,  KC_PDOT, KC_PENT, _______, \
                   _______, _______, _______, _______, _______,       _______, XXXXXXX, XXXXXXX, _______, _______ \
),

/* ,-----------------------------------------.                ,-----------------------------------------.
 * | LOCK |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |PrtScr|ScrLck|Pause |NumLck|      |                | HOME | PGDN |  UP  | PGUP | Ins  | F12  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |LSFT⇧ |LCTL⎈ |LGUI◆ |LALT⎇ | CAPS |                | END  | LEFT | DOWN | RGHT | DEL  | BSPC |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |      | UNDO | CUT  | COPY |PASTE |MOUSE |      |  |      |⯬WBAK | ←TAB |PWMNGR| →TAB |⯮WFWD |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               |      |      |      |      |      |  |      |      |      |      |      |
 *               `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
[_NAV] = LAYOUT( \
  LYRLCK,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,                       KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,\
  _______, KC_PSCR, KC_SLCK, KC_PAUSE, KC_NLCK, XXXXXXX,                     KC_HOME, KC_PGDN,  KC_UP,    KC_PGUP,   KC_INS,  KC_F12, \
  _______, KC_LSFT, KC_LCTL, KC_LGUI,  KC_LALT, KC_CAPS,                     KC_END,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_DEL,  KC_BSPC, \
  _______, UNDO,    CUT,     COPY,     PASTE,   MOUSE,   _______,   _______, KC_WBAK, PREV_TAB, PWD_MNGR, NEXT_TAB, KC_WFWD, _______, \
                   _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ \
),

/* ,-----------------------------------------.                ,-----------------------------------------.
 * | LOCK |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      | ACL0 | ACL1 | ACL2 |      |                | WH_L |WHEEL↓|MOUSE↑|WHEEL↑| WH_R | F12  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |LSFT⇧ |LCTL⎈ |LGUI◆ |LALT⎇ |      |                |      |MOUSE←|MOUSE↓|MOUSE→| DEL  | BSPC |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |      | UNDO | CUT  | COPY |PASTE |MOUSE |      |  |      |⯬WBAK | ←TAB |PWMNGR| →TAB |⯮WFWD |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               | BTN2 | BTN1 | BTN3 |      |      |  | BTN2 | BTN1 | BTN3 |      |      |
 *               `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
[_MOUSE] = LAYOUT( \
  LYRLCK,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,                       KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,\
  _______, XXXXXXX, KC_ACL0, KC_ACL1,  KC_ACL2, XXXXXXX,                     KC_WH_L, KC_WH_D,  KC_MS_U,  KC_WH_U,  KC_WH_R, KC_F12, \
  _______, KC_LSFT, KC_LCTL, KC_LGUI,  KC_LALT, XXXXXXX,                     XXXXXXX, KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_DEL,  KC_BSPC, \
  _______, UNDO,    CUT,     COPY,     PASTE,   MOUSE,   _______,   _______, KC_WBAK, PREV_TAB, PWD_MNGR, NEXT_TAB, KC_WFWD, _______, \
                   KC_BTN2, KC_BTN1, KC_BTN3, _______, _______,       KC_BTN2, KC_BTN1, KC_BTN3, _______, _______ \
),
 
/* ,-----------------------------------------.                ,-----------------------------------------.
 * | LOCK |  F2  | & 7  | * 8  | ( 9  |  P-  |                | UNDO | CUT  | COPY |PASTE |PASTEU|DUPLIC|
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  P/  | $ 4  | % 5  | ^ 6  |  P+  |                | HOME | PGDN |  UP  | PGUP | Ins  |FILTER|
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  P*  | ! 1  | @ 2  | # 3  | PENT |                | END  | LEFT | DOWN | RGHT | DEL  |RESFIL|
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |      | DEL  | ) 0  | ) 0  |  .   | PENT |      |  |      |⯬WBAK | ←TAB |PWMNGR| →TAB |⯮WFWD |LINBRK|
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               |      |      |      |      |      |  |      |      |      |      |      |
 *               `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
[_NUM] = LAYOUT( \
  LYRLCK,  KC_F2,   KC_7,    KC_8,  KC_9,   KC_PMNS,                      UNDO,    CUT,      COPY,     PASTE,    PASTEU,  DUPLIC,   
  _______, KC_PSLS, KC_4,    KC_5,  KC_6,   KC_PPLS,                      KC_HOME, KC_PGDN,  KC_UP,    KC_PGUP,  KC_INS,  FILTER, \
  _______, KC_PAST, KC_1,    KC_2,  KC_3,   KC_PENT,                      KC_END,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_DEL,  RESFIL, \
  _______, KC_DEL,  KC_0,    KC_0,  KC_DOT, KC_PENT, _______,    _______, KC_WBAK, PREV_TAB, PWD_MNGR, NEXT_TAB, KC_WFWD, LINBRK, \
                   _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ \
),

/* ,-----------------------------------------.                ,-----------------------------------------.
 * |      |      |      |      |      |      |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |  É   |      |      |                |      |  Ú   |  Í   |  Ó   |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  Á   |      |      |      |      |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               |      |      |      |      |      |  |      |      |      |      |      |
 *               `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
[_ACUT] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, E_ACUT , _______, _______,                         _______, U_ACUT , I_ACUT , O_ACUT , _______, _______, \
  _______, A_ACUT , _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,  _______,     _______,  _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ \
),

/* ,-----------------------------------------.                ,-----------------------------------------.
 * |      |      |      |      |      |      |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |  Ë   |      |      |                |      |  Ü   |  Ï   |  Ö   |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  Ä   |      |      |      |      |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               |      |      |      |      |      |  |      |      |      |      |      |
 *               `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
[_DIAE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, E_DIAE , _______, _______,                         _______, U_DIAE , I_DIAE , O_DIAE , _______, _______, \
  _______, A_DIAE , _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,     _______,  _______,  _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ \
),

/* ,-----------------------------------------.                ,-----------------------------------------.
 * |      |      |      |      |      |      |                |      |      | MSTP |      | WSTP | WSCH |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |RESET |      |QWERTY|COLEMA|SFTNUM|      |                |      | MPRV | MPLY | MNXT |      | WHOM |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                |      | VOLD | MUTE | VOLU |      | WFAV |
 * |------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------|
 * |      |POWER | PWR  | SLEP | WAKE | EJCT |      |  |      |      | CALC | MSEL | MYCM |      | WREF |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *               |      |      |      |      |      |  |      |      |      |      |      |
 *               `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX,  XXXXXXX ,  XXXXXXX ,   XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, KC_MSTP, XXXXXXX, KC_WSTP, KC_WSCH, \
  RESET,   XXXXXXX,  KC_QWERTY, KC_COLEMAK, SFT_NUM, XXXXXXX,                       XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_WHOM, \
  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX,                       XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, KC_WFAV, \
  XXXXXXX, KC_POWER, KC_PWR,    KC_SLEP,    KC_WAKE, KC_EJCT, XXXXXXX,     XXXXXXX, XXXXXXX, KC_CALC, KC_MSEL, KC_MYCM, XXXXXXX, KC_WREF, \
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
  )
};
// clang-format on

enum combos
{ BTN1_BTN2 };

const uint16_t PROGMEM btn1btn2_combo[] = {KC_BTN1, KC_BTN2, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {[BTN1_BTN2] = COMBO(btn1btn2_combo, KC_BTN3)};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_lock && prev_layer_state != 0) {
        layer_lock      = false;
        state           = prev_layer_state;
        layer_lock_done = true;
    } else {
        if (state == 0) {
            layer_lock_done = false;
        }
    }
    prev_layer_state = state;
    return update_tri_layer_state(state, _NAV, _NUM, _ADJUST);
}

#ifdef CONSOLE_ENABLE
void oneshot_layer_changed_user(uint8_t layer) {
    uprintf("Oneshot layer %d, %d on\n", layer, (get_mods() & MOD_MASK_SHIFT));
    if (!layer) {
        println("Oneshot layer off");
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();

#ifdef CONSOLE_ENABLE
    uprintf("KEYCODE: %d   %b   IS_KEY: %d IS_ANY: %d \n IS_MOD: %d\n", keycode, keycode, IS_KEY(keycode), IS_ANY(keycode), IS_MOD(keycode));
#endif

    // Remix of the behaviour of Spanish and US English keyboards
    // Quote followed by a wovel will add an acute accent to it
    // Similar with double quotes and diaeresis
    // Followed by anything else, will just send the quote or double quotes
    if ((layer_state_is(_ACUT) || layer_state_is(_DIAE)) && !IS_MOD(keycode)) {
        if (record->event.pressed) {
            switch (keycode) {
                case A_ACUT:
                case E_ACUT:
                case I_ACUT:
                case O_ACUT:
                case U_ACUT:
                case A_DIAE:
                case E_DIAE:
                case I_DIAE:
                case O_DIAE:
                case U_DIAE:
                    break;
                case DEAD_QUOT:
                    if (layer_state_is(_ACUT)) {
                        if (mod_state & MOD_MASK_SHIFT) {
                            del_mods(MOD_MASK_SHIFT);
                            tap_code(KC_QUOT);
                            set_mods(mod_state);
                            tap_code16(KC_DQUO);
                        } else {
                            tap_code16(KC_QUOT);
                        }
                    } else {
                        if (mod_state & MOD_MASK_SHIFT) {
                            tap_code16(KC_DQUO);
                        } else {
                            tap_code16(KC_DQUO);
                            del_mods(MOD_MASK_SHIFT);
                            tap_code(KC_QUOT);
                            set_mods(mod_state);
                        }
                    }
                    return false;
                default:
                    if (layer_state_is(_ACUT)) {
                        tap_code(KC_QUOT);
                    } else {
                        tap_code16(KC_DQUO);
                    }
            }
        }
    }

    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case SFT_NUM:
            if (record->event.pressed) {
                user_config.shifted_numbers ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;
        // Invert numbers and symbols on base layers
        case KC_1 ... KC_0:
            if (user_config.shifted_numbers && (layer_state_is(_QWERTY) || layer_state_is(_COLEMAK) || layer_state_is(_ACUT) || layer_state_is(_DIAE))) {
                if (record->event.pressed) {
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_SHIFT);
                        register_code(keycode);
                        set_mods(mod_state);
                    } else {
                        register_mods(MOD_LSFT);
                        register_code(keycode);
                        set_mods(mod_state);
                    }
                } else {
                    unregister_code(keycode);
                }
                return false;
            }
            return true;
        // Semicolon on shift + comma, like in Spanish keyboards
        case COMM_SCLN:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_SCLN);
                    set_mods(mod_state);
                } else {
                    register_code(KC_COMM);
                }
            } else {
                unregister_code(KC_SCLN);
                unregister_code(KC_COMM);
            }
            return false;
        // Colon on shift + dot, like in Spanish keyboards
        case DOT_COLN:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    register_code(KC_SCLN);
                } else {
                    register_code(KC_DOT);
                }
            } else {
                unregister_code(KC_SCLN);
                unregister_code(KC_DOT);
            }
            return false;
        case MT_NT:
            // Workaround for mod-tap limitation
            // to basic keycodes
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(ALGR(KC_N));
                }
                return false;
            }
            return true;
        case SCROLL:
            if (record->event.pressed) {
                tap_code16(LCAG(KC_1));
            } else {
                tap_code16(LCAG(KC_0));
            }
            return false;
        case LYRLCK:
            if (record->event.pressed) {
                if (layer_lock_done) {
                    /* Making sure that we can always leave the layer
                     by tapping the lock key, without having to worry about which
                     layer we're in to use the corresponding activation key or
                     even if this isn't present in the layer.
                     Clearing all layers will do for now. Might have to be more
                     specific in the future and only disable the locked one. */
                    layer_clear();
                    layer_lock_done = false;
                    layer_lock      = false;
                } else {
                    layer_lock = !layer_lock;
                }
            }
            return false;
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                if (mod_state & MOD_MASK_SHIFT) {
                    // Cycle through windows of the current
                    // app if SHIFT is pressed
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_GRAVE);
                    set_mods(mod_state | MOD_BIT(KC_LALT));
                } else {
                    // Cycle through apps otherwise
                    tap_code(KC_TAB);
                }
            }
            return true;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();
    switch (keycode) {
        case DEAD_QUOT:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    layer_on(_DIAE);
                    set_oneshot_layer(_DIAE, ONESHOT_START);
                } else {
                    layer_on(_ACUT);
                    set_oneshot_layer(_ACUT, ONESHOT_START);
                }
            } else {
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_A:
        case MT_NT:
            return true;
        default:
            return false;
    }
}

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 750) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}