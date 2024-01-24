#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

void* deleteNth(void *arg)
{
        Node *strt,*tmp=NULL;
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
			tmp->next=strt->next;
			free(strt);
			return 0;
		}
                tmp=strt;
		strt=strt->next;
                i++;
	}
	if(i<=n)
		printf("Position number not exitst\n");

#ifdef DEBUG
        printf("%s End\n",__func__);
#endif
	return 0;
}
