/*
 * icu.c
 *
 *  Created on: Oct 15, 2021
 *      Author: DELL
 */
#include"icu.h"
#include "commonmacros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the IO Ports Registers */
#include<avr/interrupt.h>
static volatile void (*g_callBack_ptr)(void)=NULL_PTR;
ISR(TIMER1_CAPT_vect)
{
	if(g_callBack_ptr != NULL_PTR)
	{

		(*g_callBack_ptr)();
}
}

void Icu_init(const Icu_configType * Icu_config_ptr){
	DDRD &= ~(1<<PD6);
	TCCR1A=(1<<FOC1A)|(1<<FOC1B);
	TCCR1B=(TCCR1B&0xF8)|(Icu_config_ptr->prescalar);
	TCCR1B=(TCCR1B&0xBF)|((Icu_config_ptr->edge)<<6);
	ICR1=0;
	TCNT1=0;
	TIMSK |= (1<<TICIE1);
}
void Icu_setCallBack(void(*a_ptr)(void)){
	g_callBack_ptr=a_ptr;
}
void Icu_setEdgeDetectionType(const Icu_Edgetype edge_type){
	TCCR1B=(TCCR1B&0xBF)|(edge_type<<6);
}
uint16 Icu_getInputCaptureValue(void){
	return ICR1;
}
void Icu_clearTimerValue(void){
	TCNT1=0;
}
void Icu_DeInit(void){
	TCCR1B=0;
	TCCR1A=0;
	ICR1=0;
	TCNT1=0;
	TIMSK&=~(1<<TICIE1);
}
