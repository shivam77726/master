#include "headers.h"
#include "declaration.h"

void* mainMenu(void*);
void* ExitProgram(void*);
void* createLinkedList(void*);
void* createNode(void*);
void* displayNode(void*);
void* insertNode(void*);
void* deleteNode(void*);
void* insertBeg(void*);
void* insertEnd(void*);
void* insertNth(void*);
void* insertKey(void*);

void* deleteBeg(void*);
void* deleteEnd(void*);
void* deleteNth(void*);
void* deleteKey(void*);

void* (*fun_ptr[NOF])(void*);

void init()
{
	
	fun_ptr[0]=ExitProgram;
	fun_ptr[1]=mainMenu;
	fun_ptr[2]=createLinkedList;
	fun_ptr[3]=createNode;
	fun_ptr[4]=displayNode;
	fun_ptr[5]=insertNode;
	fun_ptr[6]=deleteNode;
	fun_ptr[7]=insertBeg;
	fun_ptr[8]=insertEnd;
	fun_ptr[9]=insertNth;
	fun_ptr[10]=insertKey;
        fun_ptr[11]=deleteBeg;
	fun_ptr[12]=deleteEnd;
	fun_ptr[13]=deleteNth;
	fun_ptr[14]=deleteKey;
}
