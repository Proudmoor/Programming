#include <stdio.h>
int main (int argc, char** argv) {
	int i = 0;
	if(argc == 1){
		printf("You have only one argument.\n");
	} else if(argc > 1&& argc < 5){
		printf("Here are the arguments: \n");
		for(i = 1; i < argc; i++){
			printf("arg %d: %s\n", i, argv[i]);
		}
	} else {
		printf("You have two much arguments\n");
	}

	return 0;
}