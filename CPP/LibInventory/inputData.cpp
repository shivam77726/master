#include "includes.h"
#include "class.h"


void Book::inputData()
{
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif

	stat = ON_SHELF;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Enter Author Name:";
        cin.get (Author,20);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Enter Date(dd-mm-yyyy):";
        cin >> pubDate.day;
        cin >> pubDate.mon;
        cin >> pubDate.year;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Enter Book Title:";
        cin.get (Title,40);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Publication Location:";
        cin.get(PubLoc,40);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Publication Name:";
        cin.get(PubName,40);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');


#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif





}
