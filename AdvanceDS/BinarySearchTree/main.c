#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

int main()
{
	Node* tree=NULL;
#ifdef DEBUG
        printf("%s begin\n",__func__);
#endif
	tree=(Node*) mainMenu((void*)tree);


#ifdef DEBUG
        printf("%s End\n",__func__);
#endif

	return 0;
}
