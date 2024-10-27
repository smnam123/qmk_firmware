// Copyright 2022 @filterpaper
// SPDX-License-Identifier: GPL-2.0+

#ifdef ENABLE_RGB_MATRIX_PIXEL_RAIN
RGB_MATRIX_EFFECT(PIXEL_RAIN)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool PIXEL_RAIN(effect_params_t* params) {
    static fast_timer_t timer = 0;
    static uint16_t     index = 0;
    static rgb_t        rgb   = {};

    if (params->init) {
        rgb_matrix_set_color_all(0, 0, 0);
    }

    if (timer_elapsed_fast(timer) > (320 - rgb_matrix_config.speed)) {
        hsv_t hsv = (random8() & 2) ? (hsv_t){0, 0, 0} : (hsv_t){random8(), random8_min_max(127, 255), rgb_matrix_config.hsv.v};
        rgb       = rgb_matrix_hsv_to_rgb(hsv);
        index     = random8_max(RGB_MATRIX_LED_COUNT);
        timer     = timer_read_fast();
    }

    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    if (led_min <= index && index <= led_max && HAS_ANY_FLAGS(g_led_config.flags[index], params->flags)) {
        rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // ENABLE_RGB_MATRIX_PIXEL_RAIN