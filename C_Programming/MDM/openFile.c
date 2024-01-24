#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* openFile(void *arg)
{	
	file *of;
	of=(file*) arg;
#ifdef DEBUG
	printf("%s begin\n",__func__);
#endif
       
	


#ifdef DEBUG
	printf("Filename:%s\n",of->filename);
#endif

	if(of->mode=='w')
		of->fd =open(of->filename,O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU|S_IRWXG|S_IRWXO);
	else if(of->mode=='r')
		of->fd =open(of->filename,O_RDONLY);
	else if(of->mode=='a')
		of->fd =open(of->filename,O_WRONLY);
	else
		printf("Please Enter correct mode\n");

	if(of->fd==-1)
	{
		printf("File unable to open\n");
		return (void*) EXIT_FAILURE;
	}
		

#ifdef DEBUG
	printf("%s end\n",__func__);
#endif

	return (void*)&of->fd;
}

