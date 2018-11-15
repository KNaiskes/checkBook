#include <stdio.h>
#include <ctype.h>

#include "cli.h"

void mainMenu()
{
	char option;

	printf("************************************************************\n"
	       "* Welcome to Check Book Commanl Line Interface             *\n"
	       "************************************************************\n"
	       "\n");
	printf("Enter:\n"
			"A to add a new record \n"
			"D to delete a record \n"
			"U to update/change a record\n"
	      );

	printf("> ");
	option = getchar();

	switch(toupper(option)) {
		case 'A':
			printf("Have A\n");
			break;
		case 'D':
			printf("Have D\n");
			break;
		case 'U':
			printf("Have U\n");
			break;
	}

}
