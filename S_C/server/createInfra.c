#include "../common/headers.h"
#include "../common/declaration.h"
#include "../common/dataStructure.h"
#include "../common/defaults.h" 

void* createInfra(void* arg)
{
	int res;
	Infra *infra;
	Result *rslt;


#ifdef DEBUG
        printf("%s Begin.\n",__func__);
#endif

	infra=(Infra*)malloc(sizeof(Infra));
	if(infra==NULL)
	{
		printf("Malloc space not created\n");
		exit(EXIT_FAILURE);
	}

	//FIFO Infra
	if(access("../common/myfifo",F_OK)==-1)
        {
                res=mkfifo("../common/myfifo",0666);
                if(res==-1)
                {
                        printf("FIFO\n");
                        exit(EXIT_FAILURE);
                }
#ifdef DEBUG
                printf("FIFO created\n");
#endif
        }
	else
#ifdef DEBUG
		printf("FIFO already exist\n");
#endif

	//Pipe Infra
	if (pipe(infra->pfd) == -1) 
	{
        	perror("Pipe\n");
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("Pipe created\n");
#endif

	//Shared Memory Infra
	infra->shmid=shmget((key_t)SMKEY,sizeof(Result),IPC_CREAT|0666);
	if(infra->shmid==-1)
	{
		perror("Shared Memory\n");
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("Shared memory segment created\n");
#endif

	//Message Queue Infra
	infra->mqid=msgget((key_t)MQKEY, IPC_CREAT|0666);
	if(infra->mqid==-1)
	{
		perror("Message Queue\n");
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("Message Queue created\n");
#endif
	
	infra->semid=semget((key_t)SEMKEY, 4, IPC_CREAT|0666);
	if(infra->semid==-1)
	{
		perror("Semaphore\n");
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("Semaphore created\n");
#endif


#ifdef DEBUG
        printf("%s End.\n",__func__);
#endif

	return (void*)infra;

}
