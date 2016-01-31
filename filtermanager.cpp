#include "filtermanager.h"

FilterManager::FilterManager()
{
	currentFilterIndex = 0;

	filtersC[0].A0 = 0;
	filtersC[0].A1 = 39;
	filtersC[0].A2 = 0;
	filtersC[0].B1 = 985;
	filtersC[0].B2 = 0;
	filtersC[0].DCOffset = 0;

	filtersC[1].A0 = 1024;
	filtersC[1].A1 = -1024;
	filtersC[1].A2 = 0;
	filtersC[1].B1 = 985;
	filtersC[1].B2 = 0;
	filtersC[1].DCOffset = 32000;

	filtersC[2].A0 = 0;
	filtersC[2].A1 = 39;
	filtersC[2].A2 = -39;
	filtersC[2].B1 = 2005;
	filtersC[2].B2 = -985;
	filtersC[2].DCOffset = 32000;

	filtersC[3].A0 = 0;
	filtersC[3].A1 = 24;
	filtersC[3].A2 = 22;
	filtersC[3].B1 = 1796;
	filtersC[3].B2 = -836;
	filtersC[3].DCOffset = 0;

	filtersC[4].A0 = 725;
	filtersC[4].A1 = -1404;
	filtersC[4].A2 = 679;
	filtersC[4].B1 = 1670;
	filtersC[4].B2 = -769;
	filtersC[4].DCOffset = 32000;
}

FilterCoefficients FilterManager::getNextFilter()
{
	currentFilterIndex = (currentFilterIndex + 1) % FILTERS_COUNT;
	return getCurrentFilter();
}

FilterCoefficients FilterManager::getCurrentFilter()
{
	return filtersC[currentFilterIndex];
}

uint8_t FilterManager::getCurrentIndex()
{
	return currentFilterIndex;
}
