#include "headers.h"
#include "declarations.h"

void** Exit(void**);
void** mainMenu(void**);
void** createTree(void**);
void** displayTree(void**);
void** insertNode(void**);


void* createNode(void*);


void* (*fun_ptr[NOF])(void*);
void** (*fun_ptr1[NOF])(void**);

void init()
{
	fun_ptr[1]=createNode;

	fun_ptr1[0]=mainMenu;
	fun_ptr1[1]=createTree;
	fun_ptr1[2]=insertNode;
	fun_ptr1[3]=displayTree;
	fun_ptr1[4]=Exit;
}
