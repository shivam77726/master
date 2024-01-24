#!/bin/bash

CC=gcc
DF=-DDEBUG
CF=-c

server: server.o createInfra.o processRequest.o
	${CC} -o server server.o createInfra.o processRequest.o


server.o: server.c ../common/headers.h ../common/declaration.h ../common/dataStructure.h ../common/defaults.h
	${CC} ${CF} server.c

createInfra.o: createInfra.c ../common/headers.h ../common/declaration.h ../common/dataStructure.h
	${CC} ${CF} createInfra.c
processRequest.o: processRequest.c ../common/headers.h ../common/declaration.h ../common/dataStructure.h
	${CC} ${CF} processRequest.c


clean:
	rm -f *.o server
