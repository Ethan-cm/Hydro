/*hydrolab, a RTOS controller for hydroponics farming. Includes automated pumping, moisture detection, data collection and lighting control on a multithreaded application
done using Zephyr with the eventual goal of being completely board agnostic*/
#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <drivers/sensor.h>
#include <stdint.h>
#include "lcd.h"
#include <string.h>

#define SLEEPTIME 1000
#define DHTSLEEP  1950
#define STACKSIZE 128
#define PRIORITY  7
#define zero 0

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
	//blue = device_get_binding(LED3);
	

	//gpio_pin_configure(blue, PIN3, GPIO_OUTPUT_INACTIVE | FLAGS3);
	lcdinit(lcd);
	uint8_t column = 0;
	uint8_t row = 0;

	

	

	while(1){
		/*Start DHT sensor block *********************************
		* this block is pulling the data from the secondary thread
		* this is done due to the device requirement that data
		* is refreshed on a 2 second window*/



		/*End DHT sensor block*/
		/*LCD DISPLAY BLOCK*/
		lcdcmdwrite(lcd,LCD_CMD_CLEAR);

		lcdcursorposition(lcd, row, column); //input, row, column
		for (int i = 0; i <sizeof(str) -1; i++){
			lcddatawrite(lcd, str[i]);
		}
		//lcdcursorposition(lcd, row, sizeof(str));
		//lcddatawrite(lcd,);
		row = 1;
		lcdcursorposition(lcd, row, column);
		for (int i = 0; i <sizeof(str2) -1; i++){
			lcddatawrite(lcd, str2[i]);
		}		
		row = 0;
		/*LCD DISPLAY BLOCK ENDS*/

		k_msleep(500);
	}



}

void DHTgrab(void)
{
	const struct device *blue;

	blue = device_get_binding(LED3);

	gpio_pin_configure(blue, PIN3, GPIO_OUTPUT_INACTIVE | FLAGS3);
	bool toggle = false;
	struct sensor_value temperature;
	struct sensor_value humidity;
	double tempval;
	double humival;
	const struct device *dht11;
	const char *const dht = DT_LABEL(DT_INST(0,aosong_dht));
	dht11 = device_get_binding(dht);

	while(1){
		int rc = sensor_sample_fetch(dht11);

		rc = sensor_channel_get(dht11, SENSOR_CHAN_AMBIENT_TEMP, &temperature);
		if (rc == 0) {
		rc = sensor_channel_get(dht11, SENSOR_CHAN_HUMIDITY, &humidity);
		

		tempval = sensor_value_to_double(&temperature);
		humival = sensor_value_to_double(&humidity);
		
		//blue light blinks, just shows us if the sensor is working
		gpio_pin_set(blue, PIN3, (int)toggle);
		toggle = !toggle;
		k_msleep(2000);
	}

	
}

K_THREAD_DEFINE(dht_id, STACKSIZE, DHTgrab, NULL, NULL, NULL, PRIORITY, 0, 0);