 /*****************************************************************************
 * Timer.c
 * Contains functions to initialize a timer port
 * Caleb Hoeksema, Gregory Huras
 * April 2020
 ****************************************************************************/


#include "Timer.h"
#include "utils.h"


// Initilize timer 1 to run the beeper on PE8
void Timer_Init(void) {
	
	TIMER_CLOCK_ENABLE();
	
	// Count direction
	COUNT_DIR(TIM1->CR1, COUNT_UP);
	
	// Clock Prescale (16 bits - up to 65 535)
	TIM1->PSC = 79;					//80MHz clock --> clock/(PSC+1) = 1MHz, matches useconds
	
	// Auto-reload (also 16b)
	TIM1->ARR = 0;		// Varies based on desired output
	
	// Set PWM mode
	TIM1_MODE(MODE_PWM);
	
	// Output 1 preload enable
	TIM1_PRELOAD(PRELOAD_ON);
	
	// Output polarity
	TIM1_POLAR(ACT_HI);
	
	// Enable channel 1 complementary output (1 = on, 0 = off)
	TIM1->CCER |= TIM_CCER_CC1NE;
	
	// Main O/P enable: 0 = off, 1 = en
	OP_ENABLE(OP_ON);
	
	// 50% duty cycle
	TIM1->CCR1 = (TIM1->ARR)/2;		// Should always be 50%
	
	// Enable timer 1
	SET_BITS(TIM1->CR1, TIM_CR1_CEN);
	
}


// Enable timer 1's clock
void TIMER_CLOCK_ENABLE(void) {
	
	// Set timer 1 clock
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	
}
