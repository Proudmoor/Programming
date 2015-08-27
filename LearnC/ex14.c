#include <stdio.h>
#include <ctype.h>

int CanPrintIt(char ch);
void PrintLetters(char arg[]);

void PrintArguments(int argc, char** argv){
	int i = 0;

	for(i = 0; i < argc; i++) {
		PrintLetters(argv[i]);
	}
}

void PrintLetters(char arg[]){
	int i = 0;

	for(i = 0; arg[i] != '\0'; i++){
		char ch = arg[i];

		if(CanPrintIt(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}
	printf("\n");
}

int CanPrintIt(char ch){
	return isalpha(ch) || isblank(ch);
}

int main(int argc, char** argv){
	PrintArguments(argc, argv);
	return 0;
}