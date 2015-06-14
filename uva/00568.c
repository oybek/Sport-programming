
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	int i, m, n;
	for ( ; scanf("%d", &n) != EOF; ) {
		m = 1;

		for (i = 2; i <= n; ++i) {
			m *= i;
			for ( ; !(m % 10); m /= 10);
			m %= 100000;
		}

		printf("%5d -> %d\n", n, m%10);
	}

	return 0;
}

