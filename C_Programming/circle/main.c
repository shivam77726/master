#include "headers.h"
#include "declaration.h"

int main()
{
	float r;
	//const float pi=22.0/7.0;
	printf("Enter radius of Circle:");
	scanf("%f",&r);
	printf("Area of Circle:%f\n",area(r));
	printf("Perimeter of Circle:%f\n",perimeter(r));
	return 0;
}
