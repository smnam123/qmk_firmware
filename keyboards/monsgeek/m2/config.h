/* Copyright (C) 2023 jonylee@hfd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* LED Indicators
Pin A15 is originally for CapsLock, it somehow switched its position with Num Lock.
1. So originally:
    "indicators": {
        "num_lock": "C10"
        "caps_lock": "A15"
    }

2. Then it internally changed to:
    "indicators": {
        "num_lock": "A15"
        "caps_lock": "C10"
    }

3. Current status:
    "indicators": {
        "caps_lock": "C10"
    }

    Then Added Factory Layer indicator on Num Lock's position.
*/
#define LED_FACT_PIN            A15
#define LED_WIN_LOCK_PIN        C11


/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap <-- (KC_LCAP and so on not necessary on this build)*/
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


/* SPI Config for spi flash*/
#define SPI_DRIVER SPIDQ
#define SPI_SCK_PIN B3
#define SPI_MOSI_PIN B5
#define SPI_MISO_PIN B4
#define SPI_MOSI_PAL_MODE 5

#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN C12
#define WEAR_LEVELING_BACKING_SIZE (8 * 1024)

/* I2C Config for LED Driver */
#define DRIVER_COUNT 2
#define DRIVER_ADDR_1 0b1110100
#define DRIVER_ADDR_2 0b1110111
#define I2C1_OPMODE OPMODE_I2C
#define I2C1_CLOCK_SPEED 400000 /* 400000 */

#define DRIVER_1_LED_TOTAL 60
#define DRIVER_2_LED_TOTAL 38
#define RGB_MATRIX_LED_COUNT    (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

#define RGB_TRIGGER_ON_KEYDOWN
#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

