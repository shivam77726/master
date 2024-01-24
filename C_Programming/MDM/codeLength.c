#include "headers.h"
#include "declaration.h"

extern short cl;
void* codeLength(void *arg)
{
	int *size;
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	size=(int*)arg;
	if (*size<=2)
		cl=1;
	else if(*size<=4)
		cl=2;
	else if(*size<=8)
		cl=3;
        else if(*size<=16)
		cl=4;
        else if(*size<=32)
		cl=5;
	else if(*size<=64)
		cl=6;
        else if(*size<=128)
		cl=7;
        else if(*size<=256)
		cl=8;
	else
		cl=0;
#ifdef DEBUG
	printf("Code Length:%d\n",cl);
#endif
#ifdef DEBUG
	printf("%s End\n",__func__);
#endif
	return 0;
}
