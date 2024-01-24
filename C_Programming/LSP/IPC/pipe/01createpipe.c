#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{

        int arr[2],len,rd=1,ret;
	char buf[]="0 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 1 2 3 4 6 7 8 9 10 111";
	char msg[1024],sndmsg[]="";
	len=strlen(buf);
	printf("Lenght:%d\n",len);
        if(pipe(arr)==-1)
        {
                printf("Error");
                exit(1);
        }
	ret =fork();
	switch(ret)
	{
		case -1:
			printf("Fork not executed");
			break; 
		case 0:
			close(arr[1]);
		//	sleep(1);
			printf("Child PID:%d\tPPID:%d\n",getpid(),getppid());
			while(rd)
			{	
				if(read(arr[0],msg,2048)==-1)
				{
					printf("Not able to open arr[0]\n");
					exit(1);
				}
				printf("Enter 1 to continue read:");
				scanf("%d",&rd);
				//rd=0;
				printf("Messege received:%s\n",msg);
				
			}
			printf("Enter 1 to continue read:");
			scanf("%d",&rd);
			printf("rd:%d",rd);

			close(arr[0]);
			printf("Read Pipe Closed\n");
			break;
		default:

			printf("Parent PID:%d\tPPID:%d\n",getpid(),getppid());
			close(arr[0]);
			/*while(1)
	
			{	
				static int i=1;
				printf("%d Writing into pipe....\n",i++);
				if(write(arr[1],buf,len)==-1)
				{
					printf("Not able to open arr[1]\n");
					exit(1);
				}
	
			}*/

			if(write(arr[1],buf,1024)==-1)
			{
				printf("Not able to open arr[1]\n");
				exit(1);
			}
			//sleep(15);
			close(arr[1]);
			printf("Write Pipe Closed\n");
			//sleep(2);
	}
        return 0;
}
