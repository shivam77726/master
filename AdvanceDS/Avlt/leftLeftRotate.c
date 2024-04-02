#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* leftLeftRotate(void* arg)
{
	Node *root;
#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif
	
	printf("arg:%p,arg->Left%p,arg->Right:%p\n",(Node*)arg,((Node*)arg)->left,((Node*)arg)->right);
	root=((Node*)arg)->left;
	root->right=(Node*)arg;
	((Node*)arg)->left=NULL;
	root->right->height=root->height-1;
	
	printf("Root:%p,Root->Left%p,Root->Right:%p\n",root,root->left,root->right);



#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return (void*)root;
}
