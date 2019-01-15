#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _DVORAK 0 // Dvorak layer
#define _QWERTY 1 // Qwerty layer
#define _COLEMAK 2 // Colemak layer
#define _MEDIA 3 // Media Layer
#define _KEYPAD 4 // Keypad Layer

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  COLEMAK,
  MEDIA,
  KEYPAD
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Aliases to make the keymap more uniform
#define GUI_END GUI_T(KC_END)
#define MED_DEL LT(_MEDIA, KC_DEL)
#define KPD_ENT LT(_KEYPAD, KC_ENT)

/*
        Function Keys on All Layers (Keypad toggles):
	,-----------------------------------------------------------------.
	|  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   F7   |  F8   |
 	`-----------------------------------------------------------------'
        ,-----------------------------------------------------------------.
        |  F9  |  F10 |  F11 |  F12 | PScr | SLck | Paus | DVORAK | RESET |
        `-----------------------------------------------------------------'

        Dvorak layer:
	,-------------------------------------------.,-------------------------------------------.
	|   =    |   1  |   2  |   3  |   4  |   5  ||   6  |   7  |   8  |   9  |   0  |   +    |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	| Esc    |   '  |   ,  |   .  |   P  |   Y  ||   F  |   G  |   C  |   R  |   L  |   /    |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	| tab    |   A  |   O  |   E  |   U  |   I  ||   D  |   H  |   T  |   N  |   S  |   -    |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	|(LShift |   Z  |   X  |   C  |   V  |   X  ||   B  |   M  |   W  |   V  |   Z  |RShift) |
	`--------+------+------+------+------+------'`------+------+------+------+------+--------'
	|   `    |   \  | Left | Rght |              |  Up  |  Dn  |   [  |   ]  |
	`---------------------------'              `---------------------------'
	                             ,--------------.       ,--------------.
	                             |  Ctl |  Alt  |       | Alt  |  Ctl  |
															 ,------|-------|------||------+-------+-------.
															 |      |  Del  | GUI  || GUI  | Enter |       |
															 | BkSp |   /   |------||------|   /   | Space |
															 |      | Media | End  || PgDn | KeyPd |       |
															 `---------------------'`----------------------'

        QWERTY layer:
	,-------------------------------------------.,-------------------------------------------.
	|   =    |   1  |   2  |   3  |   4  |   5  ||   6  |   7  |   8  |   9  |   0  |   -    |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	| Tab    |   Q  |   W  |   E  |   R  |   T  ||   Y  |   U  |   I  |   O  |   P  |   \    |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	| CapsLk |   A  |   S  |   D  |   F  |   G  ||   H  |   J  |   K  |   L  |   ;  |   '    |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	| LShift |   Z  |   X  |   C  |   V  |   B  ||   N  |   M  |   ,  |   .  |   /  | RShift |
	`--------+------+------+------+------+------'`------+------+------+------+------+--------'
	         |   `  |  INS | Left | Rght |              |  Up  |  Dn  |   [  |   ]  |
	         `---------------------------'              `---------------------------'
	                             ,--------------.,--------------.
	                             | LCtl  | LAlt || RGUI | RCtl  |
	                      ,------|-------|------||------+-------+-------.
	                      |      |  Del  | Home || PgUp | Enter |       |
	                      | BkSp |   /   |------||------|   /   | Space |
	                      |      | Media | End  || PgDn | KeyPd |       |
	                      `---------------------'`----------------------'
	 
        Colemak layer:
	,-------------------------------------------.,-------------------------------------------.
	|   =    |   1  |   2  |   3  |   4  |   5  ||   6  |   7  |   8  |   9  |   0  |   -    |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	| Tab    |   Q  |   W  |   F  |   P  |   G  ||   J  |   L  |   U  |   Y  |   ;  |   \    |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	| BkSpc  |   A  |   R  |   S  |   T  |   D  ||   H  |   N  |   E  |   I  |   O  |   '    |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	| LShift |   Z  |   X  |   C  |   V  |   B  ||   K  |   M  |   ,  |   .  |   /  | RShift |
	`--------+------+------+------+------+------'`------+------+------+------+------+--------'
	         |   `  |  INS | Left | Rght |              |  Up  |  Dn  |   [  |   ]  |
	         `---------------------------'              `---------------------------'
	                             ,--------------.,--------------.
	                             | LCtl  | LAlt || RGUI | RCtl  |
	                      ,------|-------|------||------+-------+-------.
	                      |      |  Del  | Home || PgUp | Enter |       |
	                      | BkSp |   /   |------||------|   /   | Space |
	                      |      | Media | End  || PgDn | KeyPd |       |
	                      `---------------------'`----------------------'

        Media layer:
	,-------------------------------------------.,-------------------------------------------.
	|   F11  |  F1  |  F2  |  F3  |  F4  |  F5  ||  F6  |  F7  |  F8  |  F9  |  F10 |  F12   |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	|     ~  |   !  |   @  |   #  |   $  |   %  ||   ^  |   &  |   *  |   +  |   =  |   \    |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	|        | GUI  | Alt  | Shft | Ctrl | Vol+ ||      |      |      |      |      |   |    |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	|        |      |      |      | Mute | Vol- || Stop | Prev | Play | Next | Sel  |        |
	`--------+------+------+------+------+------'`------+------+------+------+------+--------'
	         |      |      |      |      |              |      |      |      |      |
	         `---------------------------'              `---------------------------'
	                              ,-------------.,-------------.
	                              |      |      ||      |      |
	                       ,------|------|------||------+------+------.
	                       |      |      |      ||      |      |      |
	                       |      |      |------||------|      |      |
	                       |      |      |      ||      |      |      |
	                       `--------------------'`--------------------'

        Keypad layer:
	,-------------------------------------------.,-------------------------------------------.
	| Power  |      |      |      |      |      ||      |      |      |      |      |        |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	|  `     |   1  |   2  |   3  |   4  |   5  ||   6  |   7  |   8  |   9  |   0  | pwr    |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	|        | GUI  |  Alt | Shift| Ctrl | vlup || msup | Left | Down |  Up  | Right|        |
	|--------+------+------+------+------+------||------+------+------+------+------+--------|
	|        | prev | mute |ply/ps| next | vldn || msdn | Home |Pg Up |Pg Dn | End  |        |
	`--------+------+------+------+------+------'`------+------+------+------+------+--------'
	         |      |      |      |      |              |      |      |      |      |      |
	         `---------------------------'              `----------------------------------'
	                              ,-------------.,-------------.
	                              |      |      ||      |      |
	                       ,------|------|------||------+------+------.
	                       |      |      |      ||      |      |      |
	                       |      |      |------||------|      |      |
	                       |      |      |      ||      |      |      |
	                       `--------------------'`--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DVORAK] = LAYOUT(
           // Left Hand
           KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
           KC_EQL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
           KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,
           KC_TAB, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
           KC_LSPO, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,
					 KC_GRV,  KC_BSLS,  KC_LEFT, KC_RGHT,
           // Left Thumb
					 KC_LCTL, KC_LALT,
					 KC_LGUI,
           KC_BSPC, MED_DEL,  KC_END,

           // Right Hand
           KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, TG(_KEYPAD),  RESET,
           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PLUS,
           KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
           KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
           KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSPC,
					 KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,
           // Right Thumb
           KC_LALT, KC_RCTL,
           KC_RGUI,
           KC_PGDN, KPD_ENT,  KC_SPC
    ),

[_QWERTY] = LAYOUT(
           // Left Hand
           KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
           KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
           KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
           KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
           KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                    KC_GRV,  KC_INS,  KC_LEFT, KC_RGHT,
           // Left Thumb
                    KC_LCTL, KC_LALT,
                             KC_HOME,
           KC_BSPC, MED_DEL,  KC_END,

           // Right Hand
           KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, TG(_KEYPAD),  RESET,
           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL ,
           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,
           // Right Thumb
           KC_RGUI, KC_RCTL,
           KC_PGUP,
           KC_PGDN, KPD_ENT,  KC_SPC
    ),

[_COLEMAK] = LAYOUT(
           // Left Hand
           KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
           KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
           KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,
           KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,
           KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                    KC_GRV,  KC_INS,  KC_LEFT, KC_RGHT,
           // Left Thumb
                    KC_LCTL, KC_LALT,
                             KC_HOME,
           KC_BSPC, MED_DEL,  KC_END,

           // Right Hand
           KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, DVORAK,  RESET,
           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
           KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
           KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
           KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,
           // Right Thumb
           KC_RGUI, KC_RCTL,
           KC_PGUP,
           KC_PGDN, KPD_ENT,  KC_SPC
    ),

[_MEDIA] = LAYOUT(
           // Left Hand
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
           KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
           _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_VOLU,
           _______, _______, _______, _______, KC_MUTE, KC_VOLD,
					 _______, _______, _______, _______,
           // Left Thumb
					 _______, _______,
					 _______,
           _______, _______, _______,

           // Right Hand
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
           KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_EQL,  KC_BSLS,
					 _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_PIPE,
					 KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSEL, _______,
					 _______, _______, _______, _______,
					 // Right Thumb
					 _______, _______,
					 _______,
					 _______, _______, _______
    ),

[_KEYPAD] = LAYOUT(
           // Left Hand
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           KC_PWR,  _______, _______, _______, _______, _______,
					 KC_GRV,  KC_1,     KC_2,     KC_3,     KC_4,    KC_5,
           _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_VOLU,
           _______, KC_MPRV, KC_MUTE, KC_MPLY, KC_MNXT, KC_VOLD,
                    _______, _______, _______, _______,
           // Left Thumb
                    _______, _______,
                             _______,
           _______, _______, _______,

           // Right Hand */
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
					 _______, _______, _______, _______, _______, _______,
           KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_PWR,
					 KC_WH_U, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
           KC_WH_D, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______,
                    _______, _______, _______, _______,
           // Right Thumb
           _______, _______,
           _______,
           _______, _______, _______
    )

};


const uint16_t PROGMEM fn_actions[] = {

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case DVORAK:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_DVORAK);
          }
          return false;
          break;
        case QWERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_COLEMAK);
          }
          return false;
          break;
      }
    return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};
