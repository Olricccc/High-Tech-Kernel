 /* Copyright (c) 2015, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __MSM_AUDIO_PINCTRL_H
#define __MSM_AUDIO_PINCTRL_H

enum pinctrl_client {
	CLIENT_WCD_INT,
	CLIENT_WCD_EXT,
	CLIENT_WSA_BONGO_1,
	CLIENT_WSA_BONGO_2,
	MAX_PINCTRL_CLIENT,
};


int msm_get_gpioset_index(enum pinctrl_client client, char *keyword);

int msm_gpioset_initialize(enum pinctrl_client client, struct device *dev);

int msm_gpioset_activate(enum pinctrl_client client, char *keyword);

int msm_gpioset_suspend(enum pinctrl_client client, char *keyword);

#endif 
