#ifndef FILTER_H
#define FILTER_H
#include <stdint.h>
#include "filtercoefficients.h"

#define U_TAB_SIZE 3
#define Y_TAB_SIZE 3

class Filter
{
public:
	Filter();
	void loadNewInput(int32_t newInput);
	void calculateNewOutput();
	int32_t getNewOutput();
	uint16_t getSanitizedOutput();
	void loadFilterCoefficients(FilterCoefficients coeff);

private:
	void shiftArrays();
	void clearArrays();

	FilterCoefficients coefficients;
	int32_t u[U_TAB_SIZE]; //input array
	int32_t y[Y_TAB_SIZE]; //output array
};

#endif