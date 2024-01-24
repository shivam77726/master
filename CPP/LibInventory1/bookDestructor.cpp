#include "includes.h"
#include "class.h"


Book::~Book()
{
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif

/*	free(Author);
	free(Title);
	free(PubLoc);
	free(PubName);
*/
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif





}
