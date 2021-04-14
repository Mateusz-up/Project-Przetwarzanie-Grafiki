#pragma once
#define _USE_MATH_DEFINES 

#include <math.h>

float naStopnie(double rad);
float naRadiany(double deg);


float naStopnie(double rad) {
	return float(rad * 180 / M_PI);
}

float naRadiany(double deg) {

	return float (deg * M_PI / 180);
}
