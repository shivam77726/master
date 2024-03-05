#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void* postOrderTraversal(void* arg)
{
	Node *tree=(Node*)arg;

#ifdef DDEBUG
	printf("%s Begin\n",__func__);
#endif

        if(tree)
        {
                postOrderTraversal((void*)tree->Left);
                postOrderTraversal((void*)tree->Right);
                printf("%d\t",tree->Value);
        }



#ifdef DDEBUG
	printf("%s End\n",__func__);
#endif
	return (void*)0;
}
