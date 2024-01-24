#include "includes.h"

enum Stat { ON_SHELF, CHECKED_OUT};

typedef struct{
 
	short day;
	short mon;
	short year;
}Date;

typedef struct{
	string Books;
	short count;
}BookCount;

class Book{

private: 
	Stat stat;
	char Author[20];
	Date pubDate;
	char Title[40];
	char PubLoc[40];
	char PubName[40];

public:
	Book();
	void displayData();
	void inputData();
	bool checkOutData(char*,char*);
	bool checkInData(char*,char*);
	friend istream& operator >> (istream& s, Book& buk);
	friend ostream& operator << (ostream& s, Book& buk);
	~Book();
};


class Library{

private:
	char *LibName;	
	Book book;

public:
	Library();
	void createBookInven();
	void displayBooks();
	void checkOutBook();
	void checkInBook();
	~Library();
};
