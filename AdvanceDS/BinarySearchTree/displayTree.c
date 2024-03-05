#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"
int i=0;
void* displayTree(void* arg)
{
	Node *tree=(Node*)arg;

#ifdef DDEBUG
	printf("%s Begin\n",__func__);
#endif

	
        static int tmp=0;
	while(!(i==depth))
	{
        if(tree)
        {
                int count=tmp;
		if(count==i)
		{
			printf("Value:%d\n",tree->Value);
			//return (void*)0;
		}
		
		else
			return (void*)0;
		
                tmp++;
                if(tree->Left)
                {
			i++;
                        displayTree((void*)tree->Left);
                        tmp=count++;
                }

                if(tree->Right)
                        displayTree((void*)tree->Right);

		if(i<tmp)
			i=tmp;


	}
	}



#ifdef DDEBUG
	printf("%s End\n",__func__);
#endif
	return (void*)0;
}
