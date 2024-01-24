CC=gcc
DF=-DDEBUG
CF=-c

demo: main.o mainMenu.o createLinkedList.o createNode.o displayNode.o insertNode.o insertBeg.o insertEnd.o insertNth.o insertKey.o deleteNode.o deleteBeg.o deleteEnd.o deleteNth.o deleteKey.o init.o ExitProgram.o
	$(CC) -o demo main.o mainMenu.o createLinkedList.o createNode.o displayNode.o insertNode.o insertBeg.o insertEnd.o insertNth.o insertKey.o deleteNode.o deleteBeg.o deleteEnd.o deleteNth.o deleteKey.o init.o ExitProgram.o


main.o: main.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) main.c
mainMenu.o: mainMenu.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) mainMenu.c
createLinkedList.o: createLinkedList.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) createLinkedList.c
createNode.o: createNode.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) createNode.c
displayNode.o: displayNode.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) displayNode.c
insertNode.o: insertNode.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) insertNode.c
insertBeg.o: insertBeg.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) insertBeg.c
insertEnd.o: insertEnd.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) insertEnd.c
insertNth.o: insertNth.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) insertNth.c
insertKey.o: insertKey.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) insertKey.c
deleteNode.o: deleteNode.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) deleteNode.c
deleteBeg.o: deleteBeg.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) deleteBeg.c
deleteEnd.o: deleteEnd.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) deleteEnd.c
deleteNth.o: deleteNth.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) deleteNth.c
deleteKey.o: deleteKey.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) deleteKey.c
init.o: init.c headers.h declaration.h
	$(CC) $(CF) $(DF) init.c
ExitProgram.o: ExitProgram.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) ExitProgram.c


clean: 
	-rm demo *.o
