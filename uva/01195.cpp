
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

vector<int> primes;
bool is_prime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (!(n%2)) return false;
	for (int d = 3; d*d <= n; d += 2)
		if (n%d == 0)
			return false;
	return true;
}

#define SIZE 10000

int m, a, b;

void gen_primes() {
	for (int d = 2; d <= SIZE; ++d)
		if (is_prime(d))
			primes.push_back(d);
}

bool is_good(int p, int q) {
	return (p*q <= m) && (a*q <= p*b) && (p*b <= b*q);
}

int main() {
	gen_primes();

	struct {
		int p, q;
	} ans;

	while (true) {
		cin >> m >> a >> b;
		if (!m && !a && !b)
			break;

		ans.p = ans.q = 0;

		for (int i = 0; i < primes.size(); ++i)
			for (int j = i; j < primes.size(); ++j)
				if (is_good(primes[i], primes[j]) && ans.q*ans.p < primes[i]*primes[j]) {
					ans.p = primes[i];
					ans.q = primes[j];
				}

		cout << ans.p << ' ' << ans.q << endl;
	}

	return 0;
}

