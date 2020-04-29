/*****************************************************************************
 * beep.h
 * Contains function prototypes run a beeper
 * Caleb Hoeksema, Gregory Huras
 * April 2020
 ****************************************************************************/
 

#ifndef _BEEP_H
#define _BEEP_H

#include "SysClock.h"
#include "stm32l476xx.h"
#include "utils.h"


// Pins
#define		BEEP_PIN		8

// Tones
#define		TONE_C3			131UL
#define		TONE_D3			147UL
#define		TONE_E3			165UL
#define		TONE_F3			175UL
#define		TONE_G3			196UL
#define		TONE_A3			220UL
#define		TONE_B3			247UL
#define		TONE_C4			262UL
#define		TONE_D4			294UL
#define		TONE_E4			330UL
#define		TONE_F4			349UL
#define		TONE_G4			392UL
#define		TONE_A4			440UL
#define		TONE_B4			494UL
#define		TONE_C5			523UL
#define		TONE_D5			587UL

// Beeper function prototypes
uint16_t keyMap(uint8_t key);
void beep(uint8_t key);

#endif
