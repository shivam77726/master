#include "../common/headers.h"
#include"../common/declaration.h"
#include"../common/dataStructure.h"

Infra *infra;
void SIGNAL_HANDLER(int);
int main()
{
	Msg *msg;
	pthread_t thread_id;
	int i=0;
	unsigned short counter=1;
#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif
	signal(SIGINT,SIGNAL_HANDLER);
	infra=(Infra*)createInfra((void*)0);
	system("ipcs");
        while(1)
        {
		//static int counter=1;
		if(sem_wait(&infra->sem)==-1)
		{
			perror("sem_wait");
			return EXIT_FAILURE;
		}

		if(pthread_create(&thread_id,NULL,&processRequest,(void*)infra)!=0)
		{
			perror("pthread_create");
			return EXIT_FAILURE;

		}
                //msg=(Msg*)processRequest((void*)infra);
		//free(msg);
		printf("\nCOUNTER:%hu\n",counter);
		counter++;
        }

	//pthread_exit(NULL);
	free(infra);

#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return 0;
}


void SIGNAL_HANDLER(int sig)
{
	printf("SIGINT:%d signal reaised\n",sig);
	system("unlink ../common/myfifo");
	if(sem_destroy(&infra->sem)==-1)
	{
		perror("sem_destroy");
		exit(EXIT_FAILURE);
	}

	exit(0);
}
