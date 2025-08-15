/*
 * Keymap derived from QMK's template for Lily58.
 */

#include QMK_KEYBOARD_H

// Bit numbers for each LED. When checking whether, say, caps lock is on, it checks bit 1
#define USB_LED_NUM_LOCK 0
#define USB_LED_CAPS_LOCK 1
#define USB_LED_SCROLL_LOCK 2

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |??????|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt |LOWER |BackSP| /Space  /       \Enter \  |DELETE|RAISE |??????|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_SCLN,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,    KC_RBRC,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_LALT, MO(_LOWER), KC_BSPC, KC_SPC,    KC_ENT, KC_DEL, MO(_RAISE), KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |KC_LWIN|      |LOWER | /Space /       \Enter \  |RAISE |BackSP|KC_LWIN|
 *                   |       |      |      |/      /         \      \ |      |      |       |
 *                   `----------------------------'           '------''---------------------'
 */
[_LOWER] = LAYOUT(
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                    KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, KC_F12,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, _______, _______,
//   KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
//   _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                             KC_LWIN, _______, _______, _______,        _______,  _______, _______, KC_RWIN
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


/*
OLED config, including logo display. See https://www.youtube.com/watch?v=OJSOEStpPIo for tutorial

I think is_keyboard_master is determined by which half has the USB-C cable plugged in.
*/
//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	if (!is_keyboard_master()){
    	return OLED_ROTATION_270; // flips display by 270 degrees
	}

  	return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
void enter_alt_code_combination(uint16_t alt_code);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
	if (is_keyboard_master()) {
    	// If you want to change the display of OLED, you need to change here
    	oled_write_ln(read_layer_state(), false);
    	oled_write_ln(read_keylog(), false);
    	oled_write_ln(read_keylogs(), false);
    	//oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    	//oled_write_ln(read_host_led_state(), false);
    	//oled_write_ln(read_timelog(), false);
	} else {
    	// oled_write(read_logo(), false);
		static const char a1v0Logo [] PROGMEM = {
			// 'a1v0 logo small jpeg', 32x128px
			// Byte array generated from https://javl.github.io/image2cpp/
			// TODO: move this into a different file if possible
			// TODO: improve the quality of this image. It's a bit rubbish
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 
			0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 
			0x00, 0xe0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x07, 0xc7, 0xc3, 0xe7, 0xe7, 0xe7, 
			0xef, 0x4f, 0x9f, 0xdf, 0xdf, 0xff, 0x0f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
			0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xe3, 0xc3, 0xe0, 0xe1, 0xe3, 0xe3, 0xe3, 
			0xe1, 0xe0, 0xe1, 0xe1, 0xe1, 0xe0, 0xe0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x0f, 
			0x00, 0x0f, 0x1f, 0x1f, 0x3f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 
			0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 
			0x00, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37, 0x3d, 0x30, 0x30, 0x3f, 0x3f, 0x30, 
			0x30, 0x3f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 
			0x60, 0x60, 0x60, 0x60, 0x60, 0x7e, 0x7e, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0x60, 0x30, 0x30, 
			0x38, 0x18, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x81, 0xc3, 0xc3, 0xc7, 0xc6, 
			0xc6, 0xce, 0xcc, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0xff, 0xe3, 0xc1, 0x81, 0x80, 0x80, 
			0x80, 0x80, 0x80, 0x81, 0xc1, 0xe3, 0xff, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 
			0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		};
		oled_write_raw_P(a1v0Logo, sizeof(a1v0Logo));
	}
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record -> event.pressed) {
		#ifdef OLED_ENABLE
    		set_keylog(keycode, record);
		#endif
    	// set_timelog();
	}
	return true;
}

enum combo_events {
	UMLAUT_U_LOWER,
	UMLAUT_U_UPPER,
};

const uint16_t PROGMEM umlaut_u[] = {KC_U, KC_SCLN, COMBO_END};
const uint16_t PROGMEM umlaut_u_caps[] = {KC_LSFT, KC_U, KC_SCLN, COMBO_END};

combo_t key_combos[] = {
	[UMLAUT_U_LOWER] = COMBO_ACTION(umlaut_u),
	[UMLAUT_U_UPPER] = COMBO_ACTION(umlaut_u_caps),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
	if (!pressed) return;
	switch (combo_index) {
		case UMLAUT_U_LOWER:
			enter_alt_code_combination(252);
			break;
		case UMLAUT_U_UPPER:
			enter_alt_code_combination(220);
			break;
		default:
			break;
	}
}

// Method uses Windows-1252 key codes: https://en.wikipedia.org/wiki/Windows-1252
// Adapted from https://gist.github.com/itspngu/9159f06153b440a754b33c6d65c5f302
// If alt code has a leading 0, omit it.
void enter_alt_code_combination(uint16_t alt_code) {
	static uint8_t lalt_mask;
	lalt_mask = keyboard_report -> mods & KC_LALT;

	bool numLockOn = host_keyboard_leds() & (1 << USB_LED_NUM_LOCK); // From: https://github.com/qmk/qmk_firmware/issues/2164
	
	if (!lalt_mask) {
		register_code(KC_LALT);
	}
	
	if (!numLockOn) {
		// 
		// TODO:
		// we're successfully entering this block if num lock is off, but
		// the code doesn't turn num lock on. I wonder if the keyboard report stuff
		// makes a difference, or if there's some sort of press-and-hold method, rather
		// than the tapping one.
		//
		// Perhaps there's some sort of method akin to host_keyboard_led_state() wherein we can set the state
		// 
		register_code(KC_NUM_LOCK);
	}

	// 
	// TODO:
	// this switch can be farmed out into its own method to help declutter
	// 
	// 
	// 
	// 
	// 
	// 
	// 

	// Adapted from https://gist.github.com/itspngu/9159f06153b440a754b33c6d65c5f302
	// Split up the alt code into its constituent digits
	static uint16_t alt_digits[4];
	
	alt_digits[0] = alt_code / 1000;
	alt_digits[1] = alt_code / 100 - alt_digits[0] * 100;
	alt_digits[2] = alt_code / 10 - alt_digits[0] * 1000 - alt_digits[1] * 10;
	alt_digits[3] = alt_code - alt_digits[0] * 1000 - alt_digits[1] * 100 - alt_digits[2] * 10;
	
	for (uint8_t i = 0; i <= 3; ++i) {
		switch(alt_digits[i]) {
			case 0:
				tap_code16(KC_KP_0);
				break;
			case 1:
				tap_code16(KC_KP_1);
				break;
			case 2:
				tap_code16(KC_KP_2);
				break;
			case 3:
				tap_code16(KC_KP_3);
				break;
			case 4:
				tap_code16(KC_KP_4);
				break;
			case 5:
				tap_code16(KC_KP_5);
				break;
			case 6:
				tap_code16(KC_KP_6);
				break;
			case 7:
				tap_code16(KC_KP_7);
				break;
			case 8:
				tap_code16(KC_KP_8);
				break;
			case 9:
				tap_code16(KC_KP_9);
				break;
		}
	}

	if (!lalt_mask) {
		unregister_code(KC_LALT);
	}

	if (!numLockOn) {
		unregister_code(KC_NUM_LOCK);
	}
}