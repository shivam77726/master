#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* rightLeftRotate(void* arg)
{
	Node *root;
#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif
	
	printf("arg:%p,arg->Left%p,arg->Right:%p\n",(Node*)arg,((Node*)arg)->left,((Node*)arg)->right);
        root=((Node*)arg)->right->left;
        ((Node*)arg)->right->left=root->right;
        root->right=((Node*)arg)->right;
        ((Node*)arg)->right=root->left;
        root->left=((Node*)arg);
        root->height+=1;
        root->right->height=root->left->height=root->height-1;

	
	printf("Root:%p,Root->Left%p,Root->Right:%p\n",root,root->left,root->right);



#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return (void*)root;
}
