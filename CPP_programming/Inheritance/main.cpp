#include "includes.h" 
#include "class.h"


int main()
{
	stackImp stk;
	unsigned short n,choice;
	
	stk.createStack();
	while(1)
	{
		cout << "--------Enter a choice-------"<<endl;
		cout << "0. Exit"<<endl;
		cout << "1. Push Element"<<endl;
		cout << "2. Pop Element"<<endl;
		cout << "3. Display Element"<<endl;

		cin >> choice;
		switch(choice)
		{
			case 0 :
				exit(0);
				break;
			case 1:
lebelpush:			cout << "Enter the no of elements want to push:";
				cin >> n;
				if(n>5)
				{
					cout<<"Please Enter value less than 5" << endl;
					goto lebelpush;
				}
				for(unsigned int i=0; i<n;i++)
					stk.push();
				break;
			case 2:
				stk.pop();
				break;
			case 3:
				stk.display();
				break;

			default:
				cout << "Enter correct choice" <<endl;

		}
	}	
		



	return 0;
}
