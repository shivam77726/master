#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main()
{
	int s[2],fd;
	int ret;
	char buf[20];

	memset(buf,'\0',20);
	//close(0);
	//close(1);

	ret=socketpair(AF_LOCAL,SOCK_DGRAM,0,s);
	if(ret==-1)
	{
		perror("sockpair");
		exit(1);
	}
	printf("s[0]:%d\n",s[0]);
	printf("s[1]:%d\n",s[1]);
	close(1);
	//dup(s[1]);
//	scanf("%s",buf);
	//printf("Hello bhai");
	perror("Hello perror");
	fd=open("myfile",O_WRONLY);
	if(fd==-1)
	{
		perror("open");
		shutdown(s[0],SHUT_RDWR);
		shutdown(s[1],SHUT_RDWR);
		exit(1);
	}
	perror("fd open");
	//dup(fd);
	printf("Hello fd");
	if(write(s[0],"Hello bhai",10)==-1)
	{
		perror("Write");
		exit(1);
	}
	if(read(s[1],buf,10)==-1)
	{
		perror("Read");
		exit(1);
	}
	perror("read success");
	/*if(write(fd,buf,10)==-1)
	{
		perror("Write");
		shutdown(s[0],SHUT_RDWR);
		shutdown(s[1],SHUT_RDWR);
		close(fd);
		exit(1);
	}*/
	perror("write success");

	/*memset(buf,'\0',20);
	if(write(s[1],"Chal foot",9)==-1)
	{
		perror("Write");
		exit(1);
	}
	if(read(s[0],buf,9)==-1)
	{
		perror("Read");
		exit(1);
	}
	printf("%s\n",buf);*/
//	system("netstat --unix -p");

	shutdown(s[0],SHUT_RDWR);
	shutdown(s[1],SHUT_RDWR);
	close(fd);
	return 0;
}
