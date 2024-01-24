#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("02_code Begin\n");
	printf("PID:%d,PPID=%d\t",getpid(),getppid());
	printf("02_code End\n");
	return 0;
}
