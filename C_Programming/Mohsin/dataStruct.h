union semun
{
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        struct seminfo *__buf;
};
typedef struct
{
	int *pipe;
	char *fifo;
	int msgQue;
	int srdMem;
	void *smptr;
	int semid;
	union semun semval[4];
}Infra;

typedef struct
{
	long pid;	//PID of client
	float result;
}Result;

typedef struct
{
	long cpid;
	int opr1;
	int opr2;
	char oper;
}Request;

