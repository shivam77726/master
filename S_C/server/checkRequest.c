#include "../common/headers.h"
#include"../common/declaration.h"
#include"../common/dataStructure.h"

void* checkRequest(void* arg)
{
        int res,pipefd[22],fret;
	Infra *infra;
	Msg *msg=arg;
#ifdef DEBUG
        printf("%s Begin.\n",__func__);
#endif
	
	fret=fork();
	//printf("CPID:%ld\nRequest type:%c\n",msg->cpid,msg->reqtype);
	switch(fret)
	{
		case -1:
			printf("Fork failed\n");
			break;	
		case 0:	
			switch(msg->reqtype)
			{
				case '+': printf("Adder has been selected\n");
					 //exec("../vendor/adder.c","adder.c",
		 		 	break;

				default : printf("Select correct request type\n");
			}
		default:

	}
	


#ifdef DEBUG
        printf("%s End.\n",__func__);
#endif


	return (void*)infra;


}
