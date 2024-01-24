#include "includes.h"
#include "class.h"


void Library:: createBookInven()
{
	fstream iofile;
	char line[12];
	static int count=0;

#ifdef DDEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif
	/*oBC.Books  = new char [13];
	if(!oBC.Books)
	{
		cerr<<"oBC.Books";
		cout << endl;
		exit(1);
	}
        memset(oBC.Books,'\0',13);*/
	iofile.open(BFile, ios::out |ios::binary);
	if(!iofile)
	{
		cout<<"File doesn't exist"<<endl;
/*		iofile.open(BFile, ios::out|ios::binary);
		if(!iofile)
		{
			cerr<<"File not created"<<endl;
			exit(1);
		}
		iofile.close();
		iofile.open(BFile, ios::out|ios::in|ios::binary);
		if(!iofile)
		{
			cerr<<"File not opened"<<endl;
			exit(1);
		}
*/		exit (1);
	}
/*	iofile >> line;	
	cout << line <<endl;
	if(strncmp(line,"No Of Books ",12)!=0)	*/
	if(iofile.peek()==EOF)
	{
		cout << "Writing No of books" << endl;
		iofile.seekg(0);
		iofile << "No of Books " << count << "    "  << endl;
		//iofile.write((char*)&oBC,sizeof(BookCount)) ;
		//iofile << oBC <<endl;
		//count=1;
/*		iofile.seekg(0, ios::beg);
		iofile >> line >> count;
		cout << line <<" " << count << endl;
*/
	}
	iofile.close();
	iofile.open(BFile,ios::in|ios::binary);
	if(!iofile)
	{
		cerr<<"File not opened in read mode"<<endl;
		exit(1);
	}
	iofile.seekg(0,ios::beg);
	//iofile >> line >> count;
	iofile.read((char*)line,sizeof(line));
	//iofile.read((char*)&count,sizeof(char));
	iofile >> count;
	cout << line << " " << count++ << endl;
	iofile.close();

	cout <<"count:" << count <<endl;

	

	iofile.open(BFile,ios::out | ios::app | ios::binary);
	if(!iofile)
	{
		cerr<<"File not opened in append mode"<<endl;
		exit(1);
	}
	cout << "Enter Book details:";
	cout << endl;
	//cin>>book ;
	book->inputData();
	iofile << endl;
        iofile.write(reinterpret_cast<char*>(book),sizeof(Book));
	iofile.close();

	iofile.open(BFile,ios::in | ios::out | ios::binary);
	if(!iofile)
	{
		cerr << "File not opened in seek mode" << endl;
		exit(1);
	}
	iofile.seekp(12,ios::beg);
	//iofile << "No of Books " << count;
	iofile << count;
	iofile.close();


#ifdef DDEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif


}
