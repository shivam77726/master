#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


typedef struct{
       char a;
}com;       

int main()
{

	int fd1,i=0;
	char *filename, b, *buf;
	char mode, write_buf[]="Shivam";
	int offset,size;
	com *s1;	
	printf("Enter mode('w'/'r'/'a':");
	scanf("%c",&mode);

	filename=(char*) malloc(20);
	if(filename==NULL)
	{
		printf("Unable to allocate memory");
		return EXIT_FAILURE;
	}

	memset(filename,'\0',20);
	printf("Enter filename:");
	for(int i=0;i<20;i++)
	{
		
		scanf("%c",filename+i);

		if(i==0 && (*(filename+i)=='\n' || *(filename+i)=='\0'))
		{	
			i=-1;
			continue;
		}

		if(*(filename+i)=='\n')
		{
			*(filename+i)='\0';
			break;
		}
	}
	printf("Filename:%s\n",filename);

	fd1=open(filename,O_RDWR|O_APPEND);
	if(fd1==-1)
	{
		printf("Unable to open %s:%d\n",filename,fd1);
		return EXIT_FAILURE;
	}
	printf("File opened Successfully:%d\n",fd1);
	size=lseek(fd1,0,SEEK_END)-1;	
	printf("Size of file:%d\n",size);
	if(size<0)
	{
		printf("Error to cal size\n");
		return EXIT_FAILURE;
	}
	offset=lseek(fd1,0,SEEK_SET);
	printf("Offset no:%d\n",offset);
	if(offset==-1)
	{
		printf("Error to set offset\n");
		return 0;
	}

	while(1)
	{
		buf=(char*) realloc(buf,i+1);
		if(read(fd1,(buf+i),1) == -1)
		{
			printf("Unable to read");
			break;
		}
		printf("i=%d\n",i);
		i++;
	}
	printf("\nString in file fd1:");
	for(int i=0;i<size; i++)
	{
		printf("%c",*(buf+i));
	}
	printf("\n");

	/*
	printf("read size:%d\n",size);
	printf("character:%s\n",buf);
	read(fd1,buf,1);
	printf("Character:%s\n",buf);
	
	//size=lseek(fd1,0,SEEK_END);
	for(int i=0;i<10;i++)
	{
		printf("Enter character:%d",i+1);
		//->a='0';
		b=48+i;
		if(write(fd1,&b,1)==-1)
		{
			printf("Error in file write\n");
		}
	}
	*/

	free(filename);
	free(buf);
	close(fd1);


	return 0;
}
