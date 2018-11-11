#include <stdio.h>
#include "dbFunctions.h"

int main(int argc, char *argv)
{
	const char *dbName = "test.db";

	createDatabase(dbName);
	insertToDatabase(dbName);
	return 0;
}
