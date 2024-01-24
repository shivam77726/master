#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

int main()
{


	Node *start=NULL;
	
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	init();
	start=(Node*)(*fun_ptr[1])((void*)start);

#ifdef DEBUG
        printf("%s End\n",__func__);
#endif
	return 0;
}
