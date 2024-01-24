#include "includes.h"
#include "class.h"


istream& operator >> (istream& s, Book& buk)
{
	int pos;
	char line[40],ch;
#ifdef DDEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif
/*	pos=s.tellg();
	cout << "pos:" << pos <<", ";
	s >> ch;
	cout << ch << ", ";
	pos=pos+7;
	s.seekg(pos);
	s.getline(line,40,'\n');
	cout << line << ", ";
	pos=s.tellg();
	cout << "pos:" << pos <<", ";
	//pos++;
	s >> ch;
	cout << ch << ", ";
	pos=pos+8;
	s.seekg(pos);
	s.getline(line,40,'\n');
	cout << line << ", ";
	pos=s.tellg();
	cout << "pos:" << pos <<", ";
	//pos++;
	s >> ch;
	cout << ch << ", ";
	pos=pos+9;
	s.seekg(pos);
	s.getline(line,40,'\n');
	cout << line << ", ";
	pos=s.tellg();
	cout << "pos:" << pos <<", ";
	//pos++;
	s >> ch;
	cout << ch << ", ";
	pos=pos+21;
	s.seekg(pos);
	s.getline(line,40,'\n');
	cout << line << ", ";
*/
	s.read(reinterpret_cast<char*>(&buk),sizeof(Book));
	buk.displayData();


#ifdef DDEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif
	return s;



}
