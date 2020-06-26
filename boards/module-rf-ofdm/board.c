/*
 * Copyright (C) 2020 Yann Charbon
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     boards_module-rf-ofdm_STM32L432KCU6_AT86RF215
 * @{
 *
 * @file
 * @brief       Board specific implementations for the Module-RF-OFDM including an STM32L432KCU6 with an AT86RF215M transceiver
 *
 * @author      Yann Charbon <y.charbon@bluewin.ch>
 *
 * @}
 */

#include "board.h"
#include "periph/gpio.h"

void board_init(void)
{
    //#ifdef MODULE_AT86RF215
    /* use at86rf215 2.4ghz radio*/
    //RF24_SWITCH_AT86RF215_ON;
    //#endif   

    /* initialize the CPU */
    cpu_init();
}
