#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void** 	insertNode(void** arg)
{
	Node **tree=(Node**)arg;
	unsigned short i=0,n=0;
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif


	if(!tree)
	{
		printf("Tree Not present\n");
		exit(1);
	}

	*tree=(Node*)fun_ptr[1]((void*)0);          //Creating Node
	if(!(*tree))
       		(fun_ptr1[4])((void**)tree);                    //Exit
	
	
	while(*(tree + n++))
	{
		if(!(*(tree+2*n)))
		{
			//Left Child
			printf("Inserting left child of %huth node\n",n);
			tree=(Node**)realloc(tree,sizeof(Node*)*(2*n+2));
	                if(!tree)
	                {
        	                perror("Tree Memory allocation");
                	        (fun_ptr1[4])((void**)tree);                    //Exit
				
               		}
			memset(tree+2*n+1,'\0',2);
			(*tree)->Parent =(struct Node*) *(tree+n);
	                printf("Enter value left node:");
	                scanf("%d",&(*tree)->Value);
			*(tree+2*n)=*tree;
			

			//Right Child
			*tree=(Node*)fun_ptr[1]((void*)0);          //Creating Node
			if(!(*tree))
       				(fun_ptr1[4])((void**)tree);                    //Exit
			
			printf("Inserting right child of %huth node\n",n);
			(*tree)->Parent =(struct Node*) *(tree+n);	
	                printf("Enter value right node:");
	                scanf("%d",&(*tree)->Value);
			*(tree+2*n+1)=*tree;
			*tree=NULL;

			(*(tree+n))->Child =(struct Node**) (tree+2*n);
			//(*(tree+n))->Child[1] =(struct Node*) *(tree+2*n+1);

			break;
		}

/*		if(!(*(tree+2*n+1)))
		{
			break;
		}
*/
	}


#ifdef DEBUG
	printf("%s End\n",__func__);
#endif
	return (void**)tree;
}
