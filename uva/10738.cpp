
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

#define sieve_SIZE 1000000
#define primes_SIZE 80000

bitset<sieve_SIZE> is_prime;
vector<int> primes;

void gen_sieve() {
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i*i < sieve_SIZE; ++i)
		if (is_prime[i])
			for (int j = i*i; j < sieve_SIZE; j += i)
				is_prime[j] = 0;
}

void gen_primes() {
	primes.reserve(primes_SIZE);
	for (int i = 0; i < sieve_SIZE; ++i)
		if (is_prime[i])
			primes.push_back(i);
}

int get_mu(int n) {
	if (n == 1) return 1;

	int pfactor_n = 0, last = -1;
	vector<int>::iterator it = primes.begin();

	while (it != primes.end() && *it < n && !is_prime[n]) {
		if (n%*it == 0) {
			/* number is not square free */
			if (*it == last)
				return 0;
			++pfactor_n;
			n /= *it;
			last = *it;
		} else {
			++it;
		}
	}
	if (n > 1) {
		if (n == last)
			return 0;
		++pfactor_n;
	}

	return (pfactor_n % 2 ? -1 : 1);
}

#define N_MAX 1000001

int N, mu[N_MAX], M[N_MAX];

int main() {
	gen_sieve();
	gen_primes();

	M[0] = 0;
	for (int i = 1; i < N_MAX; ++i) {
		mu[i] = get_mu(i);
		M[i] = M[i-1] + mu[i];
	}

	while (1) {
		cin >> N;
		if (!N)
			break;

		cout	<< setw(8) << N
				<< setw(8) << mu[N]
				<< setw(8) << M[N]
				<< endl;
	}

	return 0;
}

