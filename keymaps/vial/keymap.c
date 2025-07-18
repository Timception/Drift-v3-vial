#include QMK_KEYBOARD_H
#include <stdio.h>
//#include "drift.h"



// d e f i n e   l a y e r s

enum Layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    BASE,
    LOWER,
    RAISE,
    ADJUST
};

#define BASE MO(_QWERTY)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)


// K E Y M A P 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 
   [_BASE] = LAYOUT(
 
    KC_DEL,  KC_ESC,  KC_GRV,  KC_1, KC_2, KC_3,    KC_4,   KC_5,                    KC_6,  KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    C(KC_C), ADJUST,  KC_TAB,  KC_Q, KC_W, KC_E,    KC_R,   KC_T,                    KC_Y,  KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
             KC_LGUI, KC_CAPS, KC_A, KC_S, KC_D,    KC_F,   KC_G,                    KC_H,  KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
    C(KC_V), KC_LCTL, KC_LALT, KC_Z, KC_X, KC_C,    KC_V,   KC_B, KC_MUTE, KC_MUTE,  KC_N,  KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RALT, KC_RCTL, KC_DEL,
	                                       KC_LSFT, KC_SPC, LOWER,                   RAISE, KC_SPC, KC_BSPC
 ),


   [_LOWER] = LAYOUT(

    QK_BOOT, KC_ESC,  KC_GRV,  KC_F1,KC_F2,KC_F3,   KC_F4,  KC_F5,                     KC_F6,   KC_F8,  KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_EQL,  KC_BSPC,
    KC_TRNS, KC_TRNS, KC_TAB,  KC_Q, KC_W, KC_E,    KC_R,   KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
             KC_LGUI, KC_CAPS, KC_A, KC_S, KC_D,    KC_F,   KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_UP,
    KC_TRNS, KC_LCTL, KC_LALT, KC_Z, KC_X, KC_C,    KC_V,   KC_B,   KC_MUTE, KC_MUTE,  KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT,
	                                       KC_LSFT, KC_SPC, KC_TRNS,                   KC_TRNS, KC_SPC, KC_BSPC
 ),
  

   [_RAISE] = LAYOUT(
 
    KC_DEL,  KC_ESC,  KC_GRV,  KC_F1,KC_F2,KC_F3,   KC_F4,  KC_F5,                     KC_F6,   KC_F8,  KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_WH_U, QK_BOOT,
    KC_TRNS, KC_TRNS, KC_TAB,  KC_Q, KC_W, KC_E,    KC_R,   KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC, KC_WH_D, KC_BTN2,
             KC_LGUI, KC_CAPS, KC_A, KC_S, KC_D,    KC_F,   KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,   KC_SCLN, KC_BTN1, KC_MS_U,
    KC_TRNS, KC_LCTL, KC_LALT, KC_Z, KC_X, KC_C,    KC_V,   KC_B,    KC_MUTE, KC_MUTE, KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_MS_L, KC_MS_D, KC_MS_R,
	                                       KC_LSFT, KC_SPC, KC_TRNS,                   KC_TRNS, KC_SPC, KC_BSPC
 ),
 

   [_ADJUST] = LAYOUT(
 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS,  KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS,  KC_TRNS,
	                                             KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
 )
};

// E N D  K E Y M A P


// E N C O D E R

#ifdef ENCODER_ENABLE

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [2] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};

#endif

// E N D  E N C O D E R 


// O L E D

#ifdef OLED_ENABLE

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
	//return OLED_ROTATION_90; // Vertical Screen
	return OLED_ROTATION_180; // Horizontal Screen
}


led_t led_usb_state;

// L O G O  S T A T I C

// 128x32
static const char PROGMEM logo_static[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0x07, 
0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0xf7, 0xff, 0xff, 0xff, 0x06, 0x00, 0x80, 0xc6, 0xc7, 0xc7, 
0xc7, 0xc7, 0xc7, 0xc7, 0xc7, 0xc7, 0xc7, 0xc7, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x80, 0xfc, 
0xff, 0xff, 0x3f, 0x01, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 
0x07, 0x07, 0x01, 0x00, 0x07, 0x07, 0x07, 0xe7, 0xff, 0xff, 0xff, 0x3f, 0x07, 0x07, 0x07, 0x07, 
0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1f, 0x1f, 0x1f, 0x1e, 0x1e, 
0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x0f, 0x0f, 0x07, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x1f, 0x03, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x07, 0x1f, 0xff, 0xff, 0xf9, 0xc0, 0x00, 0x00, 0x00, 0x1f, 0x1f, 
0x1f, 0x07, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1f, 0x1f, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x04, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static void print_logo_static(void) {
        // print current mode
        oled_write_raw_P(logo_static, sizeof(logo_static));
}

// L O G O  S T A T I C  E N D


// W P M

char wpm_str[16];

// wpm variables 
int   current_wpm = 0;
led_t led_usb_state;

static void print_wpm(void) {
    //oled_set_cursor(0, 0);
    //render_logo();

    /* wpm counter */
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(0, 0);
    oled_write("WPM:     ", false);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    //oled_set_cursor(0, 0);
    //oled_write("WPM", false);
}

// W P M  E N D




uint32_t oled_tap_timer = 0;

bool oled_task_user(void) {
    // host Keyboard Layer Status	

    current_wpm   = get_current_wpm();
    led_t led_usb_state = host_keyboard_led_state();
    
    if (is_keyboard_master()) {
		
		#ifdef WPM_ENABLE
			static uint8_t prev_wpm = 0;
			// Update oled_tap_timer with sustained WPM
			if (get_current_wpm() > prev_wpm || get_mods()) {
				oled_tap_timer = timer_read32();
			}
			prev_wpm = get_current_wpm();
		#endif

        oled_set_cursor(0,1);
            // print current layer 
            oled_write("LAYER:", false);
            switch (get_highest_layer(layer_state)) {
                case _BASE:
                    oled_write_P(PSTR("  ZERO     "), false);
                break;  
                case _LOWER:
                    oled_write_P(PSTR("  ONE      "), false);
                break;
                case _RAISE: 
                    oled_write_P(PSTR("  TWO      "), false);
                break;
		        case _ADJUST:
                    oled_write_P(PSTR("  THREE    "), false);
                break;
                default:
                // or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("  undef     "), false);
            }        
        oled_set_cursor(0,2);
            print_wpm();
        oled_set_cursor(0, 3);
            // run animation
            print_logo_static();
			if (timer_elapsed32(oled_tap_timer) > OLED_TIMEOUT) {
				oled_off();
				}
    } else {
        oled_set_cursor(0, 0);
            oled_write("CAPS", led_usb_state.caps_lock);
            oled_write_P(led_usb_state.num_lock ? PSTR(" NUM") : PSTR("    "), false);
            oled_write_P(led_usb_state.scroll_lock ? PSTR(" SCR      ") : PSTR("        "), false);            
        oled_set_cursor(0, 2);
            print_logo_static();
            //print_logo_animation();   
    }

    // host Keyboard LED Status
    /*led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR(" NUM") : PSTR("   "), false);
    oled_write_P(led_state.caps_lock ? PSTR(" CAP") : PSTR("   "), false);
    oled_write_P(led_state.scroll_lock ? PSTR(" SCR") : PSTR("   "), false);*/ 
    return false;
}

// The layer_state_set_user() callback is called every time the layer state changes.
layer_state_t layer_state_set_user(layer_state_t state) {	
	oled_tap_timer = timer_read32(); //This is what triggers the oled to wake up.
	return state;
}


#endif

// O L E D  E N D




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case KC_VOLD:
		  oled_tap_timer = timer_read32(); //This is what triggers the oled to wake up.
		  break;
		  
		case KC_VOLU:
		  oled_tap_timer = timer_read32(); //This is what triggers the oled to wake up.
		  break;
		
		
		
    }

    return true;
}