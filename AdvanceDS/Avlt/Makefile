#!/bin/bash

CC=gcc
CF=-c
DF=-DDEBUG

AVL: main.o mainMenu.o exitProgram.o createTree.o createNode.o insertNode.o init.o
	${CC} -o AVL main.o mainMenu.o exitProgram.o createTree.o createNode.o insertNode.o init.o


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


clean:
	rm *.o AVL
