#include "utils.h"
#include "GPIO.h"
/*https://conestoga.desire2learn.com/d2l/common/assets/pdfjs/1.0.0.30/web/viewer.html?file=%2Fcontent%2Fenforced%2F319416-SENG72005-104-20W-1_20W_X_B320_SENG72005_SEC1_X%2FSTM32L476VGT6%2520Reference%2520manual%2520(March%25202017).pdf%3Fd2lSessionVal%3DLLbhl5IMmoUOJElfXR9CD0yi5%26ou%3D319416&lang=en-us&container=d2l-fileviewer-rendered-pdf&fullscreen=d2l-fileviewer-rendered-pdf-dialog&height=937#page=292&zoom=auto,124,751
Pg 300	
*/
// Initalize the GPIO Clocks
void GPIO_CLOCK_ENABLE(volatile uint32_t port){
	
	// Enable GPIO port clock
	RCC->AHB2ENR |= port;
}

void GPIO_Init(void){
	GPIOA_init();
	GPIOE_init();
}

void GPIOA_init(void){
	// PA 1, 2, 3, 5 - KEYPAD INPUTS
	
	GPIO_CLOCK_ENABLE(PORT_A);

	// Set pin as Digital Input (00)
	CLR_BITS(GPIOA->MODER, GPIOA_MASK); //Clears PA 1, 2, 3, 5
	
	// Set pin as NO pull-up pull-down
	CLR_BITS(GPIOA->PUPDR, GPIOA_MASK);
	
}

void GPIOE_init(void){
	
	// PE 15, 14, 13, 12 - KEYPAD outputs
	// PE 8 - TIMER MODULE
	GPIO_CLOCK_ENABLE(PORT_E);
	
	/************ KEYPAD INIT ***************/
	CLR_BITS(GPIOE->MODER, 0xFF << (2*12));
	SET_BITS(GPIOE->MODER, 0x55 << (2*12));
	
	CLR_BITS(GPIOE->OTYPER, 0xF << (12));
	SET_BITS(GPIOE->OTYPER, 0xF << (12));
	
	CLR_BITS(GPIOE->OSPEEDR, 0xF << (2*12));
	
	CLR_BITS(GPIOE->PUPDR, 0xFF << (2*12));
	/*****************************************/
	
	
	/************* TMER PE8 ******************/
	GPIOE->MODER = ~(3U<<(2*8));  
	GPIOE->MODER |= 1U<<(2*8);      //  Output(01)
	
	// GPIO Speed: Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
	GPIOE->OSPEEDR &= ~(3U<<(2*8));
	GPIOE->OSPEEDR |=   3U<<(2*8);  // High speed
	
	// GPIO Output Type: Output push-pull (0, reset), Output open drain (1) 
	GPIOE->OTYPER &= ~(1U<<8);       // Push-pull
	
	// GPIO Push-Pull: No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOE->PUPDR   &= ~(3U<<(2*8));  // No pull-up, no pull-down
	/****************************************/
	
}
/*
void GPIO_Init(GPIO_TypeDef * GPIOx){
	
	GPIO_CLOCK_ENABLE(PORT_A);
	
	CLR_BITS(GPIOx->MODER, 0xFFC3U <<(8*2)); // Clear Bits to 0
	SET_BITS(GPIOx->MODER, 0x5541U <<(8*2));	// Set the bits to General purpose output Mode (01)
	CLR_BITS(GPIOx->OTYPER, 0xF9U <<(8));	// Set bits to Push-pull
}
*/
