#include "../common/headers.h"
#include "../common/declaration.h"
#include "../common/dataStructure.h"
#include "../common/defaults.h"

void* adder(void*);

int main(int argc, char* argv[])
{
	int fd;
	pthread_t thread_id;	
	
#ifdef DDEBUG
        printf("%s Child Begin.\n",__func__);
#endif

	if(argc<2)
	{
		printf("Argument insufficient\n");
		exit(EXIT_FAILURE);
	}

	fd=atoi(argv[1]);
#ifdef DDEBUG
	printf("FD:%c\t%d\n",*argv[1],fd);
#endif


        if(pthread_create(&thread_id,NULL,&adder,(void*)&fd)!=0)
        {
	        perror("pthread_create");
                return EXIT_FAILURE;

        }

	pthread_join(thread_id,NULL);

#ifdef DDEBUG
        printf("%s Child End.\n",__func__);
#endif

	exit(0);
        return 0;

}


void* adder(void* file)
{
	int fd,res,shmkey,shmadd,value;
	Msg msg;
	sem_t *semven;
	Result *rslt;
	//struct sembuf sbuf;
	//semun se[4];
	fd=*(int*)file;
        if(read(fd,&msg,sizeof(Msg))==-1)
        {
	        printf("READ\n");
                close(fd);
                exit(EXIT_FAILURE);
        }
#ifdef DDEBUG
	printf("%s Child CPID:%ld",__FILE__,msg.cpid);
#endif


	//Shared Memory Create
        shmkey=shmget((key_t)SMKEY,sizeof(Result),IPC_CREAT|0666);
        if(shmkey==-1)
        {
                perror("Shared Memory");
                exit(EXIT_FAILURE);
        }
#ifdef DDEBUG
        printf("Shared memory segment created\n");
#endif

/*	//Semaphore Create
        semid=semget((key_t)SEMKEY, 4, IPC_CREAT|0666);
        if(semid==-1)
        {
                perror("Semaphore:\n");
                exit(EXIT_FAILURE);
        }
#ifdef DEBUG
        printf("Semaphore created\n");
#endif


	//Semaphore initialization
        for(int i=0; i<4;i++)
        {
                se[i].val=1;
                if(semctl(semid,i,SETVAL,se[i])==-1)
                {
                        perror("SEMCTL:\n");
                        exit(EXIT_FAILURE);
                }

        }
	

	//wait operation
        sbuf.sem_num=0;
        sbuf.sem_op=-1;
        sbuf.sem_flg=SEM_UNDO;
        if(semop(semid,&sbuf,1)==-1)
        {
                perror("semop:\n");
                close(fd);
                exit(EXIT_FAILURE);
        }
*/

        //Shared Memory Infra for semaphore
        shmadd=shmget((key_t)SMADKEY,sizeof(sem_t),IPC_CREAT|0666);
        if(shmadd==-1)
        {
                perror("Shared Memory semaphore");
                exit(EXIT_FAILURE);
        }

        semven=(sem_t*)shmat(shmadd,NULL,0);
        if(semven==(sem_t*)-1)
        {
                perror("SHMAT semaphore");
                exit(EXIT_FAILURE);
        }

/*        //Thread Semaphore for across the process
        if (sem_init(semven,1,0)==-1)
        {
                perror("SEM_VEN_INIT");
                exit(EXIT_FAILURE);
        }
*/
	//SEM WAIT
        if(sem_wait(semven)==-1)
        {
                perror("sem_wait shared memory");
                return (void*)EXIT_FAILURE;
        }


	//Critical region (writing data into shared memory)
	rslt=(Result*) shmat(shmkey,NULL,0);
	if(rslt==(Result*)-1)
	{
		perror("Pointer not attatched to shared memory\n");
		exit(EXIT_FAILURE);
	}
#ifdef DDEBUG
	printf("%s Shared memory attatched to pointer\n",__FILE__);
#endif
	
	rslt->result=msg.opr1+msg.opr2;
	rslt->cpid=msg.cpid;
	printf("%s Client PID:%ld\tResult:%f\n",__FILE__,rslt->cpid,rslt->result);

/*        if(sem_getvalue(semven,&value)==-1)
        {
                perror("sem_getvalue shared memory");
                return (void*)EXIT_FAILURE;
        }
	printf("Value of semaphore:%d\n",value);

        if(sem_post(semven)==-1)
        {
                perror("sem_post shared memory");
                return (void*)EXIT_FAILURE;
        }
*/
        if(sem_getvalue(semven,&value)==-1)
        {
                perror("sem_getvalue shared memory");
                return (void*)EXIT_FAILURE;
        }

/*	//signal operation
        sbuf.sem_num=0;
        sbuf.sem_op=1;
        sbuf.sem_flg=SEM_UNDO;
        if(semop(semid,&sbuf,1)==-1)
        {
                perror("semop:\n");
                close(fd);
                exit(EXIT_FAILURE);
        }

*/
	//detaching shared memory pointer
	if(shmdt((Result*)rslt)==-1)
	{
		perror("shmdt\n");
		exit(EXIT_FAILURE);
	}
#ifdef DDEBUG
	printf("%s Shared memory dettatched to pointer\n",__FILE__);
	printf("%s Semaphore value:%d\n",__FILE__,value);
#endif
	pthread_exit(NULL);
	return (void*)0;

}
