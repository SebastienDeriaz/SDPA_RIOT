/*
 * Copyright (C) 2020 Yann Charbon
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     boards_module-rf-ofdm
 * @{
 *
 * @file
 * @brief       Board specific definitions for the Module-RF-OFDM including an STM32L432KCU6 with an AT86RF215M transceiver
 *
 * @author      Yann Charbon <y.charbon@bluewin.ch>
 */

#ifndef BOARD_H
#define BOARD_H

#include "cpu.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @name    AT86RF215 configuration
 * @{
 */
#define AT86RF215_PARAM_SPI        SPI_DEV(0)       /* AT86RF215 on SPI1 */
#define AT86RF215_PARAM_CS         GPIO_PIN(PORT_A, 4)   /* PA4 */
#define AT86RF215_PARAM_INT        GPIO_PIN(PORT_B, 0)    /* PB0 */
#define AT86RF215_PARAM_RESET      GPIO_PIN(PORT_B, 1)    /* PB1 */
#define AT86RF215_PARAM_EXT_FRONTEND_CTRL_CFG   (2)
/** @} */

/**
 * @name    Pins configuration and handlers
 * @{
 */
#define ANT_SEL_PIN           GPIO_PIN(PORT_A, 1)
#define CPS_PIN               GPIO_PIN(PORT_B, 6)
#define GPIO0_PIN             GPIO_PIN(PORT_A, 0)
#define GPIO1_PIN             GPIO_PIN(PORT_A, 2)
#define GPIO2_PIN             GPIO_PIN(PORT_A, 3)
#define GPIO3_PIN             GPIO_PIN(PORT_A, 8)

#define ANT1_SEL              (GPIOA->BSRR &= ~0x2)  /* Equivalent to gpio_reset(ANT_SEL_PIN) */
#define ANT2_SEL              (GPIOA->BSRR |= 0x2)   /* Equivalent to gpio_set(ANT_SEL_PIN) */

#define CPS_LOW               (GPIOB->BSRR &= ~0x40) /* Equivalent to gpio_reset(CPS_PIN) */
#define CPS_HIGH              (GPIOB->BSRR |= 0x40)  /* Equivalent to gpio_set(CPS_PIN) */
/** @} */

/**
 * @name    Optional pins configuration
 * @{
 */
// #define USE_OPTIONAL_PINS               
#define CSD_PIN               GPIO_PIN(PORT_B, 5)
#define CTX_PIN               GPIO_PIN(PORT_B, 7)

#define CSD_LOW               (GPIOB->BSRR &= ~0x20) /* Equivalent to gpio_reset(CSD_LOW) */
#define CSD_HIGH              (GPIOB->BSRR |= 0x20)  /* Equivalent to gpio_set(CSD_LOW) */
#define CTX_LOW               (GPIOB->BSRR &= ~0x80) /* Equivalent to gpio_reset(CTX_PIN) */
#define CTX_HIGH              (GPIOB->BSRR |= 0x80)  /* Equivalent to gpio_set(CTX_PIN) */
/** @} */


/**
 * @brief Initialize board specific hardware, including clock, LEDs and std-IO
 */
void board_init(void);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */
/** @} */
