#include "includes.h"
#include "class.h"

void stackImp :: push()
{
	if(top==4)
		cout << "Stack full" <<endl;
	else
		cin >> *(stackArray + ++top);

}
