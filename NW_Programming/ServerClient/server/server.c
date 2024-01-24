#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	int sfd,cfd,size,buf_size=0;
	struct sockaddr_in saddr,caddr;
	char wbuff[40]="Hello Client From Server",rbuff[40];

	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1)
	{
		perror("Server Socket");
		exit(1);
	}
	printf("Server Socet created:%d\n",sfd);
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(6666);
	saddr.sin_addr.s_addr=htonl(INADDR_ANY);
	memset(&(saddr.sin_zero),0,8);
	printf("Size of sockaddr=%d\t Size of sockaddr_in=%d\n",sizeof(struct sockaddr),sizeof(struct sockaddr_in));
	if(bind(sfd,(struct sockaddr*)&saddr,sizeof(struct sockaddr_in))==-1)
	{
		perror("Server Bind");
		close(sfd);
		exit(1);
	}
	printf("Serveri Bind Successfully\n");

	if((listen(sfd,2))==-1)
	{
		perror("Server Listen");
		close(sfd);
		exit(1);
	}
	printf("Listen Queue Successfully\n");
	size=sizeof(struct sockaddr_in);
	cfd=accept(sfd,(struct sockaddr*)&caddr,&size);
	if(cfd==-1)
	{
		perror("Server Socket Accept");
		close(sfd);
		exit(1);
	}
	printf("Accepted Successfully:%d\n",cfd);
	
//	close(1);

//	dup(cfd);

//	printf("Hello Client I am confused");
	
//	while(1)
	{
		buf_size=write(cfd,wbuff,40);
		if(buf_size==-1)
		{
			perror("Write to Client");
			close(sfd);
			close(cfd);
		}
		printf("%d Byte Written Successfully\n",buf_size);
	}
	
	return 0;
}
