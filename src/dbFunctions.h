#ifndef DBFUNCTIONS_H_
#define DBFUNCTIONS_H_

typedef struct Checks {
	char Recipient[50];
	char Number[20];
	double Amount;
	char Payday[20];
}Check;

void createDatabase(const char *dbName);
void addRecord(const char *dbName, Check check);
void deleteRecord(const char *dbName, Check check);
void updateRecord(const char *dbName, Check check, char *lookAmount);

#endif //DBFUNCTIONS_H_
