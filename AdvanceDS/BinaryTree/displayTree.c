#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void** 	displayTree(void** arg)
{
	Node **tree=(Node**)arg;
	int i=1;
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif


	while(*(++tree))
	{
		printf("%dth node tree value:%X,%X\n\n",i,tree,*tree);
		printf("Parent node address:%X\n",(*tree)->Parent);
		printf("Value of root node:%d\n",(*tree)->Value);
		printf("Status:%d\n",(*tree)->Status);
		printf("Left child node address:%X\n",((*tree)->Child));
		printf("Right child node address:%X\n\n\n",++((*tree)->Child));
		i++;
	}


#ifdef DEBUG
	printf("%s End\n",__func__);
#endif
	return (void**)tree;
}
