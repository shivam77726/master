#include "includes.h"
#include "class.h"


void Book:: displayData()
{
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif

        cout << Author;
/*	memset(Author,'\0',20);
        Title   = new char [40];
	memset(Title,'\0',40);
        PubLoc  = new char [100];
	memset(PubLoc,'\0',100);
        PubName = new char [40];
	memset(PubName,'\0',40);
*/

#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif





}
