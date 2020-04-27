#include "Beeper.h"


void Beep(uint16_t Tone){ // Takes tone frequency parameter and ouputs it so thetone plays
// Midle of C major is 261.6256 Hz	
	
	TIM1->ARR = (1/Tone)*1000000;
	GPIOE->ODR |= GPIO_ODR_ODR_8; 
	
}

