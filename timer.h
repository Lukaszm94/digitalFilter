#include <avr/io.h>
#include <stdint.h>

#define TIMER1_OCR_10KHZ 1599
#define TIMER1_OCR_8KHZ 1999

class Timer1
{
	public:
	static void setupCTCMode(uint16_t ocrReg);
};

void setupTimer1(uint16_t ocrReg);