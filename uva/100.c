#include <stdio.h>

long f(long);

long main()
{
	long i, j;
	long a, b;
	long l;
	long d;
	long ll;

	while (scanf("%ld%ld", &i, &j) != EOF) {

		if (j < i) {
			a = j;
			b = i;
		}
		else {
			a = i;
			b = j;
		}

		ll = 0;

		for (d = a; d <= b;) {
			l = f(d);

			if (ll < l) {
				ll = l;
			}

			d++;
		}

		printf("%ld %ld %ld\n", i, j, ll);
	}

	return 0;
}

long f(long n)
{
	long i;
	for (i = 1l; n != 1l; i++) {
		if(!(n%2))
			n /= 2;
		else
			n = 3l*n+1l;
	}

	return i;
}

