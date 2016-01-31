#include "adc.h"
#include <avr/io.h>

void setupADC()
{
	ADMUX |= (1<<REFS0) | (1<<ADLAR); //ref is AVcc, conversion result is left adjusted
	ADCSRA |= (1<<ADEN) | (1<<ADATE) | (1<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); //enable DC, enable Auto Trigger, enable interrupt, 128 div factor
	ADCSRB |= (1<<ADTS0) | (1<<ADTS2); //ADC triggered by Timer1 Compare Match B
}

void startADC()
{
	ADCSRA |= (1<<ADSC); //start conversion
}

void setADCChannel(uint8_t channel)
{
	ADMUX = (ADMUX & 0xF0) | channel; //set appropriate channel
}

void ADConverter::setup()
{
	ADMUX |= (1<<REFS0) | (1<<ADLAR); //ref is AVcc, conversion result is left adjusted
	ADCSRA |= (1<<ADEN) | (1<<ADATE) | (1<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); //enable DC, enable Auto Trigger, enable interrupt, 128 div factor
	ADCSRB |= (1<<ADTS0) | (1<<ADTS2); //ADC triggered by Timer1 Compare Match B
}

void ADConverter::setChannel(uint8_t channel)
{
	ADMUX = (ADMUX & 0xF0) | channel; //set appropriate channel
}

void ADConverter::start()
{
	ADCSRA |= (1<<ADSC); //start conversion
}