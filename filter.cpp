#include "filter.h"

Filter::Filter()
{
	clearArrays();
}

void Filter::loadNewInput(int32_t newInput)
{
	shiftArrays();
	u[0] = newInput;
}

void Filter::calculateNewOutput()
{
	int32_t tmp1 = coefficients.A0 * u[0];
	int32_t tmp2 = coefficients.A1 * u[1];
	int32_t tmp3 = coefficients.A2 * u[2];
	int32_t tmp4 = coefficients.B1 * y[1];
	int32_t tmp5 = coefficients.B2 * y[2];

	int32_t tmp = tmp1 + tmp2 + tmp3 + tmp4 + tmp5;
	y[0] = ((tmp+512)/1024);
}

int32_t Filter::getNewOutput()
{
	return y[0];
}

uint16_t Filter::getSanitizedOutput()
{
	int32_t tmp = y[0] + coefficients.DCOffset;
	if(tmp < 0) {
		return 0;
	} else if(tmp > 65535L) {
		return 65535L;
	}
	return (uint16_t)tmp;
}

void Filter::loadFilterCoefficients(FilterCoefficients coeff)
{
	coefficients = coeff;
	clearArrays();
}

void Filter::shiftArrays()
{
	u[2] = u[1];
	u[1] = u[0];
	y[2] = y[1];
	y[1] = y[0];
}

void Filter::clearArrays()
{
	for(int i = 0; i < U_TAB_SIZE; i++) {
		u[i] = 0;
	}
	for(int i = 0; i < Y_TAB_SIZE; i++) {
		y[i] = 0;
	}
}