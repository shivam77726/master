#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* insertNode(void* arg)
{
	Node* tree;
	DSinsert *di=(DSinsert*)arg;
	tree=di->node;
//	int bf;

#define	MAX(tree) \
	{if(tree->left==NULL)\
		tree->left->height=0;\
	if(tree->right==NULL)\
		tree->right->height=0;\
	(tree->left->height > tree->right->height ? tree->left->height:tree->right->height);}

#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif
	printf("%d Arg->Node:%p\n",__LINE__,((DSinsert*)arg)->node);

	if(!tree)
		return fptr[3]((void*)&di->key);  //Create Node
	else if(di->key < tree->data)
	{
		di->node=tree->left;
		tree->left=(Node*)insertNode((void*)di);
		printf("Tree->Left:%p\n",tree->left);
	}
	else if(di->key > tree->data)
	{
		di->node=tree->right;
		tree->right=(Node*)insertNode((void*)di);
		printf("Tree->Right:%p\n",tree->right);
	}
	else
		printf("Key alredy exist in the tree\n");
	

        if(tree->left==NULL && tree->right!=NULL)
	{
		tree->height=1+tree->right->height;
//		bf= - tree->right->height;	
	}
	else if(tree->right==NULL && tree->left!=NULL)
	{
		tree->height=1+tree->left->height;
//		bf= tree->left->height;	
	}
	else if(tree->right==NULL && tree->left==NULL)
	{
		tree->height=1;
//		bf=0;
	}
	else
	{
		tree->height=1+(tree->left->height > tree->right->height ? tree->left->height:tree->right->height);
//		bf=tree->left->height - tree->right->height;
	}

	tree=getBalanceFactor((void*)tree);
/*
	if(bf>1 || bf <-1)
	{
		if(tree->left==NULL && tree->right==NULL)
		{
			printf("Balance Factor is Zero\n");
		}
		else if(tree->left==NULL)
		{

			if(tree->right->left==NULL && tree->right->right==NULL)
			{
				printf("Balance Factor is Zero\n");
			}
			else if(tree->right->left==NULL)
			{
				printf("Need to do RR rotation");
			}
			else
			{
				printf("Need to do RL rotation");
			}

		}
		else
		{
			if(tree->left->left==NULL && tree->left->right==NULL)
			{
				printf("Balance Factor is Zero\n");
			}
			else if(tree->left->left==NULL)
			{
				printf("Need to do LR rotation");
			}
			else
			{
				printf("Need to do LL rotation");
			}
		}
	}
*/
#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	return (void*)tree;
}
