#include "headers.h"

int main(int argc, char *argv[])
{
	int n=10,fd;
	char buff[100];

	printf("Child PID:%d,PPID:%d\tBegin\n",getpid(),getppid());
	if(argc>1)
	{
		for(int i=1; i<argc;i++)
		{
			printf("argv[%d]:%s\n",i,argv[i]);
			sleep(1);
			fd=atoi(argv[1]);
			printf("fd:%d\n",fd);
			lseek(fd,0,SEEK_SET);
			if(read(fd,buff,47)==-1)
				printf("FIle not able to read\n");
			else
			{
				//while(*str)
				printf("String in file:%s\n",buff);
			}
	
		}
	}
	else
		printf("No argument Passed\n");
	printf("Child PID:%d,PPID:%d\tEnd\n",getpid(),getppid());
	exit(n);

	return 0;
}
