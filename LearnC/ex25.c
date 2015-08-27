#include "dbg.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>


#define MAX_DATA 100

int ReadString(char **outString, int maxBuffer) {
	*outString = calloc(1, maxBuffer + 1);
	check_mem(*outString);

	char *result = fgets(*outString, maxBuffer, stdin);
	check(result != NULL, "Input error.");

	return 0;

error:
	if(*outString) free(*outString);
	*outString = NULL;
	return -1;
}

int ReadInt(int *outInt){
	char *input = NULL;
	int rc = ReadString(&input, MAX_DATA);
	check(rc == 0, "Failed to read number.");

	*outInt = atoi(input);

	free(input);
	return 0;

error:
	if(input) free(input);
	return -1;
}

int ReadScan(const char *fmt,...){
	va_list arg;
	va_start(arg, fmt);

	int i = 0; int rc = 0;
	int *outInt = NULL;
	char *outChar = NULL;
	char **outString = NULL;
	int maxBuffer = 0;

	

	for(i = 0; fmt[i] != '\0'; i++){
		if(fmt[i] == '%'){
			i++;
			switch(fmt[i]){
				case '\0':
					sentinel("Invalid format, you ended with %%.");
					break;

				case 'd':
					outInt = va_arg(arg, int*);
					rc = ReadInt(outInt);
					check(rc == 0, "Failed to read int.");
					break;

				case 'c':
					outChar = va_arg(arg, char*);
					*outChar = fgetc(stdin);
					break;

				case 's':
					maxBuffer = va_arg(arg, int);
					outString = va_arg(arg, char **);
					rc = ReadString(outString, maxBuffer);
					check(rc == 0, "Failed to read string.");
					break;

				default:
					sentinel("Invaild format.");
			}
		} else {
			fgetc(stdin);
		}

		check(!feof(stdin) && !ferror(stdin), "Input error.");
	}

	va_end(arg);
	
	return 0;

error:
	va_end(arg);
	return -1;
}

int main(int argc, char** argv) {
	char *firstName = NULL;
	char initial = ' ';
	char *lastName = NULL;
	int age = 0;

	printf("What's your first name? ");
	int rc = ReadScan("%s", MAX_DATA, &firstName);
	check(rc == 0, "Failed first name.");

	printf("What's your initial? ");
	rc = ReadScan("%c\n", &initial);
	check(rc == 0, "Failed initial.");

	printf("What's you last name? ");
	rc = ReadScan("%s", MAX_DATA, &lastName);
	check(rc == 0, "Failed last name.");

	printf("How old are you? ");
	rc = ReadScan("%d", &age);

	printf("------RESULT ------\n");
	printf("First Name: %s", firstName);
	printf("Initial   : '%c'\n",initial);
	printf("Last Name : %s", lastName);
	printf("Age: %d\n", age);

	free(firstName);
	free(lastName);
	return 0;

error: 
	return -1;
}

























