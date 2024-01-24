#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void* deleteTree(void* arg)
{
	Node* tree=(Node*)arg;
#ifdef DDEBUG
        printf("%s begin\n",__func__);
#endif

       if (tree != NULL)
        {
		deleteTree(tree->Left);
		deleteTree(tree->Right);
		printf("%d Node of Tree Deallocated\n",tree);
		free(tree);	
		//*tree=NULL;
	
        }

#ifdef DDEBUG
        printf("%s End\n",__func__);
#endif

	return (void*)0;
}
