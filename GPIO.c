/*****************************************************************************
 * GPIO.c
 * Contains code to initialize a GPIO port
 * Caleb Hoeksema, Gregory Huras
 * April 2020
 ****************************************************************************/


#include "utils.h"
#include "GPIO.h"
#include "key.h"
#include "beep.h"


// Initalize the GPIO Clocks
void GPIO_CLOCK_ENABLE(volatile uint32_t port){
	
	// Enable GPIO port clock
	RCC->AHB2ENR |= port;
}


// Initialize GPIOE to run the keypad rows and beeper
void GPIOE_Init(void){
	
	GPIO_CLOCK_ENABLE(PORT_E);
	
	// Set pin I/O mode (output for rows, timer for beeper)
	GPIOE_PIN_MODE(ROW_1, MODER_OUT);
	GPIOE_PIN_MODE(ROW_2, MODER_OUT);
	GPIOE_PIN_MODE(ROW_3, MODER_OUT);
	GPIOE_PIN_MODE(ROW_4, MODER_OUT);
	
	GPIOE_PIN_MODE(BEEP_PIN, MODER_AF);
	GPIOE->AFR[1] &= ~(0xFUL);
	GPIOE->AFR[1] |= 1UL;
	
	// Set output type (open drain to prevent shorts)
	GPIOE_OP_TYPE(ROW_1, OPEN_DR);
	GPIOE_OP_TYPE(ROW_2, OPEN_DR);
	GPIOE_OP_TYPE(ROW_3, OPEN_DR);
	GPIOE_OP_TYPE(ROW_4, OPEN_DR);
	
	// Set pull up (default high for row O/Ps)
	GPIOE_PIN_PULL(ROW_1, PULL_UP);
	GPIOE_PIN_PULL(ROW_2, PULL_UP);
	GPIOE_PIN_PULL(ROW_3, PULL_UP);
	GPIOE_PIN_PULL(ROW_4, PULL_UP);
	
	GPIOE_PIN_PULL(BEEP_PIN, PULL_NONE);
	
	// Set pin speed
	GPIOE_PIN_SPEED(BEEP_PIN, LOW_SPEED);
	
}


// Initialize GPIOA to run the keypad columns
void GPIOA_Init(void) {
	
	GPIO_CLOCK_ENABLE(PORT_A);
	
	// Set pin I/O mode (input for columns)
	GPIOA_PIN_MODE(COL_1, MODER_IN);
	GPIOA_PIN_MODE(COL_2, MODER_IN);
	GPIOA_PIN_MODE(COL_3, MODER_IN);
	GPIOA_PIN_MODE(COL_4, MODER_IN);
	
	// Set output type (open drain to prevent shorts)
	GPIOA_OP_TYPE(COL_1, OPEN_DR);
	GPIOA_OP_TYPE(COL_2, OPEN_DR);
	GPIOA_OP_TYPE(COL_3, OPEN_DR);
	GPIOA_OP_TYPE(COL_4, OPEN_DR);
	
	// Set pull up (external pull-up of 2.2k)
	GPIOA_PIN_PULL(COL_1, PULL_NONE);
	GPIOA_PIN_PULL(COL_2, PULL_NONE);
	GPIOA_PIN_PULL(COL_3, PULL_NONE);
	GPIOA_PIN_PULL(COL_4, PULL_NONE);
	
	// Set pin speed
	GPIOA_PIN_SPEED(COL_1, FAST_SPEED);
	GPIOA_PIN_SPEED(COL_2, FAST_SPEED);
	GPIOA_PIN_SPEED(COL_3, FAST_SPEED);
	GPIOA_PIN_SPEED(COL_4, FAST_SPEED);

}


// Delay function using milliseconds
void Delay_ms(uint32_t msec){
  
  SysTick->CTRL = 0;            									// Disable SysTick
  SysTick->LOAD = (80000000UL / 1000UL) * msec;   // Set reload register
  SysTick->VAL = 0;             									// Reset the SysTick counter value
																									// Select processor clock: 1 = processor clock; 0 = external clock
  
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;		// Disable SysTick interrupt, 1 = Enable, 0 = Disable
																									
  SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;			// Enable SysTick
																									
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;				// Wait for timeout
																									
  while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
																									// Disable SysTick until next time
  SysTick->CTRL = 0; 
}

