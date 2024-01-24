#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main()
{
	int key;
	char *ptr;
	key =shmget((key_t)12,8,IPC_CREAT|0666);
	if(key==-1)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	

	ptr=shmat(key,NULL,SHM_EXEC);
	if(*ptr==-1)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}	

	sleep(20);
	strcpy(ptr,"Shivam");


	return 0;
}
