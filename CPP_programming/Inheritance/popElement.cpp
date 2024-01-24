#include "includes.h"
#include "class.h"

void stackImp :: pop()
{
	if(top == -1)
		cout << "No Element in stack" << endl;
	else
		*(stackArray + top--);

}
