#include "headers.h"
#include "dataStruct.h"
#include "defaults.h"
#include "declarations.h"

int creatInfra()
{
	int ret;
	Infra *infra;
	Result result;
#ifdef DEBUG
	printf("%s : %s : Begin\n", __FILE__, __func__);
#endif
	//Allocating Space for Structure Infra using malloc
	infra = (Infra*)malloc(sizeof(Infra));
	if (!infra)
	{
		perror("malloc");
		return EXIT_FAILURE;
		//(*fptr[0])((void*)"failure"); //exitServer
	}
	
	//Allocating space for Pipe's writer and reader
	infra->pipe = (int*)malloc(sizeof(int)*2);
	if(!infra->pipe)
	{
		perror("malloc");
		free(infra);
		//(*fptr[0])((void*)"failure"); //exitServer
		return EXIT_FAILURE;
	}
	
	//Create Pipe
	ret = pipe(infra->pipe);
	if (ret == -1)
	{
		perror("pipe");
		free(infra->pipe);
		free(infra);
		//(*fptr[0])((void*)"failure"); //exitServer
		return EXIT_FAILURE;
	}

	//Creat FIFO
	ret = mkfifo(FIFONAME, 0666);
	if (ret == -1)
	{
		perror("mkfifo");
		close(infra->pipe[0]);
		close(infra->pipe[1]);
                free(infra->pipe);
                free(infra);
                //(*fptr[0])((void*)"failure"); //exitServer
		return EXIT_FAILURE;
	}
	
	//Allocating space for fifo name
	infra->fifo = (char*)malloc(sizeof(char)*20);	
	if(!infra->fifo)
	{
		perror("malloc");
		close(infra->pipe[0]);
		close(infra->pipe[1]);
                free(infra->pipe);
                free(infra);
                //(*fptr[0])((void*)"failure"); //exitServer
		return EXIT_FAILURE;
	}
	int i;
	//Filling the above allocated space with '\0'
	for(i=0; i<20; i++)
	{
		infra->fifo[i] = '\0';
	}	
	strcpy(infra->fifo, FIFONAME); //Filling infre->fifo with actual fif name
	//Creat MQ
	infra->msgQue = msgget((key_t)MSQKEY, IPC_CREAT|0666);
	if(infra->msgQue == -1)
	{
		perror("msgget");
		close(infra->pipe[0]);
                close(infra->pipe[1]);
                free(infra->pipe);
                free(infra);
                //(*fptr[0])((void*)"failure"); //exitServer
		return EXIT_FAILURE;
	}

	//Create SM
	infra->srdMem = shmget((key_t)SHMKEY, sizeof(Result), IPC_CREAT|0666); 
	if(infra->srdMem == -1)
	{
		perror("shmget");
		close(infra->pipe[0]);
                close(infra->pipe[1]);
                free(infra->pipe);
                free(infra->fifo);
                free(infra);
		return EXIT_FAILURE;
	}
	//Attaching SMS
	infra->smptr = shmat(infra->srdMem, NULL, 0);

	//Creating Semaphore
       	infra->semid = semget(SEMID, 4, 0666|IPC_CREAT); //Creates Semaphore
        if(infra->semid == -1)
        {
                perror("semget");
		close(infra->pipe[0]);
                close(infra->pipe[1]);
                free(infra->pipe);
                free(infra->fifo);
                free(infra);
		//(*fptr[0])((void*)"failure"); //exitServer
		return EXIT_FAILURE;
        }
        //system("ipcs");
	//Initializing Semaphore
 	for(i=0; i<4; i++)
        {
                infra->semval[i].val = 1;
                if(semctl(infra->semid, i, SETVAL, infra->semval[i]) < 0)
                {
                        perror("semctl");
			close(infra->pipe[0]);
	                close(infra->pipe[1]);
                	free(infra->pipe);
                	free(infra->fifo);
                	free(infra);
                	//(*fptr[0])((void*)"failure"); //exitServer
			return EXIT_FAILURE;
                }
        }
	

#ifdef DEBUG
	printf("%s : %s : End\n", __FILE__, __func__);
#endif
	return 0;
}
