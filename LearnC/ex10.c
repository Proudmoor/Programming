#include <stdio.h>
int main(int argc, char** argv){
	int i = 0;

	//go through each string in argv
	for (i = 1;i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}

	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};
	int numStates = 4;

	for(i = 0; i < numStates; i++) {
		printf("states %d: %s\n", i, states[i]);
	}

	return 0;
}