#ifndef lcd_h
#define lcd_h

#include <zephyr.h>


#define D7_PIN 0
#define D6_PIN 1
#define D5_PIN 2
#define D4_PIN 3 
#define E_PIN  4
#define RS_PIN 5

enum LCD_commands{ //indented commands are part of the root command. Just OR these commands and they should work fine. all commands are in hexadecimal as it was easier to translate. Xs are other options within the menu but for the purposes of hex they are 0
    LCD_CMD_CLEAR =   0x01, //0b0000 0001 
    LCD_CMD_HOME =    0x02, //0b0000 0010
    LCD_CMD_DISPLAY = 0x08, //0b0000 1XXX
        LCD_CMD_DISPLAY_ON =  0x04, //0b0000 X1XX
        LCD_CMD_DISPLAY_OFF = 0x00, //0b0000 X0XX
        LCD_CMD_DISPLAY_CURSOR_ON =  0x02, //0b0000 XX1X
        LCD_CMD_DISPLAY_CURSOR_OFF = 0x00, //0b0000 XX0X
        LCD_CMD_DISPLAY_BLINK_ON =   0x01, //0b0000 XXX1
        LCD_CMD_DISPLAY_BLINK_OFF =  0x00, //0b0000 XXX0
    LCD_CMD_SHIFT = 0x10, //0b0001 0000
        LCD_CMD_SHIFT_DISPLAY = 0x08, //0b0000 1000
        LCD_CMD_SHIFT_CURSOR =  0x00, //0b0000 0000
        LCD_CMD_SHIFT_LEFT =    0x00, //0b0000 0000
        LCD_CMD_SHIFT_RIGHT =   0x04, //0b0000 0100
    LCD_CMD_CONFIG = 0x20, //0b0010 0000
        LCD_CMD_CONFIG_8BITMODE = 0x10, //0b0001 0000
        LCD_CMD_CONFIG_4BITMODE = 0x00, //0b0000 0000
        LCD_CMD_CONFIG_2ROWS =  0x08, //0b0000 1000
        LCD_CMD_CONFIG_1ROWS =  0x00, //0b0000 0000
        LCD_CMD_CONFIG_5X10 =   0x04, //0b0000 1000 CONSISTENT
        LCD_CMD_CONFIG_5X8 =    0x00, //0b0000 0000 CONSISTENT
    LCD_CMD_MODE = 0x04, //0b0000 01XX
        LCD_CMD_MODE_INC =   0x02, //0b0000 0X1X
        LCD_CMD_MODE_DEC =   0x00, //0b0000 0X0X
        LCD_CMD_MODE_SHIFT = 0x01, //0b0000 0XX1
    LCD_CMD_CGRAM = 0x40, //0b0100 0000
    LCD_CMD_DDRAM = 0x80, //0b1000 0000
};

void lcdinit(const struct device *inputdevice);
void lcdcmdwrite(const struct device *inputdev, uint8_t cmddata);
void lcddatawrite(const struct device *inputdev, uint8_t data);
void lcdcursorposition(const struct device *inputdevice ,uint8_t rowpos, uint8_t colpos);

#endif