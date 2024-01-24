#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

void* ExitProgram(void* arg)
{

	Node *strt,*tmp;
	strt=(Node*)arg;

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	
	while(strt)
	{
		tmp=strt;
		strt=strt->next;
		free(tmp);
	}
	/*if(strncmp((char*)arg,"success",7)==0)
		exit (EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);*/

#ifdef DEBUG
        printf("%s End\n",__func__);
#endif
	exit(1);
	return 0;
}
