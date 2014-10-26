
#include <cstdio>
#include <iostream>
using namespace std;

#define every(i, a, b) for (int i = (a); i <= int(b); ++i)
#define repeat(n) every (i, 1, n)

int freq[ 256 ];
char s[ 2001 ];

bool is_prime(int n) {
	if (n <= 1)	return false;
	if (n == 2)	return true;
	if (!(n%2))	return false;

	for (int i = 3; i*i <= n; i += 2)
		if (!(n%i))
			return false;

	return true;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int tt = 1; tt <= N; ++tt) {
		fill(freq, freq+256, 0);

		scanf("%s", s);
		for (char * c = s; *c; ++c) {
			++freq[ int(*c) ];
		}

		bool empty = true;
		printf("Case %d: ", tt);
		for (int i = 0; i < 256; ++i)
			if (is_prime(freq[i])) {
				putchar(i);
				empty = false;
			}

		puts(empty ? "empty": "");
	}

	return 0;
}

