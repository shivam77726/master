#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

void* uniqchar(void* arg)
{
	uniqDS *Duniq;
	Duniq =(uniqDS*)arg;
#ifdef DEBUG
	printf("%s begin\n",__func__);
#endif
	for(int i=0;i<Duniq->size;i++)
	{
		//printf("char:%c\tmachar%d:%c\n",Duniq->ch,i,*(Duniq->ma+i));
		if(Duniq->ch == *(Duniq->ma+i))
		{
			//printf("False\n");
			return (void*)false;
		}
	}
	//printf("True\n");
#ifdef DEBUG
	printf("%s end\n",__func__);
#endif
	return (void*) true;
}	
