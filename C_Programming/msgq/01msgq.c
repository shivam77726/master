#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main()
{
	int msgid;


	struct msgblock
	{
		long ctrl;
		char data[100];
	}msg;

	msgid=msgget((key_t) 12, IPC_CREAT | 0777);
	printf("KEY%d\n",msgid);
	if(msgid==-1)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	msg.ctrl=12;
	strcpy(msg.data,"Hi, This is my first msgq");
	if(msgsnd(msgid,&msg.data,20,0)==-1)
	{
		perror("msgsend");
		printf("Not able to send message\n");
	}
	else
		printf("Message send successfully\n");

	system("ipcs");
	return 0;
}
