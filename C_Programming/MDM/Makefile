CC=gcc
DF=-DDEBUG
CF=-c




demo: main.o mainMenu.o openFile.o init.o uniqchar.o createMasterarray.o compression.o compressionStat.o codeLength.o findLocation.o decompressionStat.o exitFail.o
	$(CC) -o demo main.o mainMenu.o openFile.o init.o uniqchar.o createMasterarray.o compression.o compressionStat.c codeLength.o findLocation.o decompressionStat.o exitFail.o -lm


decompressionStat.o: decompressionStat.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) decompressionStat.c
compressionStat.o: compressionStat.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) compressionStat.c
compression.o: compression.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) compression.c
findLocation.o: findLocation.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) findLocation.c
codeLength.o: codeLength.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) codeLength.c
uniqchar.o: uniqchar.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) uniqchar.c
createMasterarray.o: createMasterarray.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF) createMasterarray.c
init.o: init.c headers.h declaration.h
	$(CC) $(CF) $(DF) init.c
openFile.o: openFile.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF)  openFile.c
mainMenu.o: mainMenu.c headers.h declaration.h dataStructure.h
	$(CC) $(CF) $(DF)  mainMenu.c
exitFail.o: exitFail.c headers.h declaration.h
	$(CC) $(CF) $(DF)  exitFail.c
main.o: main.c headers.h declaration.h
	$(CC) $(CF) $(DF)  main.c


clean:
	-rm  demo *.o
