#include "../common/headers.h"
#include "../common/declaration.h"
#include "../common/dataStructure.h"
#include "../common/defaults.h"


int main()
{
        int res,fd,msgkey;
	Msg msg;
	Mbuf *mbuf;

#ifdef DEBUG
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
	msg.opr1=10.00;
	msg.opr2=10.54;
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
        printf("FIFO already existing\n");

	fd=open("../common/myfifo",O_WRONLY);

        if(fd==-1)
        {
                printf("OPEN");
                exit(EXIT_FAILURE);
        }
        printf("%s FIFO opened\n",__FILE__);

        if(write(fd,&msg,sizeof(Msg))==-1)
        {
                printf("WRITE");
                close(fd);
                exit(EXIT_FAILURE);
        }
        printf("%s FIFO written\n",__FILE__);

	close(fd);

        //Message Queue Infra
        msgkey=msgget((key_t)MQKEY, IPC_CREAT|0666);
        if(msgkey==-1)
        {
                perror("Message Queue\n");
                exit(EXIT_FAILURE);
        }
        printf("%s Message Queue created\n",__FILE__);

        if(msgrcv(msgkey,(Mbuf*)mbuf,sizeof(float),getpid(),0)==-1)
        {
                perror("Message not sent\n");
                exit(EXIT_FAILURE);
        }
        printf("%s Message received from MQ\n",__FILE__);
        
	printf("%s from CPID:%ld Result:%f\n",__FILE__,mbuf->mtype,mbuf->result);


#ifdef DEBUG
        printf("%s End.\n",__func__);
#endif

        return 0;

}

