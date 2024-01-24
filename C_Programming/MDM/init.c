#include "headers.h"
#include "declaration.h"



void* openFile(void*);
void* exitFail(void*);
void* compresssion(void*);
void* compresssionStat(void*);
void* decompresssionStat(void*);
void* createMasterarray(void*);
void* uniqchar(void*);
void* codeLength(void*);
void* decompression(void*);
void* findLocation(void*);
void* mainMenu(void*);
void* (*fun_ptr[NOF])(void*);
void init()
{
	fun_ptr[0]=mainMenu;
	fun_ptr[1]=exitFail;
	fun_ptr[2]=compression;
	fun_ptr[3]=decompressionStat;
	fun_ptr[4]=createMasterarray;
	fun_ptr[5]=uniqchar;
	fun_ptr[6]=codeLength;
        fun_ptr[7]=openFile;
	fun_ptr[8]=findLocation;
	fun_ptr[9]=compressionStat;
}
