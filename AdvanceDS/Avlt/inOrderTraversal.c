#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

void* inOrderTraversal(void* arg)
{
	Node *tree=(Node*)arg;

#ifdef DDEBUG
	printf("%s Begin\n",__func__);
#endif

	if(tree)
	{
		inOrderTraversal((void*)tree->left);
		printf("%d,%d\t",tree->data,tree->height);
		inOrderTraversal((void*)tree->right);
	}



#ifdef DDEBUG
	printf("%s End\n",__func__);
#endif
	return (void*)0;
}
