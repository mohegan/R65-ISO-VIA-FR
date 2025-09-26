/*
    Copyright 20254 ND (@mohegan)
    SPDX-License-Identifier: GPL-2.0-or-later

    Voici un keymap pour le clavier RK65 en version ISO FR.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,       // 0
    _BASE_FN    // 1
};

bool alt_held = false;  // état pour ALT maintenu

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
       
    // Alt+2 -> F2
    if (keycode == KC_2 && (get_mods() & MOD_BIT(KC_LALT))) {
        if (record->event.pressed) {
            tap_code(KC_F2);
        }
        return false;
    }

    // Alt+4 -> F4 (avec maintien Alt)
    if (keycode == KC_4 && (get_mods() & MOD_BIT(KC_LALT))) {
        if (record->event.pressed) {
            if (!alt_held) {
                register_code(KC_LALT);
                alt_held = true;
            }
            tap_code(KC_F4);
        }
        return false;
    }

    // Relâchement de LAlt -> on relâche Alt maintenu
    if (keycode == KC_LALT) {
        if (!record->event.pressed && alt_held) {
            unregister_code(KC_LALT);
            alt_held = false;
        }
    }

    // Clic molette : si FN layer actif = Play/Pause, sinon = Mute
    if (keycode == KC_MUTE) {
        if (record->event.pressed) {
            // si layer 1 (FN) active -> Play/Pause, sinon -> mute normal
            if (layer_state & (1UL << 1)) {
                // utilisation de tap_code16 pour keycodes media
                tap_code16(KC_MEDIA_PLAY_PAUSE);
            } else {
                tap_code(KC_MUTE);
            }
        }
        return false;
    }
   
    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT( /* Base */
        KC_ESC,   KC_1,       KC_2,       KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,       KC_MINS,   KC_EQL,   KC_BSPC,   KC_MUTE,
        KC_TAB,   KC_Q,       KC_W,       KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,       KC_LBRC,   KC_RBRC,  KC_ENT,    KC_DEL,
        KC_CAPS,  KC_A,       KC_S,       KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,    KC_QUOT,   KC_BSLS,             KC_PGUP,  
        KC_LSFT,  KC_NUBS,    KC_Z,       KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,     KC_SLSH,   KC_RSFT,  KC_UP,     KC_PGDN,
        KC_LCTL,  KC_LGUI,    KC_LALT,                        KC_SPC,                       KC_RALT,  MO(1),                KC_LEFT,             KC_DOWN,   KC_RGHT
        ),

    [1] = LAYOUT( /* FN */
        RGB_TOG,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,            KC_F12,            KC_PSCR,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PAUSE,          KC_SCRL,           _______,   KC_INS,
        _______,  RGB_HUD,  RGB_HUI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_MODE_REVERSE,  RGB_MODE_FORWARD,             KC_HOME,
        _______,  _______,  RGB_SPD,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,           RGB_VAI,   KC_END,
        _______,  GU_TOGG,  _______,                                _______,            _______,  _______,            RGB_SAD,                              RGB_VAD,   RGB_SAI
        ),
};

/*
Layer 1 (FN) — fonctions des touches :
---------------------------------------
Ligne 1 :
 - Fn+ESC = activer/désactiver l'éclairage RGB du clavier
 - Fn+1..Fn+0 = F1..F10
 - Fn+- = F11
 - Fn+= = F12
 - Fn+Backspace = Impression écran
 - Fn+Mute (géré dans process_record_user) = Play/Pause

Ligne 2 :
 - Fn+^ = Pause
 - Fn+$ = Scroll Lock / arrêt défil
 - Fn+Suppr = Insertion

Ligne 3 :
 - Fn+Q = baisser teinte RGB (RGB_HUD)
 - Fn+S = augmenter teinte RGB (RGB_HUI)
 - Fn+ù = cycle modes RGB inversé
 - Fn+* = cycle modes RGB normal
 - Fn+PgUp = Home

Ligne 4 :
 - Fn+W = ralentir animations RGB (RGB_SPD)
 - Fn+X = accélérer animations RGB (RGB_SPI)
 - Fn+Flèche haut = augmenter intensité RGB (RGB_VAI)
 - Fn+PgDn = End

Ligne 5 :
 - Fn+Win = activer/désactiver touche Windows (GU_TOGG)
 - Fn+Flèche gauche = diminuer saturation RGB (RGB_SAD)
 - Fn+Flèche bas = diminuer intensité RGB (RGB_VAD)
 - Fn+Flèche droite = augmenter saturation RGB (RGB_SAI)

Molette (encoder) :
 - Layer 0 : volume +/-
 - Layer 1 : piste précédente / suivante
*/

#ifdef ENCODER_MAP_ENABLE
// molette : volume sur layer 0, piste précédente/suivante sur layer 1
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK)}
};
#endif
