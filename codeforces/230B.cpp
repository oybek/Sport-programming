
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001
#define SQR(x) ((x)*(x))
#define ALL(a) a.begin(), a.end()
#define DIVC(a, b) (a/b+(a%b?1:0))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define max_prime 1000000
bitset<max_prime> is_prime;
void init_sieve() {
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i*i < max_prime; ++i)
		if (is_prime[i])
			for (int j = i*i; j < max_prime; j += i)
				is_prime[j] = 0;
}

int main() {
	init_sieve();
	int n;
	int64 t, tsqrt;

	cin >> n;
	while (n--) {
		cin >> t;
		tsqrt = sqrt(t);
#ifdef DEBUG
		cout << "DEBUG: " << tsqrt << endl;
#endif
		cout << (tsqrt*tsqrt == t && is_prime[tsqrt] ? "YES" : "NO") << endl;
	}

	return 0;
}

