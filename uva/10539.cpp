
#include <cstdio>
#include <bitset>
#include <iostream>
#include <algorithm>
using namespace std;

#define every(i, a, b) for (int i = (a); i <= int(b); ++i)
#define repeat(n) every (i, 1, n)

typedef long long int64;

#define SIEVE_SZ 1000004

bitset<SIEVE_SZ> prime;
void gen_sieve() {
	prime.set();
	prime[0] = prime[1] = 0;
	for (int i = 2; i*i <= SIEVE_SZ; ++i)
		if (prime[i])
			for (int j = i*i; j <= SIEVE_SZ; j += i)
				prime[j] = false;
}

#define N_MAX 1 ## 000000 ## 000000

int main() {
	/*only exps of primes is "almost prime" */
	const int max_a_sz = 100000;
	int64 a[ max_a_sz ], i, j, i_sqr;
	int a_sz = 0;

	gen_sieve();

	for (j = 2*2; j < N_MAX; j <<= 1)
		a[ a_sz++ ] = j;

	for (i = 3; i < SIEVE_SZ; i += 2) {
		if (!prime[i])
			continue;
		i_sqr = i*i;
		if (i_sqr >= N_MAX)
			break;

		for (j = i_sqr; j < N_MAX; j *= i)
			a[ a_sz++ ] = j;
	}
	/*a_sz = 724*/
	sort(a, a+a_sz);

	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int64 low, high;
		scanf("%lld %lld", &low, &high);

		int64 * p1 = lower_bound(a+0, a+a_sz, low);
		int64 * p2 = upper_bound(a+0, a+a_sz, high)-1;

		printf("%ld\n", p2-p1+1);
	}

	return 0;
}

