#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>

/* this class provides software debouncing by 
 * storing 8 previous button states in buttonyHistory variable, if 
 * all its bits are equal to 1, then we can say that 
 * the button is pressed.
 * This class uses 'timerTick' global variable to update button state
 * at specified interval
 */

class Button
{
public:
	Button();
	void update();
	void clear();
	bool isPressed();
	
private:
	uint8_t buttonHistory;
	uint32_t previousTimerTickUpdateValue;
};

#endif