
#include <cstdio>
#include <bitset>
#include <iostream>
using namespace std;

#define SIEVE_SZ (1<<15)

bitset<SIEVE_SZ+1> prime;
void gen_sieve() {
	prime.set();
	prime[0] = prime[1] = 0;
	for (int i = 2; i*i <= SIEVE_SZ; ++i)
		if (prime[i])
			for (int j = i*i; j <= SIEVE_SZ; j += i)
				prime[j] = 0;
}

int a_sz = 0;
int a[ SIEVE_SZ ];

int main() {
	gen_sieve();
	for (int i = 2; i <= SIEVE_SZ; ++i)
		if (prime[i])
			a[ a_sz++ ] = i;

	while (1) {
		int n;
		cin >> n;
		if (!n)
			break;

		int ans = 0;
		for (int i = 0; (i < a_sz) && ((a[i]<<1) <= n); ++i) {
			ans += prime[ n-a[i] ];
		}
		cout << ans << endl;
	}

	return 0;
}

