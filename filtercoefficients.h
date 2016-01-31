#ifndef FILTERCOEFFICIENTS_H
#define FILTERCOEFFICIENTS_H

typedef struct FilterCoefficients {
	int32_t A0, A1, A2, B1, B2;
	uint16_t DCOffset;
} FilterCoefficients;

#endif