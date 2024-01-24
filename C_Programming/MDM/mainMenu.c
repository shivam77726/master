#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* mainMenu(void* arg)
{
	int choice=1;
	uniqDS arDS;
#ifdef DEBUG
	printf("%s begin\n",__func__);
#endif
	while(1){
		printf("Choose from options\n");
		//printf("2. openfile to write\n");
		printf("1. Compression\n");
		printf("2. Decompression \n");
		printf("0. Exit\n");
		printf("Enter Choice:");
		scanf("%d",&choice);
		if(choice ==0)
			(*fun_ptr[choice+1])(0);				//Exit
		else

			(*fun_ptr[choice+1])((void*)&arDS);			//compression or decompression
	}
	

#ifdef DEBUG
	printf("%s end\n",__func__);
#endif

	return 0;
}
