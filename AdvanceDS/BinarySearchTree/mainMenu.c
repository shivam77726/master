#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void* mainMenu (void* arg)
{
	Node* tree=(Node*)arg;
	unsigned short choice;
#ifdef DEBUG
        printf("%s begin\n",__func__);
#endif

	while(1)
	{
		printf("\n---------------- Choice----------\n");
		printf("0. Exit\n");
		printf("1. Create Tree \n");
		printf("2. Insert Tree Node\n");
		printf("3. Inorder Traversal\n");
		printf("4. Preorder Traversal\n");
		printf("5. Postorder Traversal\n");
		printf("--------------------------------\n");
		printf("\nEnter Choice:");
		scanf("%hu",&choice);
		printf("\n\n");
		switch(choice)
		{
			case 0:
				deleteTree((void*)tree);				//Delete Tree
				return (void*)0;
				break;
			case 1:
				tree=(Node*)createTree((void*)tree);			//Create Tree
				break;
			case 2:
				tree=(Node*)insertNode((void*)tree);			//Insert Node
				break;
			case 3:
				inOrderTraversal((void*)tree);				//In Order Traversal
				break;
			case 4:
				preOrderTraversal((void*)tree);				//Pre Order Traversal
				break;
			case 5:
				postOrderTraversal((void*)tree);			//Post Order Traversal
				break;
			default:
				printf("Please Enter Valid Choice (between 0-2)\n");
				break;
		}
	}



#ifdef DEBUG
        printf("%s End\n",__func__);
#endif

	return (void*)tree;
}
