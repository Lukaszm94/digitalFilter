#ifndef DAC_H
#define DAC_H
#include <stdint.h>
#include <util/delay.h>
#include "twi.h"
#include "debugpins.h"

enum DACstate {IDLE, SENT_FIRST_HALF, SENT_SECOND_HALF};

class DAC
{
public:
	DAC();
	void init() volatile ;
	void beginTransmission() volatile ;
	void endTransmission() volatile ;
	inline void setOutputVoltage(uint16_t output) volatile 
	{
		if(DACstate == IDLE) {
			PORTB |= (1<<DEBUG_PIN_1);
			secondByte = 0x00FF & output; //LSB
			TWDR = (output>>8);
			TWIClearInterruptFlag();
			DACstate = SENT_FIRST_HALF;
			setTWIInterruptEnabled(true);
		}
	}
	inline void isr() volatile
	{
		if(DACstate == SENT_FIRST_HALF) {
			PORTB &=~(1<<DEBUG_PIN_1);
			PORTB |= (1<<DEBUG_PIN_2);
			TWDR = secondByte;
			TWIClearInterruptFlag();
			//setTWIInterruptEnabled(false);
			DACstate = SENT_SECOND_HALF;
			//DACstate = IDLE;
		} else if(DACstate == SENT_SECOND_HALF) {
			PORTB &=~(1<<DEBUG_PIN_2);
			setTWIInterruptEnabled(false);
			DACstate = IDLE;
		}
	}
private:
	uint8_t DACstate;
	bool sentFirstByte;
	uint8_t secondByte;
};

#endif