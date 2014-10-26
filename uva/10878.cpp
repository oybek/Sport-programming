
#include <cstdio>
#include <iostream>
using namespace std;

#define every(i, a, b) for (int i = (a); i <= int(b); ++i)
#define repeat(n) every (i, 1, n)

char decode(char * s) {
	char c = 0;
	while (*s != '|') {
		if (*s == '.') {
			++s;
			continue;
		}

		c <<= 1;
		c |= (*s == 'o');
		++s;
	}
	return c;
}

int main() {
	const int size = 32;
	char s[ size ];

	while (fgets(s, size,stdin)) {
		if (*s == '_')
			continue;
		putchar(decode(s+1));
	}

	return 0;
}

