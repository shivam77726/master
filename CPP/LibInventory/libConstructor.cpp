#include "includes.h"
#include "class.h"


Library::Library()
{
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif

	libName  = new char [20];
        if(!libName)
        {
                cerr << "libName: Memory not assigned" ;
                exit(1);
        }
	strcpy(libName, "My Libreary");

        book  = new Book;
        if(!book)
        {
                cerr << "book: Memory not assigned" ;
                exit(1);
        }




#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif





}
