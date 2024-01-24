#include "includes.h"
#include "class.h"


Book:: Book()
{
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif

        Author  = new char [20];
	if(!Author)
	{
		cerr << "Author: Memory not assigned" ;
		exit(1);
	}
	memset(Author,'\0',20);
        Title   = new char [40];
	if(!Title)
	{
		cerr << "Title: Memory not assigned" ;
		exit(1);
	}
	memset(Title,'\0',40);
        PubLoc  = new char [40];
	if(!PubLoc)
	{
		cerr << "PubLoc: Memory not assigned" ;
		exit(1);
	}
	memset(PubLoc,'\0',40);
        PubName = new char [40];
	if(!PubName)
	{
		cerr << "PubName: Memory not assigned";
		exit(1);
	}
	memset(PubName,'\0',40);


#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif





}
