#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void* getBalanceFactor(void* arg)
{
	Node *tree=(Node*)arg;
	int hl,hr;

#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

	printf("%s Begin\n",__func__);
	if(tree)
	{
		//depth=0;
		hl=*(int*)depthOfTree((void*)tree->Left);
		//depth=0;
		hr=*(int*)depthOfTree((void*)tree->Right);
		tree->bf=hl-hr;
		printf("\n\nLeft Tree:%d\tRight Tree:%d\n\n",tree->Left,tree->Right);
		printf("\n\nHeight Of Left Tree:%d\tHeight Of Right Tree:%d\n\n",hl,hr);
		printf("\n\nData:%d\tBalanced Factor:%d\n\n",tree->Value,tree->bf);
		getBalanceFactor((void*)tree->Left);
		getBalanceFactor((void*)tree->Right);
	}



	printf("%s End\n",__func__);

#ifdef DEBUG
        printf("%s End\n",__func__);
#endif

	return (void*)0;
}
