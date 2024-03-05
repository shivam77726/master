#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void* daleteTree(void* arg)
{
	Node* tree=(Node*)arg;
#ifdef DDEBUG
        printf("%s begin\n",__func__);
#endif

        while(tree != NULL)
        {
		deleteTree(tree->left);
		//printf("%dth Node of Tree Deallocated\n",i++);
		deleteTree(tree->right);
		free(tree);	
		//*tree=NULL;
	
        }

#ifdef DDEBUG
        printf("%s End\n",__func__);
#endif

	return (void*)0;
}
