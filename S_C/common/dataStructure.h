typedef struct{
	int pfd[2];
	int shmid;
	int mqid;
	int semid;

}Infra;



typedef struct{
	long cpid;
	float opr1,opr2;
	char reqtype;
}Msg;



typedef struct{
	long cpid;
	float result;
}Result;

typedef struct{
	long mtype;
	float result;
}Mbuf;

typedef union {
	int val;    			/* Value for SETVAL */
        struct semid_ds *buf;		/* Buffer for IPC_STAT, IPC_SET */
        unsigned short  *array;		/* Array for GETALL, SETALL */
        struct seminfo  *__buf;		/* Buffer for IPC_INFO (Linux-specific) */
}semun;

