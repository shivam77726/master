#include "headers.h"
#include "declaration.h"

int Time12::getTime()
{
	while(1)
	{
		cout<<"Enter Time 12 hour format (HH/MM/SS AM/PM):"<<endl;
		cout<<"HH:";
		cin>>HR;
		if(HR>12 || HR<1)
		{
			printf("Give Hour between 1-12\n");
			continue;
		}
		cout<<"MM:";
		cin>>MIN;
		if(MIN>59 || MIN<0)
		{
			printf("Give Minute between 0-59\n");
			continue;
		}
		cout<<"SS:";
		cin>>SEC;
		if(SEC>59 || SEC<0)
		{
			printf("Give Second between 0-59\n");
			continue;
		}
		cout<<"AM/PM:";
		cin>>MER;
		//cout<<(strcmp(MER,"AM"))<<endl;
		//cout<<(strcmp(MER,"PM"))<<endl;
		if(strcmp(MER,"AM") && strcmp(MER,"PM") )
		{
			printf("Give Meridian AM/PM\n");
			continue;
		}
		break;
	}


	return 0;
}



int Time24::getTime()
{	
	while(1)
	{
		cout<<"Enter Time 24 hour format (HH/MM/SS ):"<<endl;
		cout<<"HH:";
		cin>>HR;
		if(HR>23 || HR<0)
		{
			printf("Give Hour between 0-23\n");
			continue;
		}
		cout<<"MM:";
		cin>>MIN;
		if(MIN>59 || MIN<0)
		{
			printf("Give Minute between 0-59\n");
			continue;
		}
		cout<<"SS:";
		cin>>SEC;
		if(SEC>59 || SEC<0)
		{
			printf("Give Second between 0-59\n");
			continue;
		}
		break;
	}

	return 0;
}
