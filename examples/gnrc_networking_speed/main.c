/*
 * Copyright (C) 2015 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Example application for demonstrating the RIOT network stack
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 * @}
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "ifconfig.h"
#include "shell.h"
#include "msg.h"

#include "xtimer.h"
#include "random.h"

#define MAIN_QUEUE_SIZE     (8)
static msg_t _main_msg_queue[MAIN_QUEUE_SIZE];

//extern int udp_cmd(int argc, char **argv);
extern int gnrc_netif_config(int argc, char **argv);
extern int _gnrc_icmpv6_ping(int argc, char **argv);


/*static const shell_command_t shell_commands[] = {
    { "udp", "send data over UDP and listen on UDP ports", udp_cmd },
    { NULL, NULL, NULL }
};*/

int main(void)
{
    /* we need a message queue for the thread running the shell in order to
     * receive potentially fast incoming networking packets */
    msg_init_queue(_main_msg_queue, MAIN_QUEUE_SIZE);
    puts("RIOT network stack example application");

    /* start shell */
    puts("All up, running the shell now");
    //char line_buf[SHELL_DEFAULT_BUFSIZE];

    // Sleep to let startup
    xtimer_ticks32_t t = xtimer_now();
    xtimer_usleep(1000000);

    // Iface configuration
    char param[20] = "phy_mode";
    char value[20] = "MR-OFDM";
    char* ifcmd[] = {"ifconfig","6","set",param,value};
    gnrc_netif_config(5,ifcmd);

    strcpy(param,"option");
    strcpy(value,"3");
    gnrc_netif_config(5,ifcmd);

    strcpy(param,"scheme");
    strcpy(value,"6");
    gnrc_netif_config(5,ifcmd);

    strcpy(param,"power");
    strcpy(value,"31");
    gnrc_netif_config(5,ifcmd);

    puts("Finished configuring iface");

    do{
        //shell_run_once(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

#ifdef BOARD_STM32F3DISCOVERYAT86RF215
        LED6_TOGGLE;
#endif

        t = xtimer_now();
        printf("\t Thread start: %lu\n", t.ticks32);
        /* sleep */
        xtimer_usleep(1000000);
        t = xtimer_now();
        printf("\t Thread stop: %lu\n", t.ticks32);

        char addr[] = "fe80::2068:3123:1af4:d23a%6";
        char sizeParam[] = "-s";
        //char intervalParam[] = "-i";
        char countParam[] = "-c";
        char* cmd[] = {"ping6",addr,countParam,"50",sizeParam,"1200"};

        _gnrc_icmpv6_ping(6, cmd);

        //uint8_t data[10];
        //random_bytes(data, sizeof(data));
        //printf("%c %c %c", (char)data[0], (char)data[1], (char)data[2]);

        //char* cmd[] = {"udp","send",addr,"8808",(char*)data};
        //udp_cmd(5,cmd);

    } while(1);
    

    /* should be never reached */
    return 0;
}
