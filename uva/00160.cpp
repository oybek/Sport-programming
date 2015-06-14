
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_SIZE 200

int f[MAX_SIZE];

void factorize(int n) {
	if (!n) return;
	int i, c, lim;

	for (c = n; c%2 == 0; c /= 2)
		++f[2];

	lim = int(sqrt(c))+1;
	for (i = 3; i <= lim; ) {
		if (c%i == 0) {
			++f[i];
			c /= i;
			lim = int(sqrt(c))+1;
		} else i += 2;
	}

	if (c > 1) ++f[c];
}

int main() {
	int n;
	for (;;) {
		cin >> n;
		if (!n)
			break;

		fill(f, f+MAX_SIZE, 0);
		for (int i = 2; i <= n; ++i)
			factorize(i);

		printf("%3d! =", n);
		int m = 0;
		for (int i = 2; i <= n; ++i) {
			if (f[i] > 0) {
				if (++m > 15) {
					printf("\n      ");
					m = 1;
				}
				printf("%3d", f[i]);
			}
		}
		printf("\n");
	}

	return 0;
}

