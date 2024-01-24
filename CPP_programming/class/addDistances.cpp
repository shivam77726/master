#include "headers.h"
#include "declaration.h"

int fDistance::addDistances(fDistance a, fDistance b)
{
	feet=a.feet + b.feet;
	inch=a.inch+b.inch;
	while(inch>=12)
	{
		feet++;
		inch-=12;
	}

	return 0;
}

int mDistance::addDistances(mDistance d, mDistance e)
{
	meter=d.meter + e.meter;
	centimeter=d.centimeter+e.centimeter;
	while(centimeter>=100)
	{
		meter++;
		centimeter-=100;
	}

	return 0;
}
