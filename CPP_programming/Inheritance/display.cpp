#include "includes.h"
#include "class.h"

void stackImp :: display()
{
	for(int i=top;i>=0;i--)
	cout << *(stackArray + i) << endl;

}
