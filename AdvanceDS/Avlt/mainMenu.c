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
	printf("3.InOrderTraversal\n");
	printf("4.Delete Node\n");
	printf("0.Exit\n");
	printf("Enter Choice:");
	scanf("%d",&choice);

	if(choice==0)
	{
		fptr[0](arg);	//Exit Program
		exit(0);
	}
	else if(choice==1)
	{
		if(arg==NULL)
		{
			printf("Please Enter Data:");
			scanf("%d",&di.key);
			arg=fptr[2]((void*)&di.key);		//Crete Tree
		}
		else
			printf("\nTree already present\n");
	}
	else if(choice==2)	
	{
		if(arg==NULL)
			printf("\nTree is not present\n");
		else
		{
			printf("Please Enter Data:");
			scanf("%d",&di.key);
			printf("arg:%p\n",(Node*)arg);
			di.node=(Node*)arg;
			arg=fptr[4]((void*)&di);		//Insert node
		}
	}
	else if(choice==3)
	{
		printf("arg:%p\n",(Node*)arg);
		fptr[5](arg);				//Inorder Travesal
	}
	else if(choice==4)	
	{
		if(arg==NULL)
			printf("\nTree is not present\n");
		else
		{
			printf("Please Enter Data to delete:");
			scanf("%d",&di.key);
			printf("arg:%p\n",(Node*)arg);
			di.node=(Node*)arg;
			arg=fptr[11]((void*)&di);		//Delete node
		}
	}
	else
		printf("Please Enter Valid Option\n");



#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return arg;
}
