#include "headers.h"
extern char **environ;

int main(int argc,char *argv[])
{
	int fd1,fd2,fd3;
	
	fd1=open("myfile.txt",O_CREAT|O_WRONLY);
	if(fd1==-1)
	{
		printf("File not open\n");
		return -1;
	}
	//close(1);
	fd2=dup(fd1);
	fd3=dup2(fd1,5);
	printf("fd1:%d\tfd2:%d\tfd3:%d\nPid:%d\tPpid:%d\n",fd1,fd2,fd3,getpid(),getppid());
	for(char** env=environ;*env;env++)
		printf("%s\n",*env);
	printf("%s\n",getenv("PATH"));
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}
