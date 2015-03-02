
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define n_MAX 10000

bitset<n_MAX> isprime;
vector<int> primes;

void gen_sieve() {
	isprime.set();
	isprime[0] = isprime[1] = false;
	for (int i = 2; i*i < n_MAX; ++i)
		if (isprime[i])
			for (int j = i*i; j < n_MAX; j += i)
				isprime[j] = false;
}

void gen_primes() {
	for (int i = 2; i < n_MAX; ++i)
		if (isprime[i])
			primes.push_back(i);
}

void factorize(int n, map<int, int> & canon) {
	for (int i = 0; SQR(primes[i]) <= n; ) {
		if (n%primes[i] == 0) {
			if (canon.find(primes[i]) == canon.end()) {
				canon[primes[i]] = 1;
			} else {
				++canon[primes[i]];
			}
			n /= primes[i];
		} else {
			++i;
		}
	}
	if (n > 1) {
		if (canon.find(n) == canon.end()) {
			canon[n] = 1;
		} else {
			++canon[n];
		}
	}
}

int main() {
	int test_n, m, n;
	map<int, int> canon; /* canonical form of number */

	gen_sieve();
	gen_primes();

	cin >> test_n;
	for (int test_i = 1; test_i <= test_n; ++test_i) {
		/* prepare stage */
		canon.clear();

		/* input stage */
		cin >> m >> n;

		/* find: a : n! | m^a */
		for (; n > 1; --n)
			factorize(n, canon);

		cout << "Case " << test_i << ":\n";
		if (canon.find(m) == canon.end()) {
			cout << "Impossible to divide\n";
		} else {
			cout << canon[m] << endl;
		}
	}

	return 0;
}

