#include <stdint.h>
#include <zephyr.h>
#include "lcd.h"


void lcdinit(const struct device *inputdevice){
	/*function initializes the LCD screen by setting the pins to output as well as
	  setting the inital commands in order to set it to 4 bit mode.
	PD0 = D7
	PD1 = D6
	PD2 = D5
	PD3 = D4
	PD4 = E
	PD5 = RS
	 */
	k_msleep(15); //15 ms delay at start of operation in order to allow internal function of LCD to initalize properlyS
	int pinarray[] = {0 /*D7*/,1 /*D6*/,2 /*D5*/,3 /*D4*/,4 /*E*/, 5 /*RS*/};

	for (int i = 0; i <= sizeof(pinarray) ; i++){ //function that configures all the pins to output
		int pin = pinarray[i];
		gpio_pin_configure(inputdevice, pin, GPIO_OUTPUT_ACTIVE);
	}
	uint8_t initcmd = (LCD_CMD_CONFIG | LCD_CMD_CONFIG_4LINES);
	lcdinitwrite(inputdevice, initcmd );
	k_msleep(10);
	initcmd = (LCD_CMD_CONFIG | LCD_CMD_CONFIG_2ROWS | LCD_CMD_CONFIG_5X8 | LCD_CMD_CONFIG_4LINES); 
	lcdcmdwrite(inputdevice, initcmd);
	k_msleep(10);
	initcmd = (LCD_CMD_DISPLAY | LCD_CMD_DISPLAY_ON); //config onoff 0b0000 1000 | 0b 0000 0100 = 0b0000 1100 = 0x0C
	lcdcmdwrite(inputdevice, initcmd);
	k_msleep(10);
	return; 
}

void lcdinitwrite(const struct device *inputdev, uint8_t cmddata){ //function for writing half bits. used in initialization and the commandwrite functions
	
	gpio_pin_set(inputdev, D7_PIN, (cmddata & (1<<7)));//bit shifting to get at the data in the register, pretty sure this is more optimized than just for looping over them with an array
	gpio_pin_set(inputdev, D6_PIN, (cmddata & (1<<6)));
	gpio_pin_set(inputdev, D5_PIN, (cmddata & (1<<5)));
	gpio_pin_set(inputdev, D4_PIN, (cmddata & (1<<4)));
	epulse(inputdev); 
	return;
}

void lcdcmdwrite(const struct device *inputdev, uint8_t cmddata){
	commandmode(inputdev);
	lcdbytewrite(inputdev, cmddata);
	return;
}

void lcddatawrite(const struct device *inputdev, uint8_t data){
	datamode(inputdev);
	lcdbytewrite(inputdev, data);

}

void lcdbytewrite(const struct device *inputdev,uint8_t data){ //
	/*function that is used by other LCD functions in order to write data to the 
	data is an int that contains 
	inputdev in the incoming device pointer (should be GPIOD)
	delay is a integer wait time in miliseconds.
	*/
	gpio_pin_set(inputdev, D7_PIN, (data & (1<<7)));//bit shifting to get at the data in the register, pretty sure this is more optimized than just for looping over them with an array
	gpio_pin_set(inputdev, D6_PIN, (data & (1<<6)));
	gpio_pin_set(inputdev, D5_PIN, (data & (1<<5)));
	gpio_pin_set(inputdev, D4_PIN, (data & (1<<4)));
	epulse(inputdev);	
	gpio_pin_set(inputdev, D7_PIN, (data & (1<<3)));
	gpio_pin_set(inputdev, D6_PIN, (data & (1<<2)));
	gpio_pin_set(inputdev, D5_PIN, (data & (1<<1)));
	gpio_pin_set(inputdev, D4_PIN, (data & (1<<0)));
	epulse(inputdev);
	return;
}

void datamode(const struct device *inputdevice){ //function used in other LCD related functions to set rsset to data mode
	gpio_pin_set(inputdevice, RS_PIN, 1);
	return;
}

void commandmode(const struct device *inputdevice){ //function used in other LCD related functions to set rsset to command mode
	gpio_pin_set(inputdevice, RS_PIN, 0);
	return;
}
void epulse(const struct device *inputdevice){ //function used in other LCD related functions to set EN on or off
	gpio_pin_set(inputdevice, E_PIN, 1);
	k_msleep(1);
	gpio_pin_set(inputdevice, E_PIN, 0);
	return;
}

void lcdcursorposition(const struct device *inputdevice ,uint8_t rowpos, uint8_t colpos) //function used to set the cursor positon to the specified row and column 
{	
	uint8_t hexadress;
	switch (rowpos){
		case 0:
			hexadress = 0x00;
		break;

		case 1:
			hexadress = 0x40;// = 0b 0010 0000
		break;

		default:
			return; 
	}	//logic statement for the row position. 

	if (colpos < 16){
		hexadress += colpos; // add the number to the position register, this is done this way because we cant possibly fuck up our row position.
	}
	else{return;}
	
	lcdcmdwrite(inputdevice, hexadress);
	
	return;

}
 
