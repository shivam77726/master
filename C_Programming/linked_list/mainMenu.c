#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

void* mainMenu(void* arg)
{

	int i=0;
	//Node *start;
	//start=(Node*)arg;
	
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	while(1)
	{
		printf("Choose option:\n");
		printf("1.____ CreateLinkedList____\n");
		printf("2.____ DisplayNode_________\n");
		printf("3.____ InsertNode__________\n");
		printf("4.____ DeleteNode__________\n");
		printf("0.____ ExitProgram_________\n");
	
		scanf("%d",&i);
		if(i==0)
			(*fun_ptr[0])((void*)arg);
		else if(i==1)
			arg =(Node*)(*fun_ptr[2])(arg);
		else if(i>1 && i<5)
			arg=(*fun_ptr[i+2])(arg);
		else
			printf("Choose correct option\n");
	}
#ifdef DEBUG
        printf("%s End\n",__func__);
#endif
	return (void*)arg;
}
