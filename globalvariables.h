#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H
#include "dac.h"


extern volatile int32_t adcReading;
extern volatile int32_t dacOutput;
extern volatile bool newInputReady;
extern volatile uint32_t timerTick; //incremented every 0.125ms
extern volatile DAC dac;

#endif