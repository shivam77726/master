#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* insertNode(void* arg)
{
	Node* tree;
	//DSinsert *di=(DSinsert*)arg;
	tree=((DSinsert*)arg)->node;

#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif
	printf("%d Arg->Node:%p\n",__LINE__,((DSinsert*)arg)->node);

	if(!(((DSinsert*)arg)->node))
		return fptr[3]((void*)&((DSinsert*)arg)->key);  //Create Node
	else if(((DSinsert*)arg)->key < ((DSinsert*)arg)->node->data)
	{
		((DSinsert*)arg)->node=((DSinsert*)arg)->node->left;
		tree->left=(Node*)insertNode(arg);
		printf("Tree->Left:%p\n",tree->left);
	}
	else if(((DSinsert*)arg)->key > ((DSinsert*)arg)->node->data)
	{
		((DSinsert*)arg)->node=((DSinsert*)arg)->node->right;
		tree->right=(Node*)insertNode(arg);
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

	((DSinsert*)arg)->node=tree;
	tree=getBalanceFactor(arg);
	printf("tree root:%p",tree);


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
