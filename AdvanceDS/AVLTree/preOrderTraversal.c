#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void* preOrderTraversal(void* arg)
{
	Node *tree=(Node*)arg;

#ifdef DDEBUG
	printf("%s Begin\n",__func__);
#endif

        if(tree)
        {
                printf("%d\t",tree->Value);
                preOrderTraversal((void*)tree->Left);
                preOrderTraversal((void*)tree->Right);
        }




#ifdef DDEBUG
	printf("%s End\n",__func__);
#endif
	return (void*)0;
}
