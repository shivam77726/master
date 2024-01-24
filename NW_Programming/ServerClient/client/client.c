#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int sfd,cfd,size;
	struct sockaddr_in saddr,caddr;

	cfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1)
	{
		perror("Server Socket");
		exit(1);
	}
	printf("Client created\n");
	caddr.sin_family=AF_INET;
	caddr.sin_port=htons(6666);
	caddr.sin_addr.s_addr=inet_addr("192.168.0.113");
	memset(&(caddr.sin_zero),0,8);
	printf("Size of sockaddr=%d\t Size of sockaddr_in=%d\n",sizeof(struct sockaddr),sizeof(struct sockaddr_in));
	size=sizeof(struct sockaddr_in);
	if(connect(cfd,(struct sockaddr*)&caddr,size)==-1)
	{
		perror("Server Connect");
		close(sfd);
		exit(1);
	}
	printf("Client Connect Successfully\n");


	return 0;
}
