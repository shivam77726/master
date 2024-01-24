#include "headers.h"
#include "declaration.h"

int main()
{
	fDistance D1,D2,D3;
	mDistance d1,d2,d3;
	Time12 T1,T2,T3;
	Time24 t1,t2,t3;
	Menu m;
	int choice=1;
	while(choice)
	{
		choice=m.mainMenu();
		switch(choice)
		{
			case 0: break;
			case 1:	D1.getDistance();
				D2.getDistance();
				D3.addDistances(D1,D2);
				D1.getDisplay();
				cout<<"+";
				D2.getDisplay();
				cout<<"=";
				D3.getDisplay();
				cout<<endl;
				break;

			case 2:	d1.getDistance();
				d2.getDistance();
				d3.addDistances(d1,d2);
				d1.getDisplay();
				cout<<"+";
				d2.getDisplay();
				cout<<"=";
				d3.getDisplay();
				cout<<endl;
				break;

			case 3:	T1.getTime();
				T2.getTime();
				T3.addTimes(T1,T2);
				T1.timeDisplay();
				T2.timeDisplay();
				T3.timeDisplay();
				cout<<endl;
				break;

			case 4:	t1.getTime();
				t2.getTime();
				t3.addTimes(t1,t2);
				t1.timeDisplay();
				t2.timeDisplay();
				t3.timeDisplay();
				cout<<endl;
				break;

			default: printf("Choose correct option\n");
		}
	}

	return 0;
}
