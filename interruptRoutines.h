#ifndef INTERRUPTROUTINES_H
#define INTERRUPTROUTINES_H
#include <avr/interrupt.h>
#include "globalvariables.h"
#include "debugpins.h"

ISR(TIMER1_COMPB_vect)
{
	timerTick++;
	PORTB |= (1<<DEBUG_PIN_0);
	PORTB |= (1<<DEBUG_PIN_5); // ADC conv start
	dac.setOutputVoltage(dacOutput);
	PORTB &=~(1<<DEBUG_PIN_0);
}

ISR(ADC_vect) //on conversion finished
{
	adcReading = ADC;
	newInputReady = true;
	PORTB &=~(1<<DEBUG_PIN_5);
}

ISR(TWI_vect)
{
	PORTB |= (1<<DEBUG_PIN_3);
	dac.isr();
	PORTB &=~(1<<DEBUG_PIN_3);
}



#endif