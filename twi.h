#ifndef TWI_H
#define TWI_H

#include <avr/io.h>

#define TWI_START_SC 0x08
#define TWI_SLAVE_W_ACK_SC 0x18
#define TWI_SLAVE_DATA_ACK_SC 0x28

#define TWI_PORT PORTC
#define TWI_SCL_PIN 5
#define TWI_SDA_PIN 4
#define DAC_ADDRESS_R 0x99
#define DAC_ADDRESS_W 0x98
#define DAC_CONTROL_BYTE 0x10

void TWISetup();
void TWIWaitForInterrupt();

inline uint8_t TWIGetStatusCode()
{
	uint8_t masked = TWSR & 0xF8; //mask first three bits (2xprescaler and reserved)
	return masked;
}

inline void TWIClearInterruptFlag()
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWIE);
}

inline void TWISendStart()
{
	TWCR = (1<<TWSTA) | (1<<TWINT) | (1<<TWEN) | (1<<TWIE);
}

inline void TWISendStop()
{
	TWCR |= (1<<TWSTO);
	TWIClearInterruptFlag();
}

inline void setTWIInterruptEnabled(bool enabled)
{
	if(enabled) {
		TWCR |= (1<<TWIE);
	} else {
		TWCR &=~((1<<TWIE) | (1<<TWINT));
	}
}

#endif