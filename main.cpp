#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#include "adc.h"
#include "dac.h"
#include "debugpins.h"
#include "led.h"
#include "button.h"
#include "timer.h"
#include "interruptRoutines.h"
#include "filter.h"
#include "filtermanager.h"

#define ADC_CHANNEL 0

volatile int32_t adcReading;
volatile int32_t dacOutput;
volatile bool newInputReady = false;
volatile uint32_t timerTick = 0; //incremented every 0.125ms
volatile DAC dac;
Filter filter;
FilterManager filterManager;
LED leds;
Button button;

int main()
{
	DDRB |= (1<<DEBUG_PIN_0) | (1<<DEBUG_PIN_1) | (1<<DEBUG_PIN_2) | (1<<DEBUG_PIN_3) | (1<<DEBUG_PIN_4) | (1<<DEBUG_PIN_5);

	filter.loadFilterCoefficients(filterManager.getCurrentFilter());
	leds.setup();
	leds.displayNumber(filterManager.getCurrentIndex() + 1);

	ADConverter::setup();
	ADConverter::setChannel(ADC_CHANNEL);
	ADConverter::start();

	dac.init();
	dac.beginTransmission();

	Timer1::setupCTCMode(TIMER1_OCR_8KHZ);
	sei();

	while(1) {
		if(newInputReady) {
			PORTB |= (1<<DEBUG_PIN_4);
			cli();
			filter.loadNewInput(adcReading);
			sei();
			filter.calculateNewOutput();
			cli();
			dacOutput = filter.getSanitizedOutput();
			newInputReady = false;
			sei();
			PORTB &=~(1<<DEBUG_PIN_4);
		}
		button.update();
		if(button.isPressed()) {
			button.clear();
			filter.loadFilterCoefficients(filterManager.getNextFilter());
			leds.displayNumber(filterManager.getCurrentIndex() + 1);
		}
	}
}

