#include "headers.h"
#include "declaration.h"


int main()
{
	int *arr;
	int n;
	
	//allocate array
	arr=(int*)malloc(sizeof(int)*n);
	if(arr==NULL)
	{
		printf("Memory not allocated");
		return -1;
	}
	
	//Enter Array Input
	printf("Enter no of Array Elements wants to input:");
	scanf("%d",&n);
	


	//Enter elements
	printf("Input Elements\n");
	for (int i=0; i<n;i++)
	{
		printf("Enter Element %d:",i);
		scanf("%d",&arr[i]);
	}

	
	//Array
	printf("\nArray\n");
	for(int i=0; i<n;i++)
	{
		printf("%d\t",arr[i]);
	}

	printf("\n");

	//Sorting
	mergesort(arr,0,n-1);
	
	printf("\nSorted Array\n");
	for(int i=0; i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	
	free(arr);
	printf("\n");
	return 0;
}
