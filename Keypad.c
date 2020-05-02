/*****************************************************************************
 * key.c
 * Contains function prototypes read a keypad
 * Caleb Hoeksema, Gregory Huras
 * April 2020
 ****************************************************************************/


#include "stm32l476xx.h"
#include "SysClock.h"
#include "GPIO.h"
#include "key.h"
#include "beep.h"


// Function to scan for the input key
	// Should include debouncing
	// Goes to the wrong row and is inconsistent
	// Put on an interrupt?
uint16_t getKey(void) {
	
	// Scan row 1
	ROW1_MODE(0);
	ROW2_MODE(1);
	ROW3_MODE(1);
	ROW4_MODE(1);
	Delay_ms(15);
	
	// Check columns
	if ((COL_PORT & COL1_BIT) == 0) {
		if (0x1 == flag)
			return(0x1);
		else {
			flag = 0x1;
			return(0x10);
		}
	}
	if ((COL_PORT & COL2_BIT) == 0) {
		if (0x2 == flag)
			return(0x2);
		else {
			flag = 0x2;
			return(0x10);
		}
	}
	if ((COL_PORT & COL3_BIT) == 0) {
		if (0x3 == flag)
			return(0x3);
		else {
			flag = 0x3;
			return(0x10);
		}
	}
	if ((COL_PORT & COL4_BIT) == 0) {
		if (0xA == flag)
			return(0xA);
		else {
			flag = 0xA;
			return(0x10);
		}
	}
	
	// Scan row 2
	ROW1_MODE(1);
	ROW2_MODE(0);
	ROW3_MODE(1);
	ROW4_MODE(1);
	Delay_ms(15);

	// Check columns	
	if ((COL_PORT & COL1_BIT) == 0) {
		if (0x4 == flag)
			return(0x4);
		else {
			flag = 0x4;
			return(0x10);
		}
	}
	if ((COL_PORT & COL2_BIT) == 0) {
		if (0x5 == flag)
			return(0x5);
		else {
			flag = 0x5;
			return(0x10);
		}
	}
	if ((COL_PORT & COL3_BIT) == 0) {
		if (0x6 == flag)
			return(0x6);
		else {
			flag = 0x6;
			return(0x10);
		}
	}
	if ((COL_PORT & COL4_BIT) == 0) {
		if (0xB == flag)
			return(0xB);
		else {
			flag = 0xB;
			return(0x10);
		}
	}
	
	// Scan row 3
	ROW1_MODE(1);
	ROW2_MODE(1);
	ROW3_MODE(0);
	ROW4_MODE(1);
	Delay_ms(15);
	
	// Check columns	
	if ((COL_PORT & COL1_BIT) == 0) {
		if (0x7 == flag)
			return(0x7);
		else {
			flag = 0x7;
			return(0x10);
		}
	}
	if ((COL_PORT & COL2_BIT) == 0) {
		if (0x8 == flag)
			return(0x8);
		else {
			flag = 0x8;
			return(0x10);
		}
	}
	if ((COL_PORT & COL3_BIT) == 0) {
		if (0x9 == flag)
			return(0x9);
		else {
			flag = 0x9;
			return(0x10);
		}
	}
	if ((COL_PORT & COL4_BIT) == 0) {
		if (0xC == flag)
			return(0xC);
		else {
			flag = 0xC;
			return(0x10);
		}
	}
	
	// Scan row 4
	ROW1_MODE(1);
	ROW2_MODE(1);
	ROW3_MODE(1);
	ROW4_MODE(0);
	Delay_ms(15);
	
	// Check columns	
	if ((COL_PORT & COL1_BIT) == 0) {
		if (0xE == flag)			// 0xE is *
			return(0xE);
		else {
			flag = 0xE;
			return(0x10);
		}
	}
	if ((COL_PORT & COL2_BIT) == 0) {
		if (0x0 == flag)
			return(0x0);
		else {
			flag = 0x0;
			return(0x10);
		}
	}
	if ((COL_PORT & COL3_BIT) == 0) {
		if (0xF == flag)			// 0xF is #
			return(0xF);
		else {
			flag = 0xF;
			return(0x10);
		}
	}
	if ((COL_PORT & COL4_BIT) == 0) {
		if (0xD == flag)
			return(0xD);
		else {
			flag = 0xD;
			return(0x10);
		}
	}
	
	// Set all rows high
	ROW1_MODE(1);
	ROW2_MODE(1);
	ROW3_MODE(1);
	ROW4_MODE(1);
	
	// Return an error
	flag = 0x10;
	return(0x10);
	
}
