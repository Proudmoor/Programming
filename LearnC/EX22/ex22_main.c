#include "ex22.h"
#include "../dbg.h"

const char *MY_NAME = "Zed A. Shaw";

void scope_demo(int count) {
	log_info("count is %d", count);

	if(count > 10) {
		int count = 100;

		log_info("count in this scope is %d", count);
	}

	log_info("count is at exit: %d", count);

	count = 3000;
	log_info("count after assign: %d", count);
}

int main(int argc, char** argv){
	log_info("My name: %s , age: %d", MY_NAME, GetAge());

	SetAge(100);

	log_info("My age is now: %d", GetAge());

	log_info("THE_SIZE is now: %d", THE_SIZE);
	PrintSize();

	THE_SIZE = 9;
	log_info("THE SIZE is now:%d", THE_SIZE);
	PrintSize();

	log_info("Ratio at first: %f", UpdateRatio(2.0));
	log_info("Ratio again: %f", UpdateRatio(10.0));
	log_info("Ratio once more: %f", UpdateRatio(300.0));

	int count = 4;
	scope_demo(count);
	scope_demo(count * 20);

	log_info("count after calling scope_demo: %d", count);

	return 0;
}