#include "declaration.h"


char _x_(int a,...)
{
	static int i=-2;
	return i+++a;
}


