#include "dac.h"
#include "twi.h"
//#include "uart.h"


DAC::DAC()
{
	sentFirstByte = false;
	DACstate = IDLE;
}

void DAC::init() volatile 
{
	TWISetup();
}

void DAC::beginTransmission() volatile 
{
	TWISendStart();
	TWIWaitForInterrupt();
	/*if(TWIGetStatusCode() != TWI_START_SC)
		uart_puts("No start sc\n\r");*/
	TWDR = DAC_ADDRESS_W;
	TWIClearInterruptFlag();
	TWIWaitForInterrupt();
	/*if(TWIGetStatusCode() != TWI_SLAVE_W_ACK_SC)
		uart_puts("No address ack\n\r");*/
	TWDR = DAC_CONTROL_BYTE;
	TWIClearInterruptFlag();
	TWIWaitForInterrupt();
	/*if(TWIGetStatusCode() != TWI_SLAVE_DATA_ACK_SC)
		uart_puts("No control byte ack\n\r");
		uart_putint(TWIGetStatusCode());*/
}

void DAC::endTransmission() volatile 
{
	TWISendStop();
}