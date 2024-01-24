#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,fret,wret,ec;

	printf("Parent Pid:%d,Ppid:%d,Begin.\n",getpid(),getppid());
	fret=fork();
	switch(fret)
	{
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
		case 0:
			n=30;
			break;
		default:
			n=15;
	}
	for(int i=0;i<n;i++)
	{
		printf("Pid:%d,Ppid:%d\n",getpid(),getppid());
		sleep(1);
	}
	if(fret>0)
	{
		wret=wait(&ec);
		printf("Parent Pid:%d,Ppid:%d,wret:%d End\n",getpid(),getppid(),wret);

	}
	else
	{
		printf("Child Pid:%d,Ppid:%d End\n",getpid(),getppid());
		exit(n);
	}
	

	return 0;
}
