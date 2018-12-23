#pragma once

/* With Elite C, there are extra unused pins */
#define UNUSED_PINS { F0, F1, C7, B0, D5 }

#define USB_MAX_POWER_CONSUMPTION 500

/* ws2812 RGB LED */
#define RGB_DI_PIN B7 // Requires Elite C
#define RGBLED_NUM 6
#define RGBLIGHT_SLEEP
