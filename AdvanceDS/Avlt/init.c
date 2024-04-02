#include "declaration.h"

void* mainMenu(void*);
void* exitProgram(void*);
void* createTree(void*);
void* createNode(void*);
void* insertNode(void*);
void* inOrderTraversal(void*);
void* getBalanceFactor(void*);
void* leftLeftRotate(void*);

void* (*fptr[NOF])(void*);


void init(void)
{

	fptr[0]=exitProgram;
	fptr[1]=mainMenu;
	fptr[2]=createTree;
	fptr[3]=createNode;
	fptr[4]=insertNode;
	fptr[5]=inOrderTraversal;
	fptr[6]=getBalanceFactor;
	fptr[7]=leftLeftRotate;
}
