#include "includes.h"
#include "class.h"
int mainMenu();

int main()
{
#ifdef DDEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;
#endif

	mainMenu();



#ifdef DDEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif


	return 0;
}
