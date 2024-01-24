#include "includes.h"
#include "class.h"
#include <bits/stdc++.h>


bool Book:: checkOutData(char *author, char *title)
{
	char *s1=author;
	char *s2=title;
	char *s3=Author;
	char *s4=Title;
#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": Begin"<<endl;

#endif

/*	transform(s1, s1+strlen(s1), s1, ::toupper);
	transform(s2, s2+strlen(s2), s2, ::toupper);
	transform(s3, s3+strlen(s3), s3, ::toupper);
	transform(s4, s4+strlen(s4), s4, ::toupper);
*/
	if(!strcmp(s1,s3) && !strcmp(s2,s4))
	{
		if(stat==CHECKED_OUT)
		{
			cout << "Book already checked out" << endl;
			return false;
		}
		stat = CHECKED_OUT;
		return true;
	}

#ifdef DEBUG
        cout<<__FILE__<<" "<<__func__<<": End"<<endl;
#endif

	return false;
}
