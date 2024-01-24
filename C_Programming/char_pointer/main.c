#include "headers.h"
#include "declaration.h"



int main()
{
	
	char (*p)(int , ...)=&_x_;
	for(;(*p)(-2,0,0,0,0);)
		printf("%d\n",!+2);


	return 0;
}
