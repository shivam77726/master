#include "headers.h"
#include "declaration.h"

int Time12::addTimes(Time12 a, Time12 b)
{
	if(strcmp(a.MER,"PM")&& a.HR!=12)
		a.HR+=12;
	else if(strcmp(a.MER,"AM")&& a.HR==12)
		a.HR=0;
	if(strcmp(b.MER,"PM") && b.HR!=12)
		b.HR+=12;
	else if(strcmp(b.MER,"AM") && b.HR==12)
		b.HR=0;
        HR=a.HR + b.HR;
        MIN=a.MIN+b.MIN;
        SEC=a.SEC+b.SEC;
        if(SEC>=60)
	{
		MIN++;
		SEC-=60;
	}
	if(MIN>=60)
	{
		HR++;
		MIN-=60;
	}
	if(HR>=24)
		HR-=24;
	if(HR==0)
	{
		strcpy(MER,"AM");
		HR=12;
	}
	else if(HR==12)
		strcpy(MER,"PM");
	else if(HR>12)
	{
		strcpy(MER,"PM");
		HR-=12;
	}
	else
		strcpy(MER,"AM");
        return 0;

}

int Time24::addTimes(Time24 a, Time24 b)
{
        HR=a.HR + b.HR;
	MIN=a.MIN+b.MIN;
	SEC=a.SEC+b.SEC;
	if(SEC>=60)
	{
		MIN++;
		SEC-=60;
	}
	if(MIN>=60)
	{
		HR++;
		MIN-=60;
	}
	if(HR>=24)
		HR-=24;
	return 0;

}
