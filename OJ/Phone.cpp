#include <cstdio>

int main(void){
	int h1, m1, s1;
	int h2, m2, s2;
	scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);

	int interval = 3600 *(h2-h1) + 60 * (m2-m1) + (s2-s1);

	interval = interval < 0? interval+24 * 3600: interval;

	printf("%d\n", interval);

	return 0;
}