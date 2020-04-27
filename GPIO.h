#ifndef _GPIO_H
#define _GPIO_H
#include "SysClock.h"
#include "stm32l476xx.h"

#define F_PD5_PD6 			(0xF << (2*5))	
#define AF_PD5_PD6 			(0x77<<(4*5))
#define MODER_PD5_PD6 	(0xA<<(2*5))
#define OTYPER_PD5_PD6 	(0x3<<5)
#define PUPDR_PD5_PD6 	(0x5<<(2*5))

#define TIMERA_PIN 0
#define TIMERB_PIN 6
// Pin modes
#define		MODER_IN		0x0UL
#define		MODER_OUT		0x1UL
#define		MODER_AF		0x2UL
#define		MODER_AL		0x3UL

// Drain mode
#define 	PUSH_PULL		0x0UL
#define 	OPEN_DR			0x1UL

// Pin speed
#define		LOW_SPEED		0x0UL
#define		MED_SPEED		0x1UL
#define		FAST_SPEED	0x2UL
#define		HI_SPEED		0x3UL

// Pin pull up/down
#define		PULL_NONE		0x0UL
#define		PULL_UP			0x1UL
#define		PULL_DOWN		0x2UL
#define		PULL_RES		0x3UL

// Ports
#define		PORT_B			RCC_AHB2ENR_GPIOBEN
#define		PORT_A			RCC_AHB2ENR_GPIOAEN
#define 	PORT_E			RCC_AHB2ENR_GPIOEEN

// Masks
#define		GPIOA_MASK	0x2E

// GPIOE MACROS
#define 	GPIOE_PIN_DRV_TYPE(pin, type)		FORCE_BITS(GPIOE->ODR, 1 << (pin), (type) << (pin))
#define		GPIOE_PIN_MODE(pin, mode)				FORCE_BITS(GPIOE->MODER, 3UL << ((pin)*2UL), (mode) << ((pin)*2UL))
#define		GPIOE_OP_TYPE(pin, mode)				FORCE_BITS(GPIOE->OTYPER, 1UL << (pin), (mode) << (pin))
#define		GPIOE_PIN_SPEED(pin, speed)			FORCE_BITS(GPIOE->OSPEEDR, 3UL << (2*(pin)), (speed) << (2*(pin)))
#define		GPIOE_PIN_PULL(pin, pull)				FORCE_BITS(GPIOE->PUPDR, 3UL << (2*(pin)), (pull) << (2*(pin)))


void GPIO_Init(void);
void GPIO_CLOCK_ENABLE(volatile uint32_t port);
void GPIOA_init(void);
void GPIOB_init(void);
void GPIOE_init(void);

#endif
