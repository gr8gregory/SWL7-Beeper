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

extern uint8_t flag;

// Pins
#define		COL_1				1UL
#define		COL_2				2UL
#define		COL_3				3UL
#define		COL_4				5UL
#define		ROW_1				15UL
#define		ROW_2				14UL
#define		ROW_3				13UL
#define		ROW_4				12UL

// Bits
#define		COL1_BIT		GPIO_IDR_IDR_1
#define		COL2_BIT		GPIO_IDR_IDR_2
#define		COL3_BIT		GPIO_IDR_IDR_3
#define		COL4_BIT		GPIO_IDR_IDR_5
#define		COL_BITS		(COL1_BIT | COL2_BIT | COL3_BIT | COL4_BIT)
#define		ROW1_BIT		GPIO_ODR_ODR_15
#define		ROW2_BIT		GPIO_ODR_ODR_14
#define		ROW3_BIT		GPIO_ODR_ODR_13
#define		ROW4_BIT		GPIO_ODR_ODR_12
#define		ROW_BITS		(ROW1_BIT | ROW2_BIT | ROW3_BIT | ROW4_BIT)

// Ports
#define		COL_PORT		GPIOA->IDR
#define		ROW_PORT		GPIOE->ODR

// Row macros

#define		ROW1_MODE(mode)				FORCE_BITS(GPIOE->ODR, ROW1_BIT, (mode) << (ROW_1))
#define		ROW2_MODE(mode)				FORCE_BITS(GPIOE->ODR, ROW2_BIT, (mode) << (ROW_2))
#define		ROW3_MODE(mode)				FORCE_BITS(GPIOE->ODR, ROW3_BIT, (mode) << (ROW_3))
#define		ROW4_MODE(mode)				FORCE_BITS(GPIOE->ODR, ROW4_BIT, (mode) << (ROW_4))


// Keypad function prototypes
uint16_t getKey(void);
//void TIM2_IRQHandler(void);

#endif
