#include "includes.h"
#include "class.h"



void Library:: displayBooks()
{
	fstream iofile;
	char line[12],ch;
	//string str;
	int count=0;
	int pos=0,i=0;
#ifdef DDEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif

	iofile.open(BFile,ios::in|ios::binary);
	if(!iofile)
        {
                cerr<<"File not opened in read mode"<<endl;
                exit(1);
        }
	iofile.seekg(12);
	//iofile.getline(line,15,'\n');
	//iofile.read((char*)line,sizeof(line));
	iofile >> count;
	cout << count <<  endl;
	iofile.seekg(17);
	pos=iofile.tellg();
	pos=pos+1;
	while(!iofile.eof())
	{

		cout << "[" << i++ << "]\t";
		iofile >> *book;
	}
	iofile.close();


	




#ifdef DDEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif


}
