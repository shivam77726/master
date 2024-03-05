#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void* 	insertNode(void* arg)
{
	Node* node=NULL;
	//Node* tmp=NULL;
	Node* tmp=(Node*)arg;

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

	node=(Node*)createNode((void*)0);          	//Creating Node
	if(!node)
	{
		perror("Node Not Created");
		return arg;
	}


	printf("Node:%d\n",node);
	printf("Tree:%d\n",tmp);


	/***************************************Node Insertion Start*******************************************/	

	if(!tmp)
	{
		printf("Inserting Root Node\n");
		tmp=node;
		arg=(void*)tmp;

	}
	else	
	{
		
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

		}
				
	}	
	printf("Tree:%d\tLeft Node:%d\tRight Node:%d,\tbf:%d\n",tmp,tmp->Left,tmp->Right,tmp->bf);
	/***************************************Node Insertion Done*******************************************/	
	
	
	
	
	/***************************************Balancing Tree Start*******************************************/
	getBalanceFactor(arg);								//Update Balance Factor
	
	printf("Balance Factor Done\n");



	/***************************************Tree Balancing done*******************************************/	
	


#ifdef DEBUG
	printf("%s End\n",__func__);
#endif
	return arg;
}
