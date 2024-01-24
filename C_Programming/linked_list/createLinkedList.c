#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

void* createLinkedList(void* arg)
{

	Node *strt=NULL,*new=NULL,*tmp=NULL;
	int n;
	

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	printf("Enter total No of Node:");
	scanf("%d",&n);
	strt=(Node*)malloc(sizeof(Node));
	if(!strt)
	{
		printf("Memory not allocated\n");
		return NULL;
	}
	strt->data=0;
	strt->next=NULL;
	tmp=strt;
	for(int i=0;i<n;i++)
	{

		new=(Node*)(*fun_ptr[3])(arg);
		tmp->next=new;
		tmp=new;
	}	

#ifdef DEBUG
        printf("%s End\n",__func__);
#endif
	return (void*)strt;
}
