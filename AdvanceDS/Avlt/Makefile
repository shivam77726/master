#!/bin/bash

CC=gcc
CF=-c
DF=-DDEBUG

AVL: main.o mainMenu.o exitProgram.o createTree.o createNode.o insertNode.o inOrderTraversal.o getBalanceFactor.o init.o leftLeftRotate.o rightRightRotate.o leftRightRotate.o rightLeftRotate.o deleteNode.o heightNode.o
	${CC} -o AVL main.o mainMenu.o exitProgram.o createTree.o createNode.o insertNode.o inOrderTraversal.o getBalanceFactor.o init.o leftLeftRotate.o rightRightRotate.o leftRightRotate.o rightLeftRotate.o deleteNode.o heightNode.o


init.o:init.c declaration.h
	${CC} ${CF} ${DF} init.c
main.o:main.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} main.c
mainMenu.o:mainMenu.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} mainMenu.c
exitProgram.o:exitProgram.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} exitProgram.c
createTree.o:createTree.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} createTree.c
createNode.o:createNode.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} createNode.c
insertNode.o:insertNode.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} insertNode.c
inOrderTraversal.o:inOrderTraversal.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} inOrderTraversal.c
heightNode.o:heightNode.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} heightNode.c
getBalanceFactor.o:getBalanceFactor.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} getBalanceFactor.c
leftLeftRotate.o:leftLeftRotate.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} leftLeftRotate.c
rightRightRotate.o:rightRightRotate.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} rightRightRotate.c
leftRightRotate.o:leftRightRotate.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} leftRightRotate.c
rightLeftRotate.o:rightLeftRotate.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} rightLeftRotate.c
deleteNode.o:deleteNode.c headers.h declaration.h dataStructure.h
	${CC} ${CF} ${DF} deleteNode.c


clean:
	rm *.o AVL
