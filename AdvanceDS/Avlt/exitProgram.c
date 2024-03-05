#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* exitProgram(void* arg)
{
	Node* tree=(Node*)arg;
#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif

        while(tree != NULL)
        {
                printf("1.Inside While\n");

                exitProgram(tree->left);
                exitProgram(tree->right);
                printf("2.Inside While\n");
                free(tree);
                tree=NULL;
                printf("Node of Tree Deallocated\n");

        }



#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	//exit(0);
	return (void*)0;
}
