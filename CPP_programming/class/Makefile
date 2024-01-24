#!/bin/bash

demo: main.o mainMenu.o getDistance.o getDisplay.o addDistances.o getTime.o timeDisplay.o addTimes.o
	g++ -o demo main.o mainMenu.o getDistance.o getDisplay.o addDistances.o getTime.o timeDisplay.o addTimes.o


main.o:main.cpp headers.h declaration.h
	g++ -c main.cpp
mainMenu.o:mainMenu.cpp headers.h declaration.h
	g++ -c mainMenu.cpp
getDistance.o:getDistance.cpp headers.h declaration.h
	g++ -c getDistance.cpp
getDisplay.o:getDisplay.cpp headers.h declaration.h
	g++ -c getDisplay.cpp
addDistances.o:addDistances.cpp headers.h declaration.h
	g++ -c addDistances.cpp
getTime.o:getTime.cpp headers.h declaration.h
	g++ -c getTime.cpp
timeDisplay.o:timeDisplay.cpp headers.h declaration.h
	g++ -c timeDisplay.cpp
addTimes.o:addTimes.cpp headers.h declaration.h
	g++ -c addTimes.cpp

clean:
	rm *.o
	rm demo
