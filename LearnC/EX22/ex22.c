#include <stdio.h>
#include "ex22.h"
#include "../dbg.h"

int THE_SIZE = 1000;

static int THE_AGE = 37;

int GetAge() {
	return THE_AGE;
}

void SetAge(int age) {
	THE_AGE = age;
}

double UpdateRatio(double newRatio) {
	static double ratio = 1.0;
	double oldRatio = ratio;
	ratio = newRatio;

	return oldRatio;
}

void PrintSize(){
	log_info("I think size is: %d", THE_SIZE);
}


