
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

using namespace std;

#define sieve_SIZE 46341
bitset<sieve_SIZE> sieve;
void init_sieve() {
	sieve.set();
	sieve[0] = sieve[1] = false;
	for (int i = 2; i*i <= sieve_SIZE; ++i)
		if (sieve[i])
			for (int j = i*i; j <= sieve_SIZE; j += i)
				sieve[j] = false;
}

vector<int> primes;
void init_primes() {
	primes.reserve(sieve_SIZE);
	for (int i = 2; i < sieve_SIZE; ++i)
		if (sieve[i])
			primes.push_back(i);
}

inline
bool is_prime(int n) {
	if (n < sieve_SIZE)
		return sieve[n];
	for (int i = 0; i < int(primes.size()) && SQR(primes[i]) <= n; ++i)
		if (n%primes[i] == 0)
			return false;
	return true;
}

unsigned int L, U;
vector<int> a;

int main() {
	init_sieve();
	init_primes();

	a.reserve(1000000);

	while (cin >> L >> U) {
		a.resize(0);

		for (; L <= U; ++L)
			if (is_prime(L))
				a.push_back(L);

		if (a.size() < 2) {
			cout << "There are no adjacent primes.\n";
		} else {
			int min_i = 1, max_i = 1;
			for (int i = 2; i < int(a.size()); ++i) {
				if (a[i]-a[i-1] < a[min_i]-a[min_i-1]) {
					min_i = i;
				}
				if (a[i]-a[i-1] > a[max_i]-a[max_i-1]) {
					max_i = i;
				}
			}

			cout	<< a[min_i-1] << ',' << a[min_i] << " are closest, "
					<< a[max_i-1] << ',' << a[max_i] << " are most distant.\n";
		}
	}

	return 0;
}

