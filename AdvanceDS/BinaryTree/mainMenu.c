#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void** mainMenu (void** arg)
{
	Node** tree=(Node**)arg;
	unsigned short choice;
#ifdef DEBUG
        printf("%s begin\n",__func__);
#endif

	if(!tree)
        	tree=(Node**)(fun_ptr1[1])((void**)tree);					//Create Tree
	while(1)
	{
		printf("----------Enter Choice----------\n");
		printf("0. Exit\n");
		printf("1. Insert Tree Node\n");
		printf("2. Display Tree\n");
		scanf("%hu",&choice);
		printf("\n\n");
		switch(choice)
		{
			case 0:
				tree=(Node**)(fun_ptr1[4])((void**)tree);			//Exit
				break;
			case 1:
				tree=(Node**)(fun_ptr1[2])((void**)tree);			//Insert Tree Node
				break;
			case 2:
				(fun_ptr1[3])((void**)tree);				//Display Tree
				break;
			default:
				printf("Please Enter Valid Choice (between 0-2)\n");
				break;
		}
	}



#ifdef DEBUG
        printf("%s End\n",__func__);
#endif

	return (void**)tree;
}
