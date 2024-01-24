#include "../common/headers.h"
#include"../common/declaration.h"
#include"../common/dataStructure.h"

void SIGNAL_HANDLER(int);
int main()
{
	Msg *msg;
	Infra *infra;
#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif
	signal(SIGINT,SIGNAL_HANDLER);
	infra=(Infra*)createInfra((void*)0);
        while(1)
        {
		static int counter=1;
		printf("\nCOUNTER:%d\n",counter);
                msg=(Msg*)processRequest((void*)infra);
		free(msg);
		counter++;
        }

	free(infra);

#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return 0;
}


void SIGNAL_HANDLER(int sig)
{
	printf("SIGINT:%d signal reaised\n",sig);
	exit(0);
}
