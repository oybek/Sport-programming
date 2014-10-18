#include <cstdio>
#include <cmath>

int main(int argc, char ** argv) {
	long n, k;
	scanf("%ld%ld", &n, &k);

	n--;

	long t = 0;
	for (long i = 1; (i <= k) && (n > 0); i <<= 1) {
		++t;
		n-=i;
	}

	if (n > 0) {
		t += n/k;

		if (n%k)
			++t;
	}

	printf("%ld\n", t);

	return 0;
}
