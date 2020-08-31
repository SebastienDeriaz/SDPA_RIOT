/*
 * Copyright (C) 2018 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @{
 *
 * @file
 * @author  Yann Charbon <y.charbon@bluewin.ch>
 *
 */

#ifndef GNRC_SPEED_IFCONFIG_H
#define GNRC_SPEED_IFCONFIG_H

#define ENABLE_DEBUG (1)
#include "debug.h"

int gnrc_netif_config(int argc, char **argv);

#endif GNRC_SPEED_IFCONFIG_H

/** @} */