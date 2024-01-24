#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun{
        int val;
        struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
        unsigned short  *array;  /* Array for GETALL, SETALL */
        struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
}semUnion;
struct sembuf su;

int main()

{
        int keyk;
        keyk=semget((key_t)12 , 1, IPC_CREAT|0666);
        if(keyk==-1)
        {
                printf("Semaphore not created\n");
                perror("semget");
        }
        semUnion.val=1;
        if(semctl(keyk,0,SETVAL,semUnion)<0)
        {
                printf("Semaphore not initialised\n");
                perror("semctl");
        }
        su.sem_num=1;
        su.sem_op=-1;
        su.sem_flg=SEM_UNDO;
        if(semop(keyk,&su,1)==-1)
        {
                printf("Semaphore not operating\n");
                perror("semop");
        }
        return 0;
}

