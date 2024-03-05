#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void* inOrderTraversal(void* arg)
{
	Node *tree=(Node*)arg;

#ifdef DDEBUG
	printf("%s Begin\n",__func__);
#endif

	if(tree)
	{
		inOrderTraversal((void*)tree->Left);
		printf("%d, %d\t",tree->Value,tree->bf);
		inOrderTraversal((void*)tree->Right);
	}



#ifdef DDEBUG
	printf("%s End\n",__func__);
#endif
	return (void*)0;
}
