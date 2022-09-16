/*
 * LCD.c
 *
 *  Created on: Oct 1, 2021
 *      Author: DELL
 */
#include <util/delay.h>
#include "commonmacros.h"
#include "lcd.h"
#include "GPIO.h"
#include<stdlib.h>
void LCD_init(void){
	GPIO_setupPinDirection(PORTB_ID,LCD_RS_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,LCD_RW_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,LCD_EN_PIN,PIN_OUTPUT);
	GPIO_setupPortDirection(PORTA_ID,PORT_OUTPUT);
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
	LCD_sendCommand(LCD_CURSOR_OFF);
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}
void LCD_displayCharacter(uint8 character){
	GPIO_writePin(PORTB_ID,LCD_RS_PIN,LOGIC_HIGH);
	GPIO_writePin(PORTB_ID,LCD_RW_PIN,LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(PORTB_ID,LCD_EN_PIN,LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(PORTA_ID,character);
	_delay_ms(1);
	GPIO_writePin(PORTB_ID,LCD_EN_PIN,LOGIC_LOW);
	_delay_ms(1);
}
void LCD_sendCommand(uint8 command){
	GPIO_writePin(PORTB_ID,LCD_RS_PIN,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,LCD_RW_PIN,LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(PORTB_ID,LCD_EN_PIN,LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(PORTA_ID,command);
	_delay_ms(1);
	GPIO_writePin(PORTB_ID,LCD_EN_PIN,LOGIC_LOW);
	_delay_ms(1);
}
void LCD_displayString(const uint8*str){
	uint8 i=0;
	while(str[i]!='\0'){
		LCD_displayCharacter(str[i]);
		i++;
	}
}
void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 lcd_memory_address;
	switch(row)
	{
	case 0:
		lcd_memory_address=col;
		break;
	case 1:
		lcd_memory_address=col+0x40;
		break;
	case 2:
		lcd_memory_address=col+0x10;
		break;
	case 3:
		lcd_memory_address=col+0x50;
		break;
	}
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data)
{
	char buff[16]; /* String to hold the ascii result */
	itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_displayString(buff); /* Display the string */
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}


