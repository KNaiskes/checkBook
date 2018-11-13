#ifndef DBFUNCTIONS_H_
#define DBFUNCTIONS_H_

typedef struct Checks {
	char Recipient[50];
	char Number[20];
	double Amount;
	char Payday[20];
}Check;

void createDatabase(const char *dbName);
void insertToDatabase(const char *dbName, Check check);
void deleteFromDatabase(const char *dbName, Check check);
void updateRecord(const char *dbName, Check check, char *lookAmount);

#endif //DBFUNCTIONS_H_
