#include "headers.h"
#include "declaration.h"


void* exitFail (void* arg)
{
	//file of;

#ifdef DEBUG
	printf("%s begin\n",__func__);
#endif
		
	exit(0);
#ifdef DEBUG
	printf("%s End\n",__func__);
#endif

	return 0;
}
