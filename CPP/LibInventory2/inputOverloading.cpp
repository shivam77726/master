#include "includes.h"
#include "class.h"


istream& operator >> (istream& s, Book& buk)
{
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;
#endif
        s.read(reinterpret_cast<char*>(&buk.stat),sizeof(enum Stat));
        s.read(reinterpret_cast<char*>(buk.Author),sizeof(char)*20);
        s.read(reinterpret_cast<char*>(&buk.pubDate),sizeof(Date));
        s.read(reinterpret_cast<char*>(buk.Title),sizeof(char)*40);
        s.read(reinterpret_cast<char*>(buk.PubLoc),sizeof(char)*40);
        s.read(reinterpret_cast<char*>(buk.PubName),sizeof(char)*40);

	//s.read(reinterpret_cast<char*>(&buk),sizeof(Book));
	//buk.displayData();
	


#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif
	return s;



}
