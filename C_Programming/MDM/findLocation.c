#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

void* findLocation(void *arg)
{
	int *loc; 
	uniqDS *fl;
	 fl=(uniqDS*)arg;

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

	loc=(int*)malloc(sizeof(int));
	if(loc==NULL)
	{
		printf("Memory not allocated\n");
		return (void*)EXIT_FAILURE;
	}
	for(int i=0;i<fl->size;i++)
	{
		if(*(fl->ma+i)==fl->ch)
		{
			*loc=i;
			printf("l:%d\tfl->ch:%c\n",*loc,fl->ch);
			break;
		}

	}




#ifdef DEBUG
	//printf("Location:%d\n",*l);
#endif
#ifdef DEBUG
	printf("%s End\n",__func__);
#endif
	return (void*)loc;
}
