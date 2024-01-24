#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* createMasterarray(void* arg)
{
	uniqDS *Duniq;
	int size=0,offset;
	Duniq = (uniqDS*) arg;
#ifdef DEBUG
	printf("%s begin\n",__func__);
#endif
	size=lseek(Duniq->fd,0,SEEK_END)-1;
	if(size==-1)
	{
		printf("Error to read size of file\n");
		return (void*)EXIT_FAILURE;
	}
	offset=lseek(Duniq->fd,0,SEEK_SET);
	//printf("Offset no:%d\n",offset);
	if(offset==-1)
	{
		printf("Error to set offset\n");
		return (void*) EXIT_FAILURE;
	}

	//Duniq.ma=&arDS->ma;
	Duniq->ma=NULL;
	Duniq->size=0;
	for(int i=0;i<size;i++)
	{
		read(Duniq->fd,&Duniq->ch,1);
		if((bool*)(*fun_ptr[5])((void*)Duniq))			//Uniqchar
		{
			Duniq->ma=(char*) realloc(Duniq->ma,Duniq->size+1);
			*(Duniq->ma+Duniq->size)=Duniq->ch;
			Duniq->size++;
		}
	}
	printf("\nMasterArray:%s\n",Duniq->ma);
	printf("Master size:%d\n",Duniq->size);

#ifdef DEBUG
	printf("%s End\n",__func__);
#endif
	return (void*)Duniq;

}
