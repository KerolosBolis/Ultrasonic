/*
 * commonmacros.h
 *
 *  Created on: Oct 2, 2021
 *      Author: DELL
 */

#ifndef COMMONMACROS_H_
#define COMMONMACROS_H_

#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT) (REG&=~(1<<BIT))
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))
#define ROL(REG,BIT) (REG=(REG<<BIT)|(REG>>(8-BIT)))
#define BIT_IS_SET(REG,BIT) (REG&(1<<BIT))
#define BIT_IS_CLEAR(REG,BIT) (!(REG&(1<<BIT)))

#endif /* COMMONMACROS_H_ */
