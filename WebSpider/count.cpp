#include <cstdio>
#include <cstring>
#include <cctype>

const int MAX_STR = 4096;

int main(void){
	char text[MAX_STR + 1];
	gets(text);

	int count[26];
	for (int i = 0; i < 26; i++){
		count[i] = 0;
	}

	int len = strlen(text);
	for (int i = 0; i < len; i++){
		char c = text[i];
		if (isalpha(c)){
			count[tolower(c) - 'a']++;
		}
	}

	for (int i = 0; i < 26; i++){
		if (count[i] != 0){
			printf("%c: %d\n", i + 'a', count[i]);
		}
	}

	return 0;
}