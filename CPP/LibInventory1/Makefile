#!/bin/bash


CC=g++
DF=-DDEBUG
CF=-c


lib: main.o mainMenu.o bookConstructor.o bookDestructor.o inputData.o displayData.o inputOverloading.o outputOverloading.o libConstructor.o libDestructor.o createBookInven.o displayBooks.o checkOutBook.o checkOutData.o checkInBook.o checkInData.o
	$(CC) -o lib main.o mainMenu.o bookConstructor.o bookDestructor.o inputData.o displayData.o inputOverloading.o outputOverloading.o libConstructor.o libDestructor.o createBookInven.o displayBooks.o checkOutBook.o checkOutData.o checkInBook.o checkInData.o


checkInData.o : checkInData.cpp includes.h class.h
	$(CC) $(CF) checkInData.cpp
checkInBook.o : checkInBook.cpp includes.h class.h
	$(CC) $(CF) checkInBook.cpp
checkOutData.o : checkOutData.cpp includes.h class.h
	$(CC) $(CF) checkOutData.cpp
checkOutBook.o : checkOutBook.cpp includes.h class.h
	$(CC) $(CF) checkOutBook.cpp
displayBooks.o : displayBooks.cpp includes.h class.h
	$(CC) $(CF) displayBooks.cpp
createBookInven.o : createBookInven.cpp includes.h class.h
	$(CC) $(CF) createBookInven.cpp
outputOverloading.o : outputOverloading.cpp includes.h class.h
	$(CC) $(CF) outputOverloading.cpp
inputOverloading.o : inputOverloading.cpp includes.h class.h
	$(CC) $(CF) inputOverloading.cpp
displayData.o : displayData.cpp includes.h class.h
	$(CC) $(CF) displayData.cpp
inputData.o : inputData.cpp includes.h class.h
	$(CC) $(CF) inputData.cpp
libDestructor.o : libDestructor.cpp includes.h class.h
	$(CC) $(CF) libDestructor.cpp
libConstructor.o : libConstructor.cpp includes.h class.h
	$(CC) $(CF) libConstructor.cpp
bookDestructor.o : bookDestructor.cpp includes.h class.h
	$(CC) $(CF) bookDestructor.cpp
bookConstructor.o : bookConstructor.cpp includes.h class.h
	$(CC) $(CF) bookConstructor.cpp
mainMenu.o : mainMenu.cpp includes.h class.h
	$(CC) $(CF) mainMenu.cpp
main.o : main.cpp includes.h class.h
	$(CC) $(CF) main.cpp

clean:
	-rm demo*.o
