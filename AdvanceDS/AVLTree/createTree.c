#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void* 	createTree(void* arg)
{
	Node *tree=(Node*)arg;
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif


	if(!tree)
	{
		tree=NULL;
		printf("Tree Created\n");
	}
	else
		printf("Tree Already Present\n");


#ifdef DEBUG
	printf("%s End\n",__func__);
#endif
	return (void*)tree;
}
