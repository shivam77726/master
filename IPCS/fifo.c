#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd,res;
	char buf[12];
	
	
	if(access("./myfifo",F_OK)==-1)
	{
		res=mkfifo("./myfifo",0777);
		if(res==-1)
		{
			printf("FIFO");
			exit(EXIT_FAILURE);
		}
		printf("FIFO created\n");
	}
	

	fd=open("./myfifo",O_RDWR);
	if(fd==-1)
	{
		printf("OPEN");
		exit(EXIT_FAILURE);
	}
	printf("FIFO opened\n");

	if(write(fd,"Hello World",12)==-1)
	{
		printf("WRITE");
		close(fd);
		exit(EXIT_FAILURE);
	}
	printf("FIFO written\n");


	if(read(fd,buf,12)==-1)
	{
		printf("READ");
		close(fd);
		exit(EXIT_FAILURE);
	}
	printf("FIFO read\n");
	close(fd);
	printf("%s\n",buf);
	return 0;
}
