#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* createNode(void* arg)
{
	Node* node;
	
#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif

	node=(Node*)malloc(sizeof(Node));

	node->data=*(int*)arg;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	printf("%s Node:%p\n",__func__,node);

#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return (void*)node;
}
