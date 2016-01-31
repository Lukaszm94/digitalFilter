#include "timer.h"

void setupTimer1(uint16_t ocrReg)
{
	TCCR1B |= (1<<WGM12) | (1<<CS10); //CTC mode, prescaler = 1
	TIMSK1 |= (1<<OCIE1B); //enable Output Compare B Interrupt
	OCR1A = OCR1B = ocrReg; //reaching OCRxA causes counter to be reset, but ADC can be triggered only by Compare Match B of Timer1
}

void Timer1::setupCTCMode(uint16_t ocrReg)
{
	TCCR1B |= (1<<WGM12) | (1<<CS10); //CTC mode, prescaler = 1
	TIMSK1 |= (1<<OCIE1B); //enable Output Compare B Interrupt
	OCR1A = OCR1B = ocrReg; //reaching OCRxA causes counter to be reset, but ADC can be triggered only by Compare Match B of Timer1
}