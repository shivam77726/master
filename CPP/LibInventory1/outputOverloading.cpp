#include "includes.h"
#include "class.h"


ostream& operator << (ostream& s, Book& buk)
{
#ifdef DDEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif

/*      cout << "Enter Date:(dd-mm-yy)"<<endl;
        cin >> buk.pubDate.day;
        cin >> buk.pubDate.mon;
        cin >> buk.pubDate.year;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Enter Book Title:";
        cin.get (buk.Title,40);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Enter Author Name:";
        cin.get (buk.Author,20);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Publication Location:";
        cin.get(buk.PubLoc,100);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Publication Name:";
        cin.get(buk.PubName,20);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
*/
	buk.inputData();
	s.write(reinterpret_cast<char*>(&buk),sizeof(buk) );
	s<<endl;
/*	s << buk.pubDate.day;
	s << buk.pubDate.mon;
	s << buk.pubDate.year;
	s << endl;

	s << buk.Title;
	s << endl;

	s << buk.Author;
	s << endl;

	s << buk.PubLoc;
	s << endl;

	s << buk.PubName;
	s << endl;
*/
#ifdef DDEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif

	return s;
}
