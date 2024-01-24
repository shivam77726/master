#include "headers.h"
#include "declaration.h"

int fDistance::getDisplay()
{
	
	cout<<"("<<feet<<"\'"<<inch<<"\")";


	return 0;
}


int mDistance::getDisplay()
{
	
	cout<<"("<<meter<<" m "<<centimeter<<" cm)";


	return 0;
}
