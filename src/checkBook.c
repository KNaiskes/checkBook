#include <stdio.h>
#include <string.h>

#include "dbFunctions.h"
#include "cli.h"

int main(int argc, char *argv)
{
	extern const char *dbName;
	dbName = "checks.db";

	mainMenu();

	return 0;
}
