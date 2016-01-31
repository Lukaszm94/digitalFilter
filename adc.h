#ifndef ADCA_H
#define ADCA_H

#include <stdint.h>

void setupADC();
void startADC();
void setADCChannel(uint8_t channel);

class ADConverter
{
public:
	static void setup();
	static void setChannel(uint8_t channel);
	static void start();
};

#endif