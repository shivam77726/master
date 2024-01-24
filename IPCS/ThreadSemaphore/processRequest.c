#include "../common/headers.h"
#include"../common/declaration.h"
#include"../common/dataStructure.h"

void* processRequest(void* arg)
{
        int res,fd,fret;
	char str[2];
	Infra *infra;
	Msg *msg;
	Result *rslt;
	struct sembuf sbuf;
	semun se[4];
	int value;
	infra=arg;

#ifdef DEBUG
        printf("%s Begin, Thread Id:%ld.\n",__func__,pthread_self());
#endif
	
	msg=(Msg*)malloc(sizeof(Msg));
	if(msg==NULL)
	{
        	perror("malloc");
                exit(EXIT_FAILURE);
	}


	fd=open("../common/myfifo",O_RDONLY);
        if(fd==-1)
        {
        	perror("OPEN");
                free(msg);
		exit(EXIT_FAILURE);
        }
#ifdef DDEBUG
        printf("%s File opened\n",__FILE__);
#endif

	res=read(fd,msg,sizeof(Msg));
        if(res==-1)
        {
        	perror("READ");
		free(msg);
		close(fd);
                exit(EXIT_FAILURE);
        }
        printf("%s CPID:%ld\n",__FILE__,msg->cpid);

	if(sem_post(&infra->sem)==-1)
	{
		perror("sem_post");
		return (void*)EXIT_FAILURE;
	}

#ifdef DDEBUG
        printf("%s CPID:%ld\n",__FILE__,msg->cpid);
#endif
	if(msg->cpid==0)
	{
		printf("Child PID is Zero\n");
		free(msg);
		return (void*)0;
	}
	
	//printf("FD:%c\t%d\n",str,infra->pfd[0]);
        fret=fork();
        switch(fret)
        {
                case -1:
                        printf("Fork failed\n");
                        break;
                case 0:
                        switch(msg->reqtype)
                        {
                                case '+':
        				//printf("%s CPID:%ld\n",__FILE__,msg->cpid);
					sprintf(str,"%d",infra->pfd[0]);
					//printf("Adder has been selected\n");
                                        execl("../vendor/adder","adder",str,NULL);
                                        break;

                                default :
					printf("Select correct request type\n");
                        }
			break;
                default:
			if(write(infra->pfd[1],msg,sizeof(Msg))==-1)
			{
        			perror("WRITE");
				close(fd);
                		exit(EXIT_FAILURE);
			}
#ifdef DDEBUG
        		printf("%s: Pipe written successfully\n",__FILE__);
#endif

        }
#ifdef DDEBUG
        printf("%s: Accessing Shared Memory\n",__FILE__);
#endif
//	sleep(1);

/*	
	//Wait operation
	sbuf.sem_num=0;
	sbuf.sem_op=0;
	sbuf.sem_flg=SEM_UNDO;
	if(semop(infra->semid,&sbuf,1)==-1)
	{
		perror("semop");
		close(fd);
		exit(EXIT_FAILURE);
	}*/

/*	if(sem_getvalue(infra->semven,&value)==-1)
        {
                perror("sem_getvalue shared memory");
                return (void*)EXIT_FAILURE;
        }
        printf("Value of semaphore:%d\n",value);
	
	if(sem_wait(infra->semven)==-1)
        {
        	perror("sem_wait shared memory");
        	return (void*)EXIT_FAILURE;
	}
	
	if(sem_getvalue(infra->semven,&value)==-1)
        {
                perror("sem_getvalue shared memory");
                return (void*)EXIT_FAILURE;
        }
        printf("Value of semaphore:%d\n",value);
*/
        //Mutex lock
        if (pthread_mutex_lock(&infra->mutexid)!=0)
        {
                perror("PTHREAD_MUTEX_LOCK");
                free(infra);
                exit(EXIT_FAILURE);
        }


	wait(NULL);
        rslt=(Result*) shmat(infra->shmid,NULL,0);
        if(rslt==(Result*)-1)
        {
                perror("SHMAT");
                exit(EXIT_FAILURE);
        }
#ifdef DDEBUG
        printf("%s Shared memory attatched to pointer\n",__FILE__);
#endif
#ifdef DDEBUG
	printf("ThreadId:%ld\tCPID:%ld,Result:%f\n",pthread_self(),rslt->cpid,rslt->result);
#endif

/*	//Signal operation
	sbuf.sem_num=0;
	sbuf.sem_op=1;
	sbuf.sem_flg=SEM_UNDO;
	if(semop(infra->semid,&sbuf,1)==-1)
	{
		perror("semop");
		close(fd);
		exit(EXIT_FAILURE);
	}
*/


	if(msgsnd(infra->mqid,(void*)rslt,sizeof(float),0)==-1)
	{
		perror("Message not sent\n");
		exit(EXIT_FAILURE);
	}
#ifdef DDEBUG
       	printf("%s Thread:%ld Message sent into MQ\n",__FILE__,pthread_self());
#endif
	
	//Sem Post
	if(sem_post(infra->semven)==-1)
        {
        	perror("sem_post shared memory");
        	return (void*)EXIT_FAILURE;
	}

        //Mutex unlock
        if (pthread_mutex_unlock(&infra->mutexid)!=0)
        {
                perror("PTHREAD_MUTEX_UNLOCK");
                free(infra);
                exit(EXIT_FAILURE);
        }

        if(shmdt((Result*)rslt)==-1)
        {
                perror("shmdt\n");
                exit(EXIT_FAILURE);
        }
#ifdef DDEBUG
        printf("%s Shared memory dettatched to pointer\n",__FILE__);
#endif


	close(fd);
	free(msg);


#ifdef DEBUG
        printf("%s End.\n",__func__);
#endif


	return (void*)0;


}
