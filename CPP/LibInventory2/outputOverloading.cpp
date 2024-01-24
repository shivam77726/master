#include "includes.h"
#include "class.h"


ostream& operator << (ostream& s, Book& buk)
{
#ifdef DDEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif
/*	Book *book;
	book = new Book;
	if(!book)
	{
		cerr << "book: Unable create memory";
		exit(1);
	}
	buk.inputData();
*/	s.write(reinterpret_cast<char*>(&buk.stat),sizeof(enum Stat));
	s.write(reinterpret_cast<char*>(buk.Author),sizeof(char)*20);
	s.write(reinterpret_cast<char*>(&buk.pubDate),sizeof(Date));
	s.write(reinterpret_cast<char*>(buk.Title),sizeof(char)*40);
	s.write(reinterpret_cast<char*>(buk.PubLoc),sizeof(char)*40);
	s.write(reinterpret_cast<char*>(buk.PubName),sizeof(char)*40);
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
