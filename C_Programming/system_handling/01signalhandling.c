#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void ouch(int sig)
{
	printf("Ouch %d signal using\n",sig);

}
int main()
{

	signal(SIGINT,ouch);
	while(1)
	{

		printf("Hello World\n");
		sleep(1);
	}
	return 0;
}
