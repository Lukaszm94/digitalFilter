#include "button.h"
#include <avr/interrupt.h>
#include "globalvariables.h" // timer tick needed
#define BUTTON_PORT PORTD
#define BUTTON_PIN_REG PIND
#define BUTTON_PIN 7
#define BUTTON_UPDATE_TICK_INTERVAL 1000

Button::Button()
{
	BUTTON_PORT |= (1<<BUTTON_PIN); // turn on internal pullup
	buttonHistory = 0;
	previousTimerTickUpdateValue = timerTick;
}

void Button::update()
{
	cli();
	uint32_t timerTickValue = timerTick;
	sei();
	if((previousTimerTickUpdateValue + BUTTON_UPDATE_TICK_INTERVAL) > timerTickValue) {
		//not yet
		return;
	}
	previousTimerTickUpdateValue = timerTickValue;
	buttonHistory = buttonHistory << 1;
	if(!(BUTTON_PIN_REG & (1<<BUTTON_PIN))) {
		buttonHistory |= 0x01;
	}
}

void Button::clear()
{
	buttonHistory = 0;
}

bool Button::isPressed()
{
	return (buttonHistory == 0xFF);
}