/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_module-rf-ofdm
 * @{
 *
 * @file
 * @brief       Peripheral MCU configuration for the module-rf-ofdm board
 *
 * @author      Yann Charbon <y.charbon@bluewin.ch>
 */

#ifndef PERIPH_CONF_H
#define PERIPH_CONF_H

#include "periph_cpu.h"
#include "l4/cfg_clock_80_1.h"  // STM32L4 clock config

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @name   Timer configuration
 * @{
 */
static const timer_conf_t timer_config[] = {
    {
        .dev      = TIM2,
        .max      = 0xffffffff,
        .rcc_mask = RCC_APB1ENR_TIM2EN,
        .bus      = APB1,
        .irqn     = TIM2_IRQn
    }
};

#define TIMER_0_ISR         isr_tim2

#define TIMER_NUMOF         ARRAY_SIZE(timer_config)
/** @} */

/**
 * @name   UART configuration
 * @{
 * Until there is only 1 USART used on the board, only USART1 has been implemented
 */
static const uart_conf_t uart_config[] = {
    {
        .dev        = USART1,                   // Pointer to UART base register
        .rcc_mask   = RCC_APB2ENR_USART1EN,     // bit in clock enable register
        .rx_pin     = GPIO_PIN(PORT_A, 10),     // RX pin
        .tx_pin     = GPIO_PIN(PORT_A,  9),     // TX pin
        .rx_af      = GPIO_AF7,                 // Alternate function for RX pin
        .tx_af      = GPIO_AF7,                 // Alternate function for TX pin
        .cts_pin    = GPIO_PIN(PORT_A,  11),    // CTS pin
        .rts_pin    = GPIO_PIN(PORT_A,  12),    // RTS pin
        .cts_af     = GPIO_AF7,                 // CTS alternate function
        .rts_af     = GPIO_AF7,                 // RTS alternate function
        .bus        = APB2,                     // APB bus
        .irqn       = USART1_IRQn               // IRQ channel
    }
};

#define UART_0_ISR          (isr_usart1)

#define UART_NUMOF          ARRAY_SIZE(uart_config)
/** @} */


/**
 * @name SPI configuration
 * @{
 * Since there is only 1 SPI used on the board, only SP1 has been implemented
 */
static const uint8_t spi_divtable[2][5] = {
    {       /* for APB1 @ 36000000Hz */
        7,  /* -> 140625Hz */
        6,  /* -> 281250Hz */
        4,  /* -> 1125000Hz */
        2,  /* -> 4500000Hz */
        1   /* -> 9000000Hz */
    },
    {       /* for APB2 @ 72000000Hz */
        7,  /* -> 281250Hz */
        7,  /* -> 281250Hz */
        5,  /* -> 1125000Hz */
        3,  /* -> 4500000Hz */
        2   /* -> 9000000Hz */
    }
};

static const spi_conf_t spi_config[] = {
    {
        .dev      = SPI1,                   // SPI device base register address
        .mosi_pin = GPIO_PIN(PORT_A, 7),    // MOSI pin
        .miso_pin = GPIO_PIN(PORT_A, 6),    // MISO pin
        .sclk_pin = GPIO_PIN(PORT_A, 5),    // SCK pin
        .cs_pin   = GPIO_UNDEF,             // CS pin
        .mosi_af  = GPIO_AF5,               // MOSI alternate function
        .miso_af  = GPIO_AF5,               // MISO alternate function
        .sclk_af  = GPIO_AF5,               // SCK alternate function
        .cs_af    = GPIO_AF5,               // CS alternate function
        .rccmask  = RCC_APB2ENR_SPI1EN,     // bit in the RCC peripheral enable register
        .apbbus   = APB2                    // APBx bus the device is connected to
    }
};

#define SPI_NUMOF           ARRAY_SIZE(spi_config)
/** @} */


#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H */
