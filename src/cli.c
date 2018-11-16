#include <stdio.h>
#include <ctype.h>

#include "cli.h"
#include "dbFunctions.h"

const char *dbName;

void mainMenu()
{

	char option;

	printf("************************************************************\n"
	       "* Welcome to Check Book Commanl Line Interface             *\n"
	       "************************************************************\n"
	       "\n");
	printf("Enter:\n"
			"A to add a new record \n"
			"D to delete a record \n"
			"U to update/change a record\n"
	      );

	printf("> ");
	option = getchar();

	switch(toupper(option)) {
		case 'A':
			addRecordMenu();
			break;
		case 'D':
			printf("Have D\n");
			break;
		case 'U':
			printf("Have U\n");
			break;
	}

}

void addRecordMenu()
{
	Check addCheck;

	printf("************************************************************\n"
	       "* Add a new record					   *\n"
	       "************************************************************\n"
	       "\n");
	printf("Enter check's recipient: ");
	scanf("%s", &addCheck.Recipient);

	printf("\n Enter check's number: ");
	scanf("%s", &addCheck.Number);

	printf("\n Enter check's amount: ");
	scanf("%lf", &addCheck.Amount);

	printf("\n Enter check's payday: ");
	scanf("%s", &addCheck.Payday);

	addRecord(dbName, addCheck);
}
