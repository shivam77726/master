#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

void* createNode(void* arg)
{

	Node *new;


#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	new=(Node*)malloc(sizeof(Node));
	if(!new)
	{
		printf("Memory not allocted\n");
		(*fun_ptr[0])(arg);
	}
	printf("Enter Data:");
	scanf("%d",&new->data);
	new->next=NULL;


#ifdef DEBUG
        printf("%s End\n",__func__);
#endif
	return (void*)new;
}
