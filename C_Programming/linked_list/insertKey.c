#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

void* insertKey(void *arg)
{
	Node *strt, *new=NULL, *tmp=NULL;
	int key=0,flag=0;

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	strt=(Node*)arg;
	tmp=strt;
	printf("Enter Key:");
	scanf("%d",&key);
	
	while(strt)
	{
		tmp=strt;
		strt=strt->next;
		if(strt->data==key)
		{
			new=(Node*)(*fun_ptr[3])(0);
			new->next=strt;
			tmp->next=new;
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("Key value not found\n");


#ifdef DEBUG
        printf("%s End\n",__func__);
#endif
	return arg;
}
