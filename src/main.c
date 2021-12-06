/*hydrolab, a RTOS controller for hydroponics farming. Includes automated pumping, moisture detection, data collection and lighting control on a multithreaded application
done using Zephyr with the eventual goal of being completely board agnostic*/
#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <drivers/sensor.h>
#include <stdint.h>
#include "lcd.h"

#define SLEEPTIME 1000

#define LED0_NODE DT_ALIAS(led2)
#define LED0	  DT_GPIO_LABEL(LED0_NODE, gpios)
#define PIN		  DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS	  DT_GPIO_FLAGS(LED0_NODE, gpios)

#define LED3_NODE DT_ALIAS(led3)
#define LED3	  DT_GPIO_LABEL(LED3_NODE, gpios)
#define PIN3	  DT_GPIO_PIN(LED3_NODE, gpios)
#define FLAGS3	  DT_GPIO_FLAGS(LED3_NODE, gpios)



const uint8_t str[] = "TEMP:"; // test string
const uint8_t str2[] = "HUMI:";
void main(void){

	//bool toggle = true;
	const struct device *blue;
	const struct device *lcd;

	lcd = device_get_binding("GPIOD");
	blue = device_get_binding(LED3);

	gpio_pin_configure(blue, PIN3, GPIO_OUTPUT_INACTIVE | FLAGS3);
	lcdinit(lcd);
	gpio_pin_set(blue, PIN3, 1);
	uint8_t column = 0;
	uint8_t row = 0;
	while(1){

		lcdcmdwrite(lcd,LCD_CMD_CLEAR);

		lcdcursorposition(lcd, row, column); //input, row, column
		for (int i = 0; i <sizeof(str) -1; i++){
			lcddatawrite(lcd, str[i]);
		}
		row = 1;
		lcdcursorposition(lcd, row, column);
		for (int i = 0; i <sizeof(str2) -1; i++){
			lcddatawrite(lcd, str2[i]);
		}		
		row = 0;
		k_msleep(500);
	}



}
