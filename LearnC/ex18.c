#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char* message) {
	if(errno) {
		perror(message);
	} else {
		printf("Error: %s\n", message);
	}

	exit(1);
}

typedef int(*CompareCb)(int a, int b);

int *BubbleSort(int *numbers, int count, CompareCb cmp){
	int temp = 0;
	int i = 0, j = 0;
	int *target = malloc(count * sizeof(int));

	if(!target) die("Memory error");

	memcpy(target, numbers, count * sizeof(int));

	for(i = 0; i < count; i++) {
		for(j = 0; j< count - 1; j++) {
			if(cmp(target[j], target[j+1]) > 0){
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}
	return target;
}

int SortedOrder(int a, int b) {
	return a - b;
}

int ReverseOrder(int a, int b){
	return b - a;
}

int StrangeOrder(int a, int b) {
	if(a == 0 || b == 0) {
		return 0;
	} else {
		return a % b;
	}
}

void TestSorting(int *numbers, int count, CompareCb cmp){
	int i = 0;
	int *sorted = BubbleSort(numbers, count, cmp);
	if(!sorted) die("Failed to sort as requested.");

	for(i = 0; i < count; i++){
		printf("%d ", sorted[i]);
	}
	printf("\n");

	free(sorted);
}

int main(int argc, char* argv[]){
	if(argc < 2) die ("USAGE: ex18 4 3 1 5 6");

	int count = argc - 1;
	int i = 0;
	char **inputs = argv +1;

	int *numbers = malloc(count * sizeof(int));
	if(!numbers) die("Memory erro");

	for(i = 0; i < count; i++){
		numbers[i] = atoi(inputs[i]);
	}

	TestSorting(numbers, count, SortedOrder);
	TestSorting(numbers, count, ReverseOrder);
	TestSorting(numbers, count, StrangeOrder);

	free(numbers);

	return 0;
}




















