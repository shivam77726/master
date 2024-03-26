#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* createTree(void* arg)
{
	
#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif


	

#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return fptr[3](arg);		//Create Node
}
