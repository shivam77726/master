#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

void sigsegv_handler(int signal) {
    printf("Segmentation fault occurred. Exiting.\n");
    exit(EXIT_FAILURE);
}
int main()
{
	if (signal(SIGSEGV, sigsegv_handler) == SIG_ERR) 
	{
        	perror("Unable to set up signal handler");
        	exit(EXIT_FAILURE);
	}

#ifdef DEBUG
	printf("%s Begin.\n",__func__);
#endif
	Node* root;
	root=NULL;
	init();
	while(1)
	{
		root=(Node*)fptr[1]((void*)root);	//mainMenu
	}


#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return 0;
}
