#include "../common/headers.h"
#include "../common/declaration.h"
#include "../common/dataStructure.h"
#include "../common/defaults.h" 

void* createInfra(void* arg)
{
	int res;
	Infra *infra;
	Result *rslt;
	semun se[4];
//	sem_t sem;


#ifdef DEBUG
        printf("%s Begin.\n",__func__);
#endif

	infra=(Infra*)malloc(sizeof(Infra));
	if(infra==NULL)
	{
		perror("Malloc");
		exit(EXIT_FAILURE);
	}

	//FIFO Infra
	if(access("../common/myfifo",F_OK)==-1)
        {
                res=mkfifo("../common/myfifo",0666);
                if(res==-1)
                {
                        perror("FIFO");
			free(infra);
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
        	perror("Pipe");
		free(infra);
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("Pipe created\n");
#endif

	//Shared Memory Infra
	infra->shmid=shmget((key_t)SMKEY,sizeof(Result),IPC_CREAT|0666);
	if(infra->shmid==-1)
	{
		perror("Shared Memory");
		free(infra);
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("Shared memory segment created\n");
#endif

	//Message Queue Infra
	infra->mqid=msgget((key_t)MQKEY, IPC_CREAT|0666);
	if(infra->mqid==-1)
	{
		perror("Message Queue");
		free(infra);
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("Message Queue created\n");
#endif

/*	//Semaphore Create	
	infra->semid=semget((key_t)SEMKEY, 4, IPC_CREAT|0666);
	if(infra->semid==-1)
	{
		perror("Semaphore");
		free(infra);
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("Semaphore created\n");
#endif


	//Semaphore Initialization
	for(int i=0; i<4;i++)
	{
		se[i].val=1;
		printf("Value:%d\n",i);
		if(semctl(infra->semid,i,SETVAL,se[i])==-1)
		{
			perror("SEMCTL");
			free(infra);
			exit(EXIT_FAILURE);
		}

	}

*/
	//Thread Semaphore creation and initializtion
	if (sem_init(&infra->sem, 0, 1)==-1)
	{
		perror("SEM_INIT");
                free(infra);
                exit(EXIT_FAILURE);
	}
	
	//Shared Memory Infra
	infra->shmadd=shmget((key_t)SMADKEY,sizeof(sem_t),IPC_CREAT|0666);
	if(infra->shmadd==-1)
	{
		perror("Shared Memory Semaphore");
		free(infra);
		exit(EXIT_FAILURE);
	}
	
	infra->semven=(sem_t*) shmat(infra->shmadd,NULL,0);
        if(infra->semven==(sem_t*)-1)
        {
                perror("SHMAT");
                exit(EXIT_FAILURE);
        }

/*	infra->semven=(sem_t*)malloc(sizeof(sem_t));
	if(infra->semven==NULL)
	{
		perror("Mallic");
		exit(EXIT_FAILURE);

	}
*/
	//Thread Semaphore for across the process
	if (sem_init(infra->semven,1,1)==-1)
	{
		perror("SEM_VEN_INIT");
                free(infra);
                exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("Thread Semaphore created.\n");
#endif

	//Mutex initialization
	if (pthread_mutex_init(&infra->mutexid,NULL)!=0)
	{
		perror("PTHREAD_MUTEX_INIT");
                free(infra);
                exit(EXIT_FAILURE);
	}
	

#ifdef DEBUG
	printf("Mutex created.\n");
#endif


#ifdef DEBUG
        printf("%s End.\n",__func__);
#endif

	return (void*)infra;

}
