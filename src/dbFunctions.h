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

#endif //DBFUNCTIONS_H_
