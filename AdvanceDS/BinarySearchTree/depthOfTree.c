#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"
int depth=0;


void* depthOfTree(void* arg)
{
	Node *tree=(Node*)arg;

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	static int tmp=0;
        if(tree)
        {
		int count=tmp;
		tmp++;
		if(tree->Left)
		{
                	depthOfTree((void*)tree->Left);
			tmp=count++;
		}

		if(tree->Right)
	                depthOfTree((void*)tree->Right);
		
		if(depth<tmp)
			depth=tmp;

#ifdef DEBUG
		printf("Depth:%d\n",depth);
#endif

        }
	tmp=0;


#ifdef DEBUG
	printf("%s End\n",__func__);
#endif
	return (void*)0;
}
