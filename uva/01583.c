
#include <stdio.h>

#define N_MAX 100045
int test_n, n, i, generator[N_MAX];

int digit_sum(int n) {
	register int s = 0;
	for (; n > 0; n /= 10)
		s += n%10;

	return s;
}

int main() {
	for (i = N_MAX-1; i >= 0; --i)
		generator[i+digit_sum(i)] = i;

	scanf("%d", &test_n);
	while (test_n--) {
		scanf("%d", &n);
		printf("%d\n", generator[n]);
	}

	return 0;
}

