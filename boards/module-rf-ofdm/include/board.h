/*
 * Copyright (C) 2020 Yann Charbon
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     boards_stm32f3discovery_AT86RF215
 * @{
 *
 * @file
 * @brief       Board specific definitions for the STM32F3Discovery evaluation board with AT86RF215 transceiver
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
 * @name    xtimer configuration
 * @{
 */
//#define XTIMER_WIDTH        (16)
//#define XTIMER_BACKOFF      (50)
//#define XTIMER_ISR_BACKOFF  (40)
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
