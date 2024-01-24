#include "headers.h"
#include "declaration.h"

void* deleteNode(void *arg)
{
	int i;

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
        printf("Choose option:\n");
	printf("1.____ Delete at Begining__________\n");
	printf("2.____ Delete at End_______________\n");
	printf("3.____ Delete at Nth position______\n");
	printf("4.____ Delete Key position___\n");
	scanf("%d",&i);
	if(i<0 && i>5)
		(*fun_ptr[i+10])(arg);
	else
		printf("Choose correct option\n");


#ifdef DEBUG
        printf("%s Begin\n",__func__);
#endif
	return 0;
}
