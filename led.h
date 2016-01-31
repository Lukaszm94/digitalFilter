#ifndef LED_H
#define LED_H
#include <stdint.h>

class LED
{
public:
	void setup();
	void displayNumber(uint8_t number);
private:
	void setOutput(bool on, uint8_t ledPin);
};

#endif