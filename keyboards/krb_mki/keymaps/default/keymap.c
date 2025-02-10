// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
  GITADD = SAFE_RANGE,GITPUSH,
  VSCODE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌──────┐┌───┐┌───┐
     * │  7   ││ 8 ││ 9 │
     * └──────┘└───┘└───┘
     * ┌──────┐┌───┐┌───┐
     * │   4  ││ 5 ││ 6 │
     * └──────┘└───┘└───┘
     * ┌──────┐┌───┐┌───┐
     * │ boot ││ 2 ││ 3 │
     * └──────┘└───┘└───┘
     */
    [0] = LAYOUT_ortho_3x3(
        GITADD, GITPUSH, TO(1),
        VSCODE, KC_5, KC_6,
        QK_BOOT, QK_REBOOT, KC_3
    ),

    [1] = LAYOUT_ortho_3x3(
        KC_7, KC_8, TO(0),
        KC_4, KC_5, KC_6,
        KC_1, KC_2, KC_3
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case GITADD:
      if (record->event.pressed) {
        SEND_STRING("git add ." SS_TAP(X_ENTER));
      }
      return false;
    case GITPUSH:
      if (record->event.pressed) {
        SEND_STRING("git push");
      }
      return false;
    case VSCODE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "code" SS_DELAY(500) SS_TAP(X_ENTER));
      }
      return false;
  }
  return true;
};
