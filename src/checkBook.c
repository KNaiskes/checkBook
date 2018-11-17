#include <stdio.h>
#include <string.h>

#include "dbFunctions.h"
#include "cli.h"

int main(int argc, char *argv)
{
	extern const char *dbName;
	dbName = "checks.db";

	/* testing */

	mainMenu();

	/*
	const char *dbName = "test.db";

	Check check;
	Check dcheck;

	strcpy(dcheck.Number, "20-30-20-25");

	strcpy(check.Recipient, "someNameY");
	strcpy(check.Number, "20-30-20-50");
	check.Amount = 1032.33;
	strcpy(check.Payday ,"2019-04-11");


	createDatabase(dbName);
	//insertToDatabase(dbName, check);

	printf("Recipient: %s, number: %s, amount: %f, Payday: %s\n", check.Recipient,
			check.Number, check.Amount, check.Payday);
	//deleteFromDatabase(dbName, dcheck);
	updateRecord(dbName, check, "20-30-20-23");

	*/

	return 0;
}
