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
	enum Stat stat;
	char *Author;
	Date pubDate;
	char *Title;
	char *PubLoc;
	char *PubName;

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
