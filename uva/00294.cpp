
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

#define SIEVE_SIZE 31624
bitset<SIEVE_SIZE> is_prime;
vector<int> primes;
void init_sieve() {
	is_prime.set();
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i*i < SIEVE_SIZE; ++i) {
		if (is_prime[i])
			for (int j = i*i; j < SIEVE_SIZE; j += i)
				is_prime[j] = false;
	}
}

void init_primes() {
	for (int i = 0; i < SIEVE_SIZE; ++i)
		if (is_prime[i])
			primes.push_back(i);
}

void factorize(int n, vector<pair<int, int> > & kf) {
#define ADD(x)\
	if (kf.size() == 0 || kf.back().first != x) {\
		kf.push_back(make_pair(x, 1));\
	} else {\
		++kf.back().second;\
	}

	if (!n) return;

	kf.resize(0);
	for (int i = 0; i < int(primes.size()) && SQR(primes[i]) <= n; ) {
		if (n%primes[i] == 0) {
			ADD(primes[i]);
			n /= primes[i];
		} else {
			++i;
		}
	}
	if (n > 1) {
		ADD(n);
	}
}

int get_div_num(int x) {
	vector<pair<int, int> > kf;
	factorize(x, kf);
	int dn = 1;
	for (vector<pair<int, int> >::iterator it = kf.begin(); it != kf.end(); ++it) {
		dn *= (it->second+1);
	}
	return dn;
}

int main() {
	init_sieve();
	init_primes();

	int test_n, x, y, n, max_dn, cur_dn;

	cin >> test_n;
	while (test_n--) {
		cin >> x >> y;

		n = x;
		max_dn = get_div_num(x);

		cout << "Between " << x << " and " << y << ", ";
		while (++x <= y) {
			cur_dn = get_div_num(x);
			if (cur_dn > max_dn) {
				max_dn = cur_dn;
				n = x;
			}
		}
		cout << n << " has a maximum of " << max_dn << " divisors.\n";
	}

	return 0;
}

