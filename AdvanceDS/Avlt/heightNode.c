#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* heightNode(void* arg)
{
	Node* tree;
	//DSinsert *di=(DSinsert*)arg;
	tree=(Node*)arg;

#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif
	printf("%d Arg->Node:%p\n",__LINE__,((DSinsert*)arg)->node);


        if(tree->left==NULL && tree->right!=NULL)
	{
		tree->height=1+tree->right->height;
	}
	else if(tree->right==NULL && tree->left!=NULL)
	{
		tree->height=1+tree->left->height;
	}
	else if(tree->right==NULL && tree->left==NULL)
	{
		tree->height=1;
	}
	else
	{
		tree->height=1+(tree->left->height > tree->right->height ? tree->left->height:tree->right->height);
	}



#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	return (void*)0;
}
