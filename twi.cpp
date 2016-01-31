#include <avr/io.h>
#include "twi.h"

void TWIWaitForInterrupt()
{
	while(!(TWCR & (1<<TWINT)));
}

void TWISetup()
{
	DDRC |= (1<<TWI_SCL_PIN) | (1<<TWI_SDA_PIN);
	TWI_PORT |= (1<<TWI_SCL_PIN) | (1<<TWI_SCL_PIN); //enable internal pull-up resistors
	TWBR = 10; //400kHz SCL speed, prescaler=1
	TWCR |= (1<<TWEN) | (1<<TWIE); //enable TWI and TWI interrupt
}