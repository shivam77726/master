#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

short cl;
void* compressionStat(void* arg)
{
        file of; 
        uniqDS *arDS;
        int location,offset,tmp;
        char wch=0;
        short Blen=8;
        arDS= (uniqDS*) arg;

#ifdef DEBUG
        printf("%s begin\n",__func__);
#endif


        of.mode='w';
        printf("...........................Start Compression.....................\n");
	printf("Enter compress Filename:");
	of.filename=(char*) malloc(20);
        if(of.filename==NULL)
        {
                printf("Filename not Allocated\n");
                return (void*) EXIT_FAILURE;
        }
        memset(of.filename,'\0',20);
        for(int i=0;i<20;i++)
        {
                scanf("%c",of.filename+i);
                if(i==0 && (*(of.filename+i)=='\n'||*(of.filename+i)=='\0'))
                {
                        i=-1;
                        continue;
                }

                if(*(of.filename+i)=='\n')
                {
                        *(of.filename+i)='\0';
                        break;
                }
        }

        *(int*) (*fun_ptr[7])((void*)&of);  //Open File
        printf("File opned successfully:%d\n",of.fd);

#ifdef DEBUG
        printf("%d\n",of.fd);
#endif


        arDS->size=lseek(arDS->fd,0,SEEK_END);
        if(arDS->size<=-1)
        {
                printf("Error to get size\n");
                return (void*) EXIT_FAILURE;
        }
        offset=lseek(arDS->fd,0,SEEK_SET);
        if(offset==-1)
        {
                printf("Error to set curser at begining\n");
                return (void*) EXIT_FAILURE;
        }

       	offset=lseek(of.fd,0,SEEK_SET);
       	if(offset==-1)
       	{
               	printf("Error to set curser\n");
               	return (void*) EXIT_FAILURE;
       	}
	

/*      //All character's location
        for(int i=0; i<size;i++)
        {
                if(read(arDS->fd,&arDS->ch,1)==-1)
                {
                        printf("Note able to read\n");
                        return ((void*)EXIT_FAILURE);
                }
                location=*(int*)(*fun_ptr[8])((void*)arDS);     //FindLocation
        }

*/
	offset=0;
	while(offset < arDS->size){
	Blen=8;
	wch=0;
        while(Blen && cl){
                
		Blen=Blen-cl;
                if(read(arDS->fd,&arDS->ch,1)==-1){
                	printf("Note able to read\n");
                        return ((void*)EXIT_FAILURE);
		}
                location=*(int*)(*fun_ptr[8])((void*)arDS);     //FindLocation 

                if(Blen>0){
                        tmp=location<<Blen;
                        wch=wch|tmp;
                }
		else if(Blen==0){
			wch=wch|location;
			printf("wch:%c\n",wch);
                        if(write(of.fd,&wch,1)==-1){
                                printf("Note able to write\n");
                                return ((void*)EXIT_FAILURE);
                        }
		}
                else{
                        tmp=location>>abs(Blen);
                        wch=wch|tmp;
			printf("wch:%c\n",wch);
                        if(write(of.fd,&wch,1)==-1){
                                printf("Note able to write\n");
                                return ((void*)EXIT_FAILURE);
                        }
                        wch=0;
                        Blen=8+Blen;
                        wch=location<<Blen;
                }
		printf("wch:%X\n",wch);
        	offset=lseek(arDS->fd,0,SEEK_CUR);
        	if(offset==-1)
        	{
                	printf("Error to set curser\n");
                	return (void*) EXIT_FAILURE;
        	}
                printf("Curser pos:%d\n",offset);

        }
	}
        
        printf(".................Compression Completed Successfully...............\n");

        free(of.filename);
	
        if(close(of.fd))
        {
                printf("File not closed\n");
        }
        else
                printf("Compressed File closed Successfully\n");

#ifdef DEBUG
        printf("%s End\n",__func__);
#endif

        return 0;

}

