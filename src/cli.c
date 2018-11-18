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
			deleteRecordMenu();
			break;
		case 'U':
			updateRecordMenu();
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

void deleteRecordMenu()
{
	char checkNumber[12];

	printf("************************************************************\n"
	       "* Delete a record					   *\n"
	       "************************************************************\n"
	       "\n");
	printf("************************************************************\n"
	       "* Available records					   *\n"
	       "************************************************************\n"
	       "\n");

	listAllrecords(dbName);

	printf("\nEnter check's number that you want to delete: ");
	scanf("%s", checkNumber);

	if(recordExists(dbName, checkNumber) == 0) {
		deleteRecord(dbName, checkNumber);
		printf("Record has successfully deleted!\n");
	} else {
		printf("There is no record with number: %s\n", checkNumber);
	}

}

void updateRecordMenu()
{
	char checkNumber[12];
	Check checkUpdate;

	printf("************************************************************\n"
	       "* Delete a record					   *\n"
	       "************************************************************\n"
	       "\n");
	printf("Enter check's number that you want to update: \n");
	scanf("%s", checkNumber);

	printf("Update recipient: \n");
	scanf("%s", &checkUpdate.Recipient);

	printf("Update number: \n");
	scanf("%s", &checkUpdate.Number);

	printf("Update amount: \n");
	scanf("%f", &checkUpdate.Amount);

	printf("Update payday: \n");
	scanf("%s", &checkUpdate.Payday);

	updateRecord(dbName, checkUpdate, checkNumber);

}
