/*
 * SPDX-FileCopyrightText: 2023-2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
/**
 * @file   BOARD_ESP32_S3_TOUCH_LCD_1_85C.h
 * @brief  Configuration file for Waveshare ESP32_S3_TOUCH_LCD_1_85C
 * @author @martinroger & Waveshare@H-sw123
 * @link   https://www.waveshare.com/esp32-s3-touch-lcd-1.85c.htm
 */

#pragma once

// *INDENT-OFF*

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Please update the following macros to configure general panel /////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Board name
 */
#define ESP_PANEL_BOARD_NAME                "Waveshare:ESP32_S3_TOUCH_LCD_1_85C"

/**
 * @brief Panel resolution configuration in pixels
 */
#define ESP_PANEL_BOARD_WIDTH               (360)   // Panel width (horizontal, in pixels)
#define ESP_PANEL_BOARD_HEIGHT              (360)   // Panel height (vertical, in pixels)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Please update the following macros to configure the LCD panel /////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief LCD panel configuration flag (0/1)
 *
 * Set to `1` to enable LCD panel support, `0` to disable
 */
#define ESP_PANEL_BOARD_USE_LCD             (1)

#if ESP_PANEL_BOARD_USE_LCD
/**
 * @brief LCD controller selection
 */
#define ESP_PANEL_BOARD_LCD_CONTROLLER      ST77916

/**
 * @brief LCD bus type selection
 */
#define ESP_PANEL_BOARD_LCD_BUS_TYPE        (ESP_PANEL_BUS_TYPE_QSPI)

#if (ESP_PANEL_BOARD_LCD_BUS_TYPE == ESP_PANEL_BUS_TYPE_SPI) || \
    (ESP_PANEL_BOARD_LCD_BUS_TYPE == ESP_PANEL_BUS_TYPE_QSPI)
/**
 * If set to 1, the bus will skip to initialize the corresponding host. Users need to initialize the host in advance.
 *
 * For drivers which created by this library, even if they use the same host, the host will be initialized only once.
 * So it is not necessary to set the macro to `1`. For other drivers (like `Wire`), please set the macro to `1`
 * ensure that the host is initialized only once.
 */
#define ESP_PANEL_BOARD_LCD_BUS_SKIP_INIT_HOST      (0)     // 0/1. Typically set to 0
#endif

/**
 * @brief LCD bus parameters configuration
 *
 * Configure parameters based on the selected bus type. Parameters for other bus types will be ignored.
 * For detailed parameter explanations, see:
 * https://docs.espressif.com/projects/esp-idf/en/v5.3.1/esp32s3/api-reference/peripherals/lcd/index.html
 * https://docs.espressif.com/projects/esp-iot-solution/en/latest/display/lcd/index.html
 */
#if ESP_PANEL_BOARD_LCD_BUS_TYPE == ESP_PANEL_BUS_TYPE_QSPI

    /**
     * @brief QSPI bus
     */
    /* For general */
    #define ESP_PANEL_BOARD_LCD_QSPI_HOST_ID        (2)
#if !ESP_PANEL_BOARD_LCD_BUS_SKIP_INIT_HOST
    /* For host */
    #define ESP_PANEL_BOARD_LCD_QSPI_IO_SCK         (40)
    #define ESP_PANEL_BOARD_LCD_QSPI_IO_DATA0       (46)
    #define ESP_PANEL_BOARD_LCD_QSPI_IO_DATA1       (45)
    #define ESP_PANEL_BOARD_LCD_QSPI_IO_DATA2       (42)
    #define ESP_PANEL_BOARD_LCD_QSPI_IO_DATA3       (41)
#endif // ESP_PANEL_BOARD_LCD_BUS_SKIP_INIT_HOST
    /* For panel */
    #define ESP_PANEL_BOARD_LCD_QSPI_IO_CS          (21)    // -1 if not used
    #define ESP_PANEL_BOARD_LCD_QSPI_MODE           (0)     // 0-3, typically set to 0
    #define ESP_PANEL_BOARD_LCD_QSPI_CLK_HZ         (80 * 1000 * 1000)
                                                            // Should be an integer divisor of 80M, typically set to 40M
    #define ESP_PANEL_BOARD_LCD_QSPI_CMD_BITS       (32)    // Typically set to 32
    #define ESP_PANEL_BOARD_LCD_QSPI_PARAM_BITS     (8)     // Typically set to 8

#endif // ESP_PANEL_BOARD_LCD_BUS_TYPE

/**
 * @brief LCD vendor initialization commands
 *
 * Vendor specific initialization can be different between manufacturers, should consult the LCD supplier for
 * initialization sequence code. Please uncomment and change the following macro definitions. Otherwise, the LCD driver
 * will use the default initialization sequence code.
 *
 * The initialization sequence can be specified in two formats:
 * 1. Raw format:
 *    {command, (uint8_t []){data0, data1, ...}, data_size, delay_ms}
 * 2. Helper macros:
 *    - ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(delay_ms, command, {data0, data1, ...})
 *    - ESP_PANEL_LCD_CMD_WITH_NONE_PARAM(delay_ms, command)
 */
#define ESP_PANEL_BOARD_LCD_VENDOR_INIT_CMD()                                                                                                \
{                                                                                                                                            \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x28}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF2, {0x28}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x73, {0xF0}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x7C, {0xD1}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x83, {0xE0}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x84, {0x61}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF2, {0x82}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x01}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF1, {0x01}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB0, {0x56}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB1, {0x4D}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB2, {0x24}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB4, {0x87}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB5, {0x44}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB6, {0x8B}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB7, {0x40}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB8, {0x86}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBA, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBB, {0x08}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBC, {0x08}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBD, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC0, {0x80}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC1, {0x10}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC2, {0x37}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC3, {0x80}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC4, {0x10}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC5, {0x37}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC6, {0xA9}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC7, {0x41}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC8, {0x01}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC9, {0xA9}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xCA, {0x41}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xCB, {0x01}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD0, {0x91}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD1, {0x68}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD2, {0x68}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF5, {0x00, 0xA5}),                                                                                  \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xDD, {0x4F}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xDE, {0x4F}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF1, {0x10}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x02}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE0, {0xF0, 0x0A, 0x10, 0x09, 0x09, 0x36, 0x35, 0x33, 0x4A, 0x29, 0x15, 0x15, 0x2E, 0x34}),          \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE1, {0xF0, 0x0A, 0x0F, 0x08, 0x08, 0x05, 0x34, 0x33, 0x4A, 0x39, 0x15, 0x15, 0x2D, 0x33}),          \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x10}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF3, {0x10}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE0, {0x07}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE1, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE2, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE3, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE4, {0xE0}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE5, {0x06}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE6, {0x21}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE7, {0x01}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE8, {0x05}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE9, {0x02}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xEA, {0xDA}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xEB, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xEC, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xED, {0x0F}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xEE, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xEF, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF8, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF9, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xFA, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xFB, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xFC, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xFD, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xFE, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xFF, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x60, {0x40}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x61, {0x04}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x62, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x63, {0x42}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x64, {0xD9}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x65, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x66, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x67, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x68, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x69, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x6A, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x6B, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x70, {0x40}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x71, {0x03}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x72, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x73, {0x42}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x74, {0xD8}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x75, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x76, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x77, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x78, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x79, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x7A, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x7B, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x80, {0x48}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x81, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x82, {0x06}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x83, {0x02}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x84, {0xD6}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x85, {0x04}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x86, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x87, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x88, {0x48}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x89, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x8A, {0x08}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x8B, {0x02}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x8C, {0xD8}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x8D, {0x04}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x8E, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x8F, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x90, {0x48}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x91, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x92, {0x0A}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x93, {0x02}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x94, {0xDA}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x95, {0x04}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x96, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x97, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x98, {0x48}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x99, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9A, {0x0C}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9B, {0x02}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9C, {0xDC}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9D, {0x04}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9E, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9F, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA0, {0x48}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA1, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA2, {0x05}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA3, {0x02}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA4, {0xD5}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA5, {0x04}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA6, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA7, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA8, {0x48}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA9, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xAA, {0x07}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xAB, {0x02}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xAC, {0xD7}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xAD, {0x04}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xAE, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xAF, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB0, {0x48}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB1, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB2, {0x09}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB3, {0x02}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB4, {0xD9}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB5, {0x04}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB6, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB7, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB8, {0x48}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB9, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBA, {0x0B}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBB, {0x02}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBC, {0xDB}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBD, {0x04}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBE, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBF, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC0, {0x10}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC1, {0x47}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC2, {0x56}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC3, {0x65}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC4, {0x74}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC5, {0x88}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC6, {0x99}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC7, {0x01}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC8, {0xBB}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC9, {0xAA}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD0, {0x10}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD1, {0x47}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD2, {0x56}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD3, {0x65}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD4, {0x74}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD5, {0x88}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD6, {0x99}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD7, {0x01}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD8, {0xBB}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD9, {0xAA}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF3, {0x01}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x21, {0x00}),                                                                                        \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(120, 0x11, {0x00}),                                                                                      \
  ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x29, {0x00}),                                                                                        \
}

/**
 * @brief LCD color configuration
 */
#define ESP_PANEL_BOARD_LCD_COLOR_BITS          (ESP_PANEL_LCD_COLOR_BITS_RGB565)
                                                        // ESP_PANEL_LCD_COLOR_BITS_RGB565/RGB666/RGB888
#define ESP_PANEL_BOARD_LCD_COLOR_BGR_ORDER     (0)     // 0: RGB, 1: BGR
#define ESP_PANEL_BOARD_LCD_COLOR_INEVRT_BIT    (1)     // 0/1

/**
 * @brief LCD transformation configuration
 */
#define ESP_PANEL_BOARD_LCD_SWAP_XY             (0)     // 0/1
#define ESP_PANEL_BOARD_LCD_MIRROR_X            (0)     // 0/1
#define ESP_PANEL_BOARD_LCD_MIRROR_Y            (0)     // 0/1
#define ESP_PANEL_BOARD_LCD_GAP_X               (0)     // [0, ESP_PANEL_BOARD_WIDTH]
#define ESP_PANEL_BOARD_LCD_GAP_Y               (0)     // [0, ESP_PANEL_BOARD_HEIGHT]

/**
 * @brief LCD reset pin configuration
 */
#define ESP_PANEL_BOARD_LCD_RST_IO              (-1)    // Reset pin, -1 if not used
#define ESP_PANEL_BOARD_LCD_RST_LEVEL           (0)     // Reset active level, 0: low, 1: high

#endif // ESP_PANEL_BOARD_USE_LCD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Please update the following macros to configure the touch panel ///////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Touch panel configuration flag (0/1)
 *
 * Set to `1` to enable touch panel support, `0` to disable
 */
#define ESP_PANEL_BOARD_USE_TOUCH               (1)

#if ESP_PANEL_BOARD_USE_TOUCH
/**
 * @brief Touch controller selection
 */
#define ESP_PANEL_BOARD_TOUCH_CONTROLLER        CST816S

/**
 * @brief Touch bus type selection
 */
#define ESP_PANEL_BOARD_TOUCH_BUS_TYPE          (ESP_PANEL_BUS_TYPE_I2C)

#if (ESP_PANEL_BOARD_TOUCH_BUS_TYPE == ESP_PANEL_BUS_TYPE_I2C) || \
    (ESP_PANEL_BOARD_TOUCH_BUS_TYPE == ESP_PANEL_BUS_TYPE_SPI)
/**
 * If set to 1, the bus will skip to initialize the corresponding host. Users need to initialize the host in advance.
 *
 * For drivers which created by this library, even if they use the same host, the host will be initialized only once.
 * So it is not necessary to set the macro to `1`. For other drivers (like `Wire`), please set the macro to `1`
 * ensure that the host is initialized only once.
 */
#define ESP_PANEL_BOARD_TOUCH_BUS_SKIP_INIT_HOST        (0)     // 0/1. Typically set to 0
#endif

/**
 * @brief Touch bus parameters configuration
 */
#if ESP_PANEL_BOARD_TOUCH_BUS_TYPE == ESP_PANEL_BUS_TYPE_I2C

    /**
     * @brief I2C bus
     */
    /* For general */
    #define ESP_PANEL_BOARD_TOUCH_I2C_HOST_ID           (1)     // Typically set to 0
#if !ESP_PANEL_BOARD_TOUCH_BUS_SKIP_INIT_HOST
    /* For host */
    #define ESP_PANEL_BOARD_TOUCH_I2C_CLK_HZ            (400 * 1000)
                                                                // Typically set to 400K
    #define ESP_PANEL_BOARD_TOUCH_I2C_SCL_PULLUP        (1)     // 0/1. Typically set to 1
    #define ESP_PANEL_BOARD_TOUCH_I2C_SDA_PULLUP        (1)     // 0/1. Typically set to 1
    #define ESP_PANEL_BOARD_TOUCH_I2C_IO_SCL            (10)
    #define ESP_PANEL_BOARD_TOUCH_I2C_IO_SDA            (11)
#endif
    /* For panel */
    #define ESP_PANEL_BOARD_TOUCH_I2C_ADDRESS           (0)     // Typically set to 0 to use the default address.
                                                                // - For touchs with only one address, set to 0
                                                                // - For touchs with multiple addresses, set to 0 or
                                                                //   the address. Like GT911, there are two addresses:
                                                                //   0x5D(default) and 0x14

#endif // ESP_PANEL_BOARD_TOUCH_BUS_TYPE

/**
 * @brief Touch panel transformation flags
 */
#define ESP_PANEL_BOARD_TOUCH_SWAP_XY           (0)     // 0/1
#define ESP_PANEL_BOARD_TOUCH_MIRROR_X          (0)     // 0/1
#define ESP_PANEL_BOARD_TOUCH_MIRROR_Y          (0)     // 0/1

/**
 * @brief Touch panel control pins
 */
#define ESP_PANEL_BOARD_TOUCH_RST_IO            (-1)    // Reset pin, -1 if not used
#define ESP_PANEL_BOARD_TOUCH_RST_LEVEL         (0)     // Reset active level, 0: low, 1: high
#define ESP_PANEL_BOARD_TOUCH_INT_IO            (4)     // Interrupt pin, -1 if not used
#define ESP_PANEL_BOARD_TOUCH_INT_LEVEL         (0)     // Interrupt active level, 0: low, 1: high

#endif // ESP_PANEL_BOARD_USE_TOUCH

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Please update the following macros to configure the backlight ////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Backlight configuration flag (0/1)
 *
 * Set to `1` to enable backlight support, `0` to disable
 */
#define ESP_PANEL_BOARD_USE_BACKLIGHT           (1)

#if ESP_PANEL_BOARD_USE_BACKLIGHT
/**
 * @brief Backlight control type selection
 */
#define ESP_PANEL_BOARD_BACKLIGHT_TYPE          (ESP_PANEL_BACKLIGHT_TYPE_PWM_LEDC)

#if (ESP_PANEL_BOARD_BACKLIGHT_TYPE == ESP_PANEL_BACKLIGHT_TYPE_SWITCH_GPIO) || \
    (ESP_PANEL_BOARD_BACKLIGHT_TYPE == ESP_PANEL_BACKLIGHT_TYPE_SWITCH_EXPANDER) || \
    (ESP_PANEL_BOARD_BACKLIGHT_TYPE == ESP_PANEL_BACKLIGHT_TYPE_PWM_LEDC)

    /**
     * @brief Backlight control pin configuration
     */
    #define ESP_PANEL_BOARD_BACKLIGHT_IO        (5)     // Output GPIO pin number
    #define ESP_PANEL_BOARD_BACKLIGHT_ON_LEVEL  (1)     // Active level, 0: low, 1: high

#endif // ESP_PANEL_BOARD_BACKLIGHT_TYPE

/**
 * @brief Backlight idle state configuration (0/1)
 *
 * Set to 1 if want to turn off the backlight after initializing. Otherwise, the backlight will be on.
 */
#define ESP_PANEL_BOARD_BACKLIGHT_IDLE_OFF      (0)

#endif // ESP_PANEL_BOARD_USE_BACKLIGHT

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Please update the following macros to configure the IO expander //////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief IO expander configuration flag (0/1)
 *
 * Set to `1` to enable IO expander support, `0` to disable
 */
#define ESP_PANEL_BOARD_USE_EXPANDER            (1)

#if ESP_PANEL_BOARD_USE_EXPANDER
/**
 * @brief IO expander chip selection
 */
#define ESP_PANEL_BOARD_EXPANDER_CHIP           TCA95XX_8BIT

/**
 * @brief IO expander I2C bus parameters configuration
 */
/**
 * If set to 1, the bus will skip to initialize the corresponding host. Users need to initialize the host in advance.
 *
 * For drivers which created by this library, even if they use the same host, the host will be initialized only once.
 * So it is not necessary to set the macro to `1`. For other devices, please set the macro to `1` ensure that the
 * host is initialized only once.
 */
#define ESP_PANEL_BOARD_EXPANDER_SKIP_INIT_HOST     (0)     // 0/1
/* For general */
#define ESP_PANEL_BOARD_EXPANDER_I2C_HOST_ID        (0)     // Typically set to 0
/* For host */
#if !ESP_PANEL_BOARD_EXPANDER_SKIP_INIT_HOST
#define ESP_PANEL_BOARD_EXPANDER_I2C_CLK_HZ         (400 * 1000)
                                                            // Typically set to 400K
#define ESP_PANEL_BOARD_EXPANDER_I2C_SCL_PULLUP     (0)     // 0/1. Typically set to 1
#define ESP_PANEL_BOARD_EXPANDER_I2C_SDA_PULLUP     (0)     // 0/1. Typically set to 1
#define ESP_PANEL_BOARD_EXPANDER_I2C_IO_SCL         (10)
#define ESP_PANEL_BOARD_EXPANDER_I2C_IO_SDA         (11)
#endif // ESP_PANEL_BOARD_EXPANDER_SKIP_INIT_HOST
/* For device */
#define ESP_PANEL_BOARD_EXPANDER_I2C_ADDRESS        (0x20)  // The actual I2C address. Even for the same model of IC,
                                                            // the I2C address may be different, and confirmation based on
                                                            // the actual hardware connection is required
#endif // ESP_PANEL_BOARD_USE_EXPANDER

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////// Please utilize the following macros to execute any additional code if required /////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Pre-begin function for LCD initialization
 *
 * @param[in] p Pointer to the board object
 * @return true on success, false on failure
 */
#define ESP_PANEL_BOARD_LCD_PRE_BEGIN_FUNCTION(p) \
    {  \
        constexpr int LCD_RST = 1; \
        auto board = static_cast<Board *>(p);  \
        auto expander = board->getIO_Expander()->getBase(); \
        /* LCD reset */ \
        expander->pinMode(LCD_RST, OUTPUT);       \
        expander->digitalWrite(LCD_RST, LOW);     \
        vTaskDelay(pdMS_TO_TICKS(10));          \
        expander->digitalWrite(LCD_RST, HIGH);    \
        vTaskDelay(pdMS_TO_TICKS(100));          \
        return true;    \
    }

/**
 * @brief Pre-begin function for touch panel initialization
 *
 * @param[in] p Pointer to the board object
 * @return true on success, false on failure
 */
#define ESP_PANEL_BOARD_TOUCH_PRE_BEGIN_FUNCTION(p) \
    {  \
        constexpr int TP_RST = 0; \
        auto board = static_cast<Board *>(p);  \
        auto expander = board->getIO_Expander()->getBase(); \
        /* Touch reset */ \
        expander->pinMode(TP_RST, OUTPUT);       \
        expander->digitalWrite(TP_RST, LOW);     \
        vTaskDelay(pdMS_TO_TICKS(30));          \
        expander->digitalWrite(TP_RST, HIGH);    \
        vTaskDelay(pdMS_TO_TICKS(50));          \
        return true;    \
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// File Version ///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Do not change the following versions. These version numbers are used to check compatibility between this
 * configuration file and the library. Rules for version numbers:
 * 1. Major version mismatch: Configurations are incompatible, must use library version
 * 2. Minor version mismatch: May be missing new configurations, recommended to update
 * 3. Patch version mismatch: No impact on functionality
 */
#define ESP_PANEL_BOARD_CUSTOM_FILE_VERSION_MAJOR 1
#define ESP_PANEL_BOARD_CUSTOM_FILE_VERSION_MINOR 0
#define ESP_PANEL_BOARD_CUSTOM_FILE_VERSION_PATCH 0

// *INDENT-ON*
