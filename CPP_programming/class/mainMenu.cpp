#include "headers.h"
#include "declaration.h"

int Menu::mainMenu()
{
	int choice;
	cout<<"Choose options:"<<endl;
	cout<<"1. Calculate Distance in feet/inch"<<endl;
	cout<<"2. Calculate Distance in meter/centimeter"<<endl;
	cout<<"3. Calculate Time in 12 hour format"<<endl;
	cout<<"4. Calculate Time in 24 hour format"<<endl;
	cout<<"0. Exit"<<endl;
	cin>>choice;
	return choice;
}
