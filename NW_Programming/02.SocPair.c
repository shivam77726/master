#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main()
{
	int s[2];
	int ret;
	char buf[20];

	memset(buf,'\0',20);

	ret=socketpair(AF_LOCAL,SOCK_DGRAM,0,s);
	if(ret==-1)
	{
		perror("sockpair");
		exit(1);
	}

	printf("S[0}:%d\n",s[0]);
	printf("S[1}:%d\n",s[1]);
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
	printf("%s\n",buf);

	memset(buf,'\0',20);
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
	printf("%s\n",buf);
//	system("netstat --unix -p");

	shutdown(s[0],SHUT_RDWR);
	shutdown(s[1],SHUT_RDWR);

	return 0;
}
