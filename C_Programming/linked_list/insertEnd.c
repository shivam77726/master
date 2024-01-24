#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

void* insertEnd(void *arg)
{
	Node *strt,*new;
	strt=(Node*)arg;

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	new=(Node*)(*fun_ptr[3])(0);
	if(!strt)
	{
		printf("Linked List not Exist\n");
		return NULL;
	}

	while(strt)
	{
		if(!strt->next)
		{
			strt->next=new;
			break;
		}
		strt=strt->next;
	}



#ifdef DEBUG
        printf("%s End\n",__func__);
#endif
	return arg;
}
