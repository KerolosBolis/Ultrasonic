/*
 * icu.h
 *
 *  Created on: Oct 15, 2021
 *      Author: DELL
 */

#ifndef ICU_H_
#define ICU_H_
#include"std_types.h"
typedef enum{
	NO_CLOCK,F_CPU_1,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Icu_Prescalar;
typedef enum{
	FALLING,RISING
}Icu_Edgetype;
typedef struct{
	Icu_Prescalar prescalar;
	Icu_Edgetype edge;
}Icu_configType;
void Icu_init(const Icu_configType * Icu_config_ptr);
void Icu_setCallBack(void(*a_ptr)(void));
void Icu_setEdgeDetectionType(const Icu_Edgetype edge_type);
uint16 Icu_getInputCaptureValue(void);
void Icu_clearTimerValue(void);
void Icu_DeInit(void);




#endif /* ICU_H_ */
