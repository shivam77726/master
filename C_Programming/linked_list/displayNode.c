#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

void* displayNode(void* arg)
{

	Node *strt;
	strt=(Node*)arg;

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	if(!strt)
	{
		printf("Linked List not Exist\n");
		return NULL;
	}
	strt=strt->next;
	while(strt)
	{
		printf("%d\n",strt->data);
		strt=strt->next;
	}



#ifdef DEBUG
        printf("%s End\n",__func__);
#endif
	return arg;
}
