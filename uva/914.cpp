
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

#define diff_SIZE 150
#define sieve_SIZE 1000000

template <const int SIZE>
class sieve {
	private:
		bitset<SIZE> b;

	public:
		sieve() {
			b.set();
			b[0] = b[1] = 0;
			for (int i = 2; i*i < SIZE; ++i)
				if (b[i])
					for (int j = i*i; j < SIZE; j += i)
						b[j] = 0;
		}

		bool operator() (int i) {
			return b[i];
		}
};

int max(int * a, int size) {
	int m_i = 0;
	for (int i = 0; i < size; ++i)
		if (a[i] > a[m_i])
			m_i = i;
	return m_i;
}

int count(int * a, int size, int j) {
	int c = 0;
	for (int i = 0; i < size; ++i)
		c += (a[i] == a[j]);
	return c;
}

int main() {
	int diff[diff_SIZE];

	sieve<sieve_SIZE> is_prime;
	vector<int> primes;

	for (int i = 2; i < sieve_SIZE; ++i)
		if (is_prime(i))
			primes.push_back(i);

	int test_n, a, b;

	cin >> test_n;
	while (test_n--) {
		fill(diff, diff+diff_SIZE, 0);

		cin >> a >> b;

		vector<int>::iterator it = lower_bound(primes.begin(), primes.end(), a);

		for (++it; it != primes.end() && *it <= b; ++it)
			++diff[ *it-*(it-1) ];

		if (count(diff, diff_SIZE, max(diff, diff_SIZE)) > 1) {
			cout << "No jumping champion\n";
		} else {
			cout << "The jumping champion is " << max(diff, diff_SIZE) << endl;
		}
	}

	return 0;
}

