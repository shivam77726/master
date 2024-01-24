#include "includes.h"
#include "class.h"


int mainMenu()
{
	Library lib;
	int choice=1;

#ifdef DDEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;
#endif
	while(choice){
		
		/************* Library Inventory Manager***************/
		cout << "0. Quit"				<< endl;
		cout << "1. Create Book Inventory"		<< endl;
		cout << "2. Create Periodical Inventory"	<< endl;
		cout << "3. Create Dvd Inventory"		<< endl;
		cout << "11. Display All Collection"		<< endl;
		cout << "12. Display Book Collection"		<< endl;
		cout << "13. Display Periodical Collection"	<< endl;
		cout << "14. Display Dvd Collection"		<< endl;
		cout << "21. Checkout Book"			<< endl;
		cout << "22. Checkout Periodical"		<< endl;
		cout << "23. Checkout Dvd"			<< endl;
		cout << "31. Checkin Book"			<< endl;
		cout << "32. Checkin Periodical"		<< endl;
		cout << "33. Checkin Dvd"			<< endl;
		/******************************************************/
		
		cout << "Enter Choice:";
		cin >> choice;

		switch(choice)
		{
			case 0:
				break;
			case 1:
				lib.createBookInven();
				break;
			case 2:
				break;
			case 3:
				break;
			case 11:
				break;
			case 12:
				lib.displayBooks();
				break;
			case 13:
				break;
			case 14:
				break;
			case 21:
				lib.checkOutBook();
				break;
			case 22:
				break;
			case 23:
				break;
			case 31:
				lib.checkInBook();
				break;
			case 32:
				break;
			case 33:
				break;

			default:
				cout << "Enter Correct Option" << endl;
				break;
		}
		
	}



#ifdef DDEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif



	return 0;
}
