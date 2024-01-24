#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#define FIFO_NAME "./fifo1"

int main()
{
	int fd,fifo_pipe,mode=0666,nob;
	char buf[64];
	printf("%s Begin,PID:%d,PPID:%d\n",__func__,getpid(),getppid());
	if(access(FIFO_NAME,F_OK)==-1)
	{
		fifo_pipe=mkfifo(FIFO_NAME,mode);
		if(fifo_pipe==-1)
		{
			printf("Pipe not created\n");
			perror("Pipe");
		}
		else
			printf("Pipe created:%d\n",fifo_pipe);
	}
	else
		printf("Pipe already exist\n");
	fd=open(FIFO_NAME,O_RDONLY);
	if(fd==-1)
	{
		printf("Pipe not open\n");
		perror("File Descriptor");

	}
	else
		printf("Pipe opned:%d\n",fd);
	nob=read(fd,&buf,45);
	if(nob==-1)
	{
		printf("NOt able to read\n");
		perror("Read");
	}
	printf("%d no of bytes reads from pipe\n",nob);
	printf("%s\n",buf);

	printf("%s End",__func__);
	return 0;

}
