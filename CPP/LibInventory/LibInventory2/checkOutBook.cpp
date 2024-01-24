#include "includes.h"
#include "class.h"



void Library::checkOutBook()
{
	fstream iofile;
	char Author[20], Title[40];
	int pos=0,count=0;
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif

        cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << "Enter Author Name and Book Name to be checkedout"<< endl;
	cout << "Enter Author Name:";
        cin.get (Author,20);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Enter Book Title:";
        cin.get (Title,40);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
	
	iofile.open(BFile,ios::in | ios::out | ios::binary);
	if(!iofile)
        {
                cerr<<"File not opened in read mode"<<endl;
                exit(1);
        }
	
	iofile.seekg(12);
        iofile >> count;

	iofile.seekg(20);
	pos=20;
	while(count--)
	{
		iofile >> book;
		if(book.checkOutData(Author,Title))
		{
			iofile.seekg(pos);
			iofile << book;
			//iofile.write(reinterpret_cast<char*>(&book),sizeof(book) );
			cout << Title << " Book has been checkedout." << endl;
			break;

		}
		pos=iofile.tellg();
		pos=pos+2;
		iofile.seekg(pos);

	}
	iofile.close();

#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif
}
