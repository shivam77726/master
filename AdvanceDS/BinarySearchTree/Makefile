#!/bin/bash

CC= gcc
CF= -c
DF= -DDEBUG

tree: main.o mainMenu.o createTree.o createNode.o insertNode.o inOrderTraversal.o preOrderTraversal.o postOrderTraversal.o deleteTree.o
	${CC} -o tree main.o mainMenu.o createTree.o createNode.o insertNode.o inOrderTraversal.o preOrderTraversal.o postOrderTraversal.o deleteTree.o


main.o:main.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} main.c
mainMenu.o:mainMenu.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} mainMenu.c
createTree.o:createTree.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} createTree.c
createNode.o:createNode.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} createNode.c
insertNode.o:insertNode.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} insertNode.c
inOrderTraversal.o:inOrderTraversal.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} inOrderTraversal.c
preOrderTraversal.o:preOrderTraversal.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} preOrderTraversal.c
postOrderTraversal.o:postOrderTraversal.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} postOrderTraversal.c
deleteTree.o:deleteTree.c headers.h declarations.h dataStructure.h
	${CC} ${CF} ${DF} deleteTree.c



clean:
	rm *.o
	rm tree
