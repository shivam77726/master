#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"

extern short cl;
void* decompressionStat(void* arg)
{
        file of; 
        uniqDS *arDS;
        int offset,tmp;
	int location;
	int fdcom,fddecom,size;
        unsigned char rch=0;
        short Blen=8;
        arDS = (uniqDS*) arg;

#ifdef DEBUG
        printf("%s begin\n",__func__);
#endif


        of.mode='r';
        printf("..........................Start Decompression.....................\n");
	of.filename="keyfile";
        arDS->fd = *(int*) (*fun_ptr[7])((void*)&of);  //Open File

#ifdef DEBUG
        printf("Key file opned successfully:%d\n",arDS->fd);
#endif


//*****************************Opening Decompress file****************************
	of.mode='w';
        printf("Enter decompress Filename:");
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
        fddecom=*(int*) (*fun_ptr[7])((void*)&of);  //Open File
        printf("Decompress file open successfully:%d\n",of.fd);

//*****************************Decompress file opened*****************************

//*****************************Opening Compress file******************************
	of.mode='r';
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
        fdcom=*(int*) (*fun_ptr[7])((void*)&of);  //Open File
        printf("Compress file open successfully:%d\n",of.fd);
	free(of.filename);	
//*************************Compress file opened***********************************
        arDS->size=lseek(arDS->fd,0,SEEK_END)-1;
        if(arDS->size <= -1)
        {
                printf("Error to get size\n");
                return (void*) EXIT_FAILURE;
        }
        
#ifdef DEBUG
        printf("\nSize:%d\n",arDS->size);
#endif
	arDS->ma=(char*) malloc(arDS->size);
        if(arDS->ma==NULL)
        {
                printf("Master array not Allocated\n");
                return (void*) EXIT_FAILURE;
        }


        offset=lseek(arDS->fd,0,SEEK_SET);
        if(offset==-1)
        {
                printf("Error to set curser at begining\n");
                return (void*) EXIT_FAILURE;
        }
        if(read(arDS->fd,arDS->ma,arDS->size+1)==-1){
		printf("Note able to read\n");
		return ((void*)EXIT_FAILURE);
	}

#ifdef DEBUG
        printf("\nMasterArray:%s\n",arDS->ma);
#endif

	(*fun_ptr[6])((void*)&arDS->size);              	//Code Length
#ifdef DEBUG
	printf("Code Length:%d\n",cl);
#endif

        
	size=lseek(fdcom,0,SEEK_END);
        if(arDS->size <= -1)
        {
                printf("Error to get decom file size\n");
                return (void*) EXIT_FAILURE;
        }

        offset=lseek(fdcom,0,SEEK_SET);
        if(offset==-1)
        {
                printf("Error to set curser at begining\n");
                return (void*) EXIT_FAILURE;
        }
	
	//printf("ma Add:%X,%X",arDS->ma+1,arDS->ma+2);



	//Decompressing
	offset=0;
	while(offset < size-1){
	Blen=8;
        
	while(Blen && cl){
                
		Blen=Blen-cl;
                if(read(fdcom,&rch,1)==-1){
                	printf("Note able to read\n");
                        return ((void*)EXIT_FAILURE);
		}
		
		offset=lseek(fdcom,0,SEEK_CUR);
                if(offset==-1)
                {
                        printf("Error to set curser\n");
                        return (void*) EXIT_FAILURE;
                }
                printf("Curser pos:%d\tch:%X\tBlen:%hi\n",offset,rch,Blen);
		if(Blen==8-cl)
		{
			location= rch >> Blen;
			printf("1. Location:%d\tch:%X\tBlen:%hi\n",location,rch,Blen);
			if(write(fddecom,arDS->ma+location,1)==-1){
                                printf("1. Note able to write\n");
                                return ((void*)EXIT_FAILURE);
                        }
		}


label:          if(Blen>0){
                	location=rch & ( (short)pow(2,Blen) - 1);
                        if((cl-Blen)>0)
				location=location << (cl-Blen);
			else{
				location=location >> (Blen-cl);
				printf("2. Location:%d\tch:%X\tBlen:%hi\n",location,rch,Blen);
				if(write(fddecom,arDS->ma+location,1)==-1){
                                	printf("2. Note able to write\n");
                                	return ((void*)EXIT_FAILURE);
				}
				if(Blen-cl>=cl){
                			Blen=Blen-cl;
                			goto label;
				}
				else
					break;
                	}

                }
/*		else if(Blen==0){
			Blen=8;
			break;
		}
*/		else{
			Blen=8+Blen;
			location=location|(rch >> Blen);
			printf("3. Location:%d\tch:%X\tBlen:%hi\n",location,rch,Blen);
			if(write(fddecom,arDS->ma+location,1)==-1){
                               	printf("3. Note able to write\n");
                               	return ((void*)EXIT_FAILURE);
			}

            		if(Blen>cl){
                		location=rch & ( (short)pow(2,Blen) - 1);
                		Blen=Blen-cl;
                		location=location>>(Blen);
				printf("4. Location:%d\tch:%X\tBlen:%hi\n",location,rch,Blen);
				if(write(fddecom,arDS->ma+location,1)==-1){
                                	printf("4. Note able to write\n");
                                	return ((void*)EXIT_FAILURE);
				}
                		goto label;
            		}
            		else if(Blen==cl){
            			location=rch & ( (short) pow(2,Blen) - 1);
				printf("5. Location:%d\tch:%X\tBlen:%hi\n",location,rch,Blen);
				if(write(fddecom,arDS->ma+location,1)==-1){
                               		printf("5. Note able to write\n");
                               		return ((void*)EXIT_FAILURE);
				}
            			break;
            		}
            		else
            		goto label;
                }

        }
	}
        printf("................Decompression Completed Successfully..............\n");
	
	free(arDS->ma);
	
        if(close(fdcom))
        {
                printf("Compressed File not closed\n");
        }
        else{

#ifdef DEBUG
                printf("Compressed File closed Successfully\n");
#endif
	}
        if(close(fddecom))
        {
                printf("Decompressed File not closed\n");
        }
        else{

#ifdef DEBUG
                printf("Decompressed File closed Successfully\n");
#endif
	}
        if(close(arDS->fd))
        {
                printf("File not closed\n");
        }
        else{

#ifdef DEBUG
                printf("Key File closed Successfully\n");
#endif
	}

#ifdef DEBUG
        printf("%s End\n",__func__);
#endif

        return 0;

}

