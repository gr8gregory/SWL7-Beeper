/*****************************************************************************
 * beep.c
 * Contains function prototypes run a beeper
 * Caleb Hoeksema, Gregory Huras
 * April 2020
 ****************************************************************************/


#include "stm32l476xx.h"
#include "SysClock.h"
#include "GPIO.h"
#include "beep.h"


// Map the key number to the proper frequency as follows:
	// 0 - D are 0x0 - 0xD, * is 0xE, and # is 0xF
	// Key:		1  2  3  A  4  5  6  B  7  8  9  C  *  0  #  D
	// Tone:	C3 D3 E3 F3 G3 A3 B3 C4 D4 E4 F4 G4 A4 B4 C5 D5
uint16_t keyMap(uint8_t key) {
	
	uint16_t map[16] = {	TONE_B4, TONE_C3, TONE_D3, TONE_E3,
				TONE_G3, TONE_A3, TONE_B3, TONE_D4,
				TONE_E4, TONE_F4, TONE_F3, TONE_C4,
				TONE_G4, TONE_D5, TONE_A4, TONE_C5};
	
	uint16_t tone = map[key];
												
	return(tone);
	
}


// Function to play the beeper
void beep(uint8_t key) {
	
	// Get the frequency for the key input
	uint16_t freq = 0;
	if (key <= 0xF)																// No comp with 0 because it is unsigned
		freq = keyMap(key);													// Returns the tone frequency
	
	else {																				// An error if anything else
		TIM1->ARR = 0;															// Turn off the beeper and exit the function
		TIM1->CCR1 = (TIM1->ARR)/2;
		return;
	}
	
	// Find the period: ARR = 1MHz*T - 1
	uint16_t period = ((1000000-freq) / (freq));	// Convert freq to period in useconds
	
	// Play the tone
	TIM1->ARR = period;
	TIM1->CCR1 = (TIM1->ARR)/2;

}
