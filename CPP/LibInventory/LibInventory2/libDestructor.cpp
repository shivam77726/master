#include "includes.h"
#include "class.h"


Library :: ~Library()
{
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif

	delete[] LibName;



#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif



}
