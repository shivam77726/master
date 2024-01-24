#include<stdio.h>
#define p(a,b) a##b
#define call(x) #x


int main(){

	int i=4,j=1;
	for (i=0;*(call(765)+i);i++)
	printf("%d\t%c\n",p(i+-,-j),*(call(675)+3));

	return 0;
}

