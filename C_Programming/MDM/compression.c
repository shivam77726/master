#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* compression(void* arg)
{
	file of;
	uniqDS *arDS;
	int location,offset;
	arDS=(uniqDS*) arg;	
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

	//Input Filename
	of.mode='r';
	printf("Enter Filename to compress:");
	of.filename=(char*) malloc(20);
        if(of.filename==NULL)
        {
                printf("Filename not Allocated\n");
                return (void*) EXIT_FAILURE;
        }
        memset(of.filename,'\0',20);
        for(int i=0;i<20;i++)
        {
                scanf("%c",of.filename+i);
                if(i==0 && (*(of.filename+i)=='\n'||*(of.filename+i)=='\0'))
                {
                        i=-1;
                        continue;
                }

                if(*(of.filename+i)=='\n')
                {
                        *(of.filename+i)='\0';
                        break;
                }
        }

	arDS->fd= *(int*) (*fun_ptr[7])((void*)&of);	//Open File
	free(of.filename);
        
	arDS=(uniqDS*)(*fun_ptr[4])((void*)arDS);	//Create Masterarray


#ifdef DEBUG
	printf("Size of Master array:%d\n",arDS->size);
#endif
	
	//Generating Keyfile****************************************
	of.mode='w';
	of.filename="keyfile";
	*(int*) (*fun_ptr[7])((void*)&of);	//Open File
	printf("\nMasterArray:%s\n",arDS->ma);
	if(write(of.fd,(arDS->ma),arDS->size)==-1){
        	printf("Note able to write\n");
        	return ((void*)EXIT_FAILURE);
        }
	if(close(of.fd))
	{
		printf("File not closed\n");
	}
	else
		printf("keyfile closed Successfully\n");
	//***********************************************************


	
	(*fun_ptr[6])((void*)&arDS->size);		//Code Length
	
	(*fun_ptr[9])((void*)arDS);			//CompressionStat

	if(close(arDS->fd))
	{
		printf("File not closed\n");
	}
	else
		printf("Input File closed Successfully\n");


#ifdef DEBUG
	printf("%s End\n",__func__);
#endif

	return 0;

}
