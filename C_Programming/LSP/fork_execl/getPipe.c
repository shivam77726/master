#include "headers.h"
#include "declaration.h"

int* getPipe()
{
	int *fdptr;
	fdptr=(int*)malloc(sizeof(int)*2);
	if(!fdptr)
	{
		perror("malloc error\n");
		exit(EXIT_FAILURE);
	}
	if(pipe(fdptr)==-1)
	{
		perror("Pipe Not Created\n");
		exit(EXIT_FAILURE);
	}
	return fdptr;
}
