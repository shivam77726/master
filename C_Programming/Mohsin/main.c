#include "headers.h"
#include "dataStruct.h"
#include "defaults.h"
#include "declarations.h"


int main()
{

#ifdef DEBUG
	printf("%s : %s : Begin\n", __FILE__, __func__);
#endif
	creatInfra();



#ifdef DEBUG
	printf("%s : %s : End\n", __FILE__, __func__);
#endif
	return 0;
}


/*int creatInfra()
{
        int ret;
        Infra *infra;
        Result result;
#ifdef DEBUG
        printf("%s : %s : Begin\n", __FILE__, __func__);
#endif
        //Allocating Space for Structure Infra using malloc
        infra = (Infra*)malloc(sizeof(Infra));
        if (!infra)
        {
                perror("malloc");
                return EXIT_FAILURE;
                //(*fptr[0])((void*)"failure"); //exitServer
        }

        infra->srdMem = shmget(SHMKEY, sizeof(Result), IPC_CREAT|0666);
        if(infra->srdMem == -1)
        {
                perror("shmget");
                return EXIT_FAILURE;
        }
#ifdef DEBUG
        printf("%s : %s : End\n", __FILE__, __func__);
#endif
        return 0;
}
*/
