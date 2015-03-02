#include <cmath>
#include <vector>
#include <bitset>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define N_MAX 1001
bitset<N_MAX> prime;
vector<int> primes, ans;

void gen_sieve() {
	prime.set();
	prime[0] = false;
	prime[1] = true;
	for (int i = 2; i*i < N_MAX; ++i)
		if (prime[i])
			for (int j = i*i; j < N_MAX; j += i)
				prime[j] = false;
}

int main() {
	gen_sieve();
	for (int i = 0; i < N_MAX; ++i)
		if (prime[i])
			primes.push_back(i);

	int N, C;
	while (cin >> N >> C) {
		cout << N << ' ' << C << ':';

		/* number of primes */
		int n = lower_bound(primes.begin(), primes.end(), N) - primes.begin() + 1;

		ans.resize(0);
		if (n%2) {
			for (int i = max(0, n/2-C+1); i < min(n/2+C-1, n); ++i)
				cout << ' ' << primes[i];
		} else {
			for (int i = max(0, n/2-C-1); i < min(n/2+C, n); ++i)
				cout << ' ' << primes[i];
		}
		cout << "\n\n";
	}

	return 0;
}

