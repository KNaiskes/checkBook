#include <sqlite3.h>
#include <stdio.h>

#include "dbFunctions.h"

static sqlite3 *db;
static *zErrMsg = 0;
static int rc;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for(int i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void createDatabase(char *dbName)
{
	char *sql;
	rc = sqlite3_open(dbName, &db);
	
	if(rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	} else {
		fprintf(stdout, "Opened database successfully\n");
	}
	sql = "CREATE TABLE CHECKS("  \
	      "ID INT PRIMARY KEY NOT NULL," \
	      "RECIPIENT TEXT    NOT NULL," \
	      "NUMBER CHAR(50) NOT NULL," \
	      "AMOUNT REAL NOT NULL," \
	      "PAYDAY CHAR(50) );";

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);
	return 0;

}

void insertToDatabase(char *dbName)
{

	char *sql;
	rc = sqlite3_open(dbName, &db);
	
	if(rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	} else {
		fprintf(stdout, "Opened database successfully\n");
	}
	 sql = "INSERT INTO CHECKS (ID, RECIPIENT, NUMBER, AMOUNT, PAYDAY)" \
	         "VALUES (1, 'company1', '20-20-30', 1024, '19-04-04' ); " \
	         "INSERT INTO CHECKS (ID,RECIPIENT,NUMBER,AMOUNT,PAYDAY)" \
	         "VALUES (2, 'company2', '30-20-12',3503, '20-04-02' );";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Records created successfully\n");
	}
	sqlite3_close(db);
	return 0;

}
