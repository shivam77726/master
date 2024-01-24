#include "headers.h"
#include "declaration.h"

int main()
{
	int ret,ec,wret,fd,*pfd;
	char sfd[2],*str="Hi, i am writing from parant process";
	printf("Parent PID:%d,PPID:%d Begin\n",getpid(),getppid());
	//fd= open("myfile.txt",O_CREAT|O_RDWR);
	pfd=getPipe();
	printf("pfd[0]:%d,pfd[1]:%d\n",*(pfd+0),*(pfd+1));
	sprintf(sfd,"%d",*(pfd+0));
	ret=fork();
	switch(ret)
	{
		case -1: printf("Fork not executed properly\n");
			break;

		case 0: printf("Child PID:%d,PPID:%d,ret:%d\n",getpid(),getppid(),ret);
			execl("./execl_child","execl_child",sfd,NULL);
			break;

		default: printf("Parent PID:%d,PPID:%d,ret:%d\n",getpid(),getppid(),ret);
			 if(write(*(pfd+1),str,47)==-1)
				 printf("Not able to write in myfile.txt\n");
			 else
				 printf("pfd[1] writetn successfully\n");
	}


	wret=wait(&ec);
	printf("PID:%d,PPID:%d,ret:%d,wret:%d End\n",getpid(),getppid(),ret,wret);
	if(WIFEXITED(ec))
		printf("Parent PID:%d,PPID:%d,ret:%d,wret:%d End\n",getpid(),getppid(),ret,WEXITSTATUS(ec));

	//close(fd);
	close(*(pfd+0));
	close(*(pfd+1));
	return 0;
}
