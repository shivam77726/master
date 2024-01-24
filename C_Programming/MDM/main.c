#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


int main()
{
	//file of;

#ifdef DEBUG
	printf("%s begin\n",__func__);
#endif
	init();
	(fun_ptr[0])(0);
#ifdef DEBUG
	printf("%s End\n",__func__);
#endif

	return 0;
}
