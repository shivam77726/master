#include "includes.h"
#include "class.h"


istream& operator >> (istream& s, Book& buk)
{
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;
#endif
	s.read(reinterpret_cast<char*>(&buk),sizeof(Book));
	//buk.displayData();
	


#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif
	return s;



}
