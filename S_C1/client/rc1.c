#include "../common/headers.h"
#include "../common/declaration.h"
#include "../common/dataStructure.h"
#include "../common/defaults.h"


int main()
{
        int res,fd,msgkey;
	Msg msg;
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

	msg.cpid=getpid();
	msg.opr1=12.00;
	msg.opr2=13.54;
	msg.reqtype='+';
        if(access("../common/myfifo",F_OK)==-1)
        {
                res=mkfifo("../common/myfifo",0666);
                if(res==-1)
                {
                        printf("FIFO");
                        exit(EXIT_FAILURE);
                }
                printf("FIFO created\n");
        }
#ifdef DDEBUG
        printf("FIFO already existing\n");
#endif

	fd=open("../common/myfifo",O_WRONLY);

        if(fd==-1)
        {
                perror("OPEN");
                exit(EXIT_FAILURE);
        }
#ifdef DDEBUG
        printf("%s FIFO opened\n",__FILE__);
#endif

        if(write(fd,&msg,sizeof(Msg))==-1)
        {
                perror("WRITE");
                close(fd);
                exit(EXIT_FAILURE);
        }
#ifdef DDEBUG
        printf("%s FIFO written\n",__FILE__);
#endif


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

        if(msgrcv(msgkey,(Mbuf*)mbuf,sizeof(float),getpid(),0)==-1)
        {
                perror("Message not sent\n");
                exit(EXIT_FAILURE);
        }
        printf("%d Message received from MQ %ld\n",getpid(),mbuf->mtype);

#ifdef DDEBUG 
	printf("%s from CPID:%ld Result:%f\n",__FILE__,mbuf->mtype,mbuf->result);
#endif
	

	if(close(fd)==-1)
	{
		printf("Not able to close fd\n");
	}

#ifdef DDEBUG
        printf("%s End.\n",__func__);
#endif

        return 0;

}

