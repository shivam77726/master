#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


int main()
{
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
