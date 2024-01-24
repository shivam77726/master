#include "includes.h"
#include "class.h"



void Library:: displayBooks()
{
	fstream iofile;
	char line[20],ch;
	int count=0;
	int pos=0,i=0;

#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;
#endif

	iofile.open(BFile,ios::in|ios::binary);
	if(!iofile)
        {
                cerr<<"File not opened in read mode"<<endl;
                exit(1);
        }

	//iofile.read((char*)line,sizeof(line));
	iofile.seekg(12);
	iofile >> count;
	cout << count << endl;
	iofile.seekg(0,ios::beg);
	iofile.getline(line,20,'\n');
	//pos=iofile.tellg();
	//iofile >> count;
	cout << line <<  endl;
	//iofile.seekg(20);
	while(count-- )
	{

		pos=iofile.tellg();
		pos = pos+2;
		iofile.seekg(pos);
		cout << "[" << i++ << "]\t";
		iofile >> book;
		book.displayData();
		//pos=iofile.tellg();
		//pos = pos+2;
		//iofile.seekg(pos);
		cout << endl;

	}

	iofile.close();

#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif
}
