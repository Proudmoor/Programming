#include <string>
#include <iostream>

int main(int args, char** argv){
	string in;
	std::cin >> in;
	std::cout << in << std::endl;
	reverse(in, str.length());
	return 0;

}

void reverse(string str, int len){
	if(str== nullptr || len <=0)
		return;
	int front = 0;
	--len;
	while(front < len){
		str[front] ^= str[len];
		str[len]   ^= str[front];
		str[front] ^= str[len];
		++front;
		--len;
	}
}