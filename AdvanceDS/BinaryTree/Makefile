#!/bin/bash

CC= gcc
CF= -c
DF= -DDEBUG

tree: main.o init.o mainMenu.o createTree.o createNode.o insertNode.o displayTree.o exit.o
	${CC}  -o tree main.o mainMenu.o createTree.o createNode.o init.o insertNode.o displayTree.o exit.o


main.o:main.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} main.c
init.o:init.c headers.h declarations.h
	${CC} ${CF} ${DF} init.c
mainMenu.o:mainMenu.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} mainMenu.c
createTree.o:createTree.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} createTree.c
displayTree.o:displayTree.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} displayTree.c
createNode.o:createNode.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} createNode.c
insertNode.o:insertNode.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} insertNode.c
exit.o:exit.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} exit.c



clean:
	rm *.o
	rm tree
