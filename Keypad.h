/*****************************************************************************
 * key.h
 * Contains function prototypes read a keypad
 * Caleb Hoeksema, Gregory Huras
 * April 2020
 ****************************************************************************/
 

#ifndef _KEY_H
#define _KEY_H

#include "SysClock.h"
#include "stm32l476xx.h"
#include "utils.h"


// Pins
#define		COL_1				5UL
#define		COL_2				1UL
#define		COL_3				2UL
#define		COL_4				3UL
#define		ROW_1				12UL
#define		ROW_2				13UL
#define		ROW_3				14UL
#define		ROW_4				15UL

// Bits
#define		COL1_BIT		GPIO_IDR_IDR_5
#define		COL2_BIT		GPIO_IDR_IDR_1
#define		COL3_BIT		GPIO_IDR_IDR_2
#define		COL4_BIT		GPIO_IDR_IDR_3
#define		COL_BITS		(COL1_BIT | COL2_BIT | COL3_BIT | COL4_BIT)
#define		ROW1_BIT		GPIO_ODR_ODR_12
#define		ROW2_BIT		GPIO_ODR_ODR_13
#define		ROW3_BIT		GPIO_ODR_ODR_14
#define		ROW4_BIT		GPIO_ODR_ODR_15
#define		ROW_BITS		(ROW1_BIT | ROW2_BIT | ROW3_BIT | ROW4_BIT)

// Ports
#define		COL_PORT		GPIOA->IDR
#define		ROW_PORT		GPIOE->ODR

// Row macros
#define		ROW_BUS(mask)		FORCE_BITS( ROW_PORT, ROW_BITS, (mask) << 11 )		// Because the row bits start on pin 12

// Keypad function prototypes
uint16_t getKey(void);
//void TIM2_IRQHandler(void);

#endif
