
/* PIN CONFIGURATION: 
DATA LINES : D4 = PA0 ; D5 = PA1; D6 = PA2; D7 = PA3;
RS = PA4;
RW = PA5;
E  = PA6;
*/
/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT zephyr_LCD
#include lcd.h

#include <device.h>
#include <drivers/gpio.h>
#include <drivers/sensor.h>

#include <logging/log.h>
LOG_MODULE_REGISTER(LCD, CONFIG_SENSOR_LOG_LEVEL);
/*
void lcdinit();
void togglepin();
*/

/*
void lcdinit(const struct device *input){


    const struct device *test = input;
	//test = device_get_binding("GPIOD");
 	gpio_pin_configure_dt(test, 0, GPIO_OUTPUT);   
}

void togglepin(const struct device *input){
		gpio_pin_toggle(input, 0);
}*/