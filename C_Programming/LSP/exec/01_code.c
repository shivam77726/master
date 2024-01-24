#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("01_code Begin\n");
	printf("PID:%d,PPID=%d\t",getpid(),getppid());
	printf("01_code End\n");
	return 0;
}
