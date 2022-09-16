/*
 * App.c
 *
 *  Created on: Oct 18, 2021
 *      Author: DELL
 */
#include"icu.h"
#include"ultrasonic.h"
#include"GPIO.h"
#include"LCD.h"
#include<avr/io.h>
int main(){
	uint16 distance;
	SREG |= (1<<7);//I-BIT ENABLE
	LCD_init();//Init lcd driver
	Ultrasonic_init();//Init ultrasonic driver
	LCD_moveCursor(1,0);
	LCD_displayString("Distance=    cm");
	while(1){
		distance=Ultrasonic_readDistance();//Read the distance
			LCD_moveCursor(1,10);
			if(distance>= 100)
			{
				LCD_intgerToString(distance);
			}
			else
			{
				LCD_intgerToString(distance);
				LCD_displayCharacter(' ');
			}
		}
	}

