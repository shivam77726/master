#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("PID=%d,PPID=%d,Exec fun Begin\n",getpid(),getppid());
	execl("/home/shivam/systemProgramming/a.out","a.out",NULL);

	printf("PID=%d,PPID=%d,Exec fun End",getpid(),getppid());



	return 0;
}
