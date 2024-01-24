#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void* 	insertNode(void* arg)
{
	Node* node=NULL;
	Node* tmp=NULL;
	Node* tree=(Node*)arg;

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

	node=(Node*)createNode((void*)0);          	//Creating Node
	if(!node)
	{
		return (void*)tree;
	}
	printf("Enter the value of Node:");
	scanf("%d",&node->Value);
	node->Left=NULL;
	node->Right=NULL;

	printf("Node:%d\n",node);
	printf("Tree:%d\n",tree);

	if(!tree)
	{
		printf("Inserting Root Node\n");
		tree=node;
	}
	else	
	{
		tmp=tree;
		while(1)
		{
			printf("Value:%d\n",tmp->Value);
			printf("Left Node:%d\tRight Node:%d\n",tmp->Left,tmp->Right);

			if(node->Value <= tmp->Value)
			{
				if(!tmp->Left)
				{
					tmp->Left=(struct Node*)node;
					
					break;
				}
				else
					tmp=(Node*)tmp->Left;
			}
			else
			{
				if(!tmp->Right)
				{
					tmp->Right=(struct Node*)node;
					break;
				}
				else
					tmp=(Node*)tmp->Right;
			}
			printf("Left Node:%d\tRight Node:%d\n",tmp->Left,tmp->Right);

		}
				
	}	
		
	


#ifdef DEBUG
	printf("%s End\n",__func__);
#endif
	return (void*)tree;
}
