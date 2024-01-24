#include "includes.h"
#include "class.h"


Library::Library()
{
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif
        LibName  = new char [20];
        if(!LibName)
        {
                cerr << "LibName: Memory not assigned" ;
                exit(1);
        }

	strcpy(LibName, "MyLib");



#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif





}
