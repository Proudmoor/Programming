#include <stdio.h>

int main(int argc, char* argv[]){

	printf("You have %d arguments\n", argc);

	int i = 0, j =0;
	for(i = 1; i < argc; i++){
		for(j = 0; argv[i][j] != '\0'; j++){
			char letter = argv[i][j];

			switch(letter){
				case 'a':
				case 'A':
					printf("%d: 'A'\n", j);
					break;

				case 'e':
				case 'E':
					printf("%d: 'E'\n", j);
					break;

				case 'i':
				case 'I':
					printf("%d: 'I'\n", j);
					break;

				case 'o':
				case 'O':
					printf("%d: 'O'\n", j);
					break;

				case 'u':
				case 'U':
					printf("%d: 'U'\n", j);
					break;

				default:
					printf("%d: '%c' is not a vowel\n", j, letter);
			}
		}
	}

	return 0;
}