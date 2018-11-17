#include <sqlite3.h>
#include <stdio.h>

#include "dbFunctions.h"

static sqlite3 *db;
static int *zErrMsg = 0;
static int rc;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for(int i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void createDatabase(const char *dbName)
{
	char *sql;
	rc = sqlite3_open(dbName, &db);
	
	if(rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	} else {
		fprintf(stdout, "Opened database successfully\n");
	}
	sql = "CREATE TABLE IF NOT EXISTS CHECKS("  \
	      "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
	      "RECIPIENT TEXT," \
	      "NUMBER CHAR(50)," \
	      "AMOUNT REAL," \
	      "PAYDAY CHAR(50) );";

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);
}

void addRecord(const char *dbName, Check check)
{

	char *sql = sqlite3_mprintf("INSERT INTO CHECKS (RECIPIENT, NUMBER, AMOUNT, PAYDAY)"
		       "VALUES ('%q','%q','%f','%q');"
		       , check.Recipient, check.Number, check.Amount, check.Payday);
	rc = sqlite3_open(dbName, &db);
	
	if(rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	} else {
		fprintf(stdout, "Opened database successfully\n");
	}
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Records created successfully\n");
	}
	sqlite3_close(db);

}

void deleteRecord(const char *dbName, Check check)
{
	char *sql = sqlite3_mprintf("DELETE FROM CHECKS WHERE NUMBER = ('%q');",
			check.Number);
	rc = sqlite3_open(dbName, &db);

	if(rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Opened database successfully\n");
	}
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Record deleted successfully\n");
	}
	sqlite3_close(db);
}

void updateRecord(const char *dbName, Check check, char *lookAmount)
{
	char *sql = sqlite3_mprintf("UPDATE CHECKS SET RECIPIENT = ('%q'),"
		       "NUMBER = ('%q'), AMOUNT = ('%f'), PAYDAY = ('%q')"
		      "WHERE NUMBER = ('%s') ",
		      check.Recipient, check.Number, 
		      check.Amount, check.Payday, lookAmount);

	rc = sqlite3_open(dbName, &db);

	if(rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Opened database successfully\n");
	}
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Record was successfully updated\n");
	}
	sqlite3_close(db);
}

int recordExists(const char *dbName, char *checkNumber)
{
	char *sql = sqlite3_mprintf("SELECT ID FROM CHECKS WHERE NUMBER = ('%q');",
			checkNumber);
	int exists;

	sqlite3_stmt *res;

	rc = sqlite3_open(dbName, &db);

	if(rc != SQLITE_OK) {
		fprintf(stderr, "Cannot open database in the check function: %s\n",
				sqlite3_errmsg(db));
		sqlite3_close(db);
	}

	rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

	int count = sqlite3_step(res);

	if (count == SQLITE_ROW) {
		exists = 0;
	} else {
		exists = -1;
	}

	sqlite3_finalize(res);
	sqlite3_close(db);

	return exists;
}
