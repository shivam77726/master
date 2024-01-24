#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void** Exit(void** arg)
{
	Node** tree=(Node**)arg;
	int i=1;
#ifdef DEBUG
        printf("%s begin\n",__func__);
#endif

        while(*(tree+i))
        {
		free(*tree);    
		printf("%dth Node of Tree Deallocated\n",i++);
		//*tree=NULL;
	
        }
	printf("All Nodes of Tree Deallocated\n");
	printf("Tree Deallocated\n");
	free(tree);


#ifdef DEBUG
        printf("%s End\n",__func__);
#endif
	exit(0);

	return (void**)NULL;
}
