#include "headers.h"
#include "declarations.h"
#include "dataStructure.h"

void* createNode(void* arg)
{
	Node *node;
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

	node=(Node*)malloc(sizeof(Node));
	if(!node)
	{
		perror("Node Memory");
		return (void*)NULL;
	}
	memset(node,'\0',sizeof(Node));

	printf("Enter the value of Node:");
        scanf("%d",&node->Value);
        node->Left=NULL;
        node->Right=NULL;
	node->bf=0;


#ifdef DEBUG
	printf("%s End\n",__func__);
#endif
	return (void*) node;
}
