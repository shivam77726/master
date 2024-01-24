#include "../common/headers.h"
#include "../common/declaration.h"
#include "../common/dataStructure.h"
#include "../common/defaults.h"

int main(int argc, char* argv[])
{
	int fd,res,shmkey;
	Msg msg;
	Result *rslt;
#ifdef DEBUG
        printf("%s Child Begin.\n",__func__);
#endif

	if(argc<2)
	{
		printf("Argument insufficient\n");
		exit(EXIT_FAILURE);
	}

	fd=atoi(argv[1]);
	printf("FD:%c\t%d\n",*argv[1],fd);

        if(read(fd,&msg,sizeof(Msg))==-1)
        {
	        printf("READ\n");
                close(fd);
                exit(EXIT_FAILURE);
        }

	printf("%s Child CPID:%ld",__FILE__,msg.cpid);

        shmkey=shmget((key_t)SMKEY,sizeof(Result),IPC_CREAT|0666);
        if(shmkey==-1)
        {
                perror("Shared Memory");
                exit(EXIT_FAILURE);
        }
        printf("Shared memory segment created\n");
	
	rslt=(Result*) shmat(shmkey,NULL,0);
	if(rslt==(Result*)-1)
	{
		perror("Pointer not attatched to shared memory\n");
		exit(EXIT_FAILURE);
	}
	printf("%s Shared memory attatched to pointer\n",__FILE__);
	
	rslt->result=msg.opr1+msg.opr2;
	rslt->cpid=msg.cpid;
	printf("Client PID:%ld\nResult:%f\n",rslt->cpid,rslt->result);
	
	if(shmdt((Result*)rslt)==-1)
	{
		perror("shmdt\n");
		exit(EXIT_FAILURE);
	}
	printf("%s Shared memory dettatched to pointer\n",__FILE__);

#ifdef DEBUG
        printf("%s Child End.\n",__func__);
#endif

        return 0;

}

