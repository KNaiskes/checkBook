
main: main.o dbFunctions.o cli.o logFile.o
	$(CC) main.o dbFunctions.o cli.o logFile.o -l sqlite3 -o checkbook

main.o: main.c
	$(CC) -c main.c

dbFunctions.o: dbFunctions.c
	$(CC) -c dbFunctions.c

cli.o: cli.c
	$(CC) -c cli.c

logFile.o: logFile.c
	$(CC) -c logFile.c

clean:
	rm *.o checkbook
	rm logs.log
