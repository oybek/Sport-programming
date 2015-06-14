
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

#if 0
#define SIEVE_SIZE 10000
bitset<SIEVE_SIZE> sieve;
void init_sieve() {
	sieve.set();
	sieve[0] = sieve[1] = false;
	for (int i = 2; i*i <= SIEVE_SIZE; ++i)
		if (sieve[i])
			for (int j = i*i; j <= SIEVE_SIZE; j += i)
				sieve[j] = false;
}

vector<int> primes;
void init_primes() {
	primes.reserve(SIEVE_SIZE);
	for (int i = 2; i < SIEVE_SIZE; ++i)
		if (sieve[i])
			primes.push_back(i);
}

bool is_prime(int n) {
	for (int i = 0; i < int(primes.size()) && SQR(primes[i]) <= n; ++i)
		if (n%primes[i] == 0)
			return false;
	return true;
}

bool is_anagrammatic_prime(int n) {
	string s = to_string(n);
	sort(s.begin(), s.end());
	do {
		if (!is_prime(atoi(s.c_str()))) {
			return false;
		}
	} while (next_permutation(s.begin(), s.end()));
	return true;
}
#endif

int a[] = { 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991 };
int a_sz = sizeof(a)/sizeof(int), n;

int clp10(int n) {
	int c = 1;
	for (; n > 0; n /= 10)
		c *= 10;
	return c;
}

int main() {
	while (1) {
		cin >> n;
		if (!n) break;
		int * p = lower_bound(a, a+a_sz, n+1);
		cout << (p == a+a_sz || *p > clp10(n) ? 0 : *p) << endl;
	}

	return 0;
}

