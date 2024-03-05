#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* mainMenu(void* arg)
{
	int choice=0;
	DSinsert di;
#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif
	init();
	printf("__mainMenu___\n");
	printf("1.Crete Tree\n");
	printf("2.Insert Node\n");
	printf("0.Exit\n");
	printf("Enter Choice:");
	scanf("%d",&choice);

	if(choice==0)
	{
		fptr[0](arg);	//Exit Program
		exit(0);
	}
	else if(choice==1 && arg ==NULL)
		arg=fptr[2](arg);		//Crete Tree
	else if(choice==2)
	{
		printf("Please Enter Data:");
		scanf("%d",&di.key);
		di.node=(Node*)arg;
		arg=fptr[4]((void*)&di);		//Insert node
	}
	else
		printf("Please Enter Valid Option\n");



#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return arg;
}
