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
 * @brief       Board specific implementations for the STM32F3Discovery evaluation board with AT86RF215 transceiver
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

    /* initialize the boards LEDs */
    gpio_init(LED0_PIN, GPIO_OUT);
    gpio_init(LED1_PIN, GPIO_OUT);
    gpio_init(LED2_PIN, GPIO_OUT);
    gpio_init(LED3_PIN, GPIO_OUT);
    gpio_init(LED4_PIN, GPIO_OUT);
    gpio_init(LED5_PIN, GPIO_OUT);
    gpio_init(LED6_PIN, GPIO_OUT);
    gpio_init(LED7_PIN, GPIO_OUT);
    gpio_init(TEST_PIN, GPIO_OUT);

    TEST_PIN_HIGH;

    //gpio_set(TEST_PIN);
    //gpio_set(LED6_PIN);
    

}
