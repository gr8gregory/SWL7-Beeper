/*****************************************************************************
 * main.c
 * Mainline function to run an beeper from a keypad
 * Caleb Hoeksema, Gregory Huras
 * April 2020
 ****************************************************************************/


#include "stm32l476xx.h"
#include "SysClock.h"
#include "GPIO.h"
#include "timer.h"
#include "utils.h"
#include "beep.h"
#include "key.h"

uint8_t flag = 0x10;

// Mainline function for reading a keypad and playing a beeper
int main(void) {
	
	// Initalize the System Clock, GPIO ports, Timer
	System_Clock_Init();
	GPIOA_Init();
	GPIOE_Init();
	Timer_Init();
	
	uint8_t key = 0x10;			// Default error condition (0x10)
	
	// Loop Forever
	while(1){
		
		key = getKey();				// returns a value from 0x0 - 0x10
		beep(key);
				
	}
}
