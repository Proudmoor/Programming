#include <iostream>

int main(int argc, char** argv){
	int *p = nullptr;
	int a = 100;
	p = &a;
	std::cout << *p << std::endl;
}