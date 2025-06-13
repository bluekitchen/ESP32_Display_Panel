/*
 * SPDX-FileCopyrightText: 2023-2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
/**
 * @file   BOARD_ESP32_S3_BOX_3.h
 * @brief  Configuration file for ESP32_S3_BOX_3 & ESP32-S3-Box-3B
 * @author Espressif@lzw655
 * @link   https://github.com/espressif/esp-box/tree/master
 */

#pragma once

// *INDENT-OFF*

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Please update the following macros to configure general panel /////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Board name
 */
#define ESP_PANEL_BOARD_NAME                "Generic:ESP32_2432S028R"

/**
 * @brief Panel resolution configuration in pixels
 */
#define ESP_PANEL_BOARD_WIDTH               (240)   // Panel width (horizontal, in pixels)
#define ESP_PANEL_BOARD_HEIGHT              (320)   // Panel height (vertical, in pixels)

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
#define ESP_PANEL_BOARD_LCD_CONTROLLER      ILI9341

/**
 * @brief LCD bus type selection
 */
#define ESP_PANEL_BOARD_LCD_BUS_TYPE        (ESP_PANEL_BUS_TYPE_SPI)

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
#if ESP_PANEL_BOARD_LCD_BUS_TYPE == ESP_PANEL_BUS_TYPE_SPI

    /**
     * @brief SPI bus
     */
    /* For general */
    #define ESP_PANEL_BOARD_LCD_SPI_HOST_ID         (1)     // Typically set to 1
#if !ESP_PANEL_BOARD_LCD_BUS_SKIP_INIT_HOST
    /* For host */
    #define ESP_PANEL_BOARD_LCD_SPI_IO_SCK          (14)
    #define ESP_PANEL_BOARD_LCD_SPI_IO_MOSI         (13)
    #define ESP_PANEL_BOARD_LCD_SPI_IO_MISO         (12)    // -1 if not used
#endif // ESP_PANEL_BOARD_LCD_BUS_SKIP_INIT_HOST
    /* For panel */
    #define ESP_PANEL_BOARD_LCD_SPI_IO_CS           (15)    // -1 if not used
    #define ESP_PANEL_BOARD_LCD_SPI_IO_DC           (2)
    #define ESP_PANEL_BOARD_LCD_SPI_MODE            (0)     // 0-3. Typically set to 0
    #define ESP_PANEL_BOARD_LCD_SPI_CLK_HZ          (30 * 1000 * 1000)
                                                            // Should be an integer divisor of 80M, typically set to 40M
    #define ESP_PANEL_BOARD_LCD_SPI_CMD_BITS        (8)     // Typically set to 8
    #define ESP_PANEL_BOARD_LCD_SPI_PARAM_BITS      (8)     // Typically set to 8

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

#define ESP_PANEL_BOARD_LCD_VENDOR_INIT_CMD()                                                                                               \
{                                                                                                                                           \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xCF, {0x00, 0xD9, 0x30}),                                                                         \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xED, {0x64, 0x03, 0x12, 0x81}),                                                                   \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE8, {0x85, 0x10, 0x7A}),                                                                         \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xCB, {0x39, 0x2C, 0x00, 0x34, 0x02}),                                                             \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF7, {0x20}),                                                                                     \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xEA, {0x00, 0x00}),                                                                               \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC0, {0x1B}),                                                                                     \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC1, {0x12}),                                                                                     \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC5, {0x26, 0x26}),                                                                               \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC7, {0xB0}),                                                                                     \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB1, {0x00, 0x1A}),                                                                               \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB6, {0x0A, 0xA2}),                                                                               \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF2, {0x00}),                                                                                     \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x26, {0x01}),                                                                                     \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE0, {0x1F, 0x24, 0x24, 0x0D, 0x12, 0x09, 0x52, 0xB7, 0x3F, 0x0C, 0x15, 0x06, 0x0E, 0x08, 0x00}), \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE1, {0x00, 0x1B, 0x1B, 0x02, 0x0E, 0x06, 0x2E, 0x48, 0x3F, 0x03, 0x0A, 0x09, 0x31, 0x37, 0x1F}), \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x2B, {0x00, 0x00, 0x01, 0x3f}),                                                                   \
    ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x2A, {0x00, 0x00, 0x00, 0xEF}),                                                                   \
    ESP_PANEL_LCD_CMD_WITH_NONE_PARAM(100, 0x11),                                                                                           \
}

/**
 * @brief LCD color configuration
 */
#define ESP_PANEL_BOARD_LCD_COLOR_BITS          (ESP_PANEL_LCD_COLOR_BITS_RGB565)
                                                        // ESP_PANEL_LCD_COLOR_BITS_RGB565/RGB666/RGB888
#define ESP_PANEL_BOARD_LCD_COLOR_BGR_ORDER     (1)     // 0: RGB, 1: BGR
#define ESP_PANEL_BOARD_LCD_COLOR_INEVRT_BIT    (0)     // 0/1

/**
 * @brief LCD transformation configuration
 */
#define ESP_PANEL_BOARD_LCD_SWAP_XY             (0)     // 0/1
#define ESP_PANEL_BOARD_LCD_MIRROR_X            (1)     // 0/1
#define ESP_PANEL_BOARD_LCD_MIRROR_Y            (1)     // 0/1
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
#define ESP_PANEL_BOARD_TOUCH_CONTROLLER        XPT2046

/**
 * @brief Touch bus type selection
 */
#define ESP_PANEL_BOARD_TOUCH_BUS_TYPE          (ESP_PANEL_BUS_TYPE_SPI)

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
#if ESP_PANEL_BOARD_TOUCH_BUS_TYPE == ESP_PANEL_BUS_TYPE_SPI

    /**
     * @brief SPI bus
     */
    /* For general */
    #define ESP_PANEL_BOARD_TOUCH_SPI_HOST_ID           (2)     // Typically set to 0
#if !ESP_PANEL_BOARD_TOUCH_BUS_SKIP_INIT_HOST
    /* For host */
    #define ESP_PANEL_BOARD_TOUCH_SPI_IO_SCK            (25)
    #define ESP_PANEL_BOARD_TOUCH_SPI_IO_MOSI           (32)
    #define ESP_PANEL_BOARD_TOUCH_SPI_IO_MISO           (39)
    #define ESP_PANEL_BOARD_TOUCH_SPI_IO_CS             (33)
#endif
    /* For panel */
    #define ESP_PANEL_BOARD_TOUCH_SPI_MODE              (0)     // 0-3. Typically set to 0
    #define ESP_PANEL_BOARD_TOUCH_SPI_CLK_HZ            (40 * 1000 * 1000)

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
#define ESP_PANEL_BOARD_TOUCH_INT_IO            (36)    // Interrupt pin, -1 if not used
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
    #define ESP_PANEL_BOARD_BACKLIGHT_IO        (21)    // Output GPIO pin number
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
#define ESP_PANEL_BOARD_USE_EXPANDER            (0)

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
        return true; \
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
