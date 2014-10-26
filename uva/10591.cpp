
#include <set>
#include <cstdio>
#include <cassert>
#include <iostream>
using namespace std;

#define every(i, a, b) for (int i = (a); i <= int(b); ++i)
#define repeat(n) every (i, 1, n)

int dig_sqr_sum(int n) {
	int sum = 0;
	while (n > 0) {
		sum += (n%10)*(n%10);
		n /= 10;
	}
	return sum;
}

int main() {
	set<int> S;
	int N, n;

	scanf("%d", &N);
	for (int tt = 1; tt <= N; ++tt) {
		scanf("%d", &n);

		printf("Case #%d: %d is ", tt, n);

		S.clear();
		while (1) {
			if (n == 1) {
				printf("a Happy number.\n");
				break;
			} else
			if (S.find(n) != S.end()) {
				printf("an Unhappy number.\n");
				break;
			} else {
				S.insert(n);
			}

			n = dig_sqr_sum(n);
		}
	}

	return 0;
}

