#include "includes.h"
#include "class.h"

void stack :: createStack()
{
	stackArray=new int[5];
	if(!stackArray)
	{
		cerr << "StackArray Memory" ;

	}
	memset(stackArray,'\0',sizeof(int)*5);

}
