#include <stdio.h>
#define SIZE 10000
int main() {
	int n;
	unsigned long long a[ SIZE+1 ];

	register int i;
	a[1] = 3;
	for (i = 2; i <= SIZE; ++i)
		a[i] = a[i-1] + (3*i*(i+1)>>1);

	scanf("%d", &n);
	printf("%llu", a[n]);

	return 0;
}

