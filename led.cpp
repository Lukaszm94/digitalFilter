#include "led.h"
#include <avr/io.h>

#define LED1_PIN 2
#define LED2_PIN 3
#define LED3_PIN 4

#define LED_PIN PIND
#define LED_PORT PORTD
#define LED_DDR DDRD

void LED::setup()
{
	LED_DDR |= (1<<LED1_PIN) | (1<<LED2_PIN) | (1<<LED3_PIN);
}

void LED::displayNumber(uint8_t number)
{
	bool LED1state = number & (1<<0);
	bool LED2state = number & (1<<1);
	bool LED3state = number & (1<<2);
	setOutput(LED1state, LED1_PIN);
	setOutput(LED2state, LED2_PIN);
	setOutput(LED3state, LED3_PIN);
}

void LED::setOutput(bool on, uint8_t ledPin)
{
	if(on)
		LED_PORT |= (1<<ledPin);
	else
		LED_PORT &=~ (1<<ledPin);
}