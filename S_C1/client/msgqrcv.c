#include "../common/headers.h"
#include "../common/declaration.h"
#include "../common/dataStructure.h"
#include "../common/defaults.h"


int main()
{
        int msgkey;
	Mbuf *mbuf;

#ifdef DDEBUG
 	printf("%s Begin.\n",__func__);
#endif
	
 	printf("%s PID:%d.\n",__FILE__,getpid());

        mbuf=(Mbuf*)malloc(sizeof(Mbuf));
        if(mbuf==NULL)
        {
                printf("Malloc space not created\n");
                exit(EXIT_FAILURE);
        }



        //Message Queue Infra
        msgkey=msgget((key_t)MQKEY, IPC_CREAT|0666);
        if(msgkey==-1)
        {
                perror("Message Queue\n");
                exit(EXIT_FAILURE);
        }
        printf("%d Message Queue created\n",getpid());
#ifdef DDEBUG
        printf("%s Message Queue created\n",__FILE__);
#endif

	for (int i=0;i<2;i++)
	{
        if(msgrcv(msgkey,(Mbuf*)mbuf,sizeof(float),0,0)==-1)
        {
                perror("Message not sent\n");
                exit(EXIT_FAILURE);
        }
        printf("%d Message received from MQ %ld\n",getpid(),mbuf->mtype);

 
	printf("%s from CPID:%ld Result:%f\n",__FILE__,mbuf->mtype,mbuf->result);

	}


#ifdef DDEBUG
        printf("%s End.\n",__func__);
#endif

        return 0;

}

