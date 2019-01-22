#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "cli.h"
#include "dbFunctions.h"

#define RECIPIENTLEN 4
#define NUMBERLEN 12
#define STRINGBUFFER 50

const char *dbName;

void mainMenu()
{

    char option;

    do {
        printf("************************************************************\n"
                "* Welcome to Check Book Commanl Line Interface             *\n"
                "************************************************************\n"
                "\n");
        printf("Enter:\n"
                "A to add a new record \n"
                "D to delete a record \n"
                "U to update/change a record\n"
                "L to list all available records\n"
                "Q to exit the program\n"
              );

        printf("> ");
        option = getchar();

        switch(toupper(option)) {
            case 'A':
                addRecordMenu();
                break;
            case 'D':
                deleteRecordMenu();
                break;
            case 'U':
                updateRecordMenu();
                break;
            case 'Q':
                break;
            case 'L':
                printf("*************************\n"
                        "* Available records     *\n"
                        "*************************\n");
                listAllrecords(dbName);
                while((getchar()) != '\n'); // clear input buffer
                break;
            default:
                printf("\nInvalid option. Try again!\n");
        }
    } while(toupper(option) != 'Q');
}

void addRecordMenu()
{
    Check addCheck;

    printf("************************************************************\n"
            "* Add a new record					   *\n"
            "************************************************************\n"
            "\n");
    while((getchar()) != '\n'); // clear input buffer
    printf("Enter check's recipient: ");
    while(fgets(addCheck.Recipient, STRINGBUFFER, stdin)  == 1) {
        if(strlen(addCheck.Recipient) < RECIPIENTLEN) {
            printf("Recipient has to be at least 4 characters long\n");
            printf("Try again!\n");
            printf("> ");
        } else break;
    }

    printf("\n Enter check's number: ");
    while(scanf("%s", &addCheck.Number) == 1) {
        if(strlen(addCheck.Number) != NUMBERLEN) {
            printf("Check number has to be 12 characters long\n");
            printf("Try again!\n");
            printf("> ");
        } else break;
    }

    printf("\n Enter check's amount: ");
    while(scanf("%lf", &addCheck.Amount) == 1) {
        if(addCheck.Amount <= 0) {
            printf("Amount cannot be equal or less than zero \n");
            printf("Try again\n");
            printf("> ");
        } else break;
    }

    printf("\n Enter check's payday: ");
    scanf("%s", &addCheck.Payday);
    while((getchar()) != '\n'); // clear input buffer

    addRecord(dbName, addCheck);
}

void deleteRecordMenu()
{
    char checkNumber[NUMBERLEN];

    printf("************************************************************\n"
            "* Delete a record					   *\n"
            "************************************************************\n"
            "\n");
    printf("************************************************************\n"
            "* Available records					   *\n"
            "************************************************************\n"
            "\n");

    listAllrecords(dbName);

    printf("\nEnter check's number that you want to delete: ");
    while(scanf("%s", checkNumber) == 1) {
        if(strlen(checkNumber) != NUMBERLEN) {
            printf("All check's numbers are 12 characters long\n");
            printf("Try again!\n");
            printf("> ");
        } else break;
    }

    if(recordExists(dbName, checkNumber) == 0) {
        deleteRecord(dbName, checkNumber);
        printf("Record has successfully deleted!\n");
    } else {
        printf("There is no record with number: %s\n", checkNumber);
    }
}

void updateRecordMenu()
{
    char checkNumber[NUMBERLEN];
    Check checkUpdate;

    printf("************************************************************\n"
            "* Update record					   *\n"
            "************************************************************\n"
            "\n");
    printf("************************************************************\n"
            "* Available records					   *\n"
            "************************************************************\n"
            "\n");

    listAllrecords(dbName);

    printf("Enter check's number that you want to update: \n");
    while(scanf("%s", checkNumber) == 1) {
        if(strlen(checkNumber) != NUMBERLEN) {
            printf("All check's numbers are 12 characters long\n");
            printf("Try again!\n");
            printf("> ");
        } else break;
    }

    while((getchar()) != '\n'); // clear input buffer
    printf("Update recipient: \n");
    while(fgets(checkUpdate.Recipient, STRINGBUFFER, stdin) == 1) {
        if(strlen(checkUpdate.Recipient) < RECIPIENTLEN) {
            printf("Recipient has to be at least 4 characters long\n");
            printf("Try again!\n");
            printf("> ");
        } else break;
    }

    printf("Update number: \n");
    while(scanf("%s", &checkUpdate.Number) == 1) {
        if(strlen(checkUpdate.Number) != NUMBERLEN) {
            printf("Check number has to be 12 characters long\n");
            printf("Try again!\n");
            printf("> ");
        } else break;
    }

    printf("Update amount: \n");
    while(scanf("%f", &checkUpdate.Amount) == 1) {
        if(checkUpdate.Amount <= 0) {
            printf("Amount cannot be equal or less than zero \n");
            printf("Try again\n");
            printf("> ");
        } else break;
    }

    printf("Update payday: \n");
    scanf("%s", &checkUpdate.Payday);

    updateRecord(dbName, checkUpdate, checkNumber);

}
