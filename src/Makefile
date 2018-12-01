
main: main.o dbFunctions.o cli.o
	$(CC) main.o dbFunctions.o cli.o -l sqlite3 -o checkbook

main.o: main.c
	$(CC) -c main.c

dbFunctions.o: dbFunctions.c
	$(CC) -c dbFunctions.c

cli.o: cli.c
	$(CC) -c cli.c

clean:
	rm *.o checkbook
