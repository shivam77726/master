#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* deleteNode(void* arg)
{
	Node* tree;
	//DSinsert *di=(DSinsert*)arg;
	tree=((DSinsert*)arg)->node;

#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif
	printf("%d Arg->Node:%p Tree->data:%d\n",__LINE__,((DSinsert*)arg)->node,tree->data);

	if(((DSinsert*)arg)->node==NULL)
	{
		printf("Key doesn't exist\n");
		return (void*)((DSinsert*)arg)->node;
	}
	
	if(((DSinsert*)arg)->key < ((DSinsert*)arg)->node->data)
	{
		((DSinsert*)arg)->node=((DSinsert*)arg)->node->left;
		tree->left=(Node*)deleteNode(arg);
		printf("Tree->Left:%p,tree->data:%d\n",tree->left,tree->data);
	}
	else if(((DSinsert*)arg)->key > ((DSinsert*)arg)->node->data)
	{
		((DSinsert*)arg)->node=((DSinsert*)arg)->node->right;
		tree->right=(Node*)deleteNode(arg);
		printf("Tree->Right:%p Tree->data:%d\n",tree->right,tree->data);
	}
	else 
	{
//		if(((DSinsert*)arg)->key == ((DSinsert*)arg)->node->data)
		if(((DSinsert*)arg)->node->left==NULL && ((DSinsert*)arg)->node->right==NULL)
		{
			free(((DSinsert*)arg)->node);
			return NULL;
		}
		else if(((DSinsert*)arg)->node->left==NULL && ((DSinsert*)arg)->node->right!=NULL)
		{
			Node* temp=((DSinsert*)arg)->node->right;
			free(((DSinsert*)arg)->node);
			return temp;
		}
		else if(((DSinsert*)arg)->node->left!=NULL && ((DSinsert*)arg)->node->right==NULL)
		{
			Node* temp=((DSinsert*)arg)->node->left;
			free(((DSinsert*)arg)->node);
			return temp;
		}
		else
		{
			Node* temp=((DSinsert*)arg)->node->right;
                        while(temp)
                        {
                                if(temp->left==NULL)
                                {
                                        ((DSinsert*)arg)->node->data=temp->data;
					printf("Tree->Right:%p Tree->data:%d\n",tree->right,tree->data);
                                        temp->data=((DSinsert*)arg)->key;
					printf("Tree->Leftt:%p Tree->data:%d\n",tree->left,tree->data);
					((DSinsert*)arg)->node=((DSinsert*)arg)->node->right;
					deleteNode(arg);

                                        break;
                                }
                                temp=temp->left;
                        }

		}
		
	}


	printf("%d Tree:%p Tree->Leftt:%p Tree->data:%d\n",__LINE__,tree,tree->left,tree->data);
	fptr[12]((void*)tree);					//Height of the node

	((DSinsert*)arg)->node=tree;
	tree=getBalanceFactor(arg);
	printf("tree root:%p",tree);


#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	return (void*)tree;
}
