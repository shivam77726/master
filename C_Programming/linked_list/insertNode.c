#include "headers.h"
#include "declaration.h"

void* insertNode(void *arg)
{
	int i;

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

        printf("Choose option:\n");
	printf("1.____ Insert at Begining__________\n");
	printf("2.____ Insert at End_______________\n");
	printf("3.____ Insert at Nth position______\n");
	printf("4.____ Insert at Key position______\n");

	scanf("%d",&i);
	if(i>0 && i<5)
		(*fun_ptr[i+6])(arg);
	else
		printf("Choose correct option\n");

#ifdef DEBUG
        printf("%s End\n",__func__);
#endif
	return arg;
}
