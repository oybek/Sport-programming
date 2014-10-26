
#include <cstdio>
#include <bitset>
#include <iostream>
using namespace std;

/*bool is_prime(int n) {*/
	/*if (n <= 1) return false;*/
	/*if (n == 2) return true;*/
	/*if (!(n%2)) return false;*/
	/*for (int i = 3; i*i <= n; i += 2)*/
		/*if (!(n%i))*/
			/*return false;*/
	/*return true;*/
/*}*/

#define SIEVE_SZ 1000000
bitset<SIEVE_SZ> prime;
void gen_sieve() {
	prime.set();
	prime[0] = prime[1] = 0;
	for (int i = 2; i*i < SIEVE_SZ; ++i)
		if (prime[i])
			for (int j = i*i; j < SIEVE_SZ; j += i)
				prime[j] = 0;
}

int dig_sum(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n%10;
		n /= 10;
	}
	return sum;
}

#define SIZE 1000000

int main() {
	gen_sieve();

	int N, i, j, sum[ SIZE ];

	sum[0] = 0;
	for (i = 1; i < SIZE; ++i)
		sum[i] = sum[i-1] + (prime[i] && prime[ dig_sum(i) ]);

	scanf("%d", &N);
	while (N--) {
		scanf("%d%d", &i, &j);
		printf("%d\n", sum[j] - sum[i-1]);
	}

	return 0;
}

