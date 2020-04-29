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
	ROW_BUS(0111);
	Delay_ms(15);
	
	// Check columns
	if ((COL_PORT & COL1_BIT) == 0)
		return(0x1);
	if ((COL_PORT & COL2_BIT) == 0)
		return(0x2);
	if ((COL_PORT & COL3_BIT) == 0)
		return(0x3);
	if ((COL_PORT & COL4_BIT) == 0)
		return(0xA);
	
	// Scan row 2
	ROW_BUS(1011);
	Delay_ms(15);

	// Check columns	
	if ((COL_PORT & COL1_BIT) == 0)
		return(0x4);
	if ((COL_PORT & COL2_BIT) == 0)
		return(0x5);
	if ((COL_PORT & COL3_BIT) == 0)
		return(0x6);
	if ((COL_PORT & COL4_BIT) == 0)
		return(0xB);
	
	// Scan row 3
	ROW_BUS(1101);
	Delay_ms(15);
	
	// Check columns	
	if ((COL_PORT & COL1_BIT) == 0)
		return(0x7);
	if ((COL_PORT & COL2_BIT) == 0)
		return(0x8);
	if ((COL_PORT & COL3_BIT) == 0)
		return(0x9);
	if ((COL_PORT & COL4_BIT) == 0)
		return(0xC);
	
	// Scan row 4
	ROW_BUS(1110);
	Delay_ms(15);
	
	// Check columns	
	if ((COL_PORT & COL1_BIT) == 0)
		return(0xE);
	if ((COL_PORT & COL2_BIT) == 0)
		return(0x0);
	if ((COL_PORT & COL3_BIT) == 0)
		return(0xF);
	if ((COL_PORT & COL4_BIT) == 0)
		return(0xD);
	
	// Set all rows high
	ROW_BUS(1111);
	
	// Return an error
	return(0x10);
	
}
