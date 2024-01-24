#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"
void* insertBeg(void *arg)
{
	Node *strt,*new;
	strt=(Node*)arg;

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif	
	
	if(!strt)
	{
		printf("Linked List not exist\n");
		return NULL;
	}
	new=(*fun_ptr[3])(0);
	if(!strt->next)
	{
		strt->next=new;
	}
	else
	{
		new->next=strt->next;
		strt->next=new;
	}

#ifdef DEBUG
        printf("%s End\n",__func__);
#endif
	return arg;
}
