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
	semun *su[4];


	infra=arg;

#ifdef DEBUG
        printf("%s Begin.\n",__func__);
#endif
	
	msg=(Msg*)malloc(sizeof(Msg));
	if(msg==NULL)
	{
        	printf("malloc");
                exit(EXIT_FAILURE);
	}


	fd=open("../common/myfifo",O_RDONLY);
        if(fd==-1)
        {
        	printf("OPEN");
                free(msg);
		exit(EXIT_FAILURE);
        }
        printf("%s File opened\n",__FILE__);

	res=read(fd,msg,sizeof(Msg));
        if(res==-1)
        {
        	printf("READ");
		free(msg);
		close(fd);
                exit(EXIT_FAILURE);
        }
        printf("%s CPID:%ld\n",__FILE__,msg->cpid);
	if(msg->cpid==0)
	{
		return (void*)msg;
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
        				printf("%s CPID:%ld\n",__FILE__,msg->cpid);
					sprintf(str,"%d",infra->pfd[0]);
					printf("Adder has been selected\n");
                                        execl("../vendor/adder","adder",str,NULL);
                                        break;

                                default :
					printf("Select correct request type\n");
                        }
			break;
                default:
			if(write(infra->pfd[1],msg,sizeof(Msg))==-1)
			{
        			printf("WRITE\n");
				close(fd);
                		exit(EXIT_FAILURE);
			}

        }

	sleep(1);	
        rslt=(Result*) shmat(infra->shmid,NULL,0);
        if(rslt==(Result*)-1)
        {
                perror("Pointer not attatched to shared memory\n");
                exit(EXIT_FAILURE);
        }
        printf("%s Shared memory attatched to pointer\n",__FILE__);
        printf("Client PID:%ld\nResult:%f\n",rslt->cpid,rslt->result);

	if(msgsnd(infra->mqid,(void*)rslt,sizeof(float),0)==-1)
	{
		perror("Message not sent\n");
		exit(EXIT_FAILURE);
	}
        printf("%s Message sent into MQ\n",__FILE__);

        if(shmdt((Result*)rslt)==-1)
        {
                perror("shmdt\n");
                exit(EXIT_FAILURE);
        }
        printf("%s Shared memory dettatched to pointer\n",__FILE__);



	close(fd);



#ifdef DEBUG
        printf("%s End.\n",__func__);
#endif


	return (void*)msg;


}
