/*
 * ultrasonic.c
 *
 *  Created on: Oct 17, 2021
 *      Author: DELL
 */
#include "commonmacros.h"
#include "ultrasonic.h"
#include "GPIO.h"
#include "icu.h"
#include"util/delay.h"//To use the delay function
uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;//Timer Value from ICU
/*Description:
1-Initialize the ICU driver as required.
2-Setup the ICU call back function.
3- Setup the direction for the trigger pin as output pin through the GPIO driver.*/
void Ultrasonic_init(void){
	Icu_configType config_Type_icu={F_CPU_8,RISING};//Configuration of ICU Init
	Icu_init(&config_Type_icu);//Initialize ICU Init
	Icu_setCallBack(Ultrasonic_edgeProcessing);//Set the CallBack function
	//Set the trigger pin as output pin
	GPIO_setupPinDirection(TRIGGER_PORT_ID,TRIGGER_PIN_ID,PIN_OUTPUT);
}
/*Description
Send the Trigger pulse to the Ultrasonic.*/
void Ultrasonic_Trigger(void){
	//Sending the trigger pulse for 10 us seconds
	GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_LOW);
}
/*Description
1-Send the trigger pulse by using Ultrasonic_Trigger function.
2- Start the measurements by the ICU from this moment.*/
uint16 Ultrasonic_readDistance(void){
	uint16 distance;
	Ultrasonic_Trigger();
	//Distance= 17000 x (TIMER value) x 1 x 10^-6 cm
	distance=g_timeHigh/DIVISON_OF_TIME;
	return distance;
}
/*Description
1-This is the call back function called by the ICU driver.
2-This is used to calculate the high time (pulse time) generated by the ultrasonic sensor.*/
void Ultrasonic_edgeProcessing(void){
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		Icu_clearTimerValue();
		//Detect the falling edge
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeHigh = Icu_getInputCaptureValue();
		/* Clear the timer counter register to start measurements again */
		Icu_clearTimerValue();
		//Detect the rising edge
		Icu_setEdgeDetectionType(RISING);
		g_edgeCount = 0;
	}
}


