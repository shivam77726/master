#include "includes.h"
enum Stat {ON_SHELF,CHECKED_OUT};
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
	char *Title;
	char *Author;
	Date pubDate;
	char *PubLoc;
	char *PubName;
	enum Stat stat;

public:
	Book();
	void displayData();
	void inputData();
	friend istream& operator >> (istream& s, Book& buk);
	friend ostream& operator << (ostream& s, Book& buk);
	~Book();
};


class Library{

private:
	char *libName;	
	Book *book;

public:
	Library();
	void createBookInven();
	void displayBooks();
	~Library();
};
