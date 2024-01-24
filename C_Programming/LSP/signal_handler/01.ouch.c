#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ouch (int sig)
{
	printf("Ouch SIG_INT came%d\n",sig);

	return;
}

int main()
{
	(void) signal (SIGINT, ouch);

	while(1)
	{
		printf("Helllo\n");
		sleep(1);
	}


	return 0;
}
