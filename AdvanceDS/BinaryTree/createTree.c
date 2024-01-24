#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void** 	createTree(void** arg)
{
	Node **tree=(Node**)arg;
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif


	if(!tree)
	{
		printf("Creating root node of the tree\n");
		tree=(Node**)malloc(sizeof(Node*) * 3);
		if(!tree)
		{
			perror("Tree Memory allocation");
			(fun_ptr1[4])((void**)tree);                    //Exit

		}
		memset(tree,'\0',3);
		*tree=NULL;
		printf("Zero node tree value:%d,%d\n",*tree,tree);
		
		*(tree+1)=(Node*)fun_ptr[1]((void*)0);		//Creating Node
		if(!(*(tree+1)))
			(fun_ptr1[4])((void**)tree);                    //Exit
		
		printf("Enter value of root node:");
		scanf("%d",&(*(tree+1))->Value);
		(*(tree+1))->Status=0;
#ifdef DEBUG
		printf("Parent node address:%d\n",(*(tree+1))->Parent);
		printf("Value of root node:%d\n",(*(tree+1))->Value);
		printf("Status:%d\n",(*(tree+1))->Status);
		//printf("Left child node address:%d\n",(tree+1)->Child);
		//printf("Right child node address:%d\n",(*(tree+1))->Child[1]);
#endif

	}


#ifdef DEBUG
	printf("%s End\n",__func__);
#endif
	return (void**)tree;
}
