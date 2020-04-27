//-------------------------------------------------------------------
// main.c - Initalize GPIO and USARTS to output a string to visualize on the scope
//
// Uses Zhu's SysClock code to init system clocks
//
// 
// copyright zhu, Gregory Huras, Caleb Hoeksema
//-------------------------------------------------------------------

// header files
#include "VirtualPort.h"
#include "utils.h"
#include "GPIO.h"
#include "Timer.h"
#include "Keypad.h"
#include "Beeper.h"

int main(void){

	System_Clock_Init();
	VIRTUAL_PORT_INIT();
	
	// Initalize the Keypad Gpios
	GPIO_Init();
	
	// Initalize PE8 timer
	Timer_Init();
	
	uint32_t Freq = 0;
	// Run loop continueously
	while(1){
		
		
		Freq = Keypad_scan();
		if((Freq > 0) && (Freq < 0xFF)){
			Beep(Freq);
		}
		else{
			// Print F error
		}
		
	}
	
} //main()
