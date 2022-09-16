/*
 * ultrasonic.h
 *
 *  Created on: Oct 17, 2021
 *      Author: DELL
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include"std_types.h"
#define TRIGGER_PORT_ID PORTB_ID
#define TRIGGER_PIN_ID  PIN5_ID
#define DIVISON_OF_TIME 58.8

void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);


#endif /* ULTRASONIC_H_ */
