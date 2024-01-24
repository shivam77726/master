#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>

int main()
{
	int s[2];
	int ret;

	ret=socketpair(AF_LOCAL,SOCK_DGRAM,0,s);
	if(ret==-1)
	{
		perror("sockpair");
		exit(1);
	}

	printf("S[0}:%d\n",s[0]);
	printf("S[1}:%d\n",s[1]);

	system("netstat --unix -p");



	return 0;
}
