#include "includes.h"
#include "class.h"


void Book:: displayData()
{
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif
        switch(stat)
	{
		case ON_SHELF:

			cout << "[ON_SHELF], ";
			break;
		case CHECKED_OUT:
			cout << "[CHECKED_OUT], ";
			break;
		default:
			cout << "[Unknown Stat], ";
	}
	cout << Author <<", ";
        cout << pubDate.day;
        cout << pubDate.mon;
        cout << pubDate.year <<", ";
        cout << Title <<", ";
        cout << PubLoc <<", ";
        cout << PubName;


#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif





}
