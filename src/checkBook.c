#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "dbFunctions.h"
#include "cli.h"

int main(int argc, char *argv)
{
	extern const char *dbName;
	dbName = "checks.db";

	if(!access(dbName, F_OK) != -1) {
		createDatabase(dbName);
	}

	mainMenu();

	return 0;
}
