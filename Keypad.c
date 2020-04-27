#include "Keypad.h"
#include "GPIO.h"
#include "Delay.h"

const uint32_t key_Freq_map [4][4] = {	//Frequencis mappd to specific keys
	
	{130,146,164,174},
	{195,220,246,261},
	{293,329,349,391},
	{415,440,493,523},
};

uint32_t Keypad_scan(void){	//Include debouncing - Ganssle
	
	// Keyboard scan doesnt work
	
	
	uint8_t ColMask[4] = {0x2, 0x4, 0x8, 0x20}; 
	uint8_t Reading, Column, Row = 0;
	uint8_t Frequency;
	// Check whether any kis has been pressed
	// 	1. Ouput Zeros on all row pins
	//	2. Delay shortly, and read inputs of clumn pins
	// 	3. If inpus are 1 for all columns, then no key has been pressed 
	// Upper nibble of GPIOE is ROW (output) - ODR
	// PA 1, 2, 3, 5 - (Input) - IDR

		// Set Row output to - 0b0000
	GPIOE->ODR = 0x0 << 12;
	Reading = GPIOA->IDR & GPIOA_MASK;
	if((Reading) == GPIOA_MASK)		// All ones
		return 0xFF; // No key pressed
	// Add delay for software debounce

// Find the specific Row	
	for(int i = 0; i < 4; i++){
		//Delay_ms(5);
		GPIOE->ODR = ~(2*i) << 12;
		Reading = GPIOA->IDR & GPIOA_MASK;
		if(Reading != GPIOA_MASK){	// Not all ones
			Row = (4 - i);
			break;
		}
	}
	// Have variables Row and Reading that have a value saved used later on. Could be jank.

	// Error Detection - if no Row was read. 
	if(Row == 0){
		return (0); // - Error, if no row was pressed. 
	}

// Find the Column
	for(int col = 0; col < 4; col++){
		if((Reading & ColMask[col]) == 0){	// Reading is the last value read on the IDR when it was triggered. 
			Column = col + 1; // if col = 0, there is no 0 colum. Add one to refelct the drawing
			break;
		}
	}
	
	// Get the frequency mapped to specific key
	Frequency = key_Freq_map[Row][Column];
	return (Frequency);
}

