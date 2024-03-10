#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* insertNode(void* arg)
{
	Node* tree;
	DSinsert *di=(DSinsert*)arg;
	tree=di->node;
#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif

	if(!tree)
		return fptr[3]((void*)&di->key);  //Create Node
	else if(di->key < tree->data)
	{
		di->node=tree->left;
		tree->left=insertNode((void*)di);
	}
	else if(di->key > tree->data)
	{
		di->node=tree->right;
		tree->right=insertNode((void*)di);
	}
	else
		printf("Key alredy exist in the tree\n");


	tree->height=1+(tree->left->height > tree->right->height ? tree->left->height:tree->right->height);

#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return (void*)arg;
}
