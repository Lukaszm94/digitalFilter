#ifndef FILTERMANAGER_H
#define FILTERMANAGER_H
#include <stdint.h>
#include "filtercoefficients.h"

#define FILTERS_COUNT 5

class FilterManager
{
public:
	FilterManager();
	FilterCoefficients getNextFilter();
	FilterCoefficients getCurrentFilter();
	uint8_t getCurrentIndex();
private:
	FilterCoefficients filtersC[FILTERS_COUNT];
	uint8_t currentFilterIndex;
};


#endif