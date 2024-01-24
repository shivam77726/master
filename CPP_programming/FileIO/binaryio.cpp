#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX =10;
class test
{
	private:
		int x;
		char buff[MAX];

	public:
		test();
		void showdata();
		void writedata();
		
};
		 
int main()
{
	test t1;
	//for(int j=0; j<MAX; j++)
	//	buff[j]=j;
	t1.writedata();
	ofstream os("edata.dat",ios::binary);
	if(!os)
	{
		cerr << "File not created";
		exit(1);
	}
	os.write(reinterpret_cast<char*>(&t1),sizeof(t1));
	os.close();
	

	ifstream is("edata.dat",ios::binary);
	if(!is)
	{
		cerr << "File read open";
		exit(1);
	}
	is.read(reinterpret_cast<char*>(&t1),sizeof(t1));
	t1.showdata();	
	cout << "Data is Correct\n";

	return 0;
}

test :: test()
{
	x=10;
	strcpy(buff,"Mr Shivam");
	cout << x << "\t" << buff << endl;
}

void test :: showdata()
{
	cout << x << "\t" << buff << endl;
}

void test :: writedata()
{
	x=15;
	strcpy(buff,"Ms Shivan");
}
