#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* rightRightRotate(void* arg)
{
	Node *root;
#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif
	
	printf("arg:%p,arg->Left%p,arg->Right:%p\n",(Node*)arg,((Node*)arg)->left,((Node*)arg)->right);
	root=((Node*)arg)->left;
	((Node*)arg)->left=root->right;
	root->right=(Node*)arg;
        heightNode(arg);
        heightNode(root);
	
	printf("Root:%p,Root->Left%p,Root->Right:%p\n",root,root->left,root->right);
	printf("Root Height:%d,(Node*)arg->height%d\n",root->height,((Node*)arg)->height);



#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return (void*)root;
}
