
#include <stdio.h>

int main()
{
	register int i;
	int a, b, t;

	scanf("%d", &t);
	for ( i = 1; i <= t; ++i )
	{
		scanf("%d%d", &a, &b);

		a += !(a&1);
		b -= !(b&1);
		a = (a-1) >> 1;
		b = (b+1) >> 1;

		printf("Case %d: %d\n", i, b*b - a*a);
	}

	return 0;
}

