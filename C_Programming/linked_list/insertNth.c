#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

void* insertNth(void *arg)
{
	Node *strt,*new=NULL;
	unsigned int n,i=1;

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

	strt=(Node*)arg;
	printf("Enter position:");
	scanf("%d",&n);

	while(strt)
	{
		if(i==n)
		{
			
			new=(Node*)(*fun_ptr[3])(0);
			new->next=strt->next;
			strt->next=new;
			break;
		}
		
		strt=strt->next;
		i++;

	}
	if(i<=n || n<=0)
		printf("Position number not exitst\n");

#ifdef DEBUG
        printf("%s End\n",__func__);
#endif
	return arg;
}
