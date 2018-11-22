
checkbook: checkBook.o dbFunctions.o cli.o
	$(CC) checkBook.o dbFunctions.o cli.o -l sqlite3 -o checkbook

checkbook.o: checkbook.c
	$(CC) -c checkBook.c

dbFunctions.o: dbFunctions.c
	$(CC) -c dbFunctions.c

cli.o: cli.c
	$(CC) -c cli.c

clean:
	rm *.o checkbook
