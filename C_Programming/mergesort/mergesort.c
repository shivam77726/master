#include "headers.h"

void merge(int *arr,int l,int m, int h)
{
	int *first, *second;
	int len1=m-l;
	int len2=h-m-1;
	int index1=0,index2=0,mainindex=l;


	first= (int*) malloc(sizeof(int)*len1);
	second= (int*) malloc(sizeof(int)*len2);
	

	printf("\nlen1:%d,len2:%d,l:%d,m:%d,h:%d\n",len1,len2,l,m,h);
	//Copying from main array
	for(int i=0;i<=len1;i++)
	{
		first[i]=arr[mainindex++];
		printf("%d\t",first[i]);
	}

	printf("\n");

	for(int i=0;i<=len2;i++)
	{
		second[i]=arr[mainindex++];
		printf("%d\t",second[i]);
	}
	printf("\n\n");

	//Sorting Array
	mainindex=l;

	while(index1<=len1 && index2<=len2)
	{
		if(first[index1]>second[index2])
			arr[mainindex++]=second[index2++];
		else
			arr[mainindex++]=first[index1++];
	}

	while(index1<=len1)
		arr[mainindex++]=first[index1++];

	while(index2<len2)
		arr[mainindex++]=second[index2++];

	free(first);
	free(second);



}

void mergesort(int *arr,int l, int h)
{
	int m=(h+l)/2;
	if(l>=h)
	{
		return;
	}

	mergesort(arr,l,m);
	mergesort(arr,m+1,h);
	merge(arr,l,m,h);

}


