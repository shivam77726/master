#include "includes.h"
#include "class.h"


Book::~Book()
{
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif

	delete[] Author;
	delete[] Title;
	delete[] PubLoc;
	delete[] PubName;

#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif





}
