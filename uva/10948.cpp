
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
bitset<sieve_SIZE> isprime;
vector<int> primes;

void init_sieve() {
	isprime.set();
	isprime[0] = isprime[1] = false;
	for (int i = 2; i*i < sieve_SIZE; ++i)
		if (isprime[i])
			for (int j = i*i; j < sieve_SIZE; j += i)
				isprime[j] = false;
}

void init_primes() {
	for (int i = 2; i < sieve_SIZE; ++i)
		if (isprime[i])
			primes.push_back(i);
}

int main() {
	init_sieve();
	init_primes();

	int N;
	while (1) {
		cin >> N;
		if (!N)
			break;

		int a = -1, b;
		for (vector<int>::iterator it = primes.begin(); it != primes.end() && (*it*2 <= N); ++it) {
			if (isprime[N-*it]) {
				if (a == -1 || a-b < N-*it*2) {
					a = N-*it;
					b = *it;
				}
			}
		}
		cout << N << ":\n";
		if (a == -1) {
			cout << "NO WAY!\n";
		} else {
			cout << b << '+' << a << endl;
		}
	}

	return 0;
}

