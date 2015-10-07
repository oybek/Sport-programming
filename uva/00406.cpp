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
	prime[0] = prime[1] = false;
	for (int i = 2; i*i < N_MAX; ++i)
		if (prime[i])
			for (int j = i*i; j < N_MAX; j += i)
				prime[j] = false;
	prime[1] = true;
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
		int n = primes.size()-1;
		while (primes[n] > N)
			--n;

		ans.resize(0);
		if (n%2) {
			ans.push_back(primes[n/2+1]);
			for (int t = 0; t < C-1; ++t)
				ans.push_back(primes[n/2-t]);
			for (int t = 0; t < C-1; ++t)
				ans.push_back(primes[n/2+2+t]);
		} else {
			for (int t = 0; t < C; ++t)
				ans.push_back(primes[n/2-t]);
			for (int t = 0; t < C; ++t)
				ans.push_back(primes[n/2+1+t]);
		}

		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); ++i)
			cout << ' ' << ans[i];
		cout << "\n\n";
	}

	return 0;
}

