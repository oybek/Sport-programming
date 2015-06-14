
#include <cstdio>
#include <iostream>
using namespace std;

int sum_part(int n, int d) {
	if (n%d == 0) return -1;
	return n/d + n%d;
}

bool is_kaprekar(int n) {
	int n_sqr = n*n;

	for (int d = 10; d <= n_sqr; d *= 10) {
		if (sum_part(n_sqr, d) == n)
			return true;
	}
	return false;
}

int main() {
	int n, a, b;
	scanf("%d", &n);

	bool first = true;
	for (int tt = 1; tt <= n; ++tt) {
		bool least_one = false;

		scanf("%d%d", &a, &b);

		if (first) first = false;
		else printf("\n");
		printf("case #%d\n", tt);
		while (a <= b) {
			if (is_kaprekar(a)) {
				least_one = true;
				printf("%d\n", a);
			}
			++a;
		}
		if (!least_one)
			printf("no kaprekar numbers\n");
	}

	return 0;
}

