#include <stdio.h>
#include <string.h>

#include "dbFunctions.h"

int main(int argc, char *argv)
{
	const char *dbName = "test.db";

	/* testing */
	Check check;

	strcpy(check.Recipient, "someName");
	strcpy(check.Number, "20-30-20-20");
	check.Amount = 2032.33;
	strcpy(check.Payday ,"2019-04-12");


	createDatabase(dbName);
	insertToDatabase(dbName, check);

	printf("Recipient: %s, number: %s, amount: %f, Payday: %s\n", check.Recipient,
			check.Number, check.Amount, check.Payday);


	return 0;
}
