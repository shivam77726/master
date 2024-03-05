#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* createTree(void* arg)
{
	
#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif

	if(arg)
	{
		perror("Tree Already Present");
		goto RET;
	}
	else
	{
#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
		return fptr[3](arg);		//Create Node
	}

RET:

#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return (void*)0;
}
